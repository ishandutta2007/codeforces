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
int n;

void solve()  {
	string s;
	int f[266];
	memset(f, 0, sizeof f);
	cin >> s;

	string let;
	for(auto i : s) {
		if(f[i] == 0)
			let += i;
		f[i]++;
	}

	sort(let.begin(), let.end());

	if(let.size() <= 4) {
		int ok = 0;
		do
		{
			ok = 1;
			for(int i = 1; i < let.size(); i++) 
				if(abs(let[i] - let[i - 1]) == 1)
					ok = 0;
			if(ok) break;
		} while (next_permutation(let.begin(), let.end()));
		if(ok == 0) {
			cout << "No answer\n";
			return ;
		}
	} else {
		string let2;
		for(int i = 0; i < let.size(); i += 2) let2 += let[i];
		for(int i = 1; i < let.size(); i += 2) let2 += let[i];
		let = let2;
	}
	// dbg(let);
	for(auto i : let)
		cout << string(f[i], i);
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; i++) solve();
}