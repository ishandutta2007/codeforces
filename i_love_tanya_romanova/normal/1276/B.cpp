/*
Set in overdrive, makin' money on the side.
Lookin' for some dirty action.
Leave 'em on the floor,
Leave 'em wantin' more.
Use it for the prime reaction.

Workin' like a dog,
Tired cold, and bored.
Stimulate me to satisfaction.
Alcohol and sluts,
Pull me from my rut,
Second only to the attraction.

YOU! Got a lot to learn.
Your head's up your ass!
YOU! Got a lot to learn.
You got no class.

No class.

Take me to the top, never never stop.
So pretty what's your name, where ya from.
I see you like the band,
Don't leave me with my hand,
Stick around I'll throw you a bone.

No class.

Crack another beer, sit on over here.
What I need I can't do alone.
Think that I'm in love, sittin' in your glove,
What's your name, here I come out, I'm done.

Why don't you use your head.
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
#define left asdgashgrketwjklrej
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

int tests,n,m,a,b;
vector<int> g[N];
int used[N],lab1[N],lab2[N];

int C;
void dfs(int v){
	used[v]=C;
	for (int i=0;i<g[v].size();i++){
		int to=g[v][i];
		if (used[to])
			continue;
		dfs(to);
	}
}

void trace_it(int root){
	for (int i=1;i<=n;i++){
		used[i]=0;
	}
	used[root]=1;
	C=1;
	for (int i=1;i<=n;i++){
		if (used[i])
			continue;
		++C;
		dfs(i);
	}

}

map<int,int> map1,map2;
map<pair<int,int>,int> map12;

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
 //   cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n>>m>>a>>b;
    	for (int i=1;i<=n;i++){
    		g[i].clear();
    	}
    	for (int i=1;i<=m;i++){
    		int a,b;
    		cin>>a>>b;
    		g[a].push_back(b);
    		g[b].push_back(a);
    	}

    	trace_it(a);
    	for (int i=1;i<=n;i++){
    		lab1[i]=used[i];
    	}
    	trace_it(b);
    	for (int i=1;i<=n;i++){
    		lab2[i]=used[i];
    	}

    	map1.clear();
    	map2.clear();
    	map12.clear();
    	for (int i=1;i<=n;i++){
    		if (i==a||i==b)
    			continue;
    		map1[lab1[i]]++;
    		map2[lab2[i]]++;
    		map12[make_pair(lab1[i],lab2[i])]++;
    	}

    	long long all_pairs=1ll*(n-2)*(n-3);

    	for (int i=1;i<=n;i++){
    		if (i==a||i==b)
    			continue;
    		all_pairs-=map1[lab1[i]]-1;
    		all_pairs-=map2[lab2[i]]-1;
//    		cout<<i<<" "<<lab1[i]<<" "<<lab2[i]<<" "<<map1[lab1[i]]<<" "<<map2[lab2[i]]<<endl;

    		all_pairs+=map12[make_pair(lab1[i],lab2[i])]-1;
    	}

    	/*for (int i=1;i<=n;i++){
    		cout<<lab1[i]<<"@@"<<lab2[i]<<endl;
    	}*/

    	cout<<all_pairs/2<<endl;

    }

    //    cin.get(); cin.get();
    return 0;
}