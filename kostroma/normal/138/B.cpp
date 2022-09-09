#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <vector>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(a) (a.begin(), a.end())

typedef long long li;
typedef long double ld;

void solve ();

int main ()
{
#ifdef DEBUG
	freopen ("in.txt", "r", stdin);
#endif
	int t=1;
	while (t--)
		solve();
	return 0;
}
//#define int li
string s;
int n;
int num[20];
int num1[20], num2[20];
int kol[20];
pair <int, int> sum_ten=mp (-1, -1);
bool flag=false;
vector <int> a1, a2;
void out ()
{
	for (int i=0; i<a1.size(); i++)
		cout<<a1[i];
	cout<<endl;
	for (int i=0; i<a2.size(); i++)
		cout<<a2[i];
}
void solve ()
{
	cin>>s;
	n=s.length();
	for (int i=0; i<n; i++)
		num[s[i]-'0']++;
	int sum=0;
	for ( int i=0; i<10; i++ )
		kol[i]=min (num[i], num[9-i]), sum+=kol[i];
	int nullnum=num[0]-kol[0];
	int ans=0;
	for (int i=0; i<=5; i++)
	{
		int j=10-i;
		if ( !num[i] || !num[j] )
			continue;
		int z=0;
		if ( num[i]==kol[i] )
			z++;
		if (num[j]==kol[j])
			z++;
		if (z==2 || i==5)
			z--;
		if (ans<sum+1-z)
		{
			ans=sum+1-z;
			sum_ten=mp (i, j);
			flag=true;
		}
	}

	if ( !flag )
	{
		for (int i=0; i<nullnum; i++)
			a1.pb (0), a2.pb (0);
		for ( int i=1; i<=9; i++ )
			for ( int j=0; j<num[i]; j++ )
				a1.pb (i), a2.pb (i);
		reverse (a1.begin(), a1.end());
		reverse (a2.begin(), a2.end());
		out ();
		return;
	}
	num[0]-=nullnum;
	for (int i=0; i<10; i++)
		num1[i]=num2[i]=num[i];

	for (int i=0; i<nullnum; i++)
			a1.pb (0), a2.pb (0);
	a1.pb (sum_ten.first), a2.pb (sum_ten.second);

	num1[sum_ten.first]--; num2[sum_ten.second]--;

	for (int i=0; i<10; i++)
		while ( num1[i] && num2[9-i] )
		{
			a1.pb (i), a2.pb (9-i);
			num1[i]--;
			num2[9-i]--;
		}

	for (int i=0; i<10; i++)
		for (int j=0; j<num1[i]; j++)
			a1.pb (i);

	for (int i=0; i<10; i++)
		for (int j=0; j<num2[i]; j++)
			a2.pb (i);

	reverse (a1.begin(), a1.end());
	reverse (a2.begin(), a2.end());
	out();
}