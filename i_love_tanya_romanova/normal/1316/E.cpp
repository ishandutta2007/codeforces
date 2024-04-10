/*
One time is all it takes to want me
One time is all it takes to think you're the only
One might believe that I might care
One night is all I need to make you disappear

I always hate the way you love me
I always seem to love what never can be mine
I need to hurt myself so I can feel
Something just one time

I'll pull you in and keep you closely
Then spit you out and make you feel like you owe me
Your heart I'll use to heal my pain
So hard for me to feel like anything or any way

I always hate the way you love me
I always seem to love what never can be mine
I need to hurt myself so I can feel
Something just one time

I always hate the way you love me
I always seem to love what never can be mine
I need to hurt myself so I can feel
I always curse myself when something's real
I need to hurt myself so I can feel
Something just one time
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
#define left asdgashgrketwjklrej
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

const int N = 200031;

int n,p,k;
vector<pair<int,int> > order;
long long cost[N][9];
long long dp[4][1<<10];
int pcount[N];

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    for (int i=1;i<N;i++){
    	pcount[i]=pcount[i/2]+i%2;
    }

    cin>>n>>p>>k;

    for (int i=1;i<=n;i++){
    	cin>>cost[i][0];
    	order.push_back(make_pair(cost[i][0],i));
    }

    sort(order.begin(),order.end());
    reverse(order.begin(),order.end());

    for (int i=1;i<=n;i++){
    	for (int j=1;j<=p;j++){
    		cin>>cost[i][j];
    	}
    }

    for (int i=0;i<(1<<p);i++){
    	dp[0][i]=-1;
    }
    dp[0][0]=0;

    for (int i=0;i<order.size();i++){
    	for (int j=0;j<(1<<p);j++){
    		dp[1-i%2][j]=-1;
    	}
    	for (int mask=0;mask<(1<<p);mask++){
    		if (dp[i%2][mask]<0)
    			continue;
    		for (int ad=0;ad<=p;ad++){
    			if (ad==0){
    				long long new_dp=dp[i%2][mask];
    				int used_k=i-pcount[mask];
    				if (used_k<k)
    					new_dp+=order[i].first;
    				dp[1-i%2][mask]=max(dp[1-i%2][mask],new_dp);
    				continue;
    			}
    			int id=order[i].second;
    			long long cost_to_get=cost[id][ad];
    			if (mask&(1<<(ad-1)))
    				continue;
    			dp[1-i%2][mask|(1<<(ad-1))]=max(dp[1-i%2][mask|(1<<(ad-1))],dp[i%2][mask]+cost_to_get);
    		}
    	}
    }

    cout<<dp[order.size()%2][(1<<p)-1];

    //    cin.get(); cin.get();
    return 0;
}