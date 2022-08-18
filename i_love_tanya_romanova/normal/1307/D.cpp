/*
All wound up
On the edge
Terrified

Sleep disturbed
Restless mind
Petrified

Bouts of fear
Permeate
All I see

Heightening
Nervousness
Threatens me

I am paralyzed
So afraid to die

Caught off guard
Warning signs
Never show

Tension strikes
Choking me
Worries grow

Why do I feel so numb
Is it something to do with where I come from
Should this be fight or flight
I don't know why I'm constantly so uptight

Rapid heartbeat pounding through my chest
Agitated body in distress
I feel like I'm in danger
Daily life is strangled by my stress

A stifling surge
Shooting through all my veins
Extreme apprehension
Suddenly I'm insane

Lost all hope for redemption
A grave situation desperate at best

Why do I feel so numb
Is it something to do with where I come from
Should this be fight or flight
I don't know why I'm constantly reeling

Helpless hysteria
A false sense of urgency
Trapped in my phobia
Possessed by anxiety

Run
Try to hide
Overwhelmed by this complex delirium

Helpless hysteria
A false sense of urgency
Trapped in my phobia
Possessed by anxiety

Run
Try to hide
Overwhelmed by this complex delirium
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

const int N = 200031;

int n,k,m;
vector<int> special;
int is_special[N];
int used[N];
int ANS;
int memo_1[N],memo_n[N];
vector<int> g[N];
queue<int> qu;

void trace(int v){
	for (int i=1;i<=n;i++){
		used[i]=0;
	}
	used[v]=1;
	qu.push(v);
	while (qu.size()){
		int v=qu.front();
		qu.pop();
		for (int i=0;i<g[v].size();i++){
			int to=g[v][i];
			if (used[to])
				continue;
			qu.push(to);
			used[to]=used[v]+1;
		}
	}
}

vector<pair<int,int> > order;

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>n>>m>>k;
    for (int i=1;i<=k;i++){
    	int id;
    	cin>>id;
    	special.push_back(id);
    	is_special[id]=1;
    }

    for (int i=1;i<=m;i++){
    	int a,b;
    	cin>>a>>b;
    	g[a].push_back(b);
    	g[b].push_back(a);
    }

    trace(1);

    ANS=used[n]-1;

    for (int i=1;i<=n;i++){
    	memo_1[i]=used[i]-1;
    }

    trace(n);

    for (int i=1;i<=n;i++){
    	memo_n[i]=used[i]-1;
    }

    int new_ans=-1;

    for (int i=1;i<=n;i++){
    	if (is_special[i]==0)
    		continue;
    	order.push_back(make_pair(memo_n[i]-memo_1[i],i));
    }

    sort(order.begin(),order.end());

    int cur_max=-1e9;
    for (int i=0;i<order.size();i++){
    	int id=order[i].second;
    	int ans_here=1+cur_max+memo_1[id];
    	//cout<<cur_min<<" "<<id<<" "<<"@"<<ans_here<<endl;
    	if (i!=0)
    		new_ans=max(new_ans,ans_here);
    	cur_max=max(cur_max,memo_n[id]);
    }

    ANS=min(ANS,new_ans);
    cout<<ANS<<endl;

    //    cin.get(); cin.get();
    return 0;
}