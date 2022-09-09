#pragma hdrstop
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <vector>
using namespace std;
/*
BE CAREFUL: ISN'T INT EQUAL TO LONG LONG?

REAL SOLUTION AFTER MAIN FUNCTION
*/
#define mp make_pair
#define pb push_back
typedef long long li;
typedef long double ld;
typedef pair <int, int> pi;
void solve();
int main ()
{
#ifdef _DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}
//#define int li
string s;
int n;
vector <int> bad;
int num[300];
string ans;
string q;
void solve ()
{
	cin>>s;
	n=s.length();
	if (n==1)
	{
		cout<<"YES\n";
		cout<<s;
		return;
	}
	bad.pb (0);
	ans.resize(n);
	for ( int i=n/2+1; i<=n; i++ )
	{
		bool f=true;
		for (int j=2; j*j<=i; j++)
			if (i%j==0)
			{
				f=false;
				break;
			}
		if (f)
			bad.pb (i-1);
	}
	int equal=n-bad.size();
	for ( int i=0; i<n; i++ )
		num[s[i]]++;
	char norm=1;
	for ( int j='a'; j<='z'; j++ )
		if ( num[j]>=equal )
		{
			norm=j;
			break;
		}
	if (norm==1)
	{
		cout<<"NO";
		return;
	}
	int t=0;
	for ( int i=0; i<n; i++ )
		if (s[i]!=norm || t>=equal)
			q.pb (s[i]);
		else 
			t++;
	for ( int i=0; i<n; i++ )
		ans[i]=norm;
	for (int i=0; i<bad.size(); i++)
	{
		ans[bad[i]]=q[q.size()-1];
		q.resize(q.size()-1);
	}
	cout<<"YES\n";
	cout<<ans;
}