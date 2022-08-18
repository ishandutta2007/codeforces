/*
Politician idiots, cruel warriors
Backstreet suckers
Holy terror, deadly masters
Bring us pain, anger and destruction

What you need is what you get
What you get is what you need
What you do is what you did
What you did is what you do

Can't you see - oh can't you see
The devil plays piano
Marching armies, machine killers
Lying prayers, hell is waiting
Holy terror, deadly masters
Bring us pain, anger and destruction

Politicians idiots, cruel warriors
Backstreet suckers
What you need is what you get
What you get is what you need
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

#define bs 998244353

const int N = 500031;

int n;
long long a[N];
vector<long long> entries[N];
long long b[N];
long long b_suf[N];
long long t[N*4];
long long t2[N*4];

int sz;
long long goal[N];
vector<pair<long long, long long> > V[N];
long long ans;

void build(int v,int tl,int tr){
	t[v]=1e18;
	if (tl==tr){
		return;
	}
	int tm=tl+tr;
	tm/=2;
	build(v*2,tl,tm);
	build(v*2+1,tm+1,tr);
}

void build2(int v,int tl,int tr){
	if (tl==tr){
		t2[v]=b[tl];
		return;
	}
	int tm=tl+tr;
	tm/=2;
	build2(v*2,tl,tm);
	build2(v*2+1,tm+1,tr);
	t2[v]=t2[v*2]+t2[v*2+1];
}

void update(int v,int tl,int tr,int ps,long long val){
	if (tl==tr){
		t[v]=val;
		return;
	}
	int tm=tl+tr;
	tm/=2;
	if (ps<=tm)
		update(v*2,tl,tm,ps,val);
	else
		update(v*2+1,tm+1,tr,ps,val);
	t[v]=min(t[v*2],t[v*2+1]);
}

void add(int v,int tl,int tr,int ps,long long val){
	if (tl==tr){
		t2[v]+=val;
		return;
	}
	int tm=tl+tr;
	tm/=2;
	if (ps<=tm)
		add(v*2,tl,tm,ps,val);
	else
		add(v*2+1,tm+1,tr,ps,val);
	t2[v]=t2[v*2]+t2[v*2+1];
}

long long get(int v,int tl,int tr,int l,int r){
	if (l>r)
		return 1e18;
	if (tl==l&&tr==r)
		return t[v];
	int tm=tl+tr;
	tm/=2;
	return min(get(v*2,tl,tm,l,min(r,tm)),get(v*2+1,tm+1,tr,max(tm+1,l),r));
}

long long get2(int v,int tl,int tr,int l,int r){
	if (tl==l&&tr==r)
		return t2[v];
	if (l>r)
		return 0;
	int tm=tl+tr;
	tm/=2;
	return get2(v*2,tl,tm,l,min(r,tm))+get2(v*2+1,tm+1,tr,max(tm+1,l),r);

}

int main(){
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", sttextdout);
	ios_base::sync_with_stdio(0);
	// cin.tie(0);

	cin>>n;

	for (int i=1;i<=n;i++){
		cin>>a[i];
		entries[a[i]].push_back(i);
	}

	for (int i=1;i<=n;i++){
		cin>>b[i];
	}

	for (int i=n;i;--i){
		b_suf[i]=b_suf[i+1]+b[i];
	}

	build(1,0,n);

	build2(1,0,n);

	update(1,0,n,0,get2(1,0,n,0,n));

	ans=1e18;

	cin>>sz;
	for (int i=1;i<=sz;i++){
		cin>>goal[i];
	}

	for (int i=1;i<=sz;i++){
		for (int j=(int)entries[goal[i]].size()-1;j>=0;--j){
			int ps=entries[goal[i]][j];
			long long bst=get(1,0,n,0,ps);
			bst-=get2(1,0,n,ps,n);
			if (bst>1e17)
				bst=1e18;
		//	cout<<ps<<" "<<bst<<" "<<get2(1,0,n,ps,n)<<endl;
			V[i].push_back(make_pair(ps,bst));
		}
		for (int j=0;j<V[i-1].size();j++){
			int ps=V[i-1][j].first;
			update(1,0,n,ps,1e18);
		}
		if (i==1)
			update(1,0,n,0,1e18);

		for (int V=goal[i-1]+1;V<=goal[i];V++)
		for (int j=0;j<entries[V].size();j++){
			int ps=entries[V][j];
			if (b[ps]>=0)
				add(1,0,n,ps,-b[ps]); // otherwise I'll delete it anyway even though I don't necessarily need to.
		}
		for (int j=0;j<V[i].size();j++){
			int ps=V[i][j].first;
			long long val=V[i][j].second;
			val+=get2(1,0,n,ps+1,n);
			if (val>1e17)
				val=1e18;
			update(1,0,n,ps,val);
		//	cout<<ps<<"@@@"<<val<<endl;
			if (i==sz)
				ans=min(ans,val);
		}
	}

	if (ans>1e17)
		cout<<"NO"<<endl;
	else
	{
		cout<<"YES"<<endl;
		cout<<ans<<endl;
	}

	// cin.get(); cin.get();
	return 0;
}