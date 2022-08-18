/*
We walk through the ages
The world on our shoulders
A burden we carry
To the dark end of our days
A thousand eyes watching
Every step we are taking
Waiting to see us
Struggle and fall

And when we are beaten
The cross holds us down
I hear them laughing
And walking away

Carry the cross
And suffer the loss
Hear my confession
Forever damnation

Reincarnation
Bleeding forever
Recover in pain
Pain gives me strength
Pick up the cross
And carry it on
Over and over
The wheel turns again

And when we are beaten
The cross holds us down
I hear them laughing
And walking away

Carry the cross
And suffer the loss
Hear my confession
Forever damnation
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

#define bs 1020202009

const int N = 100031;

int tests,n;
string st;
int cnt[N];
int k;
int val[N],used[N];
char ans[N];
int cnt_used;

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>tests;
  for (;tests;--tests){
	  cin>>st;
	  n=st.size();
	  for (int i='a';i<='z';i++){
		  cnt[i]=0;
	  }
	  for (int i=0;i<st.size();i++){
		  cnt[st[i]]++;
	  }

	  cin>>k;
	  for (int i=1;i<=k;i++){
		  cin>>val[i];
	  }

	  for (int i=1;i<=k;i++){
		  used[i]=0;
	  }

	  cnt_used=0;

	  int ptr='z';

	  while (cnt_used<k){
		  vector<int> candidates;
		  for (int i=1;i<=k;i++){
			  int ttl=0;
			  if (used[i])
				  continue;
			  for (int j=1;j<=k;j++){
				  if (used[j]==0)
					  continue;
				  ttl+=abs(j-i);
			  }
			  if (ttl==val[i]){
				  candidates.push_back(i);
			  }
		  }
		  while (cnt[ptr]<candidates.size()){
			  --ptr;
		  }
		 /* for (int i=0;i<candidates.size();i++){
			  cout<<candidates[i]<<" ";
		  }
		  cout<<endl;*/
		  for (int i=0;i<candidates.size();i++){
			  used[candidates[i]]=1;
			 // cout<<ptr<<"@@@"<<candidates[i]<<endl;
			  ans[candidates[i]]=ptr;
		  }
		  cnt_used+=candidates.size();
		  ptr--;
	  }
	  for (int i=1;i<=k;i++){
		  cout<<ans[i];
	  }
	  cout<<endl;

  }

  cin.get(); cin.get();
  return 0;
}