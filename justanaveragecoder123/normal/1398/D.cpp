#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<cassert>
#include<cassert>
#include<unordered_map>
#include<unordered_set>
#include<functional>
#include<queue>
#include<stack>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<sstream>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<numeric>
#include<random>
#include<chrono>
#include<bitset>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define xx first
#define yy second
#define sz(x) (int)(x).size()
#define gc getchar
#define IO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define mp make_pair

#ifndef ONLINE_JUDGE
#  define LOG(x) (cerr << #x << " = " << (x) << endl)
#else
#  define LOG(x) ((void)0)
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double PI=acos(-1);
const ll INF = 1LL<<62;
const ll MINF = -(1LL<<62);

template<typename T> T getint() {
	T val=0;
	char c;
	
	bool neg=false;
	while((c=gc()) && !(c>='0' && c<='9')) {
		neg|=c=='-';
	}

	do {
		val=(val*10)+c-'0';
	} while((c=gc()) && (c>='0' && c<='9'));

	return val*(neg?-1:1);
}

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); uniform_int_distribution<int>(0, n-1)(rng)

ll dp[201][201][201];
ll a,b,c;
ll t[3][201];

ll calc(ll i, ll j, ll k) {
	if(dp[i][j][k]!=-1) return dp[i][j][k];
	ll res=0;
	if(i>0&&j>0) res=max(res, calc(i-1,j-1,k)+t[0][i-1]*t[1][j-1]);
	if(i>0&&k>0) res=max(res, calc(i-1,j,k-1)+t[0][i-1]*t[2][k-1]);
	if(j>0&&k>0) res=max(res, calc(i,j-1,k-1)+t[1][j-1]*t[2][k-1]);
	return dp[i][j][k]=res;
}





int main() {
	IO;
	cin>>a>>b>>c;
	for(int i=0;i<a;++i) cin>>t[0][i];
	for(int i=0;i<b;++i) cin>>t[1][i];
	for(int i=0;i<c;++i) cin>>t[2][i];
	sort(t[0],t[0]+a);
	sort(t[1],t[1]+b);
	sort(t[2],t[2]+c);
	memset(dp, -1, sizeof dp);
	cout<<calc(a,b,c)<<"\n";
	return 0;
}