/*
Legs are tied, these hands are broken
Alone I try with words unspoken
Silent cry, a breath is frozen
With blinded eyes, I fear myself

It's burning down, it's burning high
When ashes fall, the legends rise
We burn it out a mile wide
When ashes fall, the legends rise

Throat is dry, my vision's fading
I'm paralyzed and left here waiting
Taking time, just one step forward
Won't lose my mind, I'm here to stay

It's burning down, it's burning high
When ashes fall, the legends rise
We burn it out a mile wide
When ashes fall, the legends rise

Whoa (Legends rise)
Whoa (Legends rise)

(Legends rise)

(You gonna do something about it or just stand there and bleed?)

(Legends rise)

It's burning down, it's burning high
When ashes fall, the legends rise
We burn it out a mile wide
When ashes fall, the legends rise

Whoa (Legends rise)
Whoa (Legends rise)
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

#define eps 1e-12
#define M_PI 3.141592653589793
#define bsize 300

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 1110031;

int t[N*4];

set<int> S;
set<int>::iterator it;

vector<pair<int,int> > order;

int n,k;

int toadd[N*4];

int ar[N];

int le[N];

void push(int v,int tl,int tr){
	t[v*2]+=toadd[v];
	toadd[v*2]+=toadd[v];
	toadd[v*2+1]+=toadd[v];
	t[v*2+1]+=toadd[v];
	toadd[v]=0;
}

void add(int v,int tl,int tr,int l,int r,int val){
	if (l>r)
		return;
	if (tl==l&&tr==r){
		t[v]+=val;
		toadd[v]+=val;
		return;
	}
	push(v,tl,tr);
	int tm=tl+tr;
	tm/=2;
	add(v*2,tl,tm,l,min(r,tm),val);
	add(v*2+1,tm+1,tr,max(tm+1,l),r,val);
	t[v]=max(t[v*2],t[v*2+1]);
}

int get(int v,int tl,int tr, int l,int r){
	if (l>r)
		return 0;
	if (tl==l&&tr==r)
		return t[v];
	push(v,tl,tr);
	int tm=tl+tr;
	tm/=2;
	return max(get(v*2,tl,tm,l,min(r,tm)),get(v*2+1,tm+1,tr,max(tm+1,l),r));
}

int ans[N];

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);

	cin>>n>>k;
	for (int i=1;i<=n;i++){
		scanf("%d",&ar[i]);
		order.push_back(make_pair(ar[i],-i));
	}

	sort(order.begin(),order.end());
	reverse(order.begin(),order.end());

	S.insert(n+1);
	S.insert(0);

	for (int i=0;i<order.size();i++){
		int id=-order[i].second;
		it=S.lower_bound(id);
		--it;
		le[id]=(*it);
		S.insert(id);
	}

	for (int i=1;i<=n;i++){
		int p=le[i];
		add(1,1,n,p+1,i,1);
		if (i>=k){
			ans[i-k+1]=get(1,1,n,i-k+1,i);
		}
	}

	for (int i=1;i<=n-k+1;i++){
		if (i>1)
			printf(" ");
		printf("%d",ans[i]);
	}

	cout<<endl;

//    cin.get(); cin.get();
    return 0;
}