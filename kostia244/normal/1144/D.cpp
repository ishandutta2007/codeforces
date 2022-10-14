#pragma GCC optimize("trapv")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace __gnu_pbds;
//using namespace __gnu_cxx;
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
const int maxn = 3e5 + 33, mlg = 18, mod = 1e9 + 7;
vi a;
int n;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	map<int, int> cnt;
	int t, ans = 0, anst=-1;
	for(int i = 0; i < n; i++) {
		cin >> t;
		a.pb(t);
		if(++cnt[t]>ans) {
			anst = t;
			ans = cnt[t];
		}
	}
	int k = 0;
	while(a[k]!=anst) k++;
	vector<pair<int, pi>> r;
	for(int i = k-1; i >= 0; i--) {
		r.pb({1+(a[i]>a[i+1]), {i+1, i+2}});
		a[i]=anst;
	}
	for(int i = k+1; i < n; i++) {
		if(a[i]==anst) continue;
		r.pb({1+(a[i]>a[i-1]), {i+1, i}});
		a[i] = anst;
	}
	cout << r.size() << "\n";
	for(auto i : r)
		cout << i.first << " " << i.second.first << " " << i.second.second << "\n";
}