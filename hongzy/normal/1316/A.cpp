#include <bits/stdc++.h>
using namespace std;

#define ucin ios::sync_with_stdio(0), cin.tie(0)
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned long long ull;

const int N = 4e5 + 10;
const int mod = 1e9 + 7;

int qpow(int a, int b) {
	int ans = 1;
	for(; b >= 1; b >>= 1, a = (ll) a * a % mod)
		if(b & 1) ans = (ll) ans * a % mod;
	return ans;
}

int main() {
	ucin; int t; cin>>t;
	while(t --) {
		int n,m; cin>>n>>m;int s=0;
		for(int i=1;i<=n;i++){
			int x;cin>>x;s+=x;
		}
		cout<<min(s,m)<<endl;
	}
	return 0;
}