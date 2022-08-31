/*
Find time and play with innocence
Like you ever would
I don't see you make any sense
I guess you deliver misery
Just like you should

1 o'clock and you paint the skies grey
It's not your fault We're the ones who betray
But how can you say it with such ease
You want to take a stand or just wanna please

Your bedtime story is scaring everyone
But you make me understand
The evil that man do
The evil that man do
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

const long long N = 200031;

int tests,n;
vector<pair<int,int> > by_h,by_w;
int h[N],w[N];
pair<int,int> h_min_pref[N],w_min_pref[N];
int ans[N];
int id;

pair<int,int> better(pair<int,int> p1,pair<int,int> p2){
	if (p1.first<p2.first)
		return p1;
	return p2;
}

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n;
    	by_h.clear();
    	by_w.clear();
    	for (int i=1;i<=n;i++){
    		cin>>h[i]>>w[i];
    		by_h.push_back(make_pair(h[i],i));
    		by_w.push_back(make_pair(w[i],i));
    	}
    	sort(by_h.begin(),by_h.end());
    	sort(by_w.begin(),by_w.end());

    	for (int i=0;i<by_h.size();i++){
    		h_min_pref[i]=make_pair(w[by_h[i].second],by_h[i].second);
    		if (i>0)
    			h_min_pref[i]=better(h_min_pref[i],h_min_pref[i-1]);
    	}
    	for (int i=0;i<by_w.size();i++){
    		w_min_pref[i]=make_pair(h[by_w[i].second],by_w[i].second);
    		if (i>0){
    			w_min_pref[i]=better(w_min_pref[i],w_min_pref[i-1]);
    		}
    	}

    	for (int i=1;i<=n;i++){
    		ans[i]=-1;
    		id=lower_bound(by_h.begin(),by_h.end(),make_pair(h[i],-1))-by_h.begin();
    		if (id>0){
    			pair<int,int> P=h_min_pref[id-1];
    			if (P.first<w[i])
    				ans[i]=P.second;
    		}
    		id=lower_bound(by_h.begin(),by_h.end(),make_pair(w[i],-1))-by_h.begin();
    		if (id>0){
    			pair<int,int> P=h_min_pref[id-1];
    			if (P.first<h[i])
    				ans[i]=P.second;
    		}
    	}

    	for (int i=1;i<=n;i++){
    		if (i>1)
    			cout<<" ";
    		cout<<ans[i];
    	}
    	cout<<endl;

    }

    //cin.get(); cin.get();
    return 0;
}