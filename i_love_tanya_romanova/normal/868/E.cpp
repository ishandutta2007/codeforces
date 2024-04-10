/*
Leaving with twilight though I was chosen
To wander the way in the darkest of nights
Oh in the summer sun how soon i came to stray
A true damnation when I turned away

So fell autumn rain washed away ali my pain
I feel brighter somehow lighter somehow to breath once
again
So fell autumn rain washed my sorrows away
With the sunset behind somehow I find the dreams are
to stay

So fell autumn rain

Blinded by dawning so you would take me
Futher away away from the fall
Oh you told me I must never dream again
A true damnation you left me the pain

So fell autumn rain but all things must pass

So fell autumn rain washed away all my pain
I feel bnghter somehow lighter somehow to breath once
again
So tell autumn rain washed my sorrows away
With the sunset behind somehow I f nd the dreams are
to stay

So fell winter
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

const int N = 300031;

int n;
vector<pair<int,int> > g[N];
vector<pair<int,int> > leaves;

int police_start,m;
int starts_at[N];

long long dp[100][100],global_dp[100][100];

int D[N],used[N];
int C;

void dfs(int v,int d){
	used[v]=1;
	D[v]=d;
	if (g[v].size()==1&&d>0)
		leaves.push_back(make_pair(v,d));

	C+=starts_at[v];

	for (int i=0;i<g[v].size();i++){
		int to=g[v][i].first;
		if (used[to])
			continue;
		int dist=g[v][i].second+d;
		dfs(to,dist);
	}
}

void retrace(int root){
	for (int i=0;i<=n;i++)
	{
		used[i]=0;
		D[i]=0;
	}
	leaves.clear();
	dfs(root,0);
}

void run_solver(int folks,int root){

	retrace(root);
	for (int i=0;i<=leaves.size();i++){
		for (int j=0;j<=folks;j++){
			dp[i][j]=0;
		}
	}
	dp[0][0]=1e18;
	for (int i=0;i<leaves.size();i++){
		for (int j=0;j<=folks;j++)
		{
			// no folks here
			dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
			//put somebody
			for (int q=1;q+j<=folks;q++){
				long long time_this=global_dp[folks-q][leaves[i].first]+leaves[i].second;
				time_this=min(time_this,dp[i][j]);
				dp[i+1][j+q]=max(dp[i+1][j+q],time_this);
			}
		}
	}

	global_dp[folks][root]=dp[leaves.size()][folks];
}

long long ans;

void run_solver2(int folks,int root){

	for (int i=0;i<=leaves.size();i++){
		for (int j=0;j<=folks;j++){
			dp[i][j]=0;
		}
	}
	dp[0][0]=1e18;
	for (int i=0;i<leaves.size();i++){
		for (int j=0;j<=folks;j++)
		{
			// no folks here
			dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
			//put somebody
			for (int q=1;q+j<=folks;q++){
				long long time_this=global_dp[m-q][leaves[i].first]+leaves[i].second;
				time_this=min(time_this,dp[i][j]);
				dp[i+1][j+q]=max(dp[i+1][j+q],time_this);
			}
		}
	}

	ans=min(ans,dp[leaves.size()][folks]);
}

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;

	if (n==1){
		cout<<0<<endl;
		return 0;
	}

	for (int i=1;i<n;i++){
		int a,b,c;
		cin>>a>>b>>c;
		g[a].push_back(make_pair(b,c));
		g[b].push_back(make_pair(a,c));
	}

	cin>>police_start;
	cin>>m;
	for (int i=1;i<=m;i++){
		int v;
		cin>>v;
		starts_at[v]++;
	}

	m-=starts_at[police_start];

	if (m==0){
		cout<<0<<endl;
		return 0;
	}

	for (int remaining_guys=1;remaining_guys<=m;remaining_guys++){
		for (int root=1;root<=n;root++){
			if (g[root].size()==1)
				run_solver(remaining_guys,root);
		}
	}

	for(int i=1;i<=n;i++){
		used[i]=0;
		D[i]=0;
	}
	used[police_start]=1;

	ans=1e18;

	for (int i=0;i<g[police_start].size();i++){
		leaves.clear();
		C=0;
		int to=g[police_start][i].first;
		int cost=g[police_start][i].second;
		dfs(to,cost);
		run_solver2(C,police_start);
	}

	cout<<ans<<endl;

	cin.get(); cin.get();
	return 0;
}