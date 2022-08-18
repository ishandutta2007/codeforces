/*
High velocity bullet at close range
Can damage the mind
Shattering the skull, shredding the brain
Severing the spine

Bury a round of lead in the chest
It's quite an impression
Imagine the innards of your soul
The infliction

Instinctive regression
With intent to kill
No regard of human life
Or the blood spilled

Riddled convulsions
Confetti of flesh
Scattered helplessly
Losing your control of physical facilities

Release the slide to cleanse inside
Prepare to anoint
Snap the tongue in the groove discharge
To make my hallowed point

Instinctive regression
With intent to kill
No regard of human life
Or the blood spilled

The power of a gun
Used with conviction
Dispersed on excursions
Randomly kills its victims

My sweet revenge
Bitter in depression
The thrilling release
Of a hatred deep persuasion

The power of a gun
Used with conviction
Diffused compulsions
Unending repercussions

Violent emotion
Screaming revolution
Spasmic convulsions
Death an empty gun
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
const int N = 200031;

int n,a,b,c,d;
vector<int> g[N];

int subsize[N];
int a_group,b_group,c_group,d_group;

int tin[N],tout[N],timer;

void trace(int v)
{
	++timer;
	tin[v]=timer;
	for (int i=0;i<g[v].size();i++)
	{
		int to=g[v][i];
		trace(to);
		subsize[v]+=subsize[to];
	}
	if (g[v].size()==0)
		subsize[v]=1;
	++timer;
	tout[v]=timer;
}

bool Contains(int a,int b)
{
	return tin[a]<=tin[b]&&tout[a]>=tout[b];
}

vector<int> free_list;

int dp[3][30000];
int reach[30000];

int SPAN;

bool can_solve(int a,int b,int othr_a,int othr_b)
{
	for (int i=0;i<=subsize[1];i++)
	{
		for (int j=0;j<=1;j++)
		{
			dp[j][i]=0;
		}
	}
	dp[0][0]=1;
	for (int i=0;i<free_list.size();i++)
	{
		for (int j=0;j<=subsize[1];j++)
		{
			dp[1-i%2][j]=0;
		}
		for (int j=0;j<=subsize[1];j++)
		{
			if (dp[i%2][j])
			{
				dp[1-i%2][j]=1;// out
				dp[1-i%2][j+free_list[i]]=1;// in
			}
		}
	}

	for (int i=0;i<=subsize[1];i++)
	{
		reach[i]=0;
	}

	for (int i=0;i<=subsize[1];i++)
	{
		if (dp[free_list.size()%2][i])
		{
			reach[i+othr_a]=1;
			reach[i+othr_b]=1;
		}
	}
	// S_in<=SPAN
	//S_in>=(SPAN-(a-1)-(b-1))
	for (int i=0;i<=subsize[1];i++)
	{
		if (reach[i]==0)
			continue;
		if (i>=SPAN-(a-1)-(b-1)&&i<=SPAN)
			return 1;
	}
	return 0;
}

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;
	cin>>a>>b>>c>>d;

	for (int i=2;i<=n;i++)
	{
		int par;
		cin>>par;
		g[par].push_back(i);
	}

	trace(1);

	for (int i=0;i<g[1].size();i++)
	{
		int to=g[1][i];
		if (Contains(to,a))
		{
			a_group=subsize[to];
		}
		else if (Contains(to,b))
		{
			b_group=subsize[to];
		}
		else if (Contains(to,c))
		{
			c_group=subsize[to];
		}
		else if (Contains(to,d))
		{
			d_group=subsize[to];
		}
		else
		{
			free_list.push_back(subsize[to]);
		}
	}

	if (subsize[1]%2==1)
	{
		cout<<"NO"<<endl;
		return 0;
	}

	SPAN=subsize[1]/2-1;

	if (can_solve(a_group,c_group,b_group,d_group)&&can_solve(b_group,d_group,a_group,c_group))
	{
		cout<<"YES"<<endl;
	}
	else
		cout<<"NO"<<endl;

	cin.get(); cin.get();
	return 0;
}