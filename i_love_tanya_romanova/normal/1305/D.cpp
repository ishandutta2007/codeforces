/*
You ripped my heart out and you threw it away
Torn away - threw away - ripped away
Been pushing buttons since the day that we met
All the pain - it's a shame - you're insane

Infectious
I bleed you out
So precious
You're empty

You're always saving face and hiding behind love
There's nothing left to save - just look what we've become
Scar tissue

You run in circles and you plant fuckin' lies
Escalate all the hate you create
There's just no end and you're so quick to defend
Fabricate medicate isolate

Infectious
I bleed you out
So precious
You're empty

You're always saving face and hiding behind love
There's nothing left to save - just look what we've become
Scar tissue

You're always saving face and hiding behind love
There's nothing left to save - just look what we've become
Scar tissue
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

int n;
vector<int> g[N];
int deg[N];
vector<int> leaves;
int is_leaf[N];

void kill_it (int v){
	for (int i=0;i<g[v].size();i++){
		int to=g[v][i];
		if (is_leaf[to])
			continue;
		deg[to]--;
		if (deg[to]<=1){
			leaves.push_back(to);
			is_leaf[to]=1;
		}
	}
}

void respond(int val){
	cout<<"! "<<val<<endl;
}

int query(int a,int b){
	cout<<"? "<<a<<" "<<b<<endl;
	int val;
	cin>>val;
	return val;
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
//    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>n;
    for (int i=1;i<n;i++){
    	int a,b;
    	cin>>a>>b;
    	g[a].push_back(b);
    	g[b].push_back(a);
    	deg[a]++;
    	deg[b]++;
    }

    for (int i=1;i<=n;i++){
    	if (deg[i]<=1){
    		leaves.push_back(i);
    		is_leaf[i]=1;
    	}
    }

    while (true){

    	if (leaves.size()==1){
    		respond(leaves[0]);
    		break;
    	}

    	int a=leaves.back();
    	leaves.pop_back();
    	int b=leaves.back();
    	leaves.pop_back();
    	int here=query(a,b);
    	if (here==a||here==b){
    		respond(here);
    		break;
    	}
    	kill_it(a);
    	kill_it(b);
    }


    //    cin.get(); cin.get();
    return 0;
}