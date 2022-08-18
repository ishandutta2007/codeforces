/*
She came home last night
rotten rolling drunk
She talk no sense but she sound good
so she think
So I reached over and said Hello
Is there some planet you'd care to go
And she said Venus on the rocks

She got a mean streak
Black Mamba don't compete
She got a mean streak
Temptation bitter sweet

She drives me crazy gets inside my brain
She spend my money down a drain
So I roll over for my reward
How much can I afford
And she says
Just a little more

I can't take this no more
I tried so hard but I can't get thru' the
door
Because one smile from those eyes
And I stand there paralysed
And she says
Beg for more get down sucka you know
what I like
oh hang on
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

#define eps 1e-12
#define M_PI 3.141592653589793
#define bsize 300

#define ldouble long double
using namespace std;

#define bs 998244353

const int N = 200031;

int n,m,k;

long long dp[2031][2031];

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>n>>m>>k;
    dp[1][0]=m;
    for (int i=1;i<n;i++){
    	for (int j=0;j<=k;j++){
    		dp[i+1][j]+=dp[i][j];
    		dp[i+1][j+1]+=dp[i][j]*(m-1);
    		dp[i+1][j]%=bs;
    		dp[i+1][j+1]%=bs;
    	}
    }

    cout<<dp[n][k]%bs<<endl;

//    cin.get(); cin.get();
    return 0;
}