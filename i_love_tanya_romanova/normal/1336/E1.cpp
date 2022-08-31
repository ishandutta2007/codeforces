/*
Pulling away slowly
Scurrying on
Wending through the land escape
An absence of data

Void of all emotion
Hoping this day is my last

Chasing the unobtainable
Believing my own lies
On the path of self destruction
Strangled by all emotion

Blur the edges of my memory
Pain through the breathing
Drown myself to help forget
Silence all my thinking

Chasing the unobtainable
Believing my own lies
On the path of self destruction
Strangled by all emotion

Blur the edges of my memory
Pain through the breathing
Drown myself to help forget
Silence all my thinking

There's no believing
There's no returning
There's no beginning

Blur the edges of my memory
Pain through the breathing
Drown myself to help forget
Silence all my thinking
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

int n,m;
vector<long long> order;
int used[N];
long long fact[2000];
long long invf[2000];
long long ans[100];
long long indep[N],dep[N];

long long pw(long long a,long long b){
	if (b==0)
		return 1;
	if (b%2)
		return a*pw(a,b-1)%bs;
	return pw(a*a%bs,b/2);
}

long long inv(long long x){
	return pw(x,bs-2);
}

vector<long long> get_basis(vector<long long> v){
	for (int i=0;i<m;i++){
		int found=-1;
		for (int j=0;j<v.size();j++){
			if (used[j])
				continue;
			if (v[j]&(1ll<<i)){
				found=j;
				break;
			}
		}
		//cout<<i<<"@"<<found<<endl;
		if (found==-1)
			continue;
		used[found]=1;
		for (int j=0;j<v.size();j++){
			if (j==found)
				continue;
			if (v[j]&(1ll<<i)){
				v[j]^=v[found];
			}
		}
	}
	vector<long long> ret;
	for (int i=0;i<v.size();i++){
		if (used[i])
			ret.push_back(v[i]);
	}
	return ret;
}

const int MAGIC = 20;

int memo_pc[1<<16];

long long pcount(long long x){
	if (x<(1<<15))
		return memo_pc[x];
	return pcount(x/2)+x%2;
}

long long C(long long n,long long m){
	long long res=fact[n];
	res*=invf[m];
	res%=bs;
	res*=invf[n-m];
	return res%bs;
}

void solve_small(vector<long long> V){
	for (int mask=0;mask<(1ll<<V.size());mask++){
		long long T=0;
		for (int i=0;i<V.size();i++){
			if (mask&(1<<i))
				T^=V[i];
		}
		int here=pcount(T);
		dep[here]++;
		dep[here]%=bs;
	}
}

vector<int> leftovers;
int do_have[1000];

long long dp[2][40][1<<16];

void solve_large(vector<long long> V){

	for (int i=0;i<m;i++){
		do_have[i]=0;
	}

	for (int i=0;i<V.size();i++){
		int ps=0;
		while ((V[i]&(1ll<<ps))==0)
			++ps;
		do_have[ps]=1;
		//cout<<ps<<"!"<<endl;
	}

	for (int i=0;i<m;i++){
		if (do_have[i]==0)
			leftovers.push_back(i);
	}

	/*for (int i=0;i<leftovers.size();i++){
		cout<<leftovers[i]<<"@"<<endl;
	}*/

	for (int pcount_hi=0;pcount_hi<=V.size();pcount_hi++){
		for (int mask=0;mask<(1<<leftovers.size());mask++){
			dp[0][pcount_hi][mask]=dp[1][pcount_hi][mask]=0;
		}
	}

	dp[0][0][0]=1;

	for (int i=0;i<V.size();i++){

		long long mask_here=0;

		for (int j=0;j<leftovers.size();j++){
			if (V[i]&(1ll<<leftovers[j]))
				mask_here|=(1ll<<j);
		}

		for (int pc=0;pc<=i;pc++){
			for (int mask=0;mask<(1<<leftovers.size());mask++){
				dp[1-i%2][pc][mask]=0;
			}
		}

		for (int pc=0;pc<=i;pc++){
			for (int mask=0;mask<(1<<leftovers.size());mask++){
				if (dp[i%2][pc][mask]==0)
					continue;
				// don't take it
				dp[1-i%2][pc][mask]+=dp[i%2][pc][mask];
				dp[1-i%2][pc][mask]%=bs;
				// do take it
				dp[1-i%2][pc+1][mask^mask_here]+=dp[i%2][pc][mask];
				dp[1-i%2][pc+1][mask^mask_here]%=bs;
			}
		}
	}


	for (int pc=0;pc<=V.size();pc++){
		for (int mask=0;mask<(1ll<<leftovers.size());mask++){
			int total_pc=pc+pcount(mask);
			dep[total_pc]+=dp[V.size()%2][pc][mask];
			dep[total_pc]%=bs;
		}
	}
}

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  for (int i=0;i<(1<<16);i++){
		  memo_pc[i]=memo_pc[i/2]+i%2;
  }

  fact[0]=1;
  for (int i=1;i<=100;i++){
	  fact[i]=fact[i-1]*i%bs;
  }

  for (int i=0;i<=100;i++){
	  invf[i]=inv(fact[i]);
  }

  cin>>n>>m;
  for (int i=0;i<n;i++){
	  long long val;
	  cin>>val;
	  order.push_back(val);
  }

  vector<long long> V=get_basis(order);

 /* for (int i=0;i<V.size();i++){
	  cout<<V[i]<<endl;
  }
*/
  if (V.size()<=MAGIC){
	  solve_small(V);
  }

  else
  {
	  solve_large(V);
  }

  for (int i=0;i<=m;i++){
	  ans[i]=dep[i]*pw(2,n-V.size())%bs;
  }

  for (int i=0;i<=m;i++){
	  if (i)
		  cout<<" ";
	  cout<<ans[i];
  }
  cout<<endl;

  // cin.get(); cin.get();
  return 0;
}