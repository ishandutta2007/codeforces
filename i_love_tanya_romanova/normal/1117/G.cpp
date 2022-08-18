/*
It hurts to think
Can't get the sums together
Would you draw my bitterness
Make the pictures fade

Could it be that I see
What's beneath when we fall
The truth in ever
I'm scared that I will be

The sentence is light
But my eyes see a different world
And all I do is turn into flames

Will time open my vault
New solution, I'm begging
Break the fuse that holds me back

The I is lost in me
But I am ready to give you The M,
It might even be the E
As I begin to search for I
The I is lost in me

Distract, push me in another direction
This wall that I stare into
It's getting old
Give me faith to reach for the new
Pull me apart and do me all over
I'll need a re-make
To make up for my mistakes

The I is lost in me
But I am ready to give you The M,
It might even be the E
As I begin to search for I
The I is lost in me

What if I stop to care?
What if I let you fall?

What if I stop to care?
What if I let you fall?

The I is lost in me
But I am ready to give you The M,
It might even be the E
As I begin to search for I
The I is lost in me
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

int n,ar[N];

int solve(int l,int r){
	int ret=0;
	if (l>r)
		return 0;
	int mx=l;
	for (int i=l;i<=r;i++){
		if (ar[i]>ar[mx])
			mx=i;
	}
	return r-l+1+solve(l,mx-1)+solve(mx+1,r);
}

vector<pair<int,int> > order;
set<int> S;
set<int>::iterator it;

int get_nxt(int val){
	it=S.lower_bound(val);
	return (*it);
}

int get_pre(int val){
	it=S.lower_bound(val);
	--(it);
	return (*it);
};

int m;
long long t1[N],t2[N];

vector<pair<int,int> > le_list,ri_list,lq_list,rq_list;//le_list[N],ri_list[N],lq_list[N],rq_list[N];

int lq[N],rq[N];
int le[N],ri[N];

long long ans[N];

long long S_le[N],S_ri[N];

long long prog(long long x){
	return x*(x+1)/2;
}

long long summ(long long l,long long r){
	return prog(r)-prog(l-1);
}

void build(int v,int tl,int tr){
	for (int i=0;i<N;i++){
		t1[i]=t2[i]=0;
	}
	return ;
}

long long get1 (int r)
{
	long long result = 0;
	for (; r >= 0; r = (r & (r+1)) - 1)
		result += t1[r];
	return result;
}

long long get2 (int r)
{
	long long result = 0;
	for (; r >= 0; r = (r & (r+1)) - 1)
		result += t2[r];
	return result;
}

void update1 (int i, int delta)
{
	for (; i < N; i = (i | (i+1)))
		t1[i] += delta;
}

void update2 (int i, int delta)
{
	for (; i < N; i = (i | (i+1)))
		t2[i] += delta;
}

long long get1 (int l, int r)
{
	return get1 (r) - get1 (l-1);
}

long long get2 (int l, int r)
{
	return get2 (r) - get2 (l-1);
}

pair<long long, long long> get(int v,int tl,int tr,int l,int r){
	long long v1=get1(l,r);
	long long v2=get2(l,r);
	return make_pair(v1,v2);
}

void update(int v,int tl,int tr,int ps,int val){
	update1(ps,1);
	update2(ps,val);
}

void cleanup(){
	build(1,0,n+1);
}


int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);

/*    while (true){
    	cin>>n;
    	for (int i=1;i<=n;i++){
    		cin>>ar[i];
    	}
    	cout<<solve(1,n)<<endl;
    }
*/

    cin>>n>>m;
    for (int i=1;i<=n;i++){
//    	cin>>ar[i];
    	scanf("%d",&ar[i]);
    	order.push_back(make_pair(ar[i],i));
    }


    sort(order.begin(),order.end());

    S.insert(0);
    S.insert(n+1);

    reverse(order.begin(),order.end());

    for (int i=0;i<order.size();i++){
    	int id=order[i].second;
    	le[id]=get_pre(id);
    	ri[id]=get_nxt(id);
    	S.insert(id);
    }

    for (int i=1;i<=n;i++){
    	S_le[i]=S_le[i-1]+le[i];
    	S_ri[i]=S_ri[i-1]+ri[i];
    }

    for (int i=1;i<=m;i++){
//    	cin>>lq[i];
    	scanf("%d",&lq[i]);
    }
    for (int i=1;i<=m;i++){
//    	cin>>rq[i];
    	scanf("%d",&rq[i]);
    }

    for (int i=1;i<=m;i++){
    	ans[i]=summ(lq[i],rq[i])-(S_le[rq[i]]-S_le[lq[i]-1]);
    	ans[i]+=(S_ri[rq[i]]-S_ri[lq[i]-1])-summ(lq[i],rq[i]);
    }

    for (int i=1;i<=m;i++){
    	lq_list.push_back(make_pair(lq[i],i));
    	rq_list.push_back(make_pair(rq[i],i));
    }

    for (int i=1;i<=n;i++){
    	le_list.push_back(make_pair(le[i],i));
    	ri_list.push_back(make_pair(ri[i],i));
    }

    cleanup();

    sort(lq_list.begin(),lq_list.end());
    sort(rq_list.begin(),rq_list.end());
    reverse(rq_list.begin(),rq_list.end());

    sort(le_list.begin(),le_list.end());
    sort(ri_list.begin(),ri_list.end());
    reverse(ri_list.begin(),ri_list.end());

    int ptr_q=0;
    int ptr_l=0;

    for (int i=0;i<=n+1;i++){
    	// add all
    	while (ptr_q<lq_list.size()&&lq_list[ptr_q].first==i){
    		int id=lq_list[ptr_q].second;
    		++ptr_q;
    		pair<long long, long long> ttl_over=get(1,0,n+1,lq[id],rq[id]);
    		long long to_sub=1ll*(i-1)*ttl_over.first-ttl_over.second;
    		ans[id]-=to_sub;
    		//cout<<id<<" "<<ttl_over.first<<" "<<ttl_over.second<<endl;
    	}
    	while (ptr_l<le_list.size()&&le_list[ptr_l].first==i){
    		int id=le_list[ptr_l].second;
    		++ptr_l;
    		update(1,0,n+1,id,i);
    	}
    }

    cleanup();

    int ptr_r=0;
    ptr_q=0;

    for (int i=n+1;i>=0;--i){
    	while (ptr_q<rq_list.size()&&rq_list[ptr_q].first==i){
    		int id=rq_list[ptr_q].second;
    		++ptr_q;
    		pair<long long, long long> ttl_over=get(1,0,n+1,lq[id],rq[id]);
    		long long to_sub=ttl_over.second-1ll*(i+1)*ttl_over.first;
    		//cout<<id<<" "<<ttl_over.first<<" "<<ttl_over.second<<endl;
    		ans[id]-=to_sub;
    	}

    	while (ptr_r<ri_list.size()&&ri_list[ptr_r].first==i){
    		int id=ri_list[ptr_r].second;
    		++ptr_r;
    		update(1,0,n+1,id,i);
    	}
    }

    for (int i=1;i<=m;i++){
    	if (i>1)
    		printf(" ");
    	printf("%lld",ans[i]-(rq[i]-lq[i]+1));
    }
    cout<<endl;

//    cin.get(); cin.get();
    return 0;
}