/*
Carry our streams
Lift up our less than elated lives
Transmit our selves
We breathe out
Where no one
Take in all the dark light
Turn the nighttime into day
Take in all the dark light
Turn the nighttime into day

Cathode ray sunshine
Speak out and we receive
Cathode ray sunshine
Show me and let us in

Uh-oh!

Alienate
Block out all
Amid the breaking of the light
See it again and again
Single sight

Sensory perception
Turn the nighttime into day
Sensory perception
Turn the nighttime into day

Cathode ray sunshine
Speak out and we receive
Cathode ray sunshine
Show me and let us in

Cathode ray sunshine
Speak out and we receive
Cathode ray sunshine
Show me and let us in

To our great distrust
Escapism a means of getting through alive
Take it in and spit it out again
That measly filth

Focal degradation
Bring the chaos into light
Cathode ray Sunshine
Burn
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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 100031;

int n,m,ar[N];
int ans,ptr;
int money[N];

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n>>m;

	for (int i=1;i<=n;i++){
		cin>>ar[i];
	}
	for (int i=1;i<=m;i++){
		cin>>money[i];
	}
	int ptr=1;
	for (int i=1;i<=n;i++){
		if (ar[i]<=money[ptr]){
			++ans;
			++ptr;
		}
	}

	cout<<ans<<endl;

//	cin.get(); cin.get();
	return 0;
}