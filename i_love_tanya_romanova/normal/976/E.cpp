/*
Eyes upon me
Watching me in my perpetual sleep
Dreams deceive me
My future depends on a mindless dream
I've fallen from promises
Damned to take risks on my own
The masterful science that freezes your
Mind and your soul
The wretched dream is realized
The human race is to be crystallized

Thoughts of laughter
Filling the head of the master in charge.
Worlds of wonder
Is this a cure or a painless death
I'll fight and resist
Till they all see the end that is near
The doctors the lawers and G-men
Are living in fear
Living my life with one distant hope
A cure that will kill my invincible foe
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

const int N = 300031;

int n;
long long a,b,hp[N],dmg[N];
set<pair<long long,long long> > hi,lo;
set<pair<long long,long long> >::iterator it;

long long cur_sum_in_hi;

long long s_dmg;

long long solver(){
	return cur_sum_in_hi;
}

long long ans;

void add_candidate(long long h,long long d,long long id){
	if (hi.size()<b){
		hi.insert(make_pair(h-d,id));
		if (h-d>0)
			cur_sum_in_hi+=h-d;
		return;
	}
	it=hi.begin();
	pair<long long, long long> from_hi=(*it);
	pair<long long, long long> my_pair=make_pair(h-d,id);
	if (from_hi>my_pair){
		lo.insert(my_pair);
		return;
	}
	// make swap
	if (from_hi.first>0){
		cur_sum_in_hi-=from_hi.first;
	}
	if (my_pair.first>0)
		cur_sum_in_hi+=my_pair.first;
	hi.erase(it);
	hi.insert(my_pair);
	lo.insert(from_hi);
}

void remove_candidate(long long h,long long d,int id){
	pair<long long, long long> p=make_pair(h-d,id);
	if (hi.find(p)==hi.end()){
		lo.erase(p);
		return;
	}
	if (p.first>0)
		cur_sum_in_hi-=p.first;
	hi.erase(p);
	if (lo.size()>0){
		it=lo.end();
		--it;
		pair<long long, long long> p=(*it);
		lo.erase(it);
		hi.insert(p);
		if (p.first>0)
			cur_sum_in_hi+=p.first;
	}
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n>>a>>b;
	for (int i=1;i<=n;i++){
		cin>>hp[i]>>dmg[i];
		s_dmg+=dmg[i];
	}

	if (b==0){
		cout<<s_dmg<<endl;
		return 0;
	}

	for (int i=1;i<=n;i++){
		add_candidate(hp[i],dmg[i],i);
	}

	ans=solver();

	for (int i=1;i<=n;i++){
		remove_candidate(hp[i],dmg[i],i);
		hp[i]*=(1<<a);
		add_candidate(hp[i],dmg[i],i);
		ans=max(ans,solver());
		remove_candidate(hp[i],dmg[i],i);
		hp[i]/=(1<<a);
		add_candidate(hp[i],dmg[i],i);
	}

	cout<<ans+s_dmg<<endl;

//	cin.get(); cin.get();
	return 0;
}