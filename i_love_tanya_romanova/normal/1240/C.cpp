/*
Maybe if you'de listen than you'de know what I just said
If you think the words I'm singing are why your kids are dead
Maybe could it be that no one was there to hear
Did you pay attention to their angers and their fears?
You're trying to find someone to blame who can't be put on trial
The enemy you're looking for is laughing all the while

I mourn for those who have been so deceived
You know the last words that they spoke were "Who loves me?"

People in glass house should not be throwing stones
A sticker on a record won't give your kids a home
So sad it takes someone to die for you to start to care
Your neglect and misguidance have become your nightmare
I hope and pray this tragedy was not all just in vain
Now you can help somebody else avoid the endless pain

I mourn for those who have been so deceived
You know the last words that they spoke were "Who loves me?"
I hope that someday you will stop and realize why do many kids have died

Think twice before you point a finger that you may regret
To clear you conscience is your goal, but that is all you'll get
What's done is done, you can't bring them back, Just let go of despair
You keep saying to yourself "If only I'de been there"

I mourn for those who have been so deceived
You know the last words that they spoke were "Who loves me?"
I hope that someday you will stop and realize
Just why do many kids have died
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

#define eps 1e-9
#define M_PI 3.141592653589793
#define bsize 1024

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 500031;

int tests,n,k;
vector<pair<int,int> > g[N];
int used[N];
long long dp[N][2];

void dfs(int v){
	used[v]=1;
	long long guaranteed=0;
	vector<long long> benefits;

	for (int i=0;i<g[v].size();i++){
		int to=g[v][i].first;
		int cost=g[v][i].second;
		if (used[to]==1)
			continue;
		dfs(to);
		long long without_edge=max(dp[to][0],dp[to][1]);
		long long with_edge=dp[to][0]+cost;
		guaranteed+=without_edge;
		long long benefit_here=with_edge-without_edge;
		if (benefit_here<0)
			benefit_here=0;
		benefits.push_back(benefit_here);
	}
	sort(benefits.begin(),benefits.end());
	reverse(benefits.begin(),benefits.end());
	long long S=0;
	for (int i=0;i<k-1&&i<benefits.size();i++){
		S+=benefits[i];
	}
	dp[v][0]=guaranteed+S;
	S=0;
	for (int i=0;i<k&&i<benefits.size();i++){
		S+=benefits[i];
	}
	dp[v][1]=guaranteed+S;
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
 //   cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n>>k;
    	for (int i=1;i<=n;i++){
    		g[i].clear();
    		used[i]=0;
    	}
    	for (int i=1;i<n;i++){
    		int a,b,c;
    		cin>>a>>b>>c;
    		g[a].push_back(make_pair(b,c));
    		g[b].push_back(make_pair(a,c));
    	}

    	dfs(1);
    	cout<<max(dp[1][0],dp[1][1])<<endl;
    }

//    cin.get(); cin.get();
    return 0;
}