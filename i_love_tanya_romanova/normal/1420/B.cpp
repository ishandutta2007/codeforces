/*
I can't do what you do
I'm just able to tear it down yeah
Stay in a cold minute of sleep
See the world
Right through the ether

Twisting names inside of me
Electric atmosphere to be
Must carry on one last time
Cannot end what has begun

In your eyes
You're alive
But in my eyes
You're a lie

You can't do what i do
I'm just able to ruin you yeah
Stay in the cold ways of winter
See myself right through the ether

In my eyes
You're the lie
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

#define bs 1000000007

const int N = 200031;

int tests,n;
long long ar[N],cnt[N];

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n;
    	for (int i=0;i<=30;i++){
    		cnt[i]=0;
    	}
    	for (int i=1;i<=n;i++){
    		cin>>ar[i];
    		int ps=30;
    		while (!(ar[i]&(1<<ps)))
    			--ps;
    		cnt[ps]++;
    	}
    	long long ans=0;
    	for (int i=0;i<=30;i++){
    		ans+=1ll*cnt[i]*(cnt[i]-1)/2;
    	}
    	cout<<ans<<endl;

    }
    //cin.get(); cin.get();
    return 0;
}