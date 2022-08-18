/*
Alone I sit, I wonder why
You dream of love and so do I
But in your sleep you cannot see
This pain which is always haunting me
What I need I'll never feel
This world is for me unreal
So I drink to darkness with a candle lit
And through the whole night alone I sit

The sleeping beauty
She stops the bleeding
She stops the bleeding in my soul
She is fresh air in this stinking world

The more I drink, the more I see
That suicide could be the key
To the place called paradise
Where pain not dwells, not hate nor lies
But if I look beyond all this
I reckon something I would surely miss
Because in my dreams I rule my life
And the sleeping beauty is my wife

The sleeping beauty
She stops the bleeding
She stops the bleeding in my soul
She is fresh air in this stinking world
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

int tests,n,ar[N];
vector<vector<int> > V;
vector<int> temp;

int sgn(int x){
	if (x<0)
		return -1;
	if (x>0)
		return 1;
	return 0;
}

int get_max(vector<int> v){
	int ret=v[0];
	for (int i=1;i<v.size();i++){
		ret=max(ret,v[i]);
	}
	return ret;
}

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>tests;
  for (;tests;--tests){
	  cin>>n;
	  for (int i=1;i<=n;i++){
		  cin>>ar[i];
	  }
	  V.clear();
	  temp.clear();
	  for (int i=1;i<=n;i++){
		  if (i>1&&sgn(ar[i])!=sgn(ar[i-1])){
			  V.push_back(temp);
			  temp.clear();
		  }
		  temp.push_back(ar[i]);
	  }
	  V.push_back(temp);
	  long long ans=0;
	  for (int i=0;i<V.size();i++){
		  ans+=get_max(V[i]);
	  }
	  cout<<ans<<endl;
  }
  // cin.get(); cin.get();
  return 0;
}