/*
Adventure seeker on an empty street,
Just an alley creeper, light on his feet
A young fighter screaming, with no time for doubt
With the pain and anger can't see a way out,
It ain't much I'm asking, I heard him say,
Gotta find me a future move out of my way,
I want it all, I want it all, I want it all, and I want it now,
I want it all, I want it all, I want it all, and I want it now,

Listen all you people, come gather round
I gotta get me a game plan, gotta shake you to the ground
Just give me what I know is mine,
People do you hear me, just give me the sign,
It ain't much I'm asking, if you want the truth
Here's to the future for the dreams of youth,
I want it all, I want it all, I want it all, and I want it now,
I want it all, I want it all, I want it all, and I want it now,

I'm a man with a one track mind,
So much to do in one life time (people do you hear me)
Not a man for compromise and where's and why's and living lies
So I'm living it all, yes I'm living it all,
And I'm giving it all, and I'm giving it all,
It ain't much I'm asking, if you want the truth,
Here's to the future, hear the cry of youth,
I want it all, I want it all, I want it all, and I want it now,
I want it all, I want it all, I want it all, and I want it now.
*/

//#pragma GCC optimize("O3")
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
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 1100031;

int n,m,a[N],b[N],cost[N];
vector<int> g[N],gr[N];
int used[N];
int C;
vector<int> order;

void dfs(int v){
	used[v]=1;
	for (int i=0;i<g[v].size();i++){
		int id=g[v][i];
		int to=b[id];
		if (used[to])
			continue;
		dfs(to);
	}
	order.push_back(v);
}

void rdfs(int v){
	used[v]=C;
	for (int i=0;i<gr[v].size();i++){
		int id=gr[v][i];
		int to=a[id];
		if (used[to])
			continue;
		rdfs(to);
	}
}

long long COST[N];

vector<pair<int,int> > G[N];

long long dp[N];

long long subt[N],subt_sum[N];

long long get_edge_cost(long long C){

	int l,r;
	l=0;
	r=100000;
	while (l<r){
		int mid=l+r+1;
		mid/=2;
		if (subt[mid]<=C)
			l=mid;
		else
			r=mid-1;
	}
	long long res=C*l-subt_sum[l];
	return res;
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	subt[1]=0;
	for (int i=1;i<=100000;i++){
		subt[i+1]=subt[i]+i;
	}

	for (int i=1;i<=100000;i++){
		subt_sum[i]=subt_sum[i-1]+subt[i];
	}

	cin>>n>>m;
	for (int i=1;i<=m;i++){
//		cin>>a[i]>>b[i]>>cost[i];
		scanf("%d",&a[i]);
		scanf("%d",&b[i]);
		scanf("%d",&cost[i]);
		g[a[i]].push_back(i);
		gr[b[i]].push_back(i);
	}

	for (int i=1;i<=n;i++){
		if (used[i])
			continue;
		dfs(i);
	}

	reverse(order.begin(),order.end());
	for (int i=1;i<=n;i++){
		used[i]=0;
	}

	for (int i=0;i<order.size();i++){
		int v=order[i];
		if (used[v])
			continue;
		++C;
		rdfs(v);
	}

	for(int i=1;i<=m;i++){
		int c1=used[a[i]];
		int c2=used[b[i]];
		//cout<<c1<<"$"<<c2<<endl;
		if (c1==c2){
			COST[c1]+=get_edge_cost(cost[i]);
		}
		else{
			G[c1].push_back(make_pair(c2,cost[i]));
		}
	}

	for (int i=C;i;--i){
		for (int j=0;j<G[i].size();j++){
			int to=G[i][j].first;
			long long res_there=dp[to]+G[i][j].second;
			dp[i]=max(dp[i],res_there);
		}
		dp[i]+=COST[i];
	}
	int start;
	cin>>start;
	start=used[start];
	cout<<dp[start]<<endl;

//	cin.get(); cin.get();
	return 0;
}