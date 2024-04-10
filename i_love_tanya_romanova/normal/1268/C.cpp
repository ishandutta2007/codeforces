/*
Hold a halo round the world
Golden is the day
Princess of the Universe
Your burden is the way
So there is no better time
Who will be born today
A gypsy child at day break
A king for a day

Out of the Shadows and into the sun
Dreams of the past as the old ways are done
Oh there is beauty and surely there is pain
But we must endure it to live again

Dusty dreams in fading daylight
Flicker on the walls
Nothing new your life's adrift
What purpose to it all?
Eyes are closed and death is calling
Reaching out its hand
Call upon the starlight to surround you

Out of the Shadows and into the sun
Dreams of the past as the old ways are done
Oh there is beauty and surely there is pain
But we must endure it to live again

Out of the Shadows and into the sun
Dreams of the past as the old ways are done
Oh there is beauty and surely there is pain
But we must endure it to live again

Out of the Shadows and into the sun
Dreams of the past as the old ways are done
Oh there is beauty and surely there is pain
But we must endure it to live again

Out of the Shadows and into the sun
Dreams of the past as the old ways are done
Oh there is beauty and surely there is pain
But we must endure it to live again

A man who casts no shadow has no soul
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

int n,ar[N];
vector<pair<int,int> > order;
long long inv_count[N];
int t[N*4];

pair<long long, long long> tt[N*4];
long long toadd[N*4];
int whr[N];
long long ans[N];

int get_sum(int v,int tl,int tr,int l,int r){
	if (l>r)
		return 0;
	if (tl==l&&tr==r)
		return t[v];
	int tm=tl+tr;
	tm/=2;
	return get_sum(v*2,tl,tm,l,min(r,tm))+get_sum(v*2+1,tm+1,tr,max(tm+1,l),r);
}

void add(int v,int tl,int tr,int ps,int val){
	if (tl==tr){
		t[v]+=val;
		return;
	}
	int tm=tl+tr;
	tm/=2;
	if (ps<=tm)
		add(v*2,tl,tm,ps,val);
	else
		add(v*2+1,tm+1,tr,ps,val);
	t[v]=t[v*2]+t[v*2+1];
}

pair<long long, long long> combine(pair<long long, long long> p1,pair<long long, long long> p2){
	p1.first+=p2.first;
	p1.second+=p2.second;
	return p1;
}

void push(int v){
	tt[v*2].second+=tt[v*2].first*toadd[v];
	tt[v*2+1].second+=tt[v*2+1].first*toadd[v];
	toadd[v*2]+=toadd[v];
	toadd[v*2+1]+=toadd[v];
	toadd[v]=0;
}

pair<long long, long long> get(int v,int tl,int tr,int l,int r){
	if (l>r)
		return make_pair(0ll,0ll);
	if (tl==l&&tr==r)
		return tt[v];
	push(v);
	int tm=tl+tr;
	tm/=2;
	pair<long long, long long> p1=get(v*2,tl,tm,l,min(r,tm));
	pair<long long, long long> p2=get(v*2+1,tm+1,tr,max(tm+1,l),r);
	return combine(p1,p2);
}

pair<long long, long long> get_median(int v,int tl,int tr, int id){
	if (tl==tr){
		return make_pair(tl,tt[v].second);
	}
	push(v);
	int tm=tl+tr;
	tm/=2;
	if (tt[v*2].first>=id)
		return get_median(v*2,tl,tm,id);
	return get_median(v*2+1,tm+1,tr,id-tt[v*2].first);
}

void add(int v,int tl,int tr,int l,int r,int am){
	if (l>r)
		return ;
	if (tl==l&&tr==r){
		tt[v].second+=tt[v].first*am;
		toadd[v]+=am;
		return ;
	}
	push(v);
	int tm=tl+tr;
	tm/=2;
	add(v*2,tl,tm,l,min(r,tm),am);
	add(v*2+1,tm+1,tr,max(tm+1,l),r,am);
	tt[v]=combine(tt[v*2],tt[v*2+1]);
}

void flip_it(int v,int tl,int tr,int ps,int c){
	if (tl==tr){
		tt[v]=make_pair(1,c);
		return ;
	}
	int tm=tl+tr;
	tm/=2;
	push(v);
	if (ps<=tm)
		flip_it(v*2,tl,tm,ps,c);
	else
		flip_it(v*2+1,tm+1,tr,ps,c);
	tt[v]=combine(tt[v*2],tt[v*2+1]);
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
    	order.push_back(make_pair(ar[i],i));
    	whr[ar[i]]=i;
    }

    sort(order.begin(),order.end());
    for (int i=0;i<order.size();i++){
    	int ps=order[i].second;
    	int bad=get_sum(1,1,n,ps+1,n);
    	inv_count[i+1]=inv_count[i]+bad;
    	add(1,1,n,ps,1);
    }

   /* for (int i=1;i<=n;i++){
    	cout<<inv_count[i]<<" ";
    }
    cout<<endl;
*/

    for (int i=1;i<=n;i++){
    	pair<long long, long long> p=get(1,1,n,1,whr[i]-1);
    	int turned_off=whr[i]-1;
    	turned_off-=p.first;
    	flip_it(1,1,n,whr[i],turned_off);
    	add(1,1,n,whr[i]+1,n,-1);
    	pair<long long, long long> median=get_median(1,1,n,(i+1)/2);
    	pair<long long, long long> below=get(1,1,n,1,median.first-1);
    	pair<long long, long long> above=get(1,1,n,median.first+1,n);
    	long long cost_below=(median.second*below.first)-below.second;
    	long long cost_above=above.second-(median.second*above.first);
    	ans[i]=inv_count[i]+cost_above+cost_below;
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