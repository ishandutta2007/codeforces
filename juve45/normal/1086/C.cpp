#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> //required
// #include <ext/pb_ds/tree_policy.hpp> //required

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

// using namespace __gnu_pbds; 
using namespace std;

// template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // ordered_set <int> s;
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }

int n, k, m, val[256], t, used[256];
int vv[256], u2[256];
string s, a, b;

void init() {
	memset(val, 0, sizeof val);
	memset(used, 0, sizeof used);
	memset(vv, 0, sizeof vv);
	memset(u2, 0, sizeof u2);
}

void complete() {
	// dbg(char(val['a']));
	// dbg(char(val['b']));
	// dbg(char(val['c']));
	// dbg(char(val['d']));
	// dbg(used['a']);
	// dbg(used['b']);
	// dbg(used['c']);
	// dbg(used['d']);
	int last = 'a';
	for(int i = 0; i < k; i++)
		if(val['a' + i] == 0) {
			while(used[last]) last++;
			val['a' + i] = last;
			used[last] = 1;
		}
}

bool try_low(int pos, int value) {
	if(used[value] && val[s[pos]] == 0 || val[s[pos]] && val[s[pos]] != value)
		return 0;
	if(val[s[pos]] == 0) {
		val[s[pos]] = value;
		used[value] = true;
	}

	for(int i = pos + 1; i < s.size(); i++) {
		if(val[s[i]] && val[s[i]] < a[i])
			return 0;
		if(val[s[i]] && val[s[i]] > a[i]) {
			complete();
			return 1;
		}
		if(val[s[i]] == a[i]) continue;
		
		int nxt = a[i] + 1;
		while(used[nxt] && nxt < 'a' + k) nxt++;	

		if(nxt < 'a' + k) {
			val[s[i]] = nxt;
			used[nxt] = 1;
			complete();
			return 1;
		} else {
			if(used[a[i]])
				return 0;

			val[s[i]] = a[i];
			used[a[i]] = 1;
		}
	}
	complete();
	return 1;
}

bool try_high(int pos, int value) {

	if(used[value] && val[s[pos]] == 0 || val[s[pos]] && val[s[pos]] != value)
		return 0;
	if(val[s[pos]] == 0) {
		val[s[pos]] = value;
		used[value] = 1;
	}

	for(int i = pos + 1; i < s.size(); i++) {
		
		if(val[s[i]] && val[s[i]] > b[i])
			return 0;
		
		if(val[s[i]] && val[s[i]] < b[i]) {
			complete();
			return 1;
		}
		if(val[s[i]] == b[i]) continue;
		
		int nxt = b[i] - 1;
		while(used[nxt] && nxt >= 'a') nxt--;
		
		if(nxt >= 'a') {
			val[s[i]] = nxt;
			used[nxt] = 1;
			complete();
			return 1;
		} else {
			if(used[b[i]])
				return 0;

			val[s[i]] = b[i];
			used[b[i]] = 1;
		}
	}
	complete();
	return 1;
}



bool solve() {
	int i = 0;
	while(a[i] == b[i] && i < s.size()) {

		if(val[s[i]] == 0) {
			if(used[a[i]])
				return 0;
			val[s[i]] = a[i];
			used[a[i]] = 1;
		}
		if(val[s[i]] != a[i]) return 0;
		i++;
	}
	// dbg_ok;
	if(i == s.size()) {
		complete();
		return true;
	}
	char low = a[i];
	char high = b[i];
	// dbg(low);
	// dbg(high);
	if(val[s[i]] == 0 || (low < val[s[i]] && val[s[i]] < high))
		for(char c = low + 1; c + 1 <= high; c++) {
			// dbg(c);
			if(val[s[i]] == c) {
				// dbg_ok;
				complete();
				return 1;
			}

			if(val[s[i]] == 0 && !used[c]) {
				val[s[i]] = c;
				used[c] = 1;
				complete();
				return 1;
			}
		}

	for(int i = 0; i < k; i++) vv[i + 'a'] = val[i + 'a'], u2[i + 'a'] = used[i + 'a'];
	if(try_low(i, low))
		return 1;
	
	for(int i = 0; i < k; i++) val[i + 'a'] = vv[i + 'a'], used[i + 'a'] = u2[i + 'a'];
	if(try_high(i, high))
		return 1;
	
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> t;

	while(t--) {
		cin >> k;
		cin >> s;
		cin >> a >> b;
		init();
		if(solve()) {
			cout << "YES\n";
			for(int i = 0; i < k; i++)
				cout << char(val['a' + i]);
			cout << '\n';
		} else cout << "NO\n";
	}		
}