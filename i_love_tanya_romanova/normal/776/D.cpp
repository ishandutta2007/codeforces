/*
The atmosphere around you is dark and cold
You're only seventeen but in your heart you're feeling old
But one day you will leave this place of fear
Escape to somewhere far away far away from here

A grain of sand at the ocean shore
Faceless lost with the urge for more
Can't break free suffering in pain
Following the Everlasting Flame

The factory walls here leave no room to breath
You're thirty four and some old friends became only memories
And still you need to hide your bitter tears
And dream of somewhere far away far away from here

Swallowed by this material world
Pre ordained from his death to birth
Can't break free suffering
Following the Everlasting Flame

There's just no way out of this living hell
You're fifty six now just a shadow of your broken self
A wasted life the pain won't disappear
You'll never see a better place far away from here

Swallowed by this material world
Pre ordained from his death to birth
Can't break free suffering
Following the Everlasting Flame
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
const int N = 411031;

int n,m;
int state[N];

int paired(int x)
{
	if (x<=m)
		return x+m;
	return x-m;
}

vector<int> li[N];
int w[N];

int get(int x)
{
	if (w[x]==x)
		return x;
	return w[x]=get(w[x]);
}

void add_edge(int a,int b)
{
	a=get(a);
	b=get(b);
	w[a]=b;
}

int main(){
//	freopen("explosion.in","r",stdin);
//	freopen("explosion.out","w",stdout);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>state[i];
	}

	for (int i=1;i<=m*2;i++)
	{
		w[i]=i;
	}

	for (int i=1;i<=m;i++)
	{
		int am;
		cin>>am;
		for (int j=0;j<am;j++)
		{
			int id;
			cin>>id;
			li[id].push_back(i);
		}
	}

	for (int i=1;i<=n;i++)
	{
		int a=li[i][0];
		int b=li[i][1];
		if (state[i]==1) // same value
		{
			add_edge(a,b);
			add_edge(paired(a),paired(b));
		}
		else
		{
			add_edge(a,paired(b));
			add_edge(paired(a),b);
		}
	}

	int ok=1;
	for (int i=1;i<=m;i++)
	{
		if (get(i)==get(paired(i)))
			ok=0;
	}
	if (ok)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;

	cin.get(); cin.get();
	return 0;
}