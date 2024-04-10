/*
When you leave this world
The chains undone and death unfurls
What were the choices you had?
The paths you took - good or bad

Reflections of you - You're fighting a shadow

A chip on your shoulder
Nail in your heart got you colder
Your hands made for caress
Fists of anger fear and distress

Rites of war - conflict deep inside
Rites of war - traveled, short or far
Rites of war - fighting, run or hide
Rites of war - running, from afar

Your steps filled with regret
Who you were and who you met
Did love rule your world?
Walk all alone, solidarity unfurled
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

long long fact[N],invf[N];

long long pw(long long a,long long b){
	if (b==0)
		return 1;
	if (b%2)
		return a*pw(a,b-1)%bs;
	return pw(a*a%bs,b/2);
}

long long inv(long long x){
	return pw(x,bs-2);
}

long long C(long long n,long long m){
	if (m>n)
		return 0;
	long long res=fact[n]*invf[m];
	res%=bs;
	return res*invf[n-m]%bs;
}

int tests;
long long ans;
int n,m,k;
vector<int> order;
int ptr;
int ar[N];

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);

    fact[0]=1;
    for (int i=1;i<N;i++){
    	fact[i]=fact[i-1]*i%bs;
    }

    invf[0]=1;
    for (int i=1;i<N;i++){
    	invf[i]=inv(fact[i]);
    }


    cin>>tests;
    for (;tests;--tests){
    	cin>>n>>m>>k;
    	order.clear();
    	for (int i=1;i<=n;i++){
    		cin>>ar[i];
    		order.push_back(ar[i]);
    	}
    	sort(order.begin(),order.end());
    	ans=0;
    	ptr=0;
    	for (int i=0;i<order.size();i++){
    		while (ptr+1<order.size()&&order[ptr+1]-order[i]<=k)
    			++ptr;
    		int span=ptr-i+1;
    		ans+=C(span-1,m-1);
    		ans%=bs;
    	}
    	cout<<ans<<endl;
    }

    //cin.get(); cin.get();
    return 0;
}