/*
From the distance I heard a voice
Calling my name
Feeling dizzy I'm caught in the noise
Am I going insane?

Dusty clouds surround my head
Is this the devils sign?
The voice said prepare for your death
Cause you're the next in line

Can you see it? Can you feel it?
Something evil has taken control
It's like a nightmare, it's so unreal
Am I losing my soul?
And the magic has gone

Travelling to an unknown place
What will the future bring?
Death shows its evil face
I can hear the Devil sing

Am I alive or dead
It keeps spinning in my head
Am I alive or dead?
I know the time has come
And the magic is gone
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
	long long res=1;
	if (m>n)
		return 0;
	for (int i=n;i>n-m;--i){
		res*=i;
	}
	for (int i=1;i<=m;i++){
		res/=i;
	}
	return res;
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
    	cin>>n;
    	k=2;
    	m=3;
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
    	}
    	cout<<ans<<endl;
    }

    //cin.get(); cin.get();
    return 0;
}