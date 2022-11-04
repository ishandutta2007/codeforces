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
#define eb emplace_back
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

#define int ll
main() {
	IO;
	int r,n;
	cin>>r>>n;
	vector<array<int,3>> t(n+1);
	t[0]={0,1,1};
	for(int i=1;i<=n;++i) cin>>t[i][0]>>t[i][1]>>t[i][2];
	vector<int> dp(n+1);
	dp[0]=0;
	vector<int> mx(n);
	for(int i=1;i<=n;++i) {
		dp[i]=-1e9;
		for(int j=i-1;j>=max(0LL,i-1010);j--) {
			if(t[i][0]-t[j][0]>=abs(t[i][1]-t[j][1])+abs(t[i][2]-t[j][2])) {
				//~ cerr<<j<<"->"<<i<<"\n"; 
				dp[i]=max(dp[i], dp[j]+1);
			}
		}
		if(i>=1011) {
			dp[i]=max(dp[i], mx[i-1010]+1);
		}
		mx[i]=max(mx[i-1], dp[i]);
		
	}
	
	
	cout<<*max_element(all(dp))<<"\n";;
	return 0;
}