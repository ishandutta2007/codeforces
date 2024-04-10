/*
The black hole forever mine.
I need fear.
Push me out
Oh be brave
Show me signs
Should I feel shame for the questions that I have

If you could be
The things I need.
I'll crawl through knives
An inch per tear.

These knees, they bleed for you.
Let the colour persuade the hate
That you fear.

Feed the lie.
Force the reason.
Leave me in doubt.
Need some motivation

It's in my hands.
The sky is so bright.
It's burning.
It's for me to decide.
If flames will reach heaven tonight.
It's in my hands.

Nailed to the floor
Paralyzed
Emotions drifting
Touch the new

If you could be
The things I need.
I'll crawl through knives
An inch per tear.

These knees, they bleed for you.
Let the colour persuade the hate
That you fear.
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

int tests,n,ar[N];
vector<int> order;
long long s1,s2;

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n;
    	order.clear();
    	for (int i=1;i<=n;i++){
    		cin>>ar[i];
    		order.push_back(ar[i]);
    	}
    	sort(order.begin(),order.end());
    	reverse(order.begin(),order.end());
    	s1=0;
    	s2=0;
    	for (int i=0;i<order.size();i++){
    		if (i%2==0&&order[i]%2==0)
    			s1+=order[i];
    		if (i%2==1&&order[i]%2==1)
    			s2+=order[i];
    	}
    	if (s1>s2){
    		cout<<"Alice"<<endl;
    	}
    	if (s1<s2){
    		cout<<"Bob"<<endl;
    	}
    	if (s1==s2){
    		cout<<"Tie"<<endl;
    	}
    }

    //cin.get(); cin.get();
    return 0;
}