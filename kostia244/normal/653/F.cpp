#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,ssse3,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
//using arr = array;
using pi = pair<int, int>;
using vi = vector<int>;
using vpi = vector<pi>;
using ld = long double;
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
//using oset = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
const int maxn = 1<<20, mod = (119<<23)+1, lg = 19;
string s;
int n, sa[maxn], tsa[maxn], ra[maxn], tra[maxn], c[maxn], lcp[maxn], phi[maxn];
void sort(int k) {
	memset(c, 0, sizeof c);
	int mx = max(300, n+3), t, sm = 0;
	for(int i = 0; i < n; i++) c[i + k < n ? ra[i+k] : 0]++;
	for(int i = 0; i < mx; i++) t = c[i], c[i] = sm, sm += t;
	for(int i = 0; i < n; i++) tsa[c[sa[i] + k < n ? ra[sa[i] + k] : 0]++] = sa[i];
	for(int i = 0; i < n; i++) sa[i] = tsa[i];
}
void build() {
	for(int i = 0; i < n; i++) sa[i] = i, ra[i] = s[i];
	for(int r,k = 1; k < n; k += k) {
		sort(k);
		sort(0);
		r = tra[sa[0]] = 1;
		for(int i = 1; i < n; i++) tra[sa[i]] = ra[sa[i]] == ra[sa[i-1]] && ra[sa[i]+k] == ra[sa[i-1]+k] ? r : ++r;
		for(int i = 0; i < n; i++) ra[i] = tra[i];
	}
}
void calclcp() {
	for(int i = 0; i < n; i++) phi[sa[i]] = i;
	for(int k = 0, i = 0; i < n; i++, k ? --k : 0) {
		if(phi[i] == 0) {lcp[i] = k = 0; continue;}
		int p = sa[phi[i]-1];
		while(max(i+k, p+k) < s.size() && s[i+k] == s[p+k]) k++;
		lcp[i] = k;
	}
}
int cap[maxn], psum[maxn];
vi pos[maxn];
int range(vi &a, int x) {
	return upper_bound(all(a), x)-a.begin();
}
int range(vi &a, int l, int r) {
	return max(0, range(a, r) - range(a, l-1));
}
void process() {
	stack<int> st;
	for(int i = 0; i < n; i++) {
		psum[i] = (i?psum[i-1]:0) + (s[i]=='('?1:-1);
		pos[(1<<19) + psum[i]].pb(i);
	}
	psum[n] = -(1<<30);
	st.push(n);
	for(int i = n; i--;) {
		while(psum[st.top()] >= psum[i]) st.pop();
		cap[i] = st.top();
		st.push(i);
	}
}
ll calc() {
	int P = n;
	for(int i = 0; i < n; i++) if(psum[i] < 0) {P = i; break;}
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		ans += range(pos[(1<<19)+(i?psum[i-1]:0)], i+lcp[i], i?cap[i-1]:P);
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> s;
	build();
	calclcp();
	process();
	cout << calc() << '\n';
}