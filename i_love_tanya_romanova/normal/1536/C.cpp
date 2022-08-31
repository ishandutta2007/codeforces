/*
Whipcrack, stings the sky
Don't mess with me I'm danger
The meanest one alive

Earthquake, breaks the Richter scale
The more that you resist
The more the pain you'll feel

I'm blazing on to glory
There's thunder in my veins
And nothing stands before me
Forever I'll remain

Hard as iron
Sharp as steel
Stop for no man
You better beg and kneel

Untouched, cold as ice
I'll turn your blood to water
Strangle in my vice

Shock waves, bones to dust
You're messin' with a mine field
so expect the worst

I'm blazing on to glory
There's thunder in my veins
And nothing stands before me
Forever I'll remain

Hard as iron
Sharp as steel
Stop for no man
You better beg and kneel

As I destroy, last thing you'll hear me cry, is victory, is victory

I'm blazing on to glory
There's thunder in my veins
And nothing stands before me
Forever I'll remain

Hard as iron
Sharp as steel
Stop for no man
You better beg and kneel
*/

#pragma GCC optimize("Ofast")
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

const long long bs = 1000000007;

const int N = 500031;

int tests;
map<pair<int,int>,int> M;

long long gcd(long long a,long long b){
	while (a&&b)a>b?a%=b:b%=a;
	return a+b;
}
int cnt0,cnt1;
string st;
int ans;

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	int trash;
    	cin>>trash;
    	cin>>st;
    	cnt0=0;
    	cnt1=0;
    	ans=0;
    	M.clear();
    	for (int i=1;i<=st.size();i++){
    		if (st[i-1]=='D')
    			cnt0++;
    		else
    			cnt1++;
    		long long Q=gcd(cnt0,cnt1);
    		ans=M[make_pair(cnt0/Q,cnt1/Q)];
    		M[make_pair(cnt0/Q,cnt1/Q)]++;
    		if (i>1)
    			cout<<" ";
    		cout<<ans+1;
    	}
    	cout<<endl;
    }

    //cin.get(); cin.get();
    return 0;
}