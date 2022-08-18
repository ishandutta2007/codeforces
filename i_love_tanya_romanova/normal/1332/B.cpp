/*
Wings of fire burn the night
Slumbering eyes their flares shall greet
Let the past cling on its futile self
And may the present rush for the future's glare

Grave to cradle
Cradle to grave
So infinity clash
Grave to cradle

Cradle to grave
In twofold matter

Two forces gone full circle
Never shall one of the other grow fond
Join me, the time is upon us
He spoke and in fury we flew

Far beyond the limits of time
Disown the borders of life itself
Crafted and moulded all in one form
Split up and scattered in the world that we own

Grow towards me
Beknight the strength of the symbiosis
Backwards striving
Counterparts with different eyes have observed
Of time unconditional

Grave to cradle
Cradle to grave
So infinity clash
Grave to cradle
Cradle to grave
In twofold matter

Tell of days to come
Tomorrow remembered
Your yesterday, my future

Recollection of the day
Delusions cast where dead trees sway

The sabre that separates
Is the candle that burns both ends

Born from death you now confront me
Back to death with my life I take you
Die more with each movement of mine
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

const int N = 600031;

int pr[1000];
vector<int> primes;
int used[N];
int tests,n,ar[N];
int maps[N];
int V[N];

int main() {
  //   freopen("input.txt", "r", stdin);
  //   freopen("output.txt", "w", sttextdout);
  //ios_base::sync_with_stdio(0);
  // cin.tie(0);

	pr[1]=1;
	for (int i=1;i<=40;i++){
		if (pr[i])
			continue;
		for (int j=i*2;j<=40;j+=i)
			pr[j]=1;
	}

	for (int i=2;i<=31;i++){
		if (pr[i])
			continue;
		primes.push_back(i);
	}

	cin>>tests;
	for (;tests;--tests){
		cin>>n;
		for (int i=1;i<=n;i++){
			cin>>ar[i];
		}
		for (int i=0;i<primes.size();i++){
			used[i]=0;
		}
		for (int i=1;i<=n;i++){
			for (int j=0;j<primes.size();j++){
				if (ar[i]%primes[j]==0){
					used[j]=1;
					V[i]=j;
					break;
				}
			}
		}
		int cnt=0;
		for (int i=0;i<primes.size();i++){
			if (used[i])
			{
				cnt++;
				maps[i]=cnt;
			}
		}

		cout<<cnt<<endl;
		for (int i=1;i<=n;i++){
			if (i>1)
				cout<<" ";
			cout<<maps[V[i]];
		}
		cout<<endl;
	}

  //    cin.get(); cin.get();
  return 0;
}