/*
Legs are tied, these hands are broken
Alone I try with words unspoken
Silent cry, a breath is frozen
With blinded eyes, I fear myself

It's burning down, it's burning high
When ashes fall, the legends rise
We burn it out a mile wide
When ashes fall, the legends rise

Throat is dry, my vision's fading
I'm paralyzed and left here waiting
Taking time, just one step forward
Won't lose my mind, I'm here to stay

It's burning down, it's burning high
When ashes fall, the legends rise
We burn it out a mile wide
When ashes fall, the legends rise

Whoa (Legends rise)
Whoa (Legends rise)

(Legends rise)

(You gonna do something about it or just stand there and bleed?)

(Legends rise)

It's burning down, it's burning high
When ashes fall, the legends rise
We burn it out a mile wide
When ashes fall, the legends rise

Whoa (Legends rise)
Whoa (Legends rise)
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

const int N = 1000031;

string st;
vector<pair<int,int> >v;
long long multiplier;

long long dp[N];

long long solve(vector<pair<int,int> > v){

	for (int i=0;i<=v.size();i++){
		dp[i]=0;
	}

	dp[0]=1;

	for (int i=0;i<v.size();i++){
		if (v[i].first=='1'){
			for (int j=i;j>=0;j--){
				if (v[j].first=='1')
					dp[i+1]+=dp[j]*v[i].second;
				dp[i+1]%=bs;
			}
			continue;
		}

		for (int len_here=1;len_here<=v[i].second;len_here++){
			long long ttl=0;
			for (int j=i-1;j>=0;--j){
				if (v[j].first=='0'&&v[j].second>=len_here)
					break;
				if (v[j].first=='1')
					ttl+=dp[j+1];
			}
			dp[i+1]+=ttl;
			dp[i+1]%=bs;
		}
	}

	for (int i=0;i<=v.size();i++){
		cout<<dp[i]<<" ";
	}
	cout<<endl;

	long long res=0;
	for (int i=0;i<v.size();i++){
		if (v[i].first=='1')
			res+=dp[i+1];
		res%=bs;
	}
	return res;
}

long long dp_pref_sum[N];

int sparse[20][1<<20];

void build_sparse(vector<pair<int,int> >v ){
	for (int i=0;i<v.size();i++){
		if (v[i].first=='0')
			sparse[0][i]=v[i].second;
		else
			sparse[0][i]=0;
	}

	for (int lev=1;lev<=19;++lev){
		for (int i=0;i<v.size();i++){
			sparse[lev][i]=sparse[lev-1][i];
			if (i-(1<<lev)/2>=0)
				sparse[lev][i]=max(sparse[lev][i],sparse[lev-1][i-(1<<lev)/2]);
		}
	}
}

int get_first_block_dumb(int len_here,int i){
	for (int j=i-1;j>=0;--j){
		if (v[j].first=='0'&&v[j].second>=len_here)
			return j;
	}
	return -1;
}

long long get_first_block(int len_here,int i){

	--i;

	//cout<<i<<"@@@"<<len_here<<" "<<endl;
	for (int lev=19;lev>=0;--lev){
		//cout<<lev<<"@"<<sparse[lev][i]<<"@@@"<<len_here<<" "<<i<<endl;
		if (i>=0&&sparse[lev][i]<len_here)
			i-=(1<<lev);
	}
	if (i<=0)
		return -1;
	return i-1;
}

long long smart_solve(vector<pair<int,int> > v){

	for (int i=0;i<=v.size();i++){
		dp[i]=0;
	}

	build_sparse(v);

	dp[0]=1;
	long long sum_of_magic1=0;

	for (int i=0;i<v.size();i++){
		if (v[i].first=='1'){
			sum_of_magic1+=dp[i];
			sum_of_magic1%=bs;
			dp[i+1]+=sum_of_magic1*v[i].second%bs;
			dp[i+1]%=bs;
			dp_pref_sum[i+1]=dp_pref_sum[i]+dp[i+1];
			dp_pref_sum[i+1]%=bs;
			continue;
		}

		for (int len_here=1;len_here<=v[i].second;len_here++){
			int PS=get_first_block(len_here,i);
			//cout<<get_first_block(len_here,i)<<" "<<get_first_block_dumb(len_here,i)<<" "<<len_here<<" "<<v[i].second<<endl;
			long long ttl=dp_pref_sum[i]-dp_pref_sum[PS+1];
			if (ttl<0)
				ttl+=bs;
			dp[i+1]+=ttl;
			dp_pref_sum[i+1]=dp_pref_sum[i];
			dp_pref_sum[i+1]%=bs;
			dp[i+1]%=bs;
		}
	}

/*	for (int i=0;i<=v.size();i++){
		cout<<dp[i]<<" ";
	}
	cout<<endl;
*/
	long long res=0;
	for (int i=0;i<v.size();i++){
		if (v[i].first=='1')
			res+=dp[i+1];
		res%=bs;
	}
	return res;
}
int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>st;

  int cnt=0;
  for (int i=0;i<st.size();i++){
	  if (st[i]=='1')
		  ++cnt;
  }

  if (cnt==0){
	  cout<<st.size()<<endl;
	  return 0;
  }

  cnt=0;

  for (int i=0;i<st.size();i++){
	  if (i>0&&st[i]!=st[i-1]){
		  v.push_back(make_pair(st[i-1],cnt));
		  cnt=0;
	  }
	  cnt++;
  }

  v.push_back(make_pair(st[st.size()-1],cnt));

  multiplier=1;

  if (v[0].first=='0'){
	  multiplier*=v[0].second+1;
	  v.erase(v.begin());
  }

  if (v[v.size()-1].first=='0'){
	  multiplier*=v[v.size()-1].second+1;
	  multiplier%=bs;
	  v.erase(v.begin()+v.size()-1);
  }

/*  for (int i=0;i<v.size();i++){
	  cout<<v[i].first<<" "<<v[i].second<<endl;
  }*/
  // solve should give 53

  cout<<smart_solve(v)*multiplier%bs<<endl;
//  cout<<solve(v)*multiplier%bs<<endl;


  cin.get(); cin.get();
  return 0;
}