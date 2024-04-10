/*
In the nights
We take flights
Witness the sites
The power and glory of steel
I fought and died
Lived many lives before
I am immortal like my sword
I kneel to no one except the lord
And my lord is steel
If you see me you just passed your time
To the hills you can run but not hide
Blood and death are wherever i ride
Armed for battle the lord on my side
Stand and face the lord of steel
The lord of steel
In the eyes of the lord you have sinned
Let your punishment begin
Only by death you atone
You shall not die alone
For the glory of battle
I will fight until i die
Live one day as an eagle
Or a lifetime as a fly
Like a candle burning
The wheels of time are turning
The lord of steel commands you
To die by my hand
Stand and fight the lord of steel
Time to face the lord of steel
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

const int N = 500031;

int n;
int x[N],y[N],c[N];
vector<int> order;

long long pref_sum[N];
int min_order[N],max_order[N];
long long ans;
int ans_left_id,ans_right_id;
int where_max[N];

pair<long long, long long> t[N*4];

bool cmp_min(int a,int b){
	if (min(x[a],y[a])!=min(x[b],y[b]))
		return min(x[a],y[a])<min(x[b],y[b]);
	return a<b;
}

bool cmp_max(int a,int b){
	if (max(x[a],y[a])!=max(x[b],y[b]))
		return max(x[a],y[a])<max(x[b],y[b]);
	return a<b;
}

pair<long long, long long> combine(pair<long long, long long> a,pair<long long, long long> b){
	if (a.first!=b.first)
		return a.first>b.first?a:b;
	return a;
}

long long get_max_value(int id){
	return max(x[id],y[id]);
}

int get_min_value(int id){
	return min(x[id],y[id]);
}


void build(int v,int tl,int tr){
	if (tl==tr){
		long long here=pref_sum[tl]-max(x[order[tl]],y[order[tl]]);
		if (tl!=n-1&&get_max_value(max_order[tl])==get_max_value(max_order[tl+1]))
			here=-1e18;
		t[v]=make_pair(here,0ll+tl);
		return;
	}
	int tm=tl+tr;
	tm/=2;
	build(v*2,tl,tm);
	build(v*2+1,tm+1,tr);
	t[v]=combine(t[v*2],t[v*2+1]);
}

long long toadd[N*4];

void push(int v,int tl,int tr){
	toadd[v*2]+=toadd[v];
	toadd[v*2+1]+=toadd[v];
	t[v*2].first+=toadd[v];
	t[v*2+1].first+=toadd[v];
	toadd[v]=0;
}

void add(int v,int tl,int tr,int l,int r,long long val){
	if (l>r)
		return;
	if (tl==l&&tr==r){
		toadd[v]+=val;
		t[v].first+=val;
		return;
	}
	push(v,tl,tr);
	int tm=tl+tr;
	tm/=2;
	add(v*2,tl,tm,l,min(r,tm),val);
	add(v*2+1,tm+1,tr,max(tm+1,l),r,val);
	t[v]=combine(t[v*2],t[v*2+1]);
}

vector<int> srtd;

pair<long long, long long> get(int v,int tl,int tr,int l,int r){
	if (l>r)
		return make_pair(-1000000000000000ll,-1);
	if (l==tl&&r==tr)
		return t[v];
	push(v,tl,tr);
	int tm=tl+tr;
	tm/=2;
	return combine(get(v*2,tl,tm,l,min(r,tm)),get(v*2+1,tm+1,tr,max(tm+1,l),r));
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
    	cin>>x[i]>>y[i]>>c[i];
    	order.push_back(i);
    }

    ans=-1;


    sort(order.begin(),order.end(),cmp_max);

    for (int i=0;i<order.size();i++){
    	srtd.push_back(get_max_value(order[i]));
    }

    sort(srtd.begin(),srtd.end());

    for (int i=0;i<n;i++){
    	pref_sum[i]=c[order[i]];
    	if (i>0)
    		pref_sum[i]+=pref_sum[i-1];
    }

    for (int i=0;i<n;i++){
    	where_max[order[i]]=i;
    	max_order[i]=order[i];
    }

    build(1,0,n-1);


    sort(order.begin(),order.end(),cmp_min);

    for (int i=0;i<n;i++){
    	min_order[i]=order[i];
    }

    for (int i=0;i<n;i++){

    	long long my_bound=get_min_value(order[i]);
    	int start=lower_bound(srtd.begin(),srtd.end(),my_bound)-srtd.begin();

    	pair<long long, long long> p=get(1,0,n-1,start,n-1);
    	long long here=p.first;
    	here+=min(x[order[i]],y[order[i]]);

    	if (i==0||get_min_value(min_order[i])!=get_min_value(min_order[i-1]))
    	{
    		if (here>ans){
				ans=here;
				ans_right_id=max_order[p.second];
				ans_left_id=min_order[i];
    		}
    	}

    	int toadd=c[min_order[i]];
    	int ps=where_max[min_order[i]];
    	add(1,0,n-1,ps,n-1,-toadd);
    }

    if (ans==-1){
    	cout<<0<<endl;
    	cout<<2000000000<<" "<<2000000000<<" "<<2000000000<<" "<<2000000000<<endl;
    }
    else
    {
		cout<<ans<<endl;
		int mi=min(x[ans_left_id],y[ans_left_id]);
		int ma=max(x[ans_right_id],y[ans_right_id]);
		cout<<mi<<" "<<mi<<" "<<ma<<" "<<ma<<endl;
    }
//    cin.get(); cin.get();
    return 0;
}