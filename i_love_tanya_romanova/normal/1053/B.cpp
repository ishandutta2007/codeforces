/*
Passion stains the godless taste
The human eye now raped and dazed
Our marks of shame soon worn away
The spider's trapped in a web of clay

Naked in the desert of delight
Banish the throughts into the night
Scarecrow servant of demise
Parting the honey from the flies

What's in the veins is what to keep
Still the floods of raptures sound asleep
Visions fade and die at ease
Inferior slaves are ours to please

The last of shadows shapes the end
From mountains high it all descends
One single dagger unleash the doom
Creation falls in my closed room
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

#define bs 1000000007

const int N = 600000;

int n;
long long ar[N];
int S[N],parity[N];
int with_parity[N];

long long ans;

int cnt(long long x){
	if (x==0)
		return 0;
	return cnt(x/2)+x%2;
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;
	parity[0]=0;
	for (int i=1;i<=n;i++){
		cin>>ar[i];
		ar[i]=cnt(ar[i]);
		S[i]=S[i-1]+ar[i];
		parity[i]=S[i]%2;
	}

	// long -> >=150
	for (int i=1;i<=n;i++){
		if (i-150>=0)
			with_parity[parity[i-150]]++;
		ans+=with_parity[parity[i]];
	}

	// short -> <150
	for (int i=1;i<=n;i++){
		long long mx=0;
		int ttl=0;
		for (int j=i;j<i+149&&j<=n;j++){
			mx=max(mx,ar[j]);
			ttl+=ar[j];
			if (ttl%2==0&&mx<=ttl-mx)
				ans++;
		}
	}

	cout<<ans<<endl;

//	cin.get(); cin.get();
	return 0;
}