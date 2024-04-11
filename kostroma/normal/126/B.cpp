#pragma hdrstop
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
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
//#else 
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
#endif
	int t=1;
	while (t--)
    solve();
    return 0;
}
//#define int li
string s;
vector<int> z_function () {
	int n = (int) s.length();
	vector<int> z (n);
	for (int i=1, l=0, r=0; i<n; ++i) {
		if (i <= r)
			z[i] = min (r-i+1, z[i-l]);
		while (i+z[i] < n && s[z[i]] == s[i+z[i]])
			++z[i];
		if (i+z[i]-1 > r)
			l = i,  r = i+z[i]-1;
	}
	return z;
}
vector <int> fun;
int may[2000000];
void solve ()
{
	cin>>s;
	fun=z_function();
	int ans=0;
	for (int i=1; i<s.length(); i++)
	{
		int cur=fun[i];
		if (cur+i==s.length())
			cur--;
		if (cur>0 && may[cur]==0)
			may[cur]++;
	}
	int u=-1;
	for (int i=s.length(); i>=0; i--)
		if (may[i]==1)
		{
			u=i;
			break;
		}
	for (int i=0; i<=u; i++)
		may[i]=1;
	for ( int i=0; i<s.length(); i++ )
		if ( fun[i]==s.length()-i  )
		{
			int big=s.length()-i;
			if (may[big]==1 && ans<big)
				ans=big;
		}
	if (ans==0)
	{
		cout<<"Just a legend";
		return;
	}
	string answer;
	for (int i=0; i<ans; i++)
		answer.pb(s[i]);
	cout<<answer;
}