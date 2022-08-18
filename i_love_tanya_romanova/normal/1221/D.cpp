/*
A gift of life born in a grave
Never to die
A soul that will never be saved
That will never see light
While the world is sleeping
We all fly
In the daylight silence keeping
We wait for the night
When the day ends life begins
When the shadows take light
For hundreds of years
We are your fears
We never will die
When the light goes away
We come out to play
Innocence lost and a demon within
Forgive me father, yes i have sinned
I will never be holy
I will never be saved
This was the gift on the day
I was born in a grave
Basking in the moonlight
Wolves will howl
And the bats will fly
You never knew
We were watching
Lifeless inside
For the blood is the life
The gift of the night
That has kept us alive
For thousands of years
We lived in your tears
And we never will die
When the light goes away
We come out to play
Innocence lost and a demon within
Forgive me father yes i have sinned
I will never be holy
I will never be saved
This was my gift on the day
I was born in a grave
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

#define eps 1e-9
#define M_PI 3.141592653589793
#define bsize 1024

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 400031;

int tests,n;
long long a[N],b[N],dp[N][5];

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
 //   cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n;
    	for (int i=1;i<=n;i++){
    		cin>>a[i]>>b[i];
    	}
    	for (int i=0;i<=n;i++){
    		for (int j=0;j<=2;j++){
    			dp[i][j]=1e18;
    		}
    	}
    	dp[0][0]=0;
    	for (int i=1;i<=n;i++){
    		for (int j=0;j<=2;j++){
    			for (int q=0;q<=2;q++){
    				long long a1=a[i-1]+q;
    				long long a2=a[i]+j;
    				if (a1==a2)
    					continue;
    				long long here=dp[i-1][q]+b[i]*j;
    				dp[i][j]=min(dp[i][j],here);
    			}
    		}
    	}
    	long long ret=2e18;
    	for (int i=0;i<=2;i++){
    		ret=min(ret,dp[n][i]);
    	}
    	cout<<ret<<endl;

    }
//    cin.get(); cin.get();
    return 0;
}