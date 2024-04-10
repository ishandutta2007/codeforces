/*
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
const int N = 600331;

int n,k;
vector<int> g[N];

int used[N];

int subsize[N];

long long TOTAL_DIST=0;

vector<int> sons[N];

void trace_sizes(int v)
{
	used[v]=1;
	subsize[v]=1;

	for (int i=0;i<g[v].size();i++)
	{
		int to=g[v][i];
		if (used[to])
			continue;
		trace_sizes(to);
		subsize[v]+=subsize[to];
		TOTAL_DIST+=1ll*(subsize[to])*(n-subsize[to]);
	}
}

int dep[N];
vector<pair<int,int> > entries[N];

int tin[N],tout[N];

int timer;

void dfs(int v)
{
	++timer;
	tin[v]=timer;
	used[v]=1;

	for (int i=0;i<g[v].size();i++)
	{
		int to=g[v][i];
		if (used[to])
			continue;
		dep[to]=dep[v]+1;
		sons[v].push_back(to);
		dfs(to);
	}

	++timer;
	tout[v]=timer;
}

long long cnt[100],new_cnt[100];

long long TOTAL_WITH[N];

int  make_query(int id,int l,int r)
{
	return upper_bound(entries[id].begin(),entries[id].end(),make_pair(r,1000000))-lower_bound(
			entries[id].begin(),entries[id].end(),make_pair(l,-1));
}

int main(){
	//freopen("cinema.in","r",stdin);
	//freopen("cinema.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>k;
	for (int i=1;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	trace_sizes(1);

//	cout<<TOTAL_DIST<<endl;

	for (int i=1;i<=n;i++)
	{
		used[i]=0;
	}

	dfs(1);

	for (int i=1;i<=n;i++)
	{
		int here=dep[i]%k;
		entries[here].push_back(make_pair(tin[i],i));
	}

	for (int i=0;i<=k;i++)
	{
		sort(entries[i].begin(),entries[i].end());
	}

	for (int i=1;i<=n;i++)
	{
		int L=tin[i];
		int R=tout[i];

		for (int q=0;q<=k;q++)
			cnt[q]=0;

		// sons

		for (int j=0;j<sons[i].size();j++)
		{
			int to=sons[i][j];
			int L=tin[to];
			int R=tout[to];

			for (int q=0;q<=k;q++)
			{
				new_cnt[q]=0;
			}

			for (int q=0;q<k;q++)
			{
				new_cnt[q]=make_query(q,L,R);
			}

			for (int q=0;q<k;q++)
			{
				for (int w=0;w<k;w++)
				{
					int len_here=q+w-2*(dep[i]%k);
					len_here%=k;
					if (len_here<0)
						len_here+=k;
					TOTAL_WITH[len_here]+=1ll*cnt[q]*new_cnt[w];
				}
			}

			for (int q=0;q<k;q++)
			{
				cnt[q]+=new_cnt[q];
			}
		}

		// vertex itself

		for (int q=0;q<k;q++)
		{
			int len_here=(dep[i]%k+q)-2*(dep[i]%k);
			len_here%=k;
			if (len_here<0)
				len_here+=k;
			TOTAL_WITH[len_here]+=cnt[q];
		}

	}

	/*for (int i=0;i<k;i++)
	{
		cout<<TOTAL_WITH[i]<<endl;
	}*/

	long long ans=0;

	for (int i=0;i<k;i++)
	{
		TOTAL_DIST-=TOTAL_WITH[i]*i;
		if (i>0)
			ans+=TOTAL_WITH[i];
	}

	ans+=TOTAL_DIST/k;

	cout<<ans<<endl;

	cin.get(); cin.get();
	return 0;
}