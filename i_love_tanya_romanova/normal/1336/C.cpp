/*
Searching for absolution
Nailed to your cross of self redemption

Your salvation has long time past
Holding onto the curse thats your fate

Try to tear these walls down
But I will not take the fall

First in line
Cleanse your sins cast away anxieties
Today the suffering is done

Your dream is dead
The end has just begun

Try to tear these walls down
But I will not take the fall

Forget this life and what you once knew
Forget this suffering and what is eternal
Forget this life and all that you know
Forget youre sins and what is eternal

Try to tear these walls down
But I will not take the fall
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

const int N = 200031;

string st,Z;
long long dp[3031][3031];

bool is_ok(int ps_st,int ps_Z){
	if (ps_Z>=Z.size())
		return true;
	return st[ps_st]==Z[ps_Z];
}

long long ans;

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>st;
  cin>>Z;

  for (int i=0;i<st.size();i++){
	  if (i<Z.size())
		  dp[i][i]=(st[0]==Z[i]);
	  else
		  dp[i][i]=1;
  }

  for (int i=1;i<st.size();i++){
	  for (int l=0;l<st.size();l++){
		  int r=l+i-1;
		  if (r>=st.size())
			  continue;
		  // put on left
		  if (l>0&&is_ok(i,l-1)){
			  dp[l-1][r]+=dp[l][r];
			  dp[l-1][r]%=bs;
		  }
		  if (r+1<st.size()&&is_ok(i,r+1))
		  {
			  dp[l][r+1]+=dp[l][r];
			  dp[l][r+1]%=bs;
		  }
	  }
  }

 /* for (int i=0;i<st.size();i++){
	  for (int j=0;j<st.size();j++){
		  cout<<dp[i][j]<<" ";
	  }
	  cout<<endl;
  }*/

  for (int i=Z.size()-1;i<st.size();i++){
	  ans=(ans+dp[0][i])%bs;
  }
  cout<<ans*2%bs<<endl;

  // cin.get(); cin.get();
  return 0;
}