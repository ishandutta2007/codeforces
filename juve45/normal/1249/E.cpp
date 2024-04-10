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
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const long long N = 200100;
long long n;
long long d[2 * N];
long long m, a, x, y, c, b;
vector <pair<long long, long long> > v[2 * N];
 
class cmp
{
public:
	inline bool operator()(const long long &a, const long long &b)
	{
		if(d[a] == d[b])
			return a < b;
		return d[a] < d[b];
	}
};
 
void dijkstra(long long nod)
{
	for(long long i=0;i< 2 * N;i++)
		d[i] = 1e9;
	set <long long, cmp> s;
 
	d[nod] = 0;
	s.insert(nod);
 
	while(!s.empty())
	{
		long long p = *s.begin();
		s.erase(p);
		for(long long i=0;i<v[p].size();i++)
		{
			pair<long long, long long> f = v[p][i];
 
			if(d[p] + f.second < d[f.first])
			{
				s.erase(f.first);
				d[f.first] = f.second + d[p];
				s.insert(f.first);
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> c;

	v[n].push_back({n + n, c});
	v[n + n].push_back({n, 0});
	for(long long i = 1; i < n; i++) {
		cin >> a;
		v[i].push_back({i + n, c});
		v[i + n].push_back({i, 0});
		v[i].push_back({i + 1, a});
	}
	for(long long i = 1; i < n; i++) {
		cin >> b;
		v[i + n].push_back({n + i + 1, b});
	}

	dijkstra(1);
	for(int i = 1; i <= n; i++)
		cout << d[i] << ' ';
		// cout << min(d[i], d[i + n]) << ' ';

}