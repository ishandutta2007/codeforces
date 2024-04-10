/*
I can't do what you do
I'm just able to tear it down yeah
Stay in a cold minute of sleep
See the world
Right through the ether

Twisting names inside of me
Electric atmosphere to be
Must carry on one last time
Cannot end what has begun

In your eyes
You're alive
But in my eyes
You're a lie

You can't do what I do
I'm just able to ruin you yeah
Stay in the cold ways of winter
See myself right through the ether

In my eyes
You're the lie
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

int tests,n,ar[N];
vector<int> entries[N];
int t[N*4];
int ans[N];
int answ;
set<int> zeroes;
set<int>::iterator it;

void build(int v,int tl,int tr){
	t[v]=0;
	if (tl==tr)
		return;
	int tm=tl+tr;
	tm/=2;
	build(v*2,tl,tm);
	build(v*2+1,tm+1,tr);
}

int get(int v,int tl,int tr,int l,int r){
	if (l>r)
		return 0;
	if (tl==l&&tr==r)
		return t[v];
	int tm=tl+tr;
	tm/=2;
	return max(get(v*2,tl,tm,l,min(r,tm)),get(v*2+1,tm+1,tr,max(tm+1,l),r));
}

void update(int v,int tl,int tr,int ps,int val){
	if (tl==tr){
		t[v]=val;
		return ;
	}
	int tm=tl+tr;
	tm/=2;
	if (ps<=tm)
		update(v*2,tl,tm,ps,val);
	else
		update(v*2+1,tm+1,tr,ps,val);
	t[v]=max(t[v*2],t[v*2+1]);
}

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n;
    	build(1,1,n);

    	zeroes.clear();

    	for (int i=1;i<=n;i++){
    		entries[i].clear();
    		ans[i]=0;
    		zeroes.insert(i);
    	}

    	for (int i=1;i<=n;i++){
    		cin>>ar[i];
    		entries[ar[i]].push_back(i);
    	}

    	for (int i=1;i<=n;i++){
    		for (int j=0;j<entries[i].size();j++){
    			int ps=entries[i][j];
    			// first case: insert one element in between; must be larger than we are
    			it=zeroes.lower_bound(ps);
    			if (it!=zeroes.begin()){
    				--it;
    				int B=(*it);
        			int Q=get(1,1,n,1,B);
        			ans[ps]=max(ans[ps],Q+2);
        		//	cout<<"!"<<B<<" "<<ps<<endl;
    			}
    			// second case: don't insert anything.
    			ans[ps]=max(ans[ps],get(1,1,n,1,ps-1)+1);
        		//if (ps==1)
        		//	ans[ps]=1;
        		update(1,1,n,ps,ans[ps]);
        		zeroes.erase(ps);
        		//cout<<ps<<"@@@"<<ans[ps]<<" "<<endl;
    		}
    	}

    	answ=0;
    	int cur_max=0;
    	for (int i=n;i>=1;--i){
    		answ=max(answ,ans[i]);
    		if (ar[i]<=cur_max)
    			answ=max(answ,ans[i]+1);
    		cur_max=max(cur_max,ar[i]);
    	}

    	cout<<answ<<endl;
    }

    //cin.get(); cin.get();
    return 0;
}