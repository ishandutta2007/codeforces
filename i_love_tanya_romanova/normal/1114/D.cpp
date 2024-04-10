/*
When the darkness takes from me
Cruel hands are scorned
How our light dims carelessly
Bringing bare minds torn

Come with me
When the darkness comes
We all must leave
When the darkness comes

Sifting through my memories
Lifting spirits once more
Ones we lose forever breathe
Through the past reborn

Come with me
When the darkness comes
We all must leave
When the darkness comes

Wasted seasons surround us
Take not for granted your time
Such a thing waits for no man
Stone gardens stand before us
Lifelong the memoirs always rhyme
Try to live before one dies

Come with me
When the darkness comes
We all must leave
When the darkness comes
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

#define bs 1000000007

const int N = 200031;

int n,ar[5031];
int dp[5031][6031];
vector<int> order;

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin>>n;
    for (int i=1;i<=n;i++){
    	cin>>ar[i];
    }

    for (int i=1;i<=n;i++){
    	if (i==1||ar[i]!=ar[i-1])
    		order.push_back(ar[i]);
    }

    for (int r=0;r<order.size();r++){
    	for (int l=r;l>=0;--l){
    		dp[l][r]=1e9;
    		if (l==r){
    			dp[l][r]=0;
    			continue;
    		}
    		dp[l][r]=min(dp[l+1][r],dp[l][r-1])+1;
    		if (order[l]==order[r]&&l+1<r)
    			dp[l][r]=min(dp[l][r],dp[l+1][r-1]+1);
    	}
    }

    cout<<dp[0][order.size()-1]<<endl;

//    cin.get(); cin.get();
    return 0;
}