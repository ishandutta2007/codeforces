#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

// const int N = ;
int n, k, swp[211222];
string s;
vector <int> v;

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> k;
	cin >> s;

	int off = -1;

	for(int i = 0; i < n; i++) {
		if(s[i] != s[(i + 1) % n] && s[(i + 2) % n] == s[(i + 1) % n]) {
			off = i + 1;
			break;
		}
	}


	if(off == -1) {
		if(k %2 == 1) 
			rotate(s.begin(), s.begin() + 1, s.end()); 
		cout << s << '\n';
		return 0;
	}
	off %= n;
	// rotate(s.begin(), s.begin() + off, s.end());
	// rotate(s.begin(), s.begin() + n - off, s.end());
	// dbg(s);
	rotate(s.begin(), s.begin() + off, s.end());

	// s += s[0];
	// s += s[0];

	// dbg(s);

	int sz = 1;
	for(int i = 1;i < n; i++) {
		if(s[i] == s[i - 1]) sz++;
		else {
			v.push_back(sz);	
			sz = 0;
			i++;
			while(i < n && s[i] != s[i - 1]) i++, sz++;
			v.push_back(sz);
			i --;
			sz = 1;
		}
		// dbg(i, sz);
	}
	// if(k == 32785)
	// 	cout << v;
	if(s.back() == s[s.size() - 2])
		v.push_back(sz);
	else v.back()++;
	// if(v.size() % 2 == 1)
	v.push_back(0);


	for(int i = 1;i < v.size(); i += 2) {
		if(v[i] % 2 == 0) {
			int cat = min(v[i] / 2, k);
			v[i- 1] += cat;
			v[(i + 1) % v.size()] += cat;
			v[i] -= 2 * cat;
		} else {
			swp[i] = 1;
			int cat = min(v[i] / 2, k);
			v[i - 1] += cat;
			v[(i + 1) % v.size()] += cat + (int)(cat < k);
			v[i] -= 2 * cat + (int)(cat < k);
		}
		// dbg(v);
	}

	// dbg(v);


	char c = s[0];
	string ans;
	for(int i = 0; i < v.size(); i++) {
		// char c = ch[i];
		if(i+1 == v.size()) c = s[0];
		// cout << v[i] << '\n';/
		ans += string(v[i], c);

		c = 'B' + 'W' - c;
		i++;
		// cout << v[i] << '\n';
		if(i != v.size()) {
			for(int j = 0; j < v[i]; j++)
				ans += c, 
				c = 'B' + 'W' - c;
		}
		dbg(i, swp[i]);
		if(swp[i] && v[i] == 0)
			c = 'B' + 'W' - c;
		// cout << "A" << ans.size() << '\n';		// if(v[i] % 2 == 1)
	}

	// dbg(ans);
	// dbg(off);
	// cout << ans.size();
	off = n - off;
	off %= n;
	rotate(ans.begin(), ans.begin() + off, ans.end());
	cout << ans << '\n';
}