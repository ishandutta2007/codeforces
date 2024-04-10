/*
I like to look at you from a distance
I like when you scream in my face
Afraid to say the right words in right order
So they make sense to a person with such grace

What if my dreams don't become reality?
Is my life just a big mistake?
Will I be happy for the times I had
Or would I reconsider and recalculate?

I wanna be heard but leave no trace
I wanna be seen but take no space
I wanna be, I wanna be, leave no trace
I wanna be, I wanna be, take no space

The older I get, the younger I feel
The younger I feel, the older I seem
The more I feel, my age seems real
I Like to pretend I'm as young as I feel
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

int tests,n,m;
vector<pair<int,int> > order;
int state;
int shit;

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n>>m;
    	order.clear();

    	for (int i=1;i<=m;i++){
    		int a,b;
    		cin>>a>>b;
    		order.push_back(make_pair(b,a));
    	}
    	sort(order.begin(),order.end());
    	order.push_back(make_pair(n+1,1));
    	order.push_back(make_pair(n+1,2));
    	state=0;
    	int started=0;
    	int ptr=0;
    	shit=0;
    	while (ptr<order.size()){
    		if (order[ptr].first==order[ptr+1].first){
    			if (state!=0)
    				shit=1;
    			ptr+=2;
    			continue;
    		}

    		if (state!=0){
    			if (started%2==order[ptr].first%2)
    				state=3-state;
    		}
    		if (state==order[ptr].second)
    		{
    			shit=1;break;
    		}
    		if (state==0){
    			state=3-order[ptr].second;
    			started=order[ptr].first;
    		}
    		else
    			state=0;
    		++ptr;
    	}
    	if (shit){
    		cout<<"NO"<<endl;
    	}
    	else
    	{
    		cout<<"YES"<<endl;
    	}
    }

    //cin.get(); cin.get();
    return 0;
}