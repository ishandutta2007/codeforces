#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<int>;
const int maxn = 1<<19, mlg = 18, rt = 1<<10, mod = 1e9 + 7;
int n, a[maxn], p[maxn], s[maxn];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i], p[i] = s[i] = a[i];
	for(int i = 2; i <= n; i++) p[i] |= p[i-1];
	for(int i = n-1; i >= 1; i--) s[i] |= s[i+1];
	pair<int, int> ans = {-1, -1};
	for(int i = 1; i <= n; i++) {
		int t =p[i-1]|s[i+1];
		ans = max(ans, {a[i] - (a[i]&t), i});
	}
	swap(a[1], a[ans.second]);
	for(int i = 1; i <= n; i++) cout << a[i] << " ";
}