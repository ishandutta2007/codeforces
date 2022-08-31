/*
I know you thought you're a real operator
But I don't know why
All you had was a bankroll, babe
And a glint in your eye
I'm a high-steppin' like an indian brave
I'm the one
Dancing on your grave

You know I'm a killer babe
Here's late news for you
you couldn't buy me with a million, babe
I'm too good for you
I'm know you think I'm real rough trade
Now I'm the one
Dancing on your grave

One time you was a real high-stepper
On the high trapeze
But you know you ran out of money
Wound up on your knees
I'm the one you never made
Now I'm the one
Dancing on your grave
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

const int N = 600031;

int tests,n,m;
vector<pair<int,int> > order;
int ar[N];
int rmost;
long double prob_bad;

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n>>m;
    	order.clear();
    	for (int i=1;i<=n;i++){
    		cin>>ar[i];
    		order.push_back(make_pair(ar[i],i));
    	}
    	rmost=0;
    	sort(order.begin(),order.end());
    	for (int i=0;i<order.size();i++){
    		int ps=order[i].second;
    		ar[ps]=i+1;
    	}
    	for (int i=1;i<=n;i++){
    		if (ar[i]>i)
    			rmost=max(rmost,ar[i]);
    	}
    	prob_bad=1.0;
    	if (rmost==0)
    		prob_bad=0;
    	for (int i=1;i<=m;i++){
    		int len;
    		double prob;
    		cin>>len>>prob;
    		if(prob_bad<-1e20)
    			continue;
    		if (len>=rmost)
    			prob_bad=prob_bad*(1.0-prob);
    	}
    	cout.precision(12);
    	cout<<fixed<<1.0-prob_bad<<endl;
    }

    //cin.get(); cin.get();
    return 0;
}