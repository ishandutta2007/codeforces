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

#define bs 998244353

const int N = 600031;

vector<vector<long long> > mult(vector<vector<long long> > a,vector<vector<long long> > b){
	vector<vector<long long> > ret;
	ret.resize(a.size());
	for (int i=0;i<ret.size();i++){
		ret[i].resize(a.size());
		for (int j=0;j<ret[i].size();j++){
			ret[i][j]=0;
		}
	}

	for (int i=0;i<a.size();i++){
		for (int j=0;j<a.size();j++){
			for (int k=0;k<a.size();k++){
				ret[i][j]+=a[i][k]*b[k][j];
				ret[i][j]%=bs;
			}
		}
	}
	return ret;
}

vector<vector<long long> > one(){
	vector<vector<long long>  >ret;
	ret.resize(2);
	for (int i=0;i<2;i++){
		ret[i].resize(2);
		for (int j=0;j<2;j++){
			ret[i][j]=(i==j);
		}
	}
	return ret;
}

vector<vector<long long> > pw(vector<vector<long long> > a,long long b){
	if (b==0)
		return one();
	if (b%2)
		return mult(a,pw(a,b-1));
	return pw(mult(a,a),b/2);
}

long long PW(long long a,long long b){
	if (b==0)
		return 1;
	if (b%2)
		return a*PW(a,b-1)%bs;
	return PW(a*a%bs,b/2);
}

long long n,m,L,R;

long long count_even(long long x){
	return x/2;
}

long long count_odd(long long x){
	return x-count_even(x);
}

int main() {
  //   freopen("input.txt", "r", stdin);
  //   freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>n>>m>>L>>R;

  if (1ll*n*m%2==1){
	  cout<<PW(R-L+1,n*m)<<endl;
	  return 0;
  }

  vector<vector<long long> > dp;
  dp.resize(2);
  dp[0].resize(2);
  dp[1].resize(2);
  dp[0][0]=dp[1][1]=count_even(R)-count_even(L-1);
  dp[0][1]=dp[1][0]=count_odd(R)-count_odd(L-1);

  dp=pw(dp,n*m);

  cout<<dp[0][0]<<endl;

  //    cin.get(); cin.get();
  return 0;
}