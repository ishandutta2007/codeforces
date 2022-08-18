/*
The new age of terror has now begun
The targets re civilians
They're out manned and out gunned
No one is safe, there's no where to hide
Brought to their knees, can't kill their pride
Unmerciful mercenaries, bring horror to the land
No conscious, no pity, now with death in each hand
All out war and your freedom's at stake
The government's corrupt: it's your life they will take

[Chorus:]
Attack take them by surprise, wipe them out!
Ambush control from the start to the end
The new age of terror! The new age of terror!

Mental warfare, their fucking with your minds
Scare tactics, no honor, no hints, no signs
Prepare for the worst unimaginable hell
Stripped of your innocents, your soul is for sale
Remembering the dead, you must carry on
To give up and give in, no that would be wrong
Evil minds with sick sinister plans
We must stop them now, 'cause our lives are in their hands

[Chorus]

Violence breeds violence, bitter fighting
You kill in god's eyes, it's a sin
Religious wars, have murdered more people
The masters of hate they will win

You'll burn in hell for the lies that you've told
Satan he possesses your unsaintly soul
Confess human suffering the pain you have dealt
Justify sending your soldiers to an early grave

Violence breeds violence, bitter fighting
You kill in god's eyes, it's a sin
Religious wars, have murdered more people
The masters of hate they will win

Confess human suffering the pain you have dealt
Justify sending your soldiers to an early grave

The new age of terror has now begun
The targets re civilians
They're out manned and out gunned
No one is safe, there's no where to hide
Brought to their knees, can't kill their pride
Unmerciful mercenaries, bring horror to the land
No conscious, no pity, now with death in each hand
All out war and your freedom's at stake
The government's corrupt: it's your life they will take!!

[Chorus]
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

#define bsize 256

#define ldouble long double

using namespace std;

long long INF = 1e9;
const int N = 1200031;

int n,m;
vector<int> g[N];
int used[N];
int deg[N];

void dfs(int v)
{
	used[v]=1;
	for (int i=0;i<g[v].size();i++)
	{
		int to=g[v][i];
		if (used[to])
			continue;
		dfs(to);
	}
}

vector<pair<int,int> > edges;

int loops;
int non_loops;
int is_loop[N];

int main(){
	//freopen("cinema.in","r",stdin);
	//freopen("cinema.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
//	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>m;
	for (int i=1;i<=m;i++)
	{
		int a,b;
	//	cin>>a>>b;
		scanf("%d",&a);
		scanf("%d",&b);
		if (a==b)
		{
			deg[a]++;
			g[a].push_back(a);
			is_loop[a]++;
			edges.push_back(make_pair(a,b));
			loops++;
			continue;
		}

		if (a>b)
			swap(a,b);
		non_loops++;
		g[a].push_back(b);
		g[b].push_back(a);
		deg[a]++;
		deg[b]++;
		edges.push_back(make_pair(a,b));
	}

	for (int i=1;i<=n;i++)
	{
		if (used[i])
			continue;
		if (g[i].size()==0)
			continue;
		dfs(i);
		break;
	}

	for (int i=1;i<=n;i++)
	{
		if (g[i].size()>0&&used[i]==0)
		{
			cout<<0<<endl;
			return 0;
		}
	}

	long long ans=0;
	for (int i=1;i<=n;i++)
	{
		int here=g[i].size();
		if (is_loop[i])
			--here;
		ans+=1ll*here*(here-1)/2;
//		ans+=1ll*g[i].size()*(g[i].size()-1)/2;
	}

	ans+=loops*1ll*(non_loops);

	ans+=1ll*loops*(loops-1)/2;

	int cnt=0;

	/*sort(edges.begin(),edges.end());
	for (int i=0;i<edges.size();i++)
	{
		if (i>0&&edges[i]!=edges[i-1])
		{
			ans-=cnt*1ll*(cnt-1)/2;
			cnt=0;
		}
		++cnt;
	}
	ans-=1ll*cnt*(cnt-1)/2;
	*/
	cout<<ans<<endl;

	cin.get(); cin.get();
	return 0;
}