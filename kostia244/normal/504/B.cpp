#pragma GCC optimize("O2")
#pragma GCC target("avx,avx2,ssse3,sse2,sse,fma,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;
using vpi = vector<pair<int, int>>;
using namespace __gnu_pbds;
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
const int maxn = 1<<18;
int n, a[maxn], b[maxn], c[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	oset x;
	for(int i = 0; i < n; i++) x.insert(i);
	for(int t, i = 0; i < n; i++) {
		cin >> t;
		a[n-i-1] = x.order_of_key(t);
		x.erase(t);
	}
	for(int i = 0; i < n; i++) x.insert(i);
	for(int t, i = 0; i < n; i++) {
		cin >> t;
		b[n-i-1] = x.order_of_key(t);
		x.erase(t);
	}
	ll co = 0;
	for(int i =0; i < n; i++) {
		c[i] = a[i]+b[i]+co;
		co=c[i]/(i+1);
		c[i]%=(i+1);
	}
	for(int i = 0; i < n; i++) x.insert(i);
	for(int t, i = 0; i < n; i++) {
		t = *x.find_by_order(c[n-i-1]);
		cout <<t<< " ";
		x.erase(t);
	}
	return 0;
}