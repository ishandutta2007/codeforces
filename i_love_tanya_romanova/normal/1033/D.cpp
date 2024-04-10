/*
Survival
Survival

One more goddamn day when I know what I want
And my want will be considered tonight, considered tonight
Just another day when all that I want will mark me as a sinner tonight, I'm a sinner tonight

People can no longer cover their eyes
If this disturbs you then walk away
You will remember the night you were struck by the sight of ten thousand fists in the air

Power un-restrained dead on the mark is what we will deliver tonight, deliver tonight
Pleasure fused with pain
This triumph of the soul will make you shiver tonight, will make you shiver tonight

People can no longer cover their eyes
If this disturbs you then walk away
You will remember the night you were struck by the sight of ten thousand fists in the air

We are the ones that will open your mind
Leave the weak and the haunted behind
We are the ones that will open your mind
Leave the weak and the haunted behind
We are the ones that will open your mind
Leave the weak and the haunted behind
We are the ones that will open your mind
Leave the weak and the haunted behind

People can no longer cover their eyes
If this disturbs you then walk away
You will remember the night you were struck by the sight of ten thousand fists in the air

Ten thousand fists in the air
Ten thousand fists in the air
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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 998244353

const int N = 600031;

long long n,ar[N];
vector<long long> unknown;
map<long long, long long> deg;
map<long long, long long> ::iterator it;

long long safe_mult(long long a,long long b){
	if (a==0||b==0)
		return 0;
	if (2e18/b<=a)
		return 2e18;
	return a*b;
}

long long safe_pow(long long a,long long b){
	long long res=1;
	for (int i=1;i<=b;i++){
		res=safe_mult(res,a);
	}
	return res;
}

long long gcd(long long a,long long b){
	while (a&&b)a>b?a%=b:b%=a;
	return a+b;
}

vector<pair<long long, long long> > try_factorize(long long val){
	vector<pair<long long, long long> > ret;
	// x^2, x^3, x^4
	for (int i=4;i>=2;i--){
		long long here=pow(val,1.0/i);
		for (long long q=here-5;q<=here+5;q++){
			if (q<=1)
				continue;
			long long val2=safe_pow(q,i);
			if (val2==val){
				//cout<<val<<" "<<q<<"@"<<i<<endl;
				ret.push_back(make_pair(q,i));
				return ret;
			}
		}
	}

	// look at GCD, for a*b && b*c
	for (int i=1;i<=n;i++){
		if (ar[i]==val)
			continue;
		long long Q=gcd(ar[i],val);
		if (Q==1)
			continue;
		ret.push_back(make_pair(Q,1));
		ret.push_back(make_pair(val/Q,1));
		return ret;
	}

	return ret;
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>ar[i];

	}

	for (int i=1;i<=n;i++){
		vector<pair<long long, long long> > V=try_factorize(ar[i]);
		if (V.size()==0){
			unknown.push_back(ar[i]);
		}
		else
		{
			for (int j=0;j<V.size();j++){
				deg[V[j].first]+=V[j].second;
			}
		}
	}

	// start with known first
	long long ans=1;
	for (it=deg.begin();it!=deg.end();it++){
		int cnt=(*it).second;
		ans=ans*(cnt+1);
		ans%=bs;
	}
	sort(unknown.begin(),unknown.end());
	// all are p*q, some may repeat
	int T=0;
	for (int i=0;i<unknown.size();i++){
		if (i>0&&unknown[i]!=unknown[i-1])
		{
			ans*=(T+1);
			ans%=bs;
			ans*=(T+1);
			ans%=bs;
			T=0;
		}
		++T;
	}
	ans*=(T+1);
	ans%=bs;
	ans*=(T+1);
	ans%=bs;

	cout<<ans<<endl;


//	cin.get(); cin.get();
	return 0;
}