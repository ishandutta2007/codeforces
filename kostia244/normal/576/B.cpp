#pragma GCC optimize("trapv")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
//using namespace __gnu_cxx;
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
const int maxn = 1e5 + 33, mlg = 18, mod = 1e9 + 7;
set<pair<int, int>> ts;
int n, a[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int x = -1, y = -1, z = -1;
	for (int i = 1; i <= n; i++) {
		if(a[a[i]] == i) {
			x = i, y = a[i];
		}
		if(a[i]==i) z = i;
	}
	if(z!=-1) {
		cout << "YES\n";
		for(int i = 1; i <= n; i++) if(i!=z) cout << z << " " << i << "\n";
		return 0;
	}
	if(x==-1) {
		cout << "NO";
		return 0;
	}
	ts.insert({x, y});
	vi u(n+1, 0);
	for(int i = 1; i <= n; i++) {
		if(i == x || i == y || ts.count({x, i}) || ts.count({y, i})) continue;
		int t = i;
		while(ts.insert({x, t}).second) {
			if(u[t]) {
				cout << "NO";
				return 0;
			}
			u[t] = 1;
			t = a[t];
			swap(x, y);
		}
	}
	cout << "YES\n";
	for(auto i : ts)
		cout << i.first << " " << i.second << "\n";
}