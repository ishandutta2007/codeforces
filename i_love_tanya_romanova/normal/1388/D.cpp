/*
I had your back, but it's no use
False accusations are on the loose
You know what? It makes no sense that you tied your own noose
You never felt the sores decay
Your perfect world is ending today
So what? I wouldn't have it any other way

Is this your paradise? You think you thought this through?
'Cause when you rolled the dice, the house came down on you
Don't care what you do or say, your suicide begins today
Have fun in paradise, this hell is just for you

You against you
Shitty time to make a stand all without a master plan, just you
You against you

So how's your paradise? Hindsight just laughs at you
With conflict comes a price, that price weighs heaviest on you
I guess I should say thanks, dissension in the ranks
Your panic lit the fuel, now it's you against you
You against you

Wasnt looking for a fight, but I'm showing up tonight
Shitty time to make a stand all without a master plan, just you
You against you

These seeds are what you've sown
Never should have lit that fuse
Enjoy your paradise
This hell is just for you

You against you
Wasnt looking for a fight, but I'm showing up tonight
Shitty time to make a stand all without a master plan, just you
You against you
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

int n;
long long a[N],b[N];
vector<int> roots;
long long ans;
vector<int> g[N];
vector<int> pos,neg;

void solve(int v){
	for (int i=0;i<g[v].size();i++){
		int to=g[v][i];
		solve(to);
		if (a[to]>0)
			a[v]+=a[to];
	}
	if (a[v]>0)
		pos.push_back(v);
	else
		neg.push_back(v);
	ans+=a[v];

}

int main() {
   //freopen("input.txt", "r", stdin);
   //freopen("output.txt", "w", stdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>n;
  for (int i=1;i<=n;i++){
	  cin>>a[i];
  }
  for (int i=1;i<=n;i++){
	  cin>>b[i];
	  if (b[i]==-1){
		  roots.push_back(i);
	  }
	  else
	  {
		  g[b[i]].push_back(i);
	  }
  }

  for (int i=0;i<roots.size();i++){
	  solve(roots[i]);
  }

  cout<<ans<<endl;

  reverse(neg.begin(),neg.end());
  for (int i=0;i<neg.size();i++){
	  pos.push_back(neg[i]);
  }

  for (int i=0;i<pos.size();i++){
	  if (i)
		  cout<<" ";
	  cout<<pos[i];
  }
  cout<<endl;

  cin.get(); cin.get();
  return 0;
}