/*
Suit up for destruction
Death looks behind many faces
Hatred plants its deepest seed
In the most obvious places

Symbols of allegiance
Chaos spells devotion
Evil is their sanction
The master plan is set in motion

Oh yeah!

What the hell are you proud of?
Heads held low
Self-respect must be earned

[Chorus:]
Evil poisons taste just like wine
Swallow the lies until you are blind
And you're going blind

Now let it flow...

Waiting to deliver
Imposing martial laws of pain
KKK or CIA
They are one and all the same

What the hell are you proud of?
Heads held low
Self-respect must be earned

[Chorus]

Evil poisons taste just like wine
Swallow the lies until you are blind
And you're going blind

Can't get to me or abuse me
Your racist tears will amuse me
And then you'll bleed...

Now let it flow...

Charismatic leaders
Preach their sermons of ignorance
Please take heed soon my friends
Promises won't cleanse the sins

Oh yeah!

What the hell are you proud of?
Heads held low
Self-respect must be earned

[Chorus]

Now let it flow...
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

#define bs 1000000007

const int N = 200031;

int tests,n;
string st;
int cnt[N][28];
int ans[N][27];
int done[N][27];

int C;
int solve(int l,int r,int dep){
	//cout<<l<<"@"<<r<<" "<<dep<<endl;
	if (done[l][dep]==C)
		return ans[l][dep];
	if (l==r)
		return (st[l-1]!=dep+'a');
	int var1=0;
	int var2=0;
	done[l][dep]=C;
	int len=(r-l+1)/2;
	var1+=len-(cnt[l+len-1][dep]-cnt[l-1][dep]);
	var2+=len-(cnt[l+2*len-1][dep]-cnt[l+len-1][dep]);
	var1+=solve(l+len,r,dep+1);
//	cout<<var2<<"@"<<endl;
	var2+=solve(l,r-len,dep+1);
	ans[l][dep]=min(var1,var2);
	return ans[l][dep];
}

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>tests;
  for (;tests;--tests){
	  cin>>n;
	  cin>>st;
	  ++C;
	  for (int i=1;i<=st.size();i++){
		  for (int j=0;j<26;j++){
			  cnt[i][j]=cnt[i-1][j];
			  if (st[i-1]==j+'a')
				  cnt[i][j]++;
		  }
	  }
	  cout<<solve(1,n,0)<<endl;
  }

  cin.get(); cin.get();
  return 0;
}