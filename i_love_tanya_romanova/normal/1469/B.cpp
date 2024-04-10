/*
We spend a lifetime
In death we trade
Until it's over manipulate the ones who stay

Guarded and secret
Stalking a world in which I'm new
Sorely deceitful
In all that is so abused

For the universal dream, born to understand
For the universal need, born to understand

Repenting lifestyles
In death we train
Until it's over
Eliminate the ones who stay

Guarded and secret
Another world in which I grew
Sorely deceitful
In all that is so abused

For the universal dream, born to understand
For the universal need, born to understand

Manipulate the ones who say
Save me
Manipulate the ones who stay
Incriminate me
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

const int N = 600031;

int tests,n,ar[N],p1[N],p2[N];
int m,ans;

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>tests;
    for (;tests;--tests){
    	cin>>n;
    	for (int i=1;i<=n;i++){
    		cin>>ar[i];
    		p1[i]=p1[i-1]+ar[i];
    	}
    	cin>>m;
    	for (int i=1;i<=m;i++){
    		cin>>ar[i];
    		p2[i]=p2[i-1]+ar[i];
    	}
    	ans=0;
    	for (int i=0;i<=n;i++){
    		for (int j=0;j<=m;j++){
    			ans=max(ans,p1[i]+p2[j]);
    		}
    	}
    	cout<<ans<<endl;
    }
    //cin.get(); cin.get();
    return 0;
}