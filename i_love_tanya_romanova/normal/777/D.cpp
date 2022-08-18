/*
Twisting and turning unable to sleep
Do the voices ever stop
My thoughts speak louder the more I resist
And they're driving me insane
Do they ever go

Inside I'm a danger to myself
I'm a danger to myself
Inside I'm a prisoner of my own hell
My own hell

Losing the battle I've waged on myself
Lock me up and toss the key
Toys in the attic its all getting worse
Why wont they let me be oh god make it stop

Inside I'm a danger to myself
I'm a danger to myself
Inside I'm a prisoner of my own hell
My own hell

Fit me for a straitjacket
Put me in a padded cell
I'm a danger to you all
And I'm a danger to myself

Inside I'm a danger to myself
I'm a danger to myself
Inside I'm a prisoner of my own hell
My own hell

Inside I'm a danger to myself
I'm a danger to myself
Inside I'm a prisoner of my own hell
My own hell
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

#define eps 1e-11
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

#define ldouble long double

using namespace std;

long long INF = 1e9;
const int N = 711031;

int n;
string st[N];
int worst;
string ans[N];
int cut_len;

int get_lcp(int a,int b)
{
	for (int i=0;;i++)
	{
		if (i==st[a].size()||i==st[b].size())
			return i;
		if (st[a][i]!=st[b][i])
			return i;
	}
}

bool cmp(int a,int b,int Q)
{
	if (st[a].size()==Q)
		return false;
	if (st[b].size()==Q)
		return true;
	return (st[a][Q]>st[b][Q]);
}

int main(){
//	freopen("explosion.in","r",stdin);
//	freopen("explosion.out","w",stdout);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>st[i];
	}

	st[n+1]=st[n];

	worst=n+1;
	for (int i=n;i>=1;--i)
	{
		int Q=get_lcp(i,worst);
		if (cmp(i,worst,Q))
		{
			cut_len=Q;
		}
		else
		{
			cut_len=st[i].size();
			//worst=i;
		}
		ans[i]="";
		for (int j=0;j<cut_len;j++)
		{
			ans[i]+=st[i][j];
		}
		if (ans[i]<st[n+1])
			st[n+1]=ans[i];
	}

	for (int i=1;i<=n;i++)
	{
		cout<<ans[i]<<"\n";
	}

	cin.get(); cin.get();
	return 0;
}