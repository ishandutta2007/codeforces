/*
All the shades of gray that loom inside me
No one's ever home and there's no one around me
Such a perfect waste this soul behind me
No one really knows what truly drives me
 
I know what I've done wrong
I knew it all along
I can't let it go, let it go, let it go
 
Run away, run away
Look away, look away
I see it inside you
I'm stuck in my ways, stuck in my ways
Run away, run away
Get away, get away
Leave me behind you
I'm stuck in my ways, stuck in my ways
 
All the shades of red that have designed me
All the hell I've seen, it still confines me
All the pain I've felt, it's still inside me
All the rage I have, it still completes me
 
I know what I've done wrong
I knew it all along
I can't let it go, let it go, let it go
Let it go
 
Run away, run away
Look away, look away
I see it inside you
I'm stuck in my ways, stuck in my ways
Run away, run away
Get away, get away
Leave me behind you
I'm stuck in my ways, stuck in my ways
Stuck in my ways, stuck in my ways
 
Just run away, run away
Look away, look away
I see it inside you
I'm stuck in my ways, stuck in my ways
Run away, run away
Get away, get away
Leave me behind you
I'm stuck in my ways, stuck in my ways
Stuck in my ways, stuck in my ways
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
 
const int MAGIC = 400;
 
int n,m;
vector<int> g[N];
int deg[N];
int L[N],R[N];
long long ans;
 
int ar[N];
int ps[N];
int tests;
 
bool adj(int a,int b){
	int ps=lower_bound(g[b].begin(),g[b].end(),a)-g[b].begin();
	if (ps<g[b].size()&&g[b][ps]==a)
		return true;
	else
		return false;
}
 
void update(int v){
	ans-=1ll*L[v]*R[v];
	L[v]--;
	R[v]++;
	ans+=1ll*L[v]*R[v];
}
 
int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
 //   cin.tie(0);
 
    cin>>n>>m;
    for (int i=1;i<=m;i++){
    	int a,b;
    	cin>>a>>b;
    	g[a].push_back(b);
    	g[b].push_back(a);
    	deg[a]++;
    	deg[b]++;
    }
 
    for (int i=1;i<=n;i++){
    	ar[i]=i;
    }
    for (int i=1;i<=n;i++){
    	sort(g[i].begin(),g[i].end());
    }
 
    for (int i=1;i<=n;i++){
    	ps[i]=i;
    }
 
    for (int i=1;i<=n;i++){
    	for (int j=0;j<g[i].size();j++){
    		int to=g[i][j];
    		if (to<i)
    			L[i]++;
    		else
    			R[i]++;
    	}
    }
 
    ans=0;
    for (int i=1;i<=n;i++){
    	ans+=1ll*L[i]*R[i];
    }
 
    cout<<ans<<endl;
 
    cin>>tests;
    for (int test=1;test<=tests;test++){
    	int id;
    	cin>>id;
    	int old_ps=ps[id];
    	int new_ps=n+test;
    	ar[new_ps]=id;
    	ar[old_ps]=0;
    	ps[id]=new_ps;
 
    	ans-=1ll*L[id]*R[id];
    	L[id]=g[id].size();
    	R[id]=0;
 
    	if (g[id].size()<=MAGIC){
    		for (int i=0;i<g[id].size();i++){
    			int to=g[id][i];
    			if (ps[to]>old_ps&&ps[to]<new_ps){
    				update(to);
    			}
    		}
    	}
    	else
    	{
    		for (int i=old_ps+1;i<new_ps;i++){
    			int val=ar[i];
    			if (val==0)
    				continue;
    			if (adj(id,val)){
    				update(val);
    			}
    		}
    	}
    	cout<<ans<<endl;
    }
 
//    cin.get(); cin.get();
    return 0;
}