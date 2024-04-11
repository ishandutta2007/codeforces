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
#endif
    solve();
    return 0;
}
//#define int li
const int K=26, MAXLEN=100500;
struct state
{
	int length, link;
	int next[K];
	bool terminal;
	bool clonned;
	int id;
	bool operator < ( const state &b ) const { return length<b.length; }
};
state st[2*MAXLEN];
state sorted[2*MAXLEN];
int sz=0;
int last;
string s;
void extend ( char c )
{
	int nlast=sz++;
	st[nlast].length=st[last].length+1;
	st[nlast].clonned=false;
	memset ( st[nlast].next, -1, sizeof st[nlast].next );
	int p=last;
	for (; p!=-1 && st[p].next[c]==-1; p=st[p].link)
		st[p].next[c]=nlast;
	if (p==-1)
		st[nlast].link=0;
	else
	{
		int q=st[p].next[c];
		if ( st[p].length+1==st[q].length )
			st[nlast].link=q;
		else
		{
			int clone=sz++;
			st[clone].length=st[p].length+1;
			st[clone].clonned=true;
			memcpy (st[clone].next, st[q].next, sizeof st[clone].next);
			st[clone].link=st[q].link;
			for (; p!=-1 && st[p].next[c]==q; p=st[p].link)
				st[p].next[c]=clone;
			st[q].link=st[nlast].link=clone;
		}
	}
	last=nlast;
}
void mark_terminal()
{
	for (int p=last; p!=-1; p=st[p].link)
		st[p].terminal=true;
}
li cnt[2*MAXLEN];
bool done[2*MAXLEN];
li num[2*MAXLEN];
void solve ()
{
	last=0;
	st[0].length=0; st[0].link=-1;
	st[0].clonned=false;
	memset ( st[0].next, -1, sizeof st[0].next );
	sz++;
	cin>>s;
	for (int i=0; i<s.length(); i++)
		extend(s[i]-'a');
	mark_terminal();
	for (int i=0; i<sz; i++)
	{
		st[i].id=i;
		sorted[i]=st[i];
		cnt[i]=(st[i].clonned)?0:1;
	}


	sort ( sorted, sorted+sz );
	for (int i=sz-1; i>=0; i--)
	{
		if (sorted[i].link!=-1)
		cnt[sorted[i].link]+=cnt[sorted[i].id];
	}

	num[0]=1;
	for (int i=0; i<sz; i++)
	{
		for (int j=0; j<K; j++)
			if ( sorted[i].next[j]!=-1 )
				num[sorted[i].next[j]]+=num[sorted[i].id];
	}

	//for (int i=0; i<sz; i++)
	//{
	//	cout<<i<<"   "<<num[i]<<endl;
	//	//cout<<i<<"   "<<st[i].length<<"   "<<st[i].link<<endl;
	//	//cout<<endl<<num[i]<<"    "<<cnt[i]<<endl<<endl;
	//	//for (int j=0; j<K; j++)
	//	//	if ( st[i].next[j]!=-1 )
	//			//printf ("%c  %d\n", j+'a', st[i].next[j]);
	//	cout<<endl;
	//}

	li ans=0;
	for (int i=1; i<sz; i++)
		ans+=(num[i]*cnt[i]*(cnt[i]+1)/2);
	cout<<ans;
}