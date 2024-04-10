#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <functional>
#include <bitset>
#include <assert.h>
#include <unordered_map>
#include <fstream>
#include <ctime>
#include <complex>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef pair<ll,ll> P;
typedef pair<int,int> pii;
typedef vector<P> vpl;
typedef tuple<ll,ll,ll> tapu;
#define rep(i,n) for(int i=0; i<(n); i++)
#define REP(i,a,b) for(int i=(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const int inf = 1<<30;
const ll linf = 1LL<<62;
const int MAX = 2020000;
ll dy[8] = {1,-1,0,0,1,-1,1,-1};
ll dx[8] = {0,0,1,-1,1,-1,-1,1};
const double pi = acos(-1);
const double eps = 1e-10;
template<typename T1,typename T2> inline bool chmin(T1 &a,T2 b){
	if(a>b){
		a = b; return true;
	}
	else return false;
}
template<typename T1,typename T2> inline bool chmax(T1 &a,T2 b){
	if(a<b){
		a = b; return true;
	}
	else return false;
}
template<typename T> inline void print(T &a){
    for(auto itr = a.begin(); itr != a.end(); itr++){
		cout << *itr << " ";
	}
    cout << "\n";
}
template<typename T1,typename T2> inline void print2(T1 a, T2 b){
	cout << "debug: " << a << " " << b << "\n";
}
template<typename T1,typename T2,typename T3> inline void print3(T1 a, T2 b, T3 c){
	cout << "debug: " << a << " " << b << " " << c << "\n";
}
void mark() {cout << "#" << "\n";}
ll pcount(ll x) {return __builtin_popcountll(x);}
//const int mod = 1e9 + 7;
const int mod = 998244353;

vector<ll> prime;
bool isprime[MAX];

int sieve(int n){
	int p = 0;
	for(int i=0; i<=n; i++) isprime[i] = true;
	isprime[0] = isprime[1] = false;
	for(int i=2; i<=n; i++){
		if(isprime[i]){
			prime.push_back(i);
			for(int j=2*i; j<=n; j+=i) isprime[j] = false;
		}
	}
	return p;
}

int main(){
	sieve(1000000);
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	int t; cin >> t;
	while(t--){
		ll n; cin >> n;
		ll sosuu = upper_bound(all(prime), n) - prime.begin() - 1;
		ll L = -1, R = sosuu;
		while(R-L > 1){
			ll mid = (L+R) / 2;
			if(prime[mid] * prime[mid] <= n) L = mid;
			else R = mid;
		}
		cout << sosuu - L + 1 << "\n";
	}
}