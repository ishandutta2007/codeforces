/*
Let me hear the battle cry
Calling on the wind
Let me see the banners fly
Before the storm begins

Let me feel the spirits soar
Destroy the enemy
Striking at the evil core
For all the world to see

This day will last forever
Deep in the hearts of men
Courage and victory
Remember, remember

One Shot At Glory
In the crossfire overhead
Fate stands before me
Words have all been said

One Shot At Glory
Driving hard and seeing red
Destiny calls me
One night of fire
One Shot At Glory

Fighting on with dignity
In life and death we deal
The power and the majesty
Amidst the blood and steel

I still hear the battle cry
The call goes on and on
I still see the banners fly
The battle's always won
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
#define left asdgashgrketwjklrej
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd
#define prev asdgSHJsfgsdfhdsh
#define hash asdgasdgasdgdfrywewery

#define eps 1e-9
#define M_PI 3.141592653589793
#define bsize 1024

#define ldouble long double
using namespace std;

#define bs 998244353

const int N = 500031;

int n,k,ar[N];
int interesting;

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

long long fact[N],invf[N];
long long pw2[N];

long long ans=0;

long long C(long long n,long long m){
	if (m>n)
		return 0;
	long long res=fact[n];
	res*=invf[m];
	res%=bs;
	res*=invf[n-m];
	return res%bs;
}

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
 //   cin.tie(0);

    fact[0]=1;
    for (int i=1;i<N;i++){
    	fact[i]=fact[i-1]*i%bs;
    }

    for (int i=0;i<N;i++){
    	invf[i]=inv(fact[i]);
    }

    cin>>n>>k;
    for (int i=1;i<=n;i++){
    	cin>>ar[i];
    }

    for (int i=1;i<=n;i++){
    	int nxt=i+1;
    	if (nxt>n)
    		nxt=1;
    	if (ar[nxt]!=ar[i])
    		++interesting;
    }

    int boring=n-interesting;

    pw2[0]=1;
    for (int i=1;i<N;i++){
    	pw2[i]=pw2[i-1]*(k-2)%bs;
    }

    for (int unrelated=0;unrelated<=interesting;unrelated++){
    	long long total_ways_here=pw(2,interesting-unrelated);
    	if (interesting%2==unrelated%2) // ties possible
    	{
			long long ties=C(interesting-unrelated,(interesting-unrelated)/2);
			total_ways_here-=ties;
			if (total_ways_here<0)
				total_ways_here+=bs;
    	}
    	total_ways_here*=inv(2);
    	total_ways_here%=bs;
    	//cout<<total_ways_here<<" "<<unrelated<<endl;
    	long long fill_in=pw2[unrelated];
    	total_ways_here*=fill_in;
    	total_ways_here%=bs;
    	long long pick_unrelated=C(interesting,unrelated);
    	total_ways_here*=pick_unrelated;
    	total_ways_here%=bs;
    	ans+=total_ways_here;
    	ans%=bs;
    }

/*    for (int A=1;A<=interesting;A++){
    	for (int B=0;B<A;B++){
    		if (A+B>interesting)
    			continue;
    		long long ways=pw2[interesting-A-B]*C(interesting,A)%bs*C(interesting-A,B)%bs;
    		ans+=ways;
    		ans%=bs;
    	}
    }*/

    ans*=pw(k,boring);
    ans%=bs;

    cout<<ans<<endl;

//    cin.get(); cin.get();
    return 0;
}