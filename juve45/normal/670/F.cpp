#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

template<class T> ostream& print(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return print(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return print(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return print(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }

const int N = 5;
int n, k, m, f[256];
string s, t;

int cnt(int a) {
	if(a == 0) return 1;
	int ans = 0;
	while(a) {
		ans++;
		a /= 10;
	}
	return ans;
}

string gen_min() {
	string ss;
	for(int i = 0; i <= 9; i++)
		ss += string(f[i], '0' + i);
	return ss;
}

string gen_min2() {

	string ss;
	int fst = -1, snd = -1;

	for(int i = 1;i <= 9; i++) 
		if(f[i]) {
			fst = i; 
			f[i]--;
			break;
		}
	snd = t[0] - '0';
	for(int i = 0; snd == t[0] - '0' && i < t.size(); i++) 
		snd = t[i] - '0';

	// dbg(fst);
	// dbg(snd);

	if(fst == -1) ss += t;
	else ss += fst + '0';
	
	for(int i = 0; i <= 9; i++) {
		if(i == t[0] - '0' && snd <= i && fst >= 0) {
			ss += t;
			t[0] = 'a';
		}
		ss += string(f[i], '0' + i);
		if(i == t[0] - '0' && fst >= 0)
			ss += t;
	}
	return ss;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> s >> t;
	
	int sz = s.size();
	while(s.size() - cnt(sz) != sz) sz--;

	for(auto i : s) f[i - '0']++;

	int sz2 = sz;
	// dbg(sz2);
	while(sz2) {
		f[sz2 % 10]--;
		sz2 /= 10;		
	}

	// dbg(t);
	// dbg_v(f, 11);
	for(auto i : t)
		f[i - '0']--;
	// dbg_v(f, 11);

	if(t.size() == 1) {
		cout << gen_min2();
		return 0;
	}

	string ans1 = t + gen_min();
	string ans2 = gen_min2();

	if(ans1[0] != '0')
		cout << min(ans1, ans2);
	else cout << ans2;
}