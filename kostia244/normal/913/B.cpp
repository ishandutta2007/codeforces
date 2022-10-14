#include<bits/stdc++.h>
#define int ll
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
const int maxn = 1<<20;
int n, deg[maxn], p[maxn], l[maxn];
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(int i = 2; i <= n; i++) {
		cin >> p[i];
		deg[p[i]]++;
	}
	for(int i = 2; i <= n; i++) {
		l[p[i]] += deg[i] == 0;
	}
	for(int i = 1; i <= n; i++) if(deg[i] && l[i] < 3) return cout << "NO\n", 0;
	cout << "YES\n";
}