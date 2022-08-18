/*
Man and machine and nothing there in between
A flying circus and a man from Prussia
The sky and a plane, this man commands his domain
The western front and all the way to Russia

Death from above, you're under fire
Stained red as blood, he's roaming higher

Born a soldier from the horseback to the skies
That's where the legend will arise

And he's flying

Higher, the king of the sky
He's flying too fast and he's flying too high
Higher, an eye for an eye
The legend will never die

First to the scene he is a lethal machine
It's bloody April and the tide is turning
Fire at will it is the thrill of the kill
Four in a day shot down with engines burning

Embrace the fame, red squadron leader
Call out his name, Rote Kampfflieger

In the game to win, a gambler rolls the dice
Eighty allies paid the price

And he's flying

Higher, the king of the sky
He's flying too fast and he's flying to high
Higher, an eye for an eye
The legend will never die

Higher
Higher, the king of the sky
He's flying too fast and he's flying too high
He's flying higher, an eye for an eye
The legend will never die

Higher

Born a soldier from the horseback to the skies
And the legend never dies

And he's flying
And he's flying
And he's flying

Higher, the king of the sky
He's flying too fast and he's flying too high
Higher, an eye for an eye
The legend will never die

Higher, the king of the sky
He's flying too fast and he's flying too high
Higher, an eye for an eye
The legend will never die
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

const int N = 200031;

int n,m;
int w[N];
long long total_w;
vector<int> g[N];
long long cost_blocked;
long long best_tail;

long long best_subtree[N];
long long can_escape[N];
long long used[N];

void dfs(int v,int par){
	used[v]=1;
	best_subtree[v]=w[v];
	for (int i=0;i<g[v].size();i++){
		int to=g[v][i];
		if (to==par)
			continue;
		if (used[to])
			can_escape[v]=1;
		else
		{
			dfs(to,v);
			if (can_escape[to])
				can_escape[v]=1;
			best_subtree[v]=max(best_subtree[v],w[v]+best_subtree[to]);
		}
	}
	if (can_escape[v]==0)
		cost_blocked+=w[v],
		best_tail=max(best_tail,best_subtree[v]);
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
 //   cin.tie(0);

    cin>>n>>m;
    for (int i=1;i<=n;i++){
    	cin>>w[i];
    	total_w+=w[i];
    }

    for (int i=1;i<=m;i++){
    	int a,b;
    	cin>>a>>b;
    	g[a].push_back(b);
    	g[b].push_back(a);
    }

    int start;
    cin>>start;

    dfs(start,start);

    cout<<total_w-cost_blocked+best_tail<<endl;

//    cin.get(); cin.get();
    return 0;
}