#include <bits/stdc++.h>

#define dbg(x) //cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define DMAX 200100
#define NMAX 
#define MMAX 

using namespace std;

int n, k, x, t;
string s;

template<class T>
ostream& operator<<(ostream& out, vector<T> v)
{
	out << v.size() << '\n';
	for(auto e : v)
		out << e << '\n';
	return out;
}

struct op {
	int a, t, i;
};

op v[DMAX], p[DMAX];

bool comp(op a, op b) {
	if(a.a > b.a) return true;
	if(a.a == b.a) return a.t < b.t;
	return false;
}

bool comp2(op a, op b) {
	if(a.t < b.t) return true;
	if(a.t == b.t) return a.a < b.a;
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> t;
	for(int i = 1; i <= n; i++) {
		cin >> v[i].a >> v[i].t;
		v[i].i = i;
 	}

 	sort(v + 1, v + n + 1, comp);
 	int ind = 1;
 	int sum = 0;
 	int ans = 0;
 	set <pair<int, int> > s;
 	for(int i = n; i > 0; i--) {
 		while (ind <= n && v[ind].a >= i) {
 			dbg(v[ind].t);
 			dbg(sum);
 			dbg(i);
 			s.insert({v[ind].t, ind});
 			sum += v[ind].t;
 			while(sum > t) {
 				auto p = *s.rbegin();
 				auto it = s.end();
 				it--;
 				s.erase(it); 				
 				sum -= p.first;
 			}

 			ind++;
 		}

		// for(auto i : s)
		// 	cout << i.second << ' ';
 		dbg(sum);
 		ans = max(min((int)s.size(), i), ans);
 	}

 	s.clear();
 	sum = 0;
 	ind = 1;
 	int nr = 0;
 	for(int i = 1; i <= n; i++) if(v[i].a >= ans) p[++nr] = v[i];

 	sort(p + 1, p + nr + 1, comp2);

/* 	while (ind <= n && v[ind].a >= ans) {
 			s.insert({v[ind].t, v[ind].i});
 			sum += v[ind].t;
 			dbg(sum);
 			while(sum > t) {
 				auto p = *s.rbegin();
 				auto it = s.end();
 				it--;
 				s.erase(it);
 				sum -= p.first;
 			}
 			ind++;
 		}
 		*/

 	cout << ans << '\n' << ans << '\n';
 	for(int i = 1; i <= ans; i++)
 		cout << p[i].i << ' ';

 	// for(auto i : s)
 	// 	cout << i.second << ' ';
 	cout << '\n';
}