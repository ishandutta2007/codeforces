/*
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

const int N = 510031;

int n,m;

vector<int> get_primes(int x){
	vector<int> ret;
	for (int i=2;i*i<=x;i++){
		if (x%i)
			continue;
		ret.push_back(i);
		while (x%i==0)
			x/=i;
	}
	if (x>1)
		ret.push_back(x);
	return ret;
}

int tests;

int get_phi(int x){
	vector<int> P=get_primes(x);
	for (int i=0;i<P.size();i++){
		x=x/P[i]*(P[i]-1);
	}
	return x;
}

int ar[N];

vector<int> phis;

long long magic_mod(long long a,long long b){
	long long rem=a%b;
	if (a<2e9)
		return a;
	long long F=2e9/b;
	return F*b+rem;
}

long long pw(long long a,long long b,long long mod){
	if (b==0)
		return 1;
	if (b%2)
		return magic_mod(a*pw(a,b-1,mod),mod);
	return pw(magic_mod(a*a,mod),b/2,mod);
}

long long query(int l,int r,int ps){
	if (l==r)
		return magic_mod(ar[l],phis[ps]);
	if (phis[ps]==1)
		return 1;
	//cout<<l<<" "<<r<<" "<<phis[ps]<<" "<<ar[l]<<" "<<query(l+1,r,ps+1)<<endl;
	//cout<<pw(2,2,100)<<endl;

	return pw(ar[l],query(l+1,r,ps+1),phis[ps]);
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n>>m;

	for (int i=1;i<=n;i++){
		cin>>ar[i];
	}

	phis.push_back(m);
	while (phis.back()!=1)
	{
		int x=phis.back();
		phis.push_back(get_phi(x));
	}

	/*for (int i=0;i<phis.size();i++){
		cout<<phis[i]<<" ";
	}
	cout<<endl;
*/

	cin>>tests;

	for(;tests;--tests){
		int l,r;
		cin>>l>>r;
		long long x=query(l,r,0);
		//cout<<"@@@"<<l<<" "<<r<<endl;

		cout<<x%m<<"\n";
	}

	cin.get(); cin.get();
	return 0;
}