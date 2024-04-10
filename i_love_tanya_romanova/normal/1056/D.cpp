/*
I keep singing the same old song
Like I did before
When you left me
You left me in darkness
I'd never known before
I was restless
A fool for your time
Waiting 'round for you to call
But now I've found me
An angel of mercy
I don't feel bad at all

Your body was honey
I tasted a lot
But let me tell you babe
I need more than you got
I want someone to hold me
An' keep me satisfied
I need love

I've got nothing to do
Ain't got nothing to say
Just live your life
The way you know
When you moved on
You took all the sweetness
Was I a fool to let you go
With the woman I forget for the moment
All the times we knew before
Tho I'm still singing
The same old love song
I don't want you knocking on my door
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

#define bs 1000000007

const int N = 600031;

int n;
vector<int> g[N];
vector<pair<int,int> > order;
int sz[N];

void dfs(int v){
	if (g[v].size()==0){
		sz[v]=1;
	}
	for (int i=0;i<g[v].size();i++){
		int to=g[v][i];
		dfs(to);
		sz[v]+=sz[to];
	}
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;
	for (int i=2;i<=n;i++){
		int v;
		cin>>v;
		g[v].push_back(i);
	}

	dfs(1);

	for (int i=1;i<=n;i++){
		order.push_back(make_pair(sz[i],i));
	}

	sort(order.begin(),order.end());

	for (int i=0;i<order.size();i++){
		if (i)
			cout<<" ";
		cout<<order[i].first;
	}
	cout<<endl;

//	cin.get(); cin.get();
	return 0;
}