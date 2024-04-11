#pragma GCC optimize("O2")
#include<bits/stdc++.h>
#define int ll
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
const int maxn = 1<<20, mod = 998244353;

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	string s;
	cin >> s;
	int ok = s=="1";
	cin >> s;
	for(char a = 'a'; a <= 'z'; a++) ok |= count(all(s), a)>1;
	cout << (ok?"Yes\n":"No\n");
}