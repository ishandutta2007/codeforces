/*
As I aim for that bright white day
Conflict serum is my aura
It seems that life's so fragile
I guess I'll fly some other time

I lack from superhighway thoughts
Won't live as long as the city lights
Soaked by underwater times
Electric splash on a midnight drive

Wish I could rape the day,
just something radical
Lost the sense of sweet things
Who's gonna take me widely?

Guided by the pinball map
The driver, still unknown to me
Who was sent to glorify?
Before we injected this common pride

Sometimes I don't belong
Release me from your world
Pacified by the small things in life
I wait for earthquakes to rearrange

Never been able to use the force
I only have it read to me
Despite all the misguided faith
(Maybe) I'll find a place in this mess

Early morning moments
A glimpse of joy
But soon it's over and I return to dust
As I try to be
Everything and everyone
I shrivel up and waste away
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

const int N = 110031;

long long n,m;

vector<vector<long long> > one(int sz){
	vector<vector<long long> > ret;
	ret.resize(sz);
	for(int i=0;i<ret.size();i++){
		ret[i].resize(sz);
		for (int j=0;j<ret.size();j++){
			ret[i][j]=(i==j);
		}
	}
	return ret;
}

vector<vector<long long> > mult(vector<vector<long long> > a,vector<vector<long long> > b){
	vector<vector<long long > > ret;
	ret.resize(a.size());
	for (int i=0;i<ret.size();i++){
		ret[i].resize(a.size());
		for (int j=0;j<ret.size();j++){
			ret[i][j]=0;
		}
	}
	for (int k=0;k<ret.size();k++){
		for (int i=0;i<a.size();i++){
			for (int j=0;j<b.size();j++){
				ret[i][j]=(ret[i][j]+a[i][k]*b[k][j]);
				ret[i][j]%=bs;
			}
		}
	}
	return ret;
}

vector<vector<long long> > pw(vector<vector<long long> > a,long long b){
//	cout<<b<<"@"<<endl;
	if (b==0)
		return one((int)a.size());
	if (b%2)
		return mult(a,pw(a,b-1));
	return pw(mult(a,a),b/2);
}

vector<vector<long long> > dp;

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>n>>m;

    dp.resize(m);
    for (int i=0;i<m;i++){
    	dp[i].resize(m);
    }

    for (int i=0;i<dp.size();i++){
    	for (int j=0;j<dp.size();j++){
    		dp[i][j]=0;
    	}
    }

    for (int i=0;i<dp.size();i++){
    	dp[i][(i+1)%m]++;
    }
    dp[0][0]++;

    dp=pw(dp,n);

    cout<<dp[0][0]<<endl;


//    cin.get(); cin.get();
    return 0;
}