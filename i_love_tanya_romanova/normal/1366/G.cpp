/*
Spreading lies, spreading gossip
From your mouth, only garbage
Propaganda mind control
Your false world will crawl upon

Father of hate
Father of lies

Illusion master, lies spreader
Reality, for you don't matter
You feed on hate, you feed on lies
Your blank face, is your disguise

Father of hate
Father of lies

You are Salieri, against Mozart
From your envy, hatred grows
You're a thief, you're a robber
None of this, was ever yours

Father of hate
Father of lies

Traitor... Judas... Liar... Scum...
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

string st1,st2;
int bal[N];
map<int,int> M;
int nxt[N];
int dp[10031][10031];

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>st1>>st2;

  int total_dots=0;

  for (int i=1;i<=st1.size();i++){
	  if (st1[i-1]=='.')
		  bal[i]=bal[i-1]-1,
		  total_dots++;
	  else
		  bal[i]=bal[i-1]+1;
  }

  M[bal[st1.size()]]=st1.size();

  for (int i=st1.size()-1;i>=0;--i){
	  if (M.find(bal[i])==M.end())
		  nxt[i]=-1;
	  else
	  {
		  int ok=1;
		  nxt[i]=M[bal[i]];
		  for (int j=i;j<nxt[i];j++){
			  if (bal[j]<bal[i])
				  ok=0;
		  }
		  if (ok==0)
			  nxt[i]=-1;
	  }
	  M[bal[i]]=i;
  }

  for (int i=0;i<=st1.size();i++){
	  for (int j=0;j<=st2.size();j++){
		  dp[i][j]=1e9;
	  }
  }

 /* for (int i=0;i<st1.size();i++){
	  cout<<i<<" "<<nxt[i]<<endl;
  }
*/
  dp[0][0]=0;
  for (int i=0;i<=st1.size();i++){
	  for (int j=0;j<=st2.size();j++){
		  if (dp[i][j]>1e8)
			  continue;
		  // delete ith
		  if (i<st1.size()){
			  dp[i+1][j]=min(dp[i+1][j],dp[i][j]+(st1[i]=='.'));
		  }
		  // match them
		  if (i<st1.size()&&j<st2.size()&&st1[i]==st2[j])
			  dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]);
		  // make a hop
		  if (nxt[i]!=-1){
			  dp[nxt[i]][j]=min(dp[nxt[i]][j],dp[i][j]);
		  }
	  }
  }

  int diff=st1.size()-st2.size();
  int will_use_dots=total_dots-dp[st1.size()][st2.size()];
  int burn=diff-2*will_use_dots;

 // cout<<diff<<" "<<will_use_dots<<endl;

  cout<<burn<<endl;

  cin.get(); cin.get();
  return 0;
}