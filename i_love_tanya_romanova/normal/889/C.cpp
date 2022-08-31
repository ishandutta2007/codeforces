/*
Insectine man, carnivore. The shape of us, the conduct of flies
All-consuming swarm in inconspicuous disguise
Bloodseeking, parasitic. Ecstatically tracing decay
Thriving in the glow that death emits, the warm perfume it radiates

Revolting conformity. Hive mind unity

Excitedly their mandibles grind, aroused by vile ambition
At the sickly sweet promise of decomposition
Deliriously ingesting. Liquefied ruin absorbed
Innocence devoured by the elated horde

They are us, let's not even pretend

Aroused and frenzied they scurry, encircling death
A vile swarm awaiting the final breath

Myriad eyes visualizing the end
Blackened skies. Rabid heavens descend
On the bereft, unforgivingly

Precious life debased. Our dipteran legacy embraced

Crack the shell. Ascend the sky
Rise, extend your palpitating wings
Crack the shell. Ascend the sky
Fly you disgraceful wretched things
*/

//#pragma GCC optimize("O3")
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>

#include <memory.h>
#include <assert.h>

#define y0 sdkfaslhagaklsldk

#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 1000031;

vector<int> order;
int cnt_with[N];

int eval(vector<int> v){
	int res=0;
	int mx=0;
	int cur=0;
	for (int i=0;i<v.size();i++){
		if (v[i]>mx){
			mx=v[i];
			cur=0;
			if (mx==v.size())
				return res;
		}
		else{
			cur++;
			res=max(res,cur);
		}
	}
}

long long n,k;
long long dp[N];
long long sum_of_valid_dp;
long long sum_of_all_dp;

long long invf[N],fact[N];

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

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	fact[0]=1;
	for (int i=1;i<N;i++){
		fact[i]=fact[i-1]*i%bs;
	}
	invf[N-1]=inv(fact[N-1]);
	for (int i=N-2;i>=0;--i){
		invf[i]=invf[i+1]*(i+1)%bs;
	}

	/*for (int n=1;n<=8;n++){
		order.clear();
		for (int i=1;i<=n;i++){
			order.push_back(i);
		}
		for (int j=0;j<=n;j++){
			cnt_with[j]=0;
		}
		do
		{
			int here=eval(order);
			cnt_with[here]++;
		}while (next_permutation(order.begin(),order.end()));
		for (int j=0;j<=n;j++){
			cout<<cnt_with[j]<<" ";
		}
		cout<<endl;
	}
*/
	cin>>n>>k;

	dp[1]=1;
	sum_of_valid_dp=1;// which still can be extended
	sum_of_all_dp=1;// which can't be extended maybe

	for (int i=2;i<=n;i++){
		// dp which got k bad in a row already can't be extended anymore
		// to have 1 bad at position 2 last good should be at 0, so i-k-1
		if (i-k-1>0){
			long long to_subtract=dp[i-k-1];
			to_subtract*=(fact[i-2]*invf[i-k-2]%bs);
			to_subtract%=bs;
			sum_of_valid_dp-=to_subtract;
			if (sum_of_valid_dp<0)
				sum_of_valid_dp+=bs;
		}
		dp[i]=sum_of_valid_dp;
		sum_of_valid_dp*=(i-1);
		sum_of_valid_dp%=bs;
		sum_of_valid_dp+=dp[i];
		sum_of_valid_dp%=bs;
		sum_of_all_dp*=(i-1);
		sum_of_all_dp%=bs;
		sum_of_all_dp+=dp[i];
		sum_of_all_dp%=bs;
	}

	long long res=fact[n];
	res=res-sum_of_all_dp;
	res%=bs;
	if (res<0)
		res+=bs;
	cout<<res<<endl;

//	cin.get(); cin.get();
	return 0;
}