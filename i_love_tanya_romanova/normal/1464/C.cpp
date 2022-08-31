/*
Here at lunch hour at Municipal High
We'll see something over the edge
This school is about to see more things crash
Then when you first failed Drivers Ed

Everybody that's inside will be caught in the fight

First somebody screams
Then food begins to fly
Milk cartons raised forward toward the sky

The room quickly erupts
It cannot be controlled
The brawl suddenly begins to explode

Soldiers from all grades choose sides
Combat has begun. Who will survive?
Teachers run in fear fleeing the hall
No one can escape the food brawl

Refreshments become ammunition
The tables is your only cover
There's shit all on your favorite shirt
Now somebody's gonna suffer

First somebody screams
Then food begins to fly
Milk cartons raised forward toward the sky

Soldiers from all grades choose sides
Combat has begun. Who will survive?
Teachers run in fear fleeing the hall
No one can escape the food brawl

It rains condiments and the floor runs slick
With Wednesdays special lunch dish
The jocks are cornered and the principal is a goner
As the faculty looks on in horror

Those who oppose will fall
The lunch hall food brawl!
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

set<string> S[200];
set<string>::iterator it,it2;

string neg(string st){
	for (int i=0;i<st.size();i++){
		if (st[i]=='-')
			st[i]='+';
		else
			st[i]='-';
	}
	return st;
}

void generate(int len){
	if (len==1){
		S[len].insert("+");
		return;
	}
	for (int le=1;le<len;le++){
		for (it=S[le].begin();it!=S[le].end();it++){
			for (it2=S[len-le].begin();it2!=S[len-le].end();it2++){
				string s1=(*it);
				string s2=(*it2);
				s1=neg(s1);
				S[len].insert(s1+s2);
			}
		}
	}
}

void show(int len){
	cout<<S[len].size()<<endl;
	/*for (it=S[len].begin();it!=S[len].end();it++){
		cout<<(*it)<<endl;
	}*/
}

string st;
long long n,T;
long long pw[100];
long long cnt[N];

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

   /* for (int len=1;len<=15;len++){
    	generate(len);
    	show(len);
    	cin.get();
    }*/

    pw[0]=1;
    for (int i=1;i<=60;i++){
    	pw[i]=pw[i-1]*2;
    }

    cin>>n>>T;
    cin>>st;

    // -+ at the end always;

    int val1=st[st.size()-2]-'a';
    int val2=st[st.size()-1]-'a';
    T-=pw[val2];
    T+=pw[val1];

    // now some knapsack?
    st.erase(st.end()-1);
    st.erase(st.end()-1);

    // let's take everything with - first, then fix

//    cout<<st<<endl;

    for (int i=0;i<st.size();i++){
    	int id=st[i]-'a';
    	T+=pw[id];
    	cnt[id]++;
    }

    for (int i=25;i>=0;--i){
    	if (T<0)
    		continue;
    	// flipping at i changes sum by 2^(i+1)
    	long long need_here=(T/pw[i+1]);
    	long long can_here=cnt[i];
    	long long take_here=min(need_here,can_here);
    	T-=pw[i+1]*take_here;
    }

    if (T==0)
    	cout<<"Yes"<<endl;
    else
    	cout<<"No"<<endl;

    //cin.get(); cin.get();
    return 0;
}