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

const int N = 50100;
int n, v[N], x, y, z;

pair <pair<int, int>, int> p[N];
vector <int> w, w2;

bool cmp(int a, int b) {
	return p[a] < p[b];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i<= n; i++) {
		cin >> x >> y >> z;
		p[i] = {{x, y}, z};
		v[i] = i;
	}

	sort(v + 1,  v + n + 1, cmp);
	
	for(int i = 1; i <= n; i++) 
		w.push_back(v[i]);

	for(int i = 0; i < w.size(); i++)
		if(i + 1 < w.size() && p[w[i]].st == p[w[i + 1]].st)	{
			cout << w[i] << ' ' << w[i + 1] << '\n';
			i++;
		} else w2.push_back(w[i]);

	w = w2;
	// dbg(w);
	w2.clear();
	for(int i = 0; i < w.size(); i++)
		if(i + 1 < w.size() && p[w[i]].st.st == p[w[i + 1]].st.st)	{
			cout << w[i] << ' ' << w[i + 1] << '\n';
			i++;
		} else w2.push_back(w[i]);

	w = w2;
	for(int i = 0; i + 1 <= w.size(); i += 2)
		cout << w[i] << ' ' << w[i + 1] << '\n';
	return 0;
}