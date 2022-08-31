/*
Bodies fill the fields I see, hungry heroes end
No one to play soldier now, no one to pretend
Running blind through killing fields, bred to kill them all
Victim of what said should be
A servant 'til I fall

Soldier boy, made of clay
Now an empty shell
Twenty-one, only son
But he served us well
Bred to kill, not to care
Do just as we say
Finished here
Greetings, Death
Hes yours to take away

Back to the front
You will do what I say, when I say
Back to the front
You will die when I say, you must die
Back to the front
You coward
You servant
You blind man

Barking of machinegun fire does nothing to me now
Sounding of the clock that ticks, get used to it somehow
More a man, more stripes you bare, glory-seeker trends
Bodies fill the fields I see
The slaughter never ends

Soldier boy, made of clay
Now an empty shell
Twenty-one, only son
But he served us well
Bred to kill, not to care
Do just as we say
Finished here
Greetings, Death
Hes yours to take away

Back to the front
You will do what I say, when I say
Back to the front
You will die when I say, you must die
Back to the front
You coward
You servant
You blind man

Why, am I dying?
Kill, have no fear
Lie, live off lying
Hell, hell is here

I was born for dying

Life planned out before my birth, nothing could I say
Had no chance to see myself, molded day by day
Looking back I realize, nothing have I done
Left to die with only friend
Alone I clench my gun

Soldier boy, made of clay
Now an empty shell
Twenty-one, only son
But he served us well
Bred to kill, not to care
Do just as we say
Finished here
Greetings, Death
Hes yours to take away

Back to the front
You will do what I say, when I say
Back to the front
You will die when I say, you must die
Back to the front
You coward
You servant
You blind man

Back to the front
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
const int N = 1000031;

int n;
int v;
vector<int> g[N];
int root;
int t[N];
int tin[N],tout[N];
int s;
int ans_tin,ans_tout,subsize[N];
int ans1,ans2;
int timer;

int ok_v[N];
int need;
int found;

void dfs(int v)
{
	ok_v[v]=-1;

	++timer;
	tin[v]=timer;
	subsize[v]=t[v];
	for (int i=0;i<g[v].size();i++)
	{
		int to=g[v][i];
		dfs(to);
		if (ok_v[to]!=-1)
			ok_v[v]=ok_v[to];
		subsize[v]+=subsize[to];
	}

	if (subsize[v]==2*need&&ok_v[v]!=-1&&v!=root)
	{
		found=1;
		ans1=v;
		ans2=ok_v[v];
	}

	if (subsize[v]==need)
	{
		ok_v[v]=v;
	}

	++timer;
	tout[v]=timer;
}

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;
	for (int i=1;i<=n;i++)
	{
//		cin>>v;
		scanf("%d",&v);
		if (v==0)
			root=i;
		else
		{
			g[v].push_back(i);
		}
//		cin>>t[i];
		scanf("%d",&t[i]);
		s+=t[i];
	}

	if (s%3)
	{
		cout<<-1<<endl;
		return 0;
	}

	need=s/3;

	dfs(root);

	if (found)
	{
		cout<<ans1<<" "<<ans2<<endl;
		return 0;
	}

	ans_tout=1e9;
	ans_tin=-1e9;

	for (int i=1;i<=n;i++)
	{
		if (subsize[i]!=need)
			continue;
		if (i==root)
			continue;
		if (tout[i]<ans_tout)
		{
			ans_tout=tout[i];
			ans1=i;
		}
		if (tin[i]>ans_tin)
		{
			ans_tin=tin[i];
			ans2=i;
		}
	}

	/*for (int i=1;i<=n;i++)
	{
		cout<<subsize[i]<<" ";
	}
	cout<<endl;*/
	//cout<<ans_tin<<"%"<<ans_tout<<endl;

	if (ans_tin<=ans_tout)
	{
		cout<<-1<<endl;
	}
	else
	{
		cout<<ans1<<" "<<ans2<<endl;
	}

	cin.get(); cin.get();
	return 0;
}