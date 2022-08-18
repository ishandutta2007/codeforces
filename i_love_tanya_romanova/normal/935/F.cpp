/*
Oh yeah, I see the way you roll your eyes, the way your purse your lips
Throw your stuff into a suitcase, put your hands upon your hips
I'm not moved by your evil glare, the way you toss your hair
You make stupid accusations by which time I've lost the thread

Sometimes I wonder how it is you get to piss me off this much
I may be heavier handed and I like the tender touch
You moan and groan about me staying out and drinking with the guys
I bet I bring them home try this one for size

Something awfully wrong with this deal babe
Any fool could see its true
Can't you understand how I feel babe
You got me, but all I got is you

I guess I just don't have it in me, to keep you satisfied
To be honest with you babe, I'm only in it for the ride
And you may never bring yourself to take me as I am
But in case you hadn't noticed, I don't give a fucking damn!
*/

//#pragma GCC optimize("O3")
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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 400031;

int n,ar[N];
set<int> local_maxima;
set<int>::iterator it;

long long dif[N];
int tests;

long long CUR_ANS;

int get_local_maximum(int start){
	it=local_maxima.lower_bound(start);
	if (it==local_maxima.end())
		return -1;
	return (*it);
}

void update_maxima(int ps){
	if (local_maxima.find(ps)!=local_maxima.end())
		local_maxima.erase(ps);
	if (ps<=1||ps>=n)
		return ;
	if (dif[ps]>=0&&dif[ps+1]<=0)
		local_maxima.insert(ps);
}

pair<long long, long long> t[N*4];

pair<long long, long long> combine(pair<long long, long long> p1,pair<long long, long long> p2){
	if (p1.first<p2.first)
		return p1;
	return p2;
}

void build(int v,int tl,int tr){
	if (tl==tr){
		if (dif[tl]<0)
			t[v]=make_pair(abs(dif[tl]),tl);
		else
			t[v]=make_pair(1e18,tl);
		return ;
	}
	int tm=tl+tr;
	tm/=2;
	build(v*2,tl,tm);
	build(v*2+1,tm+1,tr);
	t[v]=combine(t[v*2],t[v*2+1]);
}

void update(int v,int tl,int tr,int ps){
	if (tl==tr){
		if (dif[tl]<0)
			t[v]=make_pair(abs(dif[tl]),tl);
		else
			t[v]=make_pair(1e18,tl);
		return;
	}
	int tm=tl+tr;
	tm/=2;
	if (ps<=tm)
		update(v*2,tl,tm,ps);
	else
		update(v*2+1,tm+1,tr,ps);
	t[v]=combine(t[v*2],t[v*2+1]);
}

pair<long long, long long> get(int v,int tl,int tr,int l,int r){ // get min
	if (l>r)
		return make_pair(1e18,1e18);
	if (tl==l&&tr==r)
		return t[v];
	int tm=tl+tr;
	tm/=2;
	return combine(
		get(v*2,tl,tm,l,min(r,tm)),
		get(v*2+1,tm+1,tr,max(tm+1,l),r)
	);
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n;

	// n>=3 !!

	for (int i=1;i<=n;i++){
		cin>>ar[i];
	}

	for (int i=2;i<n;i++){
		if (ar[i]>=ar[i-1]&&ar[i]>=ar[i+1]){
			local_maxima.insert(i);
		}
	}

	for (int i=1;i<=n;i++){
		dif[i]=ar[i]-ar[i-1];
	}

	for (int i=2;i<=n;i++){
		CUR_ANS+=abs(ar[i]-ar[i-1]);
	}

	build(1,1,n);

	cin>>tests;
	for (;tests;--tests){
		/*cout<<"CUR ANS: "<<CUR_ANS<<endl;
		for (int i=1;i<=n;i++){
			cout<<dif[i]<<" ";
		}
		cout<<endl;
		*/
		int tp;
		cin>>tp;
		if (tp==1){ // query
			int l,r,x;
			cin>>l>>r>>x;
			int P=get_local_maximum(l);
			if (P>=l&&P<=r)// just take +2x there
			{
				cout<<CUR_ANS+2*x<<endl;
				continue;
			}
			// shit is not that good otherwise; else (:)
			{
				// at least
				long long best_aprox=CUR_ANS-2*x;
				if (l==1) // try first
				{
					long long aprox_first=CUR_ANS;
					aprox_first-=abs(dif[2]);
					aprox_first+=abs(dif[2]-x);
					best_aprox=max(best_aprox,aprox_first);
				}
				if (r==n) // try last
				{
					long long aprox_last=CUR_ANS;
					aprox_last-=abs(dif[n]);
					aprox_last+=abs(dif[n]+x);
					best_aprox=max(best_aprox,aprox_last);
				}

				// find smallest
				// dif in range l+1,r-1; we'll get +X on one side and P.Up on this smallest dif
				long long q_r=min(0ll+n-1,0ll+r-1);
				long long q_l=max(1,l+1);
				/*if (q_l<=q_r){
					pair<long long, long long> P=get(1,1,n,q_l,q_r);
					long long smallest_dif=P.first;
					long long aprox_here=CUR_ANS+x;
					if (smallest_dif>=x){ // sign stays same
						aprox_here-=x;
					}
					else // sign changes
					{
						aprox_here-=abs(smallest_dif);
						aprox_here+=abs(x-smallest_dif);
					}
					best_aprox=max(best_aprox,aprox_here);
				}*/
				for (int i=l+1;i<r;i++){
					long long score_here=CUR_ANS;
					score_here-=abs(dif[i]);
					score_here-=abs(dif[i+1]);
					score_here+=abs(dif[i]+x);
					score_here+=abs(dif[i+1]-x);
					best_aprox=max(best_aprox,score_here);
				}

				// consider changing l and r, some shit may happen there
				if (l!=1&&l!=n){
					long long score_here=CUR_ANS;
					score_here-=abs(dif[l]);
					score_here-=abs(dif[l+1]);
					score_here+=abs(dif[l]+x);
					score_here+=abs(dif[l+1]-x);
					best_aprox=max(best_aprox,score_here);
				}
				if (r!=1&&r!=n){
					long long score_here=CUR_ANS;
					score_here-=abs(dif[r]);
					score_here-=abs(dif[r+1]);
					score_here+=abs(dif[r]+x);
					score_here+=abs(dif[r+1]-x);
					best_aprox=max(best_aprox,score_here);
				}
				cout<<best_aprox<<endl;
			}
		}
		else // update
		{
			int l,r,val;
			cin>>l>>r>>val;
			// ar[l]-ar[l-1]+=val; ar[r+1]-ar[r]-=val;

			if (l!=1){
				CUR_ANS-=abs(dif[l]);
			}
			dif[l]+=val;
			if (l!=1){
				CUR_ANS+=abs(dif[l]);
			}

			if (r!=n){
				CUR_ANS-=abs(dif[r+1]);
			}
			dif[r+1]-=val;
			if (r!=n){
				CUR_ANS+=abs(dif[r+1]);
			}

			update_maxima(l-1);
			update_maxima(l);
			update_maxima(r);
			update_maxima(r+1);
			update(1,1,n,l);
			if (r+1<=n)
				update(1,1,n,r+1);
		}
	}

//	cin.get(); cin.get();
	return 0;
}