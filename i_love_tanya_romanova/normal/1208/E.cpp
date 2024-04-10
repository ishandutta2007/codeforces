/*
I used the deadwood to make the fire rise
The blood of innocence burning in the skies
I filled my cup with the rising of the sea
And poured it out in an ocean of debris

I'm swimming in the smoke
Of bridges I have burned
So don't apologize
I'm losing what I don't deserve
What I don't deserve

We held our breath when the clouds began to form
But you were lost in the beating of the storm
And in the end we were made to be apart
Like separate chambers of the human heart

I'm swimming in the smoke
Of bridges I have burned
So don't apologize
I'm losing what I don't deserve

It's in the blackened bones
Of bridges I have burned
So don't apologize
I'm losing what I don't deserve
What I don't deserve

I'm swimming in the smoke
Of bridges I have burned
So don't apologize
I'm losing what I don't deserve

The blame is mine alone
For bridges I have burned
So don't apologize
I'm losing what I don't deserve

What I don't deserve
What I don't deserve
What I don't deserve

I used the deadwood to make the fire rise
The blood of innocence burning in the skies
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

const int N = 1100031;

int n,W;
int SZ;
int ar[N];
int t[N*4];
long long add_suf[N];

void build(int v,int tl,int tr){
	if (tl==tr){
		t[v]=ar[tl];
		return;
	}
	int tm=tl+tr;
	tm/=2;
	build(v*2,tl,tm);
	build(v*2+1,tm+1,tr);
	t[v]=max(t[v*2],t[v*2+1]);
}

long long ans[N];
int flag[N];

int get(int v,int tl,int tr,int l,int r){
	if (l>r)
		return -2e9;
	if (tl==l&&tr==r)
		return t[v];
	int tm=tl+tr;
	tm/=2;
	return max(get(v*2,tl,tm,l,min(r,tm)),get(v*2+1,tm+1,tr,max(tm+1,l),r));
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
 //   cin.tie(0);

    cin>>n;
    cin>>W;

    for (int iter=1;iter<=n;iter++){
    	cin>>SZ;
    	for (int j=1;j<=SZ;j++){
    		cin>>ar[j];
    	}
    	build(1,1,SZ);
    	int mx=0;
    	for (int j=1;j<=SZ;j++){
    		mx=max(mx,ar[j]);
    	}
    	int l=SZ+1;
    	int r=W-SZ;
    	if (l<=r){
    		add_suf[l]+=mx;
    		add_suf[r+1]-=mx;
    	}

    	for (int i=1;i<=SZ;i++){
    		flag[i]=iter;
    		int le,ri;
    		// todo
    		int start;
    		start=W-SZ;
    		le=i-start;
    		ri=i;
    		int best_can=-2e9;
    		if (le<1||ri>SZ)
    			best_can=0;
    		le=max(le,1);
    		ri=min(ri,SZ);
    		//cout<<i<<" "<<le<<" "<<ri<<" "<<SZ<<endl;
    		int here=get(1,1,SZ,le,ri);
    		here=max(here,best_can);
    		ans[i]+=here;
    	}

    	for (int i=W-SZ+1;i<=W;i++){
    		if (flag[i]==iter)
    			continue;
    		flag[i]=iter;
    		int le,ri;
			// todo
			int start;
			start=W-SZ;
			le=i-start;
			ri=i;
			int best_can=-2e9;
			if (le<1||ri>SZ)
				best_can=0;
			le=max(le,1);
			ri=min(ri,SZ);
			int here=get(1,1,SZ,le,ri);
    		here=max(here,best_can);
			ans[i]+=here;
    	}
    }

    long long aggregated;

    aggregated=0;
    for (int i=1;i<=W;i++){
    	aggregated+=add_suf[i];
    	ans[i]+=aggregated;
    }

    for (int i=1;i<=W;i++){
    	if (i>1)
    		cout<<" ";
    	cout<<ans[i];
    }
    cout<<endl;

//    cin.get(); cin.get();
    return 0;
}