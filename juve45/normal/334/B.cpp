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
int n, x, y;
vector <pair<int, int> > v;

int main() {
	ios_base::sync_with_stdio(false);
	// cin >> n;
	for(int i = 0; i < 8; i++) cin >> x >> y, v.push_back({x, y});
	sort(v.begin(), v.end());
	


	if(v[0].st == v[1].st && v[1].st == v[2].st) {
		if(v[5].st == v[6].st && v[6].st == v[7].st)
			if(v[3].st == v[4].st)
				if(v[0].nd == v[3].nd && v[3].nd == v[5].nd)
					if(v[1].nd == v[6].nd)
						if(v[2].nd == v[4].nd && v[7].nd == v[4].nd)
							if(v[3].st < v[5].st && v[0].st < v[3].st)
								if(v[0].nd < v[1].nd && v[1].nd < v[2].nd)
								return cout << "respectable\n", 0; 
	}
	cout << "ugly\n";
}