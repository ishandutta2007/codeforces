/*
Strangelove
Dance the dividing line

We shall burn the earth
We shall burn our lives

For the tallest tree shall battle most
The wind it leaves the week behind
The storm that you've denied me
Shall force your world to fall
Your castles made to tremble
With foundations based upon a lie

The storm that you've denied me
Sweep the undivided truth
His mind shall not of thoughts be tempted
Nor words can heal his bleeding scars

We must burn our minds

Colours collide with the world of his beliefs
Bring back the storm of distant years
Tumbling, trembling as there is no waking up
There is no dividing line as logic now fails

Stream upwards, rage against them all
Speak of words hidden in your song
Mere mortals strive for length in numbers
There is no dividing line

As the writer defies the empty page
The empty mind its feed shall seek

Pass on to the frail and mindless
Now what sanity discards

The storm shall sweep the weak of heart
And tear your castles down
Crush the very foundations
On which your faith is based
Torn across the dividing line
*/

//#pragma GCC optimize("O3")
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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 400031;

int l,r,a[N],b[N],dp[N];
vector<int> good,bad;
int n;
int S[N];

bool cmp(int id1,int id2){
	if (a[id1]!=a[id2])
		return a[id1]<a[id2];
	return id1<id2;
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n>>l>>r;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=1;i<=n;i++){
		cin>>b[i];
		if (b[i]==0)
			bad.push_back(i);
		else
			good.push_back(i);
	}

	for (int i=0;i<=10000;i++){
		dp[i]=1e9;
	}

	dp[0]=0;
	for (int i=0;i<bad.size();i++){
		int id=bad[i];
		for (int j=10000;j>=0;--j)
				dp[j+a[id]]=min(dp[j+a[id]],dp[j]);
	}

	sort(good.begin(),good.end(),cmp);

	int ans=0;

	for(int i=0;i<good.size();i++){
		S[i+1]=S[i]+a[good[i]];
	}

	for (int i=(int)good.size()-1;i>=0;--i){
		int ptr=i+1;
		for (int j=l;j<=r;j++){
			if (dp[j]<1e7)
			{
				int rem=r-j;
				while (S[ptr]>rem)
					--ptr;
				int can_take=ptr;
				if (ptr<=i||dp[j]<good.size()-i-1)
					++can_take;
				ans=max(ans,can_take);
			}
		}
		for (int j=10000;j>=0;--j){
			dp[j+a[good[i]]]=min(dp[j+a[good[i]]],dp[j]+1);
		}
	}

	for (int i=0;i<=10000;i++){
		dp[i]=1e9;
	}
	dp[0]=0;
	for (int i=1;i<=n;i++){
		for (int j=10000;j>=0;--j)
			dp[j+a[i]]=min(dp[j+a[i]],dp[j]+b[i]);
	}

	for (int i=l;i<=r;i++){
		if (dp[i]<good.size())
			ans=max(ans,1);
	}

	cout<<ans<<endl;

//	cin.get(); cin.get();
	return 0;
}