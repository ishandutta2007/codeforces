#pragma hdrstop
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <stack>
#include <memory.h>
#include <queue>
#include <time.h>

using namespace std;

#define mp make_pair
#define pb push_back

typedef long long li;
typedef long double ld;
typedef pair <int, int> pi;
typedef vector <int> vi;

void solve();
#define FILE "substrings"
int main ()
{
#ifdef DEBUG
	freopen ("in.txt", "r", stdin);
	//freopen ("out.txt", "w", stdout);
	//cout<<FILE<<endl;
#else
	//freopen ("input.txt", "r", stdin);
	//freopen ("output.txt", "w", stdout);
#endif
	int t=1;
	//cin>>t;
	while (t--)
		solve();
	return 0;
}

#define int li

string s;
int m;
string q[200];

int p=31;
int step[100500];
int hashes[100500];

int minpref[2000], minsuf[2000];

int h[200][2000];

bool Equal (int l1, int r1, int i, int l2, int r2)
{
	if (r2>=q[i].length())
		return false;
	if (l2<0)
		return false;
	if (r1>=s.length())
		return false;
	if (l1<0)
		return false;
	if (l1>r1 || l2>r2)
		return false;

	int hash1=hashes[r1]-((l1==0)?0:hashes[l1-1])*step[r1-l1+1];
	int hash2=h[i][r2]-((l2==0)?0:h[i][l2-1])*step[r2-l2+1];
	return hash1==hash2;
}

void solve()
{
	cin>>s>>m;
	for (int i=0; i<m; i++)
		cin>>q[i];
	step[0]=1;
	for (int i=1; i<100500; i++)
		step[i]=step[i-1]*p;
	hashes[0]=s[0];
	for (int i=1; i<s.length(); i++)
		hashes[i]=hashes[i-1]*p+s[i];
	int ans=0;
	for (int i=0; i<m; i++)
	{
		if (q[i].length()==1)
		continue;
		memset (minpref, -1, sizeof minpref);
		memset (minsuf, -1, sizeof minsuf);
		h[i][0]=q[i][0];
		for (int j=1; j<q[i].length(); j++)
			h[i][j]=h[i][j-1]*p+q[i][j];

		int cur=0;
		int now=q[i].length();
		for (int j=0; j<s.length(); j++)
		{

			while (cur<now && j+cur<s.length() && Equal ( j, j+cur, i, 0, cur ) )
				minpref[++cur]=j;
		}
		cur=0;
		for (int j=s.length()-1; j>=0; j--)
		{
			while (cur<now && j-cur>=0 && Equal ( j-cur, j, i, now-1-cur, now-1 ) )
				minsuf[++cur]=j;
		}

		if (minpref[now]!=-1 || minsuf[now]!=-1)
		{
			ans++;
			continue;
		}



		for (int j=1; j<now; j++)
			if (minpref[j]!=-1)
			{
				int w=now-j;
				if (minsuf[w]==-1)
					continue;
				if (minpref[j]+j-1<minsuf[w]-w+1)
				{
					ans++;
					break;
				}
			}

	}

	cout<<ans;


}