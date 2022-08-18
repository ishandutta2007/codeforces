/*
All that is, was and will be
Universe much too big to see

Time and space never ending
Disturbing thoughts, questions pending
Limitations of human understanding
Too quick to criticize
Obligation to survive
We hunger to be alive

All that is, ever
Ever was
Will be ever
Twisting
Turning
Through the never

In the dark, see past our eyes
Pursuit of truth no matter where it lies

Gazing up to the breeze of the heavens
On a quest, meaning, reason
Came to be, how it begun
All alone in the family of the sun
Curiosity teasing everyone
On our home, third stone from the sun

All that is, ever
Ever was
Will be ever
Twisting
Turning
Through the never

On through the never
We must go
On through the never
Out of the
Edge of forever
We must go
On through the never
Then ever comes

All that is, ever
Ever was
Will be ever
Who we are
Ask forever
Twisting
Turning
Through the never

Never
*/

#pragma GCC optimize("O3")
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>

#include <memory.h>
#include <assert.h>

#define y0 sdkfaslhagaklsldk

#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd

#define eps 1e-8
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

#define ldouble long double

using namespace std;

long long INF = 1e9;
const int N = 500331;

const int SZ = 15000000;

int n,ar[N];
int ROOT[N];
map<int,int> fe;
int root;

int l_son[SZ],r_son[SZ],t[SZ];

int CNT;

void build(int v,int tl,int tr)
{
	CNT=max(CNT,v);

	if (tl==tr)
		return;
	int tm=tl+tr;
	tm/=2;
	build(v*2,tl,tm);
	build(v*2+1,tm+1,tr);
	l_son[v]=v*2;
	r_son[v]=v*2+1;
}

vector<int> ans;

int get_kth(int v,int tl,int tr,int need)
{
	if (tl==tr)
		return tl;
	int tm=tl+tr;
	tm/=2;
	if (t[l_son[v]]>=need)
		return get_kth(l_son[v],tl,tm,need);
	need-=t[l_son[v]];
	return get_kth(r_son[v],tm+1,tr,need);
}

int add(int v,int tl,int tr,int ps,int val)
{
	if (tl==tr)
	{
		++CNT;
		t[CNT]=t[v]+val;
		return CNT;
	}
	int tm=tl+tr;
	tm/=2;
	if (ps<=tm)
	{
		++CNT;
		int here=CNT;
		r_son[here]=r_son[v];
		l_son[here]=add(l_son[v],tl,tm,ps,val);
		t[here]=t[l_son[here]]+t[r_son[here]];
		return here;
	}
	else
	{
		++CNT;
		int here=CNT;
		l_son[here]=l_son[v];
		r_son[here]=add(r_son[v],tm+1,tr,ps,val);
		t[here]=t[l_son[here]]+t[r_son[here]];
		return here;
	}
}

int main(){
	//freopen("cinema.in","r",stdin);
	//freopen("cinema.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;

	for (int i=1;i<=n;i++)
	{
		cin>>ar[i];
	}

	build(1,1,n);

	root=1;

	root=add(root,1,n+1,n+1,1000000);

	for (int i=n;i>=1;--i)
	{
		int here=ar[i];
		root=add(root,1,n+1,i,1);
		if (fe.find(here)!=fe.end())
		{
			root=add(root,1,n+1,fe[here],-1);
		}
		fe[here]=i;
		ROOT[i]=root;
	}

	for (int step=1;step<=n;step++)
	{
		int cnt=0;
		int ptr=1;
		while (ptr!=n+1)
		{
			int Q=get_kth(ROOT[ptr],1,n+1,step+1);
			++cnt;
			ptr=Q;
		}
		ans.push_back(cnt);
	}

	for (int i=0;i<ans.size();i++)
	{
		if (i)
			cout<<" ";
		cout<<ans[i];
	}
	cout<<endl;


	cin.get(); cin.get();
	return 0;
}