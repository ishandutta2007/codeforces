#pragma GCC optimize("trapv")
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<int>;
const int maxn = 60;
int n, k, t[maxn];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
string gen() {
	string s(1, 'A'+(rng()%26));
	for(int i = 1; i < 10; i++)
		s+='a'+(rng()%26);
	return s;
}
string ans[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	string tt;
	for(int i = k; i <= n; i++) {
		cin >> tt;
		t[i] = (tt=="YES");
	}
	for(int i = 1; i < k; i++)
		ans[i] = gen();
	for(int i = k; i <= n; i++) {
		if(t[i]) ans[i] = gen();
		else ans[i] = ans[i-k+1];
	}
	for(int i = 1; i <= n; i++) cout << ans[i] << " ";
}