/*
Shot!

Revelations - of the minds
Destination - changing all the times
Pave the way - speed of light
Here to stay - can not fear this fight or get it right

Falling away - a generation dies
Rolling into the new signs
Generation day... Shot!

A situation - coming strong
From a nation - spinning worlds along
Don't ya see this new world life?
Can not beat it
Can not tear it down to make it right

Falling away - a generation dies
Rolling into the new signs
Generation day... Shot!

Shot!

Falling away - a generation dies
Rolling into the new signs
Generation day... Shot!
Generation day... Shot!
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
#define prev asdgSHJsfgsdfhdsh
#define hash asdgasdgasdgdfrywewery

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 998244353

const int N = 1100000;

int n,k;
vector<int> g[N];
int deg[N];
int par[N];
int tin[N],tout[N];
int root;

int up[N];
int timer;

vector<int> order,leaves;

int jump[N];
int dp[N];
int shortest[N];
int tail[N];

void merge(int a,int b){ // b to a
	dp[a]+=dp[b];
	if (tail[a]<0&&tail[b]<0)
		return;
	if (tail[a]>=tail[b]+1&&tail[a]+tail[b]+1<=k)
		return;
	if (tail[b]+1+shortest[a]<=k)
		return;

	if (tail[a]<=tail[b]&&tail[a]+tail[b]+1<=k){
		tail[a]=tail[b]+1;
		return;
	}

	if (tail[b]+1>k){
		dp[a]++;
		return;
	}

	if (tail[b]>=tail[a]){
		dp[a]++;
		shortest[a]=min(shortest[a],tail[b]+1);
	}
	else
	{
		dp[a]++;
		shortest[a]=min(shortest[a],tail[a]+1);
		tail[a]=tail[b]+1;
	}
}

void dfs(int v,int par){
	//cout<<v<<"@"<<par<<endl;
	up[v]=par;
	order.push_back(v);
	++timer;
	tin[v]=timer;
	dp[v]=0;
	shortest[v]=1e9;
	tail[v]=-1e9;

	vector<int> sons;

	for (int i=0;i<g[v].size();i++){
		int to=g[v][i];
		if (to==par)
			continue;
		dfs(to,v);
		merge(v,to);
		shortest[v]=min(shortest[v],shortest[to]+1);
	}

	if (g[v].size()==1){
		tail[v]=0;
		return;
	}
}

pair<int,int> ans[N];


int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	scanf("%d",&n);
	scanf("%d",&k);

	for(int i=1;i<n;i++){
		int a,b;
		scanf("%d",&a);
		scanf("%d",&b);
		g[a].push_back(b);
		g[b].push_back(a);
		deg[a]++;
		deg[b]++;
	}

	root=1;
	while (deg[root]==1)
		++root;

	dfs(root,root);
	int ans=dp[root];
	if (tail[root]>0)
		ans++;
	cout<<ans<<endl;

//	cin.get(); cin.get();
	return 0;
}