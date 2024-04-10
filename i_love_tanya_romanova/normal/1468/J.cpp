/*
It is to see a traitor go free
It is to feel a filter in me
It is to leave the lights that I saw
It is to ask: is it easy to go?

In this dead hour
Here with you
Seconds are worthless
In this dead hour
When all is blank
Minutes are worthless

How long will it take until
There will be room enough for hope
It is so sad to see
Dispossession
It has become my obsession

It is to have a knife in my back
It is to say my soul got a crack
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

const int N = 600031;

int tests;
long long n,m,k;
long long ans;
long long w[N];
vector<pair<int,pair<int,int> > > edges;

int get(int x){
	if (x==w[x])
		return x;
	return w[x]=get(w[x]);
}

void merge(int a,int b){
	a=get(a);
	b=get(b);
	w[a]=b;
}

int T;

bool all_connected(){
	for (int i=1;i<=n;i++){
		if (get(i)!=get(1))
			return false;
	}
	return true;
}

long long get_first_edge_above(){
	for (int i=0;i<edges.size();i++){
		if (edges[i].first>k)
			return edges[i].first;
	}
	return 2e9+1e5;
}

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n>>m>>k;
    	for (int i=1;i<=n;i++){
    		w[i]=i;
    	}
    	edges.clear();
    	ans=0;
    	for (int i=1;i<=m;i++){
    		int a,b,c;
    		cin>>a>>b>>c;
    		edges.push_back(make_pair(c,make_pair(a,b)));
    	}
    	T=-1;
    	sort(edges.begin(),edges.end());
    	for (int i=edges.size()-1;i>=0;--i){
    		if (edges[i].first<=k){
    			int v1=edges[i].second.first;
    			int v2=edges[i].second.second;
    			merge(v1,v2);
    			if (T==-1)
    				T=edges[i].first;
    		}
    	}

    	if (all_connected()){
    		long long Q=get_first_edge_above();
    		cout<<min(k-T,Q-k)<<endl;
    	}
    	else
    	{
    		ans=0;
    		for (int i=0;i<edges.size();i++){
    			int v1=edges[i].second.first;
    			int v2=edges[i].second.second;
    			if (get(v1)==get(v2))
    				continue;
    			ans+=edges[i].first-k;
    			merge(v1,v2);
    		}
    		cout<<ans<<endl;
    	}
    }

    //cin.get(); cin.get();
    return 0;
}