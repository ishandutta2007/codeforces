/*
As through your shattered eyes
It all came together
And your heart cries
Weeping through the weather
Another way to change your mind
I'm weaker than they say
To leave this all behind
The only way to stay

Don't you know
I'm the end of what we'll be
And right below us
The last thing you'll see

In the water
I saw you drown
Down the water
Saw you drown

As through my shattered sight
You're no longer here
And my heart cries
Sleeping through the light
Another way to change my mind
Never is the day
To leave this all behind
The only way to stay
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

const int N = 300031;

int tests,n,q,ar[N];
long long dp[N][3];

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n>>q;
    	for (int i=1;i<=n;i++){
    		cin>>ar[i];
    	}
    	for (int i=1;i<=n;i++){
    		dp[i][0]=dp[i][1]=-1e18;
    	}
    	dp[0][1]=0;

    	for (int i=1;i<=n;i++){
    		dp[i][0]=max(dp[i][0],dp[i-1][0]);
    		dp[i][1]=max(dp[i][1],dp[i-1][1]);
    		dp[i][0]=max(dp[i][0],dp[i-1][1]+ar[i]);
    		dp[i][1]=max(dp[i][1],dp[i-1][0]-ar[i]);
    	}
    	cout<<max(dp[n][0],dp[n][1])<<endl;
    }
    //cin.get(); cin.get();
    return 0;
}