#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vector<ll>>;
const ll mod = 696969569;
using oset = tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll base = 33 + (rng() % 100), X[300300], P[300300];
gp_hash_table<int, int> cnt[300300];
vi len, lenpos, lencnt;

inline void insert(int x) {
	if(++lencnt[x]==1) {
		lenpos[x] = len.size();
		len.pb(x);
	}
}
inline void erase(int x) {
	if(--lencnt[x]==0) {//swap pos_x and back, pop_back
		int px = lenpos[x];
		lenpos[len.back()]=px;
		swap(len[px], len.back());
		len.pop_back();
	}
}

inline ll bp(ll a, ll p) {
	ll res = 1;
	while(p) {
		if(p&1) res = (res*a)%mod;
		p>>=1;
		a = (a*a)%mod;
	}
	return res;
}
inline void add(string& x) {
	ll a = 0, b = 1, c=0;
	for (auto i : x)
		(a += i*P[c++])%=mod;
	cnt[x.size()][a]++;
	insert(x.size());
}
inline void rem(string& x) {
	ll a = 0, b = 1, c=0;
	for (auto i : x)
		(a += i*P[c++])%=mod;
	if (!--cnt[x.size()][a])
		cnt[x.size()].erase(a);
	if (cnt[x.size()].empty())
		erase(x.size());
}
ll find(string &s) {
	ll ans = 0;
	for(auto L : len) {
		ll a=0, b=1;
		ll ax=0, bx=1;
		for(int i = 0; i < s.size(); i++) {
			(a += s[i]*P[i])%=mod;
			if(i-L>=0) {
				(ax += s[i-L]*P[i-L])%=mod;
			}
			if(i-L>=-1)ans+=cnt[L][((mod+a-ax)*X[i-L+1])%mod];
		}
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, t;
	for(int i = 0; i < 300300; i++) X[i] = bp(base, mod-1-i);
	for(int i = 0; i < 300300; i++) P[i] = bp(base, i);
	lenpos.assign(300300, 0);
	lencnt.assign(300300, 0);
	string s;
	cin >> n;
	while (n--) {
		cin >> t>>s;
		if(t==1)add(s);
		if(t==2)rem(s);
		if(t==3)cout<<find(s)<<"\n";
		cout.flush();
	}
}