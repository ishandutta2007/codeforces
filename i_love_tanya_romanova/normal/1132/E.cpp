/*
When will it ever end and when will my life begin...

No sweat, no regrets run down my back
A fine line just right before I crack
oh man to see me and then wave your finger up in my face
Believing in what you say and promising another day

Will it ever end, when will my life begin
All this built up pain forever plaguing me
Its the last time, its my lifeline
Its the last time that I'll be forever shamed

No breath and disrespecting all my time
Dividing and speaking out of line
Tell me the reason oh everybody needs to feel your pain
So draw the line back to me
and save me from insanity

Will it ever end, when will my life begin
All this built up pain forever plaguing me
Its the last time, its my lifeline
Its the last time that I'll be forever shamed

When will it ever end, when will my life begin
All this built up pain forever plaguing me
Its the last time, its my lifeline
Its the last time that I'll be forever shamed

Ha, ha!

Will it ever end, when will my life begin
All this built up pain forever plaguing me
Its the last time, its my lifeline
Its the last time that I'll be forever shamed

When will it ever end, when will my life begin
All this built up pain forever plaguing me
Its the last time, its my lifeline
Its the last time that I'll be forever shamed

Forever shamed! Forever!
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

const int N = 410031;

long long W;
long long S[N];
long long cnt[N];
set<long long> ::iterator it;
set<long long> memo[100];

const long long MAGIC = 5000;

void backtrack(int ps,long long val){
	if (val<W-MAGIC&&val<S[ps]-MAGIC)
		return;

	if (memo[ps].find(val)!=memo[ps].end())
		return;
	memo[ps].insert(val);
	if (ps==8)
		return;
	long long mx=min(S[ps+1],W);
	long long can_fit=(mx-val)/(ps+1);
	can_fit=min(can_fit,cnt[ps+1]);
	for (long long i=can_fit;i>=can_fit-500;i--){
		if (i<0)
			return;
		backtrack(ps+1,val+i*(ps+1));
	}
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>W;
    for (int i=1;i<=8;i++){
    	cin>>cnt[i];
    	S[i]=S[i-1]+cnt[i]*i;
    }

    backtrack(0,0);

    it=memo[8].end();
    --it;
    cout<<(*it)<<endl;

//    cin.get(); cin.get();
    return 0;
}