#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace __gnu_pbds;
#define all(x) x.begin(), x.end()
#define pb push_back
//#include <x86intrin.h>
#define pb push_back
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
const int maxn = 1e6 + 3;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve() {//radsadsfsdfsdfuckcf
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	map<int, int> cnt[11];
	ll n, k;
	cin >> n >> k;
	//n = 200000, k = 123321;
	vi a;
	a.resize(n);
	for(auto &i : a) {
		cin >> i;
		//i = rng()%100000000;
		int len = 0, rem = i%k;
		while(len < 10) {
			len++, rem = rem*10ll%k;
			cnt[len][rem]++;
		}
	}
	ll ans = 0;
	for(auto &i : a) {
		int len = to_string(i).size();
		ans += cnt[len][(k-i%k)%k];
		int t = i;
		for(int i = 0; i < len; i++) t=t*10ll%k;
		if((t+i)%k==0) ans--;
	}
	cout << ans << '\n';
}