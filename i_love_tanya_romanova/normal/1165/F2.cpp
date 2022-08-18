/*
By a black road
Giving a brief smile
Something's on the way
Forgotten for a while
And you try to speak this
Without a voice down by a black road
We try to forget and try to make it through

Someday we'll go
Further from this right into the bliss
Some night we'll try
To leave this place for another

They keep pushing me
So far from every chance
Makes it so much harder
For me to carry on
So I try to speak this
Without a thought down by a black road
We try to forget and try to make it through
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

#define eps 1e-9
#define M_PI 3.141592653589793
#define bsize 300

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 700031;

int n,m;
vector<int> cheap[N];
int k[N];
int total_k;

int rem[N];

int can_save(int t){
	for (int i=1;i<=n;i++){
		rem[i]=k[i];
	}

	int money_left=t;

	int T=0;
	for(int i=t;i>=1;--i){
		money_left=min(money_left,i);
		for (int j=0;j<cheap[i].size();j++){
			int id=cheap[i][j];
			int buy=min(money_left,rem[id]);
			T+=buy;
			money_left-=buy;
			rem[id]-=buy;
		}
	}
	return T;
}

int cost(int t){
	int total_need=2*total_k;
	return total_need-can_save(t);
}
int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>n>>m;
    for (int i=1;i<=n;i++){
    	cin>>k[i];
    	total_k+=k[i];
    }

    for (int i=1;i<=m;i++){
    	int d,id;
    	cin>>d>>id;
    	cheap[d].push_back(id);
    }

    int l,r;
    l=1;
    r=600000;
    while (l<r){
    	int mid=l+r;
    	mid/=2;
    	if (cost(mid)<=mid)
    		r=mid;
    	else
    		l=mid+1;
    }

    cout<<l<<endl;

//    cin.get(); cin.get();
    return 0;
}