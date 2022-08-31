/*
The thin darkness here
Not strong enough to make you appear
I once changed my style
When they said hello I said goodbye
I once played a role
I was out there marketing my soul

The city of glass that I live in
The coldness from my brothers skin

I trusted you you lied
It's all I hear a fucking lie
I don't give a shit it's over now
It's all I know you broke the vow

Truth is I have seen it come
Seen the ghost of the sun
Can't have it undone
In time we all call out for relief
See two lovers meet
Pass you on the street
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

long long n,k,ar[N];
vector<long long> order;
long long suf_sum[N],with_coef[N];
long long cur_penalty;
long long ans;
long long sz[N];

long long solver(int ps){
	long long score_prog=with_coef[ps];
	long long shifted=suf_sum[ps]*(sz[ps%k]);
	return score_prog+shifted;
}

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

    cin>>n>>k;
    ++k;
    for (int i=1;i<=n;i++){
    	cin>>ar[i];
    	order.push_back(ar[i]);
    }

    sort(order.begin(),order.end());

   /* if (k==0){
    	ans=0;
    	long long sum=0;
    	for (int i=order.size()-1;i>=0;--i){
    		ans+=sum;
    		sum+=order[i];
    	}
    	cout<<ans<<endl;
    	return 0;
    }
*/
    for (int i=order.size()-1;i>=0;--i){
    	suf_sum[i]=suf_sum[i+1]+order[i];
    	with_coef[i]=with_coef[i+1]+suf_sum[i+1];
    //	cout<<suf_sum[i]<<"@@@"<<with_coef[i]<<endl;
    }

    cur_penalty=0;

    ans=-1e18;

    for (int i=0;i<=order.size();i++){
    	ans=max(ans,solver(i)+cur_penalty);
    	//cout<<solver(i)<<" "<<cur_penalty<<endl;

    	if (i==order.size())
    		break;
    	cur_penalty+=sz[i%k]*order[i];
    	sz[i%k]++;
    }

    cout<<ans<<endl;

    //cin.get(); cin.get();
    return 0;
}