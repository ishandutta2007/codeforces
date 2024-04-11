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
const int maxn = 2e5 + 33, mlg = 18, mod = 1e9 + 7;
int n, q, sa[maxn], tsa[maxn], ra[maxn], tra[maxn], phi[maxn], lcp[maxn], c[maxn], spt[maxn][mlg], llg[maxn];
string s;
void sort(int k) {
	int mi = max(300, n+1), sm=0,t;
	memset(c, 0, sizeof c);
	for(int i = 0; i < n; i++)
		c[i+k<n?ra[i+k]:0]++;
	for(int i = 0; i < mi; i++) {
		t = c[i], c[i] = sm, sm += t;
	}
	for(int i = 0; i < n; i++)
		tsa[c[sa[i]+k<n?ra[sa[i]+k]:0]++]=sa[i];
	for(int i = 0; i < n; i++)
		sa[i] = tsa[i];
}
void build() {
	for(int i = 0; i < n; i++) sa[i] = i, ra[i] = s[i];
	int r;
	for(int k = 1; n > k; k<<=1) {
		sort(k);
		sort(0);
		r = tra[sa[0]] = 1;
		for(int i = 1; i < n; i++) {
			if(ra[sa[i]]!=ra[sa[i-1]]||ra[sa[i]+k]!=ra[sa[i-1]+k]) r++;
			tra[sa[i]] = r;
		}
		for(int i = 0; i < n; i++) ra[i] = tra[i];
	}
}
void plcp() {
	for(int i = 0; i < n; i++) phi[sa[i]] = i;
	for(int k = 0, i = 0; i < n; i++, k ? k-- : 0) {
//		cout << i << " " << phi[i] << "\n";
		if(!phi[i])lcp[phi[i]] = 0;//, cout << i <<"\n";
		else {
			int p = sa[phi[i]-1];
			while(i + k < n && p + k < n && s[i+k]==s[p+k]) k++;
//			cout << i << " " << p << " " << k << "\n";
			lcp[phi[i]] = k;
		}
	}
}

void initsparse() {
	llg[1] = 0;
	for(int i = 2; i < maxn; i++) {
		llg[i] = llg[i-1];
		if((i&(i-1)) == 0) llg[i]++;
	}
	for(int j = 0; j < mlg; j++) {
		for(int i = 0; i < n; i++) {
			if(!j) spt[i][j] = lcp[i];
			else spt[i][j] = min(spt[i][j-1], i + (1<<(j-1)) < n ? spt[i + (1<<(j-1))][j-1] : 1<<28);
		}
	}
}
int get(int l, int r) {
	int k = llg[r-l+1];
//	cout << l << " " << r << " " << r-l+1 << " " << (1<<k) << "\n";
	return min(spt[l][k], spt[r-(1<<k)+1][k]);
}
void scanline(map<int, pi> &cnt, ll &ans) {
	ll sm = 0;
	map<int, int, greater<int>> num;
	int lst = -1;
	for(auto i : cnt) {
		if(lst!=-1&&num.size()) {
			int x = get(lst+1, i.first);
//			cout << lst+1 << " " << i.first << " " << x << "\n";
			while(num.begin()->first > x) {
				sm -= (num.begin()->first)*1ll*(num.begin()->second);
				sm += x*1ll*(num.begin()->second);
				num[x] += num.begin()->second;
				num.erase(num.begin());
			}
		}
//		cout << sa[i.first] << " " << sm << "\n";
		sm += i.second.first*1ll*(s.size()-sa[i.first]);
//		cout << sa[i.first] << " " << sm << "\n";
		num[s.size()-sa[i.first]]+=i.second.first;
		ans += i.second.second*sm;
		lst = i.first;
	}
}
void solve() {
	int k, l, t;
	cin >> k >> l;
	map<int, pi> cnt;
	vi a, b;
	while(k--) {
		cin >> t, t--, cnt[phi[t]].first++;
		a.pb(phi[t]);
	}
	while(l--) {
		cin >> t, t--, cnt[phi[t]].second++;
		b.pb(phi[t]);
	}
	ll ans = 0;
	scanline(cnt, ans);
	for(auto &i : cnt) swap(i.second.second, i.second.first);
	scanline(cnt, ans);
	for(auto i : cnt)
		if(i.second.second&&i.second.first)
			ans -= s.size()-sa[i.first];
	cout << ans << "\n";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q >> s;
	build();
	plcp();
//	for(int i = 0; i < n; i++)
//		cout << lcp[i] << s.substr(sa[i]) << "\n";
	initsparse();
	while(q--) solve();
}