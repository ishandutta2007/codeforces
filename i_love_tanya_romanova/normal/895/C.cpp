/*
Midnight runaway, know you're running scared
Bright lights, big city, nobody seems to care
Open your eyes who's there, who's there
Open your eyes, nightmare
Unclean, fever dream on the high side, in the Mean Machine

Black bomber in the night, can you handle the pain
Better call the FBI, better change your name
Open your eyes, oh no, oh no
Open your eyes, creepshow
Unclean, fever dream, on the wild side in the Mean Machine

Unclean, fever dream, take a ride Mean Machine
Wet dream, bad scene, we don't care where you been
On the screen, movie queen, things ain't always
What they seem. stay clean, crazy dream
Off the high side in the Mean Machine
*/

//#pragma GCC optimize("O3")
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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 300031;

int pr[1000];
vector<int> primes;

set<int> Q;
int n;
int ar[N];
int cnt[1<<20];

long long fact[N],invf[N];

int W[200][200];

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

int get_mask(int x){
	int res=0;
	for (int i=0;i<primes.size();i++){
		while (x%primes[i]==0){
			x/=primes[i];
			res^=(1<<i);
		}
	}
	return res;
}

long long C(long long n,long long m){
	if (m>n)
		return 0;
	long long res=fact[n];
	res*=invf[m];
	res%=bs;
	res*=invf[n-m];
	return res%bs;
}

long long dp[2][1<<20];

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	fact[0]=1;
	for (int i=1;i<N;i++){
		fact[i]=fact[i-1]*i%bs;
	}

	for (int i=0;i<N;i++){
		invf[i]=inv(fact[i]);
	}

	pr[1]=1;
	for (int i=2;i<=70;i++){
		if (pr[i]==0){
			for (int j=i*2;j<=70;j+=i)
				pr[j]=1;
		}
	}

	primes.clear();
	for (int j=2;j<=70;j++){
		if (pr[j]==0)
			primes.push_back(j);
	}

	//cout<<primes.size()<<endl;

	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>ar[i];
//		ar[i]=i;
	//	int here=get_mask(ar[i]);
//		Q.insert(here);
		cnt[ar[i]]++;
	}

//	cout<<Q.size()<<endl;

	for (int i=1;i<=70;i++){
		for (int j=0;j<=cnt[i];j++){
			W[i][j%2]+=C(cnt[i],j);
			W[i][j%2]%=bs;
		}
	}

	dp[0][0]=1;
	for (int i=1;i<=70;i++){
		for (int j=0;j<(1<<19);j++){
			dp[i%2][j]=0;
		}
		int my_mask=get_mask(i);
		for (int old_mask=0;old_mask<(1<<19);old_mask++){
			for (int take=0;take<=1;take++){
				dp[i%2][old_mask^(my_mask*take)]=(dp[i%2][old_mask^(my_mask*take)]+
						1ll*dp[1-i%2][old_mask]*W[i][take])%bs;
			}
		}
	}

	cout<<(dp[0][0]+bs-1)%bs<<endl;

//	cin.get(); cin.get();
	return 0;
}