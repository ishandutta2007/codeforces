/*
Creepy crawl
On concrete and dust
Asphalt jungle
Piles of crust

Non sense thoughts
Inside the mind
What really means
What I want?

Open up your mind
And go your own way
Open up your mind
And go your own way
Open up your mind
And go your own way
Open up your mind
And go your own way

Straight old thoughts
To force you down
Raping rape
Breed apart

Open up your mind
And go your own way
Open up your mind
And go your own way
Open up your mind
And go your own way

Open up your mind
And go your own way
Open up your mind
And go your own way
Open up your mind
And go your own way
Open up your mind
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

const int N = 1200031;

int n,mex[N],cnt[N];
set<int> allowed,cur_mex_set;
set<int>::iterator it;
int ans[N];
int real_mex[N],shit;

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>n;
  for (int i=1;i<=n;i++){
	 cin>>mex[i];
	 cnt[mex[i]]++;
  }

  for (int i=0;i<=n;i++){
	  if (cnt[i]==0){
		  allowed.insert(i);
	  }
  }

  for (int i=1;i<=n;i++){
	  it=allowed.begin();
	  ans[i]=(*it);
	  allowed.erase(it);
	  cnt[mex[i]]--;
	  if (cnt[mex[i]]==0)
		  allowed.insert(mex[i]);
  }

  for (int i=0;i<=n;i++){
	  cur_mex_set.insert(i);
  }

  for (int i=1;i<=n;i++){
	  if (cur_mex_set.find(ans[i])!=cur_mex_set.end())
		  cur_mex_set.erase(ans[i]);
	  it=cur_mex_set.begin();
	  real_mex[i]=(*it);
  }

  for (int i=1;i<=n;i++){
	  //cout<<ans[i]<<" ";
	  if (mex[i]!=real_mex[i])
		  shit=1;
  }

  if (shit){
	  cout<<-1<<endl;
  }
  else{
	  for (int i=1;i<=n;i++){
		  if (i>1)
			  cout<<" ";
		  cout<<ans[i];
	  }
	  cout<<endl;
  }

  cin.get(); cin.get();
  return 0;
}