/*
I believe I see your face
Reflected in the glass
Your blue eyes seem to laugh at me
You have captured my soul
You broke my heart 'long time ago
I'll make you love me too
Don't play for keeps, don't play to win
We're playing your game
I can't believe the words you say
That love's just gone someday
A coolness has replaced your love
My fortune fades away
I recall the times we had
Those days of happiness
I never will believe you
When you say love's a game
Night after night
It's a game
Love is a game
As you lie there, my heart stands still
You're just another girl
I once had loved sky blue eyes
With lots of golden smiles
I'm so confused, I chose another
You're not the same
The time has come and I accept
That love is just a game
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

#define bs 998244353

const int N = 500031;

long long D;

vector<long long> primes;

long long gcd(long long a,long long b){
	while (a&&b)a>b?a%=b:b%=a;
	return a+b;
}

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

int tests;
long long A,B;

long long ans;

long long fact[N],invf[N];

int count_deg(long long a,long long b){
	int ret=0;
	while (a%b==0){
		ret++;
		a/=b;
	}
	return ret;
}

long long C(long long n,long long m){
	long long res=fact[n]*invf[m];
	res%=bs;
	res*=invf[n-m];
	return res%bs;
}


long long solver(long long a,long long b){
	long long res=1;
	long long ttl=0;
	for (int i=0;i<primes.size();i++){
		int dif=abs(count_deg(a,primes[i])-count_deg(b,primes[i]));
		res=res*C(ttl+dif,ttl);
		res%=bs;
		ttl+=dif;
	}
	return res;
}

int main(){
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", sttextdout);
	ios_base::sync_with_stdio(0);
	// cin.tie(0);

	fact[0]=1;
	for (int i=1;i<100;i++){
		fact[i]=fact[i-1]*i%bs;
	}

	for (int i=0;i<100;i++){
		invf[i]=inv(fact[i]);
	}

	cin>>D;
	if (D%2==0){
		primes.push_back(2);
		while (D%2==0){
			D/=2;
		}
	}
	for (int i=3;1ll*i*i<=D;i+=2){
		if (D%i==0){
			primes.push_back(i);
			while (D%i==0)
				D/=i;
		}
	}

	if (D>1)
		primes.push_back(D);

	cin>>tests;
	for (;tests;--tests){
		cin>>A>>B;
		long long Q=gcd(A,B);
		long long res=solver(A,Q)*solver(B,Q)%bs;
		cout<<res<<endl;
	}

	// cin.get(); cin.get();
	return 0;
}