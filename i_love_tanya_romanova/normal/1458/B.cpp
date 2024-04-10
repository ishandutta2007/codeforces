/*
All your beliefs filled up with lies
Blinded from what you call prophets
Your Jihad's a joke, revenge is our fight
We'll crush the Al Quaeda to stop it

Drop the bombs in...
Drop the bombs in...
Wipe out your muthafucking schemes
Bring the troops in...
Bring the troops in...
Wipe out your minority

World has united to weed out the scum
Our people have all took a stand
We're tired of your bullshit, the actions of few
That threaten the future of man

Drop the bombs in...
Drop the bombs in...
Wipe out your muthafucking schemes
Dig the roots out...
Dig the roots out...
Your holy war is nothing to be proud

A call to arms
This call for pride
You can never take from what we feel inside
All our strength
Is in our hearts
This is our call to arms...
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

int n,a[131],b[131];
int dp[3][131][13131];
int sum_of_b;
double ans[131];

int main() {
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    // cin.tie(0);

    cin>>n;
    for (int i=1;i<=n;i++){
    	cin>>a[i]>>b[i];
    	sum_of_b+=b[i];
    }

    for (int ps=0;ps<=n;ps++){
    	for (int cnt=0;cnt<=n;cnt++){
    		for (int total_w=0;total_w<=10000;total_w++){
    			dp[ps%2][cnt][total_w]=-1e9;
    		}
    	}
    }
    dp[0][0][0]=0;
    for (int i=1;i<=n;i++){

    	for (int cnt=0;cnt<=n;cnt++){
    		for (int total_w=0;total_w<=10000;total_w++){
    			dp[i%2][cnt][total_w]=-1e9;
    		}
    	}

    	for (int cnt=0;cnt<=n;cnt++){
    		for (int total_w=0;total_w<=10000;total_w++){
    			if (dp[1-i%2][cnt][total_w]<0)
    				continue;
    			dp[i%2][cnt][total_w]=max(dp[i%2][cnt][total_w],dp[1-i%2][cnt][total_w]);
    			dp[i%2][cnt+1][total_w+a[i]]=max(dp[i%2][cnt+1][total_w+a[i]],dp[1-i%2][cnt][total_w]+b[i]);
    		}
    	}
    }

    for (int i=1;i<=n;i++){
    	ans[i]=0;
    	for (int j=0;j<=10000;j++){
    		if (dp[n%2][i][j]<0)
    			continue;
    		double here_already=dp[n%2][i][j];
    		double outside=sum_of_b-here_already;
    		double best_ans=here_already+outside/2;
    		best_ans=min(best_ans,j+.0);
    		ans[i]=max(ans[i],best_ans);
    	}
    	cout.precision(12);
    	if (i>1)
    		cout<<" ";
    	cout<<fixed<<ans[i];
    }
    cout<<endl;

    //cin.get(); cin.get();
    return 0;
}