/*
One more breath
is one too many
Wither away soon to die
Nothing left of this badly
burned shell
Relinquish my breathing

Feeling so cold
The silence is deafening
Feeling so cold
In this Elysium dream

Covered in dirt
Vision dissipates
The blackness
helps to forget
The sweet aroma of death
Is in the air
Smile as the casket closes

Life is a pale shade of gray
Choking the life out of me
Pointless existence
We've fucked up
My feelings are dead
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

int n,k;
vector<int> g[N];
int used[N];
vector<int> benefits;
int subsize[N];
int dep[N];

void dfs(int v){
	used[v]=1;
	subsize[v]=1;
	for (int i=0;i<g[v].size();i++){
		int to=g[v][i];
		if (used[to])
			continue;
		dep[to]=dep[v]+1;
		dfs(to);
		subsize[v]+=subsize[to];
	}
}

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>n>>k;
  k=n-k;

  for (int i=1;i<n;i++){
	  int a,b;
	  cin>>a>>b;
	  g[a].push_back(b);
	  g[b].push_back(a);
  }

  dfs(1);

  for (int i=1;i<=n;i++){
	  benefits.push_back(subsize[i]-dep[i]-1);
  }
  sort(benefits.begin(),benefits.end());
  reverse(benefits.begin(),benefits.end());

  long long ans=0;
  for (int i=0;i<k;i++){
	  ans+=benefits[i];
  }
  cout<<ans<<endl;


  // cin.get(); cin.get();
  return 0;
}