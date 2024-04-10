/*
Circle of hands
Cold spirits plan
Searching my land for an enemy
Came across love's sweet cost
And in the face of beauty
Evil was lost

Sky full of eyes, minds full of lies
Black from their cold hearts, down to their graves
Murdered the dawn, spreading their scorn
Cursing the sun of which love was born

We must keep them away
Or pretty soon we'll pay
And count the cost in sorrow
Sacrifice, the future has its price
And today is only yesterday's tomorrow

We must keep them away
Or pretty soon we'll pay
And count the cost in sorrow
Sacrifice, the future has its price
And today is only yesterday's tomorrow, tomorrow
Tomorrow, tomorrow
Tomorrow, tomorrow
Tomorrow, tomorrow
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

#define eps 1e-11
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

#define ldouble long double

using namespace std;

long long INF = 1e9;
const int N = 200031;

int n,tests;
long double dp[2050],ndp[2050];
long double memo[N];

int main(){
//	freopen("japanese.in","r",stdin);
//	freopen("japanese.out","w",stdout);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>tests;

	dp[0]=1.0;
	for (int i=0;i<=10000;i++)
	{
		for (int j=0;j<=n;j++)
		{
			ndp[j]=0;
		}
		for (int j=0;j<=n;j++)
		{
			double chance_same=j*1.0/n;
			double chance_new=1.0-chance_same;
			ndp[j+1]+=dp[j]*chance_new;
			ndp[j]+=dp[j]*chance_same;
		}
		for (int j=0;j<=n;j++)
		{
			dp[j]=ndp[j];
		}
		memo[i+1]=dp[n];
	//	cout<<i<<" "<<memo[i+1]<<endl;
	}

	for (;tests;--tests)
	{
		int val;
		cin>>val;
		int ans=0;
		while (memo[ans]<val*1.0/2000-eps)
			++ans;
		cout<<ans<<endl;
	}

	cin.get(); cin.get();
	return 0;
}