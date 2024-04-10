/*
Born a curse somewhere out of sight
Lost beings have cared for my needs
Years have passed me by
Another being has never been seen
Labyrinth, undying solitude
I pictured myself set free
I made a vow to one day rise
From the broken existence I lead

I am the outsider
Outsider
Escape and behold the day
Outsider
Unswayed by what the world will say

Breaking through layers of my cell
Upon the hallowed ground I now stand
I meet the glare of the beast
But the horror makes no demand
Terror stares in its form, unknown
In the golden arch its framed
Beckoning I touch the glass
The terror and I are the same

I am the outsider
Outsider
Escape and behold the day
Outsider
Unswayed by what the world will say
Outsider
Forward into the wild domain
Outsider
Unknown forever to remain

Frantic I crave the light
For I know not who I am
Voiceless I cant relate
To the ones I once belonged

I am the outsider
Outsider
Escape and behold the day
Outsider
Unswayed by what the world will say
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

const int N = 400031;

long long pw(long long a,long long b){
	if (b==0)
		return 1;
	if (b%2)
		return a*pw(a,b-1)%bs;
	return pw(a*a%bs,b/2);
}

long long inver[331];
int pr[331];
vector<int> primes;
int n;

int tests;
int ar[N];
long long M[N];

pair<long long, long long> t[N*4];
pair<long long, long long> tomult[N*4];

long long get_pw(long long val,int p){
	return pw(val,p);
}

void push(int v,int tl,int tr){

	int tm=tl+tr;
	tm/=2;

	if (tomult[v].first!=1){

		tomult[v*2].first=(tomult[v*2].first*tomult[v].first)%bs;
		tomult[v*2+1].first=(tomult[v*2+1].first*tomult[v].first)%bs;
		long long le=get_pw(tomult[v].first,tm-tl+1);
		long long ri=get_pw(tomult[v].first,tr-tm);
		t[v*2].first=(t[v*2].first*le)%bs;
		t[v*2+1].first=(t[v*2+1].first*ri)%bs;
		tomult[v].first=1;
	}

	if (tomult[v].second!=0){
		tomult[v*2].second|=tomult[v].second;
		tomult[v*2+1].second|=tomult[v].second;
		t[v*2].second|=tomult[v].second;
		t[v*2+1].second|=tomult[v].second;
		tomult[v].second=0;
	}

}

void build(int v,int tl,int tr){
	tomult[v].first=1;
	if (tl==tr){
		t[v].first=ar[tl];
		t[v].second=M[tl];
		return;
	}
	int tm=tl+tr;
	tm/=2;
	build(v*2,tl,tm);
	build(v*2+1,tm+1,tr);
	t[v].first=(t[v*2].first*t[v*2+1].first)%bs;
	t[v].second=(t[v*2].second|t[v*2+1].second);
}

void update(int v,int tl,int tr,int l,int r,int val,long long msk){
	if (l>r)
		return;
	if (tl==l&&tr==r){
		t[v].first=t[v].first*get_pw(val,tr-tl+1)%bs;
		t[v].second|=msk;
		tomult[v].first*=val;
		tomult[v].first%=bs;
		tomult[v].second|=msk;
		return ;
	}
	push(v,tl,tr);
	int tm=tl+tr;
	tm/=2;
	update(v*2,tl,tm,l,min(r,tm),val,msk);
	update(v*2+1,tm+1,tr,max(tm+1,l),r,val,msk);
	t[v].first=t[v*2].first*t[v*2+1].first%bs;
	t[v].second=(t[v*2].second|t[v*2+1].second);
}

pair<long long, long long> get(int v,int tl,int tr,int l,int r){
	if (l>r)
		return make_pair(1,0);
	if (l==tl&&r==tr)
		return t[v];
	push(v,tl,tr);
	int tm=tl+tr;
	tm/=2;
	pair<long long, long long> p1=get(v*2,tl,tm,l,min(r,tm));
	pair<long long, long long> p2=get(v*2+1,tm+1,tr,max(tm+1,l),r);
	p1.first=(p1.first*p2.first)%bs;
	p1.second|=p2.second;
	return p1;
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);

	pr[1]=1;
	for (int i=2;i<=300;i++){
		if (pr[i]==0){
			for (int j=i*2;j<=300;j+=i){
				pr[j]=1;
			}
		}
	}

	for (int i=1;i<=300;i++){
		inver[i]=pw(i,bs-2);
	}

	for (int i=2;i<=300;i++){
		if (pr[i]==0)
			primes.push_back(i);
	}


	cin>>n>>tests;
	for (int i=1;i<=n;i++){
///		cin>>ar[i];
		scanf("%d",&ar[i]);
	}

	/*for (int i=0;i<primes.size();i++){
		for (int j=1;j<=n;j++){
			S[i].insert(j);
		}
	}
*/

	for (int i=1;i<=n;i++){
		long long msk=0;

		for (int j=0;j<primes.size();j++){
			if (ar[i]%primes[j]==0){
				msk|=(1ll<<j);
			}
		}
		M[i]=msk;
//		update(1,1,n,i,i,1,msk);
	}

	build(1,1,n);



	for (;tests;--tests){
		string s;
		cin>>s;
		if (s=="TOTIENT"){
			int l,r;
//			cin>>l>>r;
			scanf("%d",&l);
			scanf("%d",&r);
			pair<long long, long long> res=get(1,1,n,l,r);
			for (int i=0;i<primes.size();i++){
				//continue;
				if (res.second&(1ll<<i))
				{
					res.first=res.first*inver[primes[i]];
					res.first%=bs;
					res.first*=primes[i]-1;
					res.first%=bs;
				}
			}
			printf("%lld\n",res.first);
		}
		else
		{
			int l,r,val;
			scanf("%d",&l);
			scanf("%d",&r);
			scanf("%d",&val);
			long long msk=0;

			for (int j=0;j<primes.size();j++){
				if (val%primes[j]==0){
					msk|=(1ll<<j);
				}
			}
			update(1,1,n,l,r,val,msk);
		}

	}
//    cin.get(); cin.get();
    return 0;
}