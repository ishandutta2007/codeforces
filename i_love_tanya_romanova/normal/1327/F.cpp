/*
Monsters, proudly displaying their deeds for the world to proscribe
Demons, walking the earth hell bent on their genocide
Complete destruction, blood lust seduction
Drinking warm blood with a smile
Beyond the horror, they're born to suffer
Hundreds of thousands defiled

Show no mercy, slow executions
Laugh while mutilating
God be damned, war is hell
God be damned

Dissected while still alive, the violence you live to endure
Cleansing, inherently violent, purging the world for the pure
Triumph of evil, hatred primeval
Unenlightened corrupted souls
Orgy of murder, heartless and vile
Merchants of death in control

Show no mercy, slow executions
Laugh while mutilating
God be damned, war is hell
God be damned, war is hell
God be damned, war is hell

Monsters, proudly displaying their deeds for the world to proscribe
Demons, walking the earth hell bent on their genocide

Show no mercy, slow executions
Laugh while mutilating
God be damned, war is hell
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

int n,k,m;
int l[N],r[N],x[N];
vector<int> starts[N],ends[N];

vector<int> start_one[N],end_zero[N];
long long pref_sum[N],ways[N];

long long query(long long l,long long r){
	long long ret=pref_sum[r];
	if (l>0)
		ret-=pref_sum[l-1];
	if (ret<0)
		ret+=bs;
	return ret;
}

long long solver(int lev){

	int cur_r=0;
	int cur_l=0;
	for (int i=1;i<=n;i++){
		start_one[i].clear();
		end_zero[i].clear();
	}

	int valid_start=0;

	for (int i=1;i<=m;i++){
		if (x[i]&(1<<lev))
			start_one[l[i]].push_back(r[i]);
		if (!(x[i]&(1<<lev)))
			end_zero[r[i]].push_back(l[i]),
			valid_start=max(valid_start,l[i]);
	}

	pref_sum[0]=1;
	ways[0]=1;

	for (int i=1;i<=n;i++){
		for (int j=0;j<start_one[i].size();j++){
			int to=start_one[i][j];
			cur_r=max(cur_r,to);
		}
		long long ways_here=0;
		if (cur_r<i) // can put 0
		{
			ways_here=query(cur_l, i-1);
		}
		pref_sum[i]=pref_sum[i-1]+ways_here;
		pref_sum[i]%=bs;
		ways[i]=ways_here;

		for (int j=0;j<end_zero[i].size();j++){
			int f=end_zero[i][j];
			cur_l=max(cur_l,f);
		}
	}

	long long ret=0;
	for (int i=valid_start;i<=n;i++){
		ret=ret+ways[i];
		ret%=bs;
	}
	//cout<<lev<<" "<<valid_start<<" "<<ways[valid_start]<<endl;

	return ret;
}

int main() {
  //   freopen("input.txt", "r", stdin);
  //   freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>n>>k>>m;
  for (int i=1;i<=m;i++)
  {
	  cin>>l[i]>>r[i]>>x[i];
  }

  long long ans=1;

  for (int bit=0;bit<k;bit++){
	  long long here=solver(bit);
	  ans=ans*here%bs;
  }

  cout<<ans<<endl;

  //    cin.get(); cin.get();
  return 0;
}