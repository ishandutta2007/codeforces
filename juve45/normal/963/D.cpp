#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define DMAX 100100

using namespace std;
string s, st[DMAX];

const unsigned long long BASE = 37;
int n, a[DMAX];

unsigned long long h[DMAX];
unordered_set<int> lgs;
unordered_map<unsigned long long, int> mp;
vector <int> v[DMAX];
int lastv = 0;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}


inline void upd(unsigned long long hsh, int pos) {
	if(mp.count(hsh) != 0)
		v[mp[hsh]].push_back(pos);
}

void pre() {
	for(auto lg : lgs) {
		// lungimea lg
		unsigned long long hpow = 1, hsh = 0;
		for(int i = 0; i < lg; i++) hsh = hsh * BASE + (s[i] - 'a' + 1), hpow *= BASE;
		upd(hsh, 0);

		for(int i = lg; i < s.size(); i++) {
			hsh = hsh * BASE - hpow * (s[i - lg] - 'a' + 1) + (s[i] - 'a' + 1);
			upd(hsh, i - lg + 1);
		}
	}
}


int main() {

	ios_base::sync_with_stdio(false);

  
  cin >> s;
  cin >> n;  

  for(int i = 1; i <= n; i++) {
    cin >> a[i] >> st[i];
		lgs.insert(st[i].size());
  }
 	
 	for(int i = 1; i <= n; i++) {
  	h[i] = 0;
  	for(int j = 0; j < st[i].size(); j++)
  		h[i] = h[i] * BASE + (st[i][j] - 'a' + 1);
  	mp[h[i]] = i;
  }

  pre();

  for(int i = 1; i <= n; i++) {

  	// dbg(v[i]);

  	if(v[i].size() < a[i]) {
  		cout << "-1\n";
  		continue;
  	}

  	int j = a[i] - 1, ans = s.size(), lg = st[i].size();
  	for(int ii = 0; j < v[i].size(); j++, ii++) {
  		ans = min(ans, (v[i][j] - v[i][ii] + lg));
  	}
  	cout << ans << '\n';
  }

}