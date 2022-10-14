#include<bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
const int D = 30, maxn = 90e5;
struct trie {
	int go[maxn][2], cnt[maxn], sz = 1;
	void init() {
		memset(go, 0, sizeof go);
		memset(cnt, 0, sizeof cnt);
		sz = 1;
	}
	void add(int x) {
		for(int cur = 0, i = D; i--;) {
			int u = (x>>i)&1;
			if(!go[cur][u]) go[cur][u] = sz++;
			cur = go[cur][u];
			cnt[cur]++;
		}
	}
	void rem(int x) {
		for(int cur = 0, i = D; i--;) {
			int u = (x>>i)&1;
			cur = go[cur][u];
			cnt[cur]--;
		}
	}
	int get(int x) {
		int ans = 0;
		for(int cur = 0, i = D; i--;) {
			int u = (x>>i)&1;
			if(cnt[go[cur][u]])
				cur = go[cur][u];
			else
				cur = go[cur][u^1], ans += 1<<i;
		}
		return ans;
	}
};
int n, a[300300], b[300300];
trie x;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	x.init();
	cin >>n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++) {
		cin >> b[i];
		x.add(b[i]);
	}
	for(int i = 1; i <= n; i++){
		int t = x.get(a[i]);
		x.rem(t^a[i]);
		cout << t << " ";
	}
}