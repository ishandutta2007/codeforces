/*
Where should I start
Disjointed heart
I've got no commitment
To my own flesh and blood
Left all alone
Far from my home
No one to hear me, to heal my ill heart, I

Keep it locked up inside

Cannot express
To the point I've regressed
If anger's a gift, then I guess I've been blessed, I

Keep it locked up inside
Keep my distance from your lies

It's too late to love me now
You have never shown me
It's too late to love me now
You don't even know me

Breaking a part of my heart to find release
Taking you out of my blood to bring me peace
Breaking a part of my heart to find release
Taking you out of my blood to bring me peace

Breaking a part of my heart to find release (Break)
Taking you out of my blood to bring me peace (Me)
Breaking a part of my heart to find release (Too)
Taking you out of my blood to bring me peace

Keep it locked up inside
Keep my distance from your lies

Breaking a part of my heart to find release (Break)
Taking you out of my blood to bring me peace (Me)
Breaking a part of my heart to find release (Too)
Taking you out of my blood to bring me peace
Breaking a part of my heart to find release
Taking you out of my blood to bring me peace
Breaking a part of my heart to find release
Taking you out of my blood to bring me peace

Keep my distance
Keep my distance
Keep my distance
Keep my distance

Spit drips from the jaw of the witless witness
Cryptic colloquialisms shift your mid rift
Dog-paddle through a bog of shadows and smog
With my thought catalog, analog, rap battle log
Keep my distance, and fear resistance, hurt by persistence
The twisted web of tangled lies strangles my hope to waste and numbs the taste
And I'm forced to face these hate crimes against the state of being, feeling the weightlessness, press me to the ceiling, reeling around rooms, riding a bubble of sound
Tuned to the frequency making your chest shake with every boom, involuntary muscle contraction
Ignoring your neck's breaking, musical gas fume euphoria
The sound pounds to make the dead flush
To hand you a head rush with read rhymes and said stuff
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

int n;
long long t[N*4],toadd[N*4];
long long ar[N];

void push(int v,int l,int r){
	t[v*2]+=toadd[v];
	toadd[v*2]+=toadd[v];
	t[v*2+1]+=toadd[v];
	toadd[v*2+1]+=toadd[v];
	toadd[v]=0;
}

void build(int v,int tl,int tr){
	if (tl==tr){
		t[v]=ar[tl];
		return;
	}
	int tm=tl+tr;
	tm/=2;
	build(v*2,tl,tm);
	build(v*2+1,tm+1,tr);
	t[v]=min(t[v*2],t[v*2+1]);
}

int solve(int v,int tl,int tr){
	if (tl==tr){
		return tl;
	}
	push(v,tl,tr);
	int tm=tl+tr;
	tm/=2;
	if (t[v*2+1]!=0)
		return solve(v*2,tl,tm);
	else
		return solve(v*2+1,tm+1,tr);
}

int ans[N];

void add(int v,int tl,int tr,int l,int r,long long val){
	if (l>r)
		return;
	if (tl==l&&tr==r){
		t[v]+=val;
		toadd[v]+=val;
		return ;
	}
	push(v,tl,tr);
	int tm=tl+tr;
	tm/=2;
	add(v*2,tl,tm,l,min(r,tm),val);
	add(v*2+1,tm+1,tr,max(tm+1,l),r,val);
	t[v]=min(t[v*2],t[v*2+1]);
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
 //   cin.tie(0);

    cin>>n;

    for (int i=1;i<=n;i++){
    	cin>>ar[i];
    }

    build(1,1,n);

    for (int i=1;i<=n;i++){
    	int X=solve(1,1,n);
    	ans[X]=i;
    	add(1,1,n,X+1,n,-i);
    	add(1,1,n,X,X,1000000000000ll);
    }

    for (int i=1;i<=n;i++){
    	if (i>1)
    		cout<<" ";
    	cout<<ans[i];
    }
    cout<<endl;

//    cin.get(); cin.get();
    return 0;
}