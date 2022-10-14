//#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
const int maxn = 100003;
using ld = long double;
int n;
vi a;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >>n ;
	a.resize(n);
	for(auto &i : a) cin >> i;
	sort(all(a));
	int j = 0;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		while(a[i]-a[j]>5)j++;
//		cout << i << " " << j << "\n";
		ans = max(ans, i-j+1);
	}
	cout << ans;
}