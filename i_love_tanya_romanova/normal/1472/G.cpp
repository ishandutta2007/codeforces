/*
Tell me which side I'm on
Approaching constant failure
Tell me which side I'm on
(Who's friend or foe?)
Approaching constant failure

Between love and hate
Which path to follow?
How can I keep balance in this race?
Come faith, I'm dying (slowly)

In many ways I'm the burden that devides us from the light
In many ways you're the halo that keeps my spirit alive

Temptation
Play the good or evil part
With me, you evoke the dark
Erase the free will and watch me heal

Tell me which side I'm on
Approaching constant failure

Between love and hate
Which path to follow?
How can I keep balance in this race?
Come faith, I'm dying...

Amused by the trials and tribulations
If I survive I fly from here
But as the chosen pessimist

I carve my name in stone
I carve my name in stone

Amused by the trials and tribulations
If I survive I fly from here

How can I keep balance in this race?
Come faith I'm dying...
*/

#pragma GCC optimize("O3")
#define _CRT_SECURE_NO_WARNINGS
#include <assert.h>
#include <math.h>
#include <memory.h>
#include <stdio.h>

#include <algorithm>
#include <complex>
#include <ctime>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd
#define left asdgashgrketwjklrej
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd
#define prev asdgSHJsfgsdfhdsh
#define hash asdgasdgasdgdfrywewery

#define eps 1e-12
#define M_PI 3.141592653589793
#define bsize 1024

#define ldouble long double
using namespace std;

const int bs = 1000000007;

const long long N = 200031;

int tests,n,m;
vector<int> g[N];
int used[N];
queue<int> qu;
vector<int> order;
int ans[N];

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n>>m;
    	for (int i=1;i<=n;i++){
    		g[i].clear();
    		used[i]=0;
    	}
    	for (int i=1;i<=m;i++){
    		int a,b;
    		cin>>a>>b;
    		g[a].push_back(b);
    	}
    	qu.push(1);
    	used[1]=1;
    	order.clear();
    	while (qu.size()){
    		int v=qu.front();
    		order.push_back(v);
    		qu.pop();
    		for (int i=0;i<g[v].size();i++){
    			int to=g[v][i];
    			if (used[to])
    				continue;
    			used[to]=used[v]+1;
    			qu.push(to);
    		}
    	}

    	reverse(order.begin(),order.end());
    	for (int i=0;i<order.size();i++){
    		int v=order[i];
    		ans[v]=used[v];
    		for (int i=0;i<g[v].size();i++){
    			int to=g[v][i];
    			if (used[to]>used[v]){
    				ans[v]=min(ans[v],ans[to]);
    			}
    			else
    			{
    				ans[v]=min(ans[v],used[to]);
    			}
    		}
    	}

    	for (int i=1;i<=n;i++){
    		if (i>1)
    			cout<<" ";
    		cout<<ans[i]-1;
    	}
    	cout<<endl;
    }

    //cin.get(); cin.get();
    return 0;
}