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
int n, t, li = -1, ld = 1e9;
bitset<200200> ans;
vi a;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	a.resize(n);
	for(auto &i : a) cin >> i;
	for(int y, x,i = 0; i < n; i++) {
		x = a[i]>li;
		y = a[i]<ld;
		if(x^y) {
			if(x) li=a[i];
			else ld = a[i], ans.set(i);
		} else {
			if(x+y==0) return cout << "NO", 0;
			if(i+1==n||a[i+1]>a[i]) li=a[i];
			else ld = a[i], ans.set(i);
		}
	}
	cout << "YES\n";
	for(int i = 0; i < n; i++)
		cout << ans[i] << " ";
}