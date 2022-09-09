#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
typedef long long li;
typedef pair <int, int> pi;
#define mp make_pair
#define pb push_back
void solve ();
int main()
{
		freopen("input.txt","r",stdin);
#ifndef _DEBUG
	freopen("output.txt","w",stdout);
#endif
	 solve();
	return 0;
}
//#define int li
int n, m;
int c[60][60];
int A, B, C;
int stolb[60], str[60];
void solve()
{
	cin>>n>>m;
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			cin>>c[i][j];
	int sum=0;
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
		{
			sum+=c[i][j];
			str[i]+=c[i][j];
			stolb[j]+=c[i][j];
		}
	cin>>A>>B>>C;
	int ans=0;
	if ( sum!=A+B+C )
	{
		cout<<"0";
		return;
	}
	if ( n>2 )
	for ( int i=1; i<n-1; i++ )
		for ( int j=i+1; j<n; j++ )
		{
			int sum1=0, sum2=0;
			for ( int k=0; k<i; k++ )
				sum1+=str[k];
			for (int k=i; k<j; k++)
				sum2+=str[k];
			if ((sum1==A && sum2==B) || (sum1==A && sum2==C) ||(sum1==B && sum2==A) || (sum1==B && sum2==C) || (sum1==C && sum2==A) || (sum1==C && sum2==B))
				ans++;
		}
	if (m>2)
	for ( int i=1; i<m-1; i++ )
		for ( int j=i+1; j<m; j++ )
		{
			int sum1=0, sum2=0;
			for ( int k=0; k<i; k++ )
				sum1+=stolb[k];
			for (int k=i; k<j; k++)
				sum2+=stolb[k];
			if ((sum1==A && sum2==B) || (sum1==A && sum2==C) ||(sum1==B && sum2==A) || (sum1==B && sum2==C) || (sum1==C && sum2==A) || (sum1==C && sum2==B))
				ans++;
		}
		cout<<ans;
}