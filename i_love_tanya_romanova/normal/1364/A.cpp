/*
The pest in the eyes of death follows us
Through the dirty streets of blood
It begins to eat inside us, decaying our bones
How will we escape if the void covers our lungs?
We are buried in the spewed trash for ourselves

Blood, pain - nothing to say
Why then - must we die?

Escape to the void
Escape to the void

I look at my face on the other side of the mirror
My face falls down in pieces full of worms
I burst my rotten heart with my own hands
I'm dying and I can't help myself

Blood, pain - nothing to say
Why then - must we die?

What have I been running from?
I'm not guilty
You've shown me the worst way
Cause you're my victim... the next one

The pest in the eyes of death follows us
Through the dirty streets of blood
It begins to eat inside us, decaying our bones
How will we escape if the void covers our lungs?
We are buried in the spewed trash for ourselves

Blood, pain - nothing to say
Why then - must we die?

Escape to the void
Escape to the void
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

map<int,int> mapp;
int n,x;
vector<pair<int,int> > order;
int tests;
int s[N];
int ar[N];
int ans;

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>tests;
  for (;tests;--tests){
	  cin>>n>>x;
	  order.clear();
	  mapp.clear();
	  for (int i=0;i<n;i++){
		  cin>>ar[i];
		  s[i+1]=s[i]+ar[i];
		  s[i+1]%=x;
	  }
	  for (int i=0;i<=n;i++){
		  if (mapp.find(s[i])==mapp.end()){
			  mapp[s[i]]=i;
			  order.push_back(make_pair(i,s[i]));
		  }
	  }

	  sort(order.begin(),order.end());
	  ans=-1;
	  for (int i=0;i<=n;i++){
		  for (int j=0;j<=2&&j<order.size();j++){
			  int rem=order[j].second;
			  if (rem==s[i])
				  continue;
			  ans=max(ans,abs(i-order[j].first));
		  }
	  }
	  cout<<ans<<endl;
  }
  cin.get(); cin.get();
  return 0;
}