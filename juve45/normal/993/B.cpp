#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const int N = 110;

int n, k, m, a, b, use1[111], use2[N], ans;
vector <int> v1, v2;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

int fr(int k) {return k / 10;}
int bk(int k) {return k % 10;}

bool ok(int a, int b) {
	if(a == b) return 0;
	if(fr(a) == fr(b))
		return 1;
	if(fr(a) == bk(b))
		return 1;
	if(bk(a) == fr(b))
		return 1;
	if(bk(a) == bk(b))
		return 1;
	return 0;
}

int get(int a, int b) {
	if(fr(a) == fr(b))
		return fr(a);
	if(fr(a) == bk(b))
		return fr(a);
	return bk(a);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a >> b;
		if(a > b) swap(a, b);
		v1.push_back(a * 10 + b);
	}
	
	for(int i = 1; i <= m; i++) {
		cin >> a >> b;
		if(a > b) swap(a, b);
		v2.push_back(a * 10 + b);
	}


	for(auto i : v1) 
		for(auto j : v2)
			if(ok(i, j))
				ans++;
	
	if(ans == 0) {
		cout << "-1\n";
		return -1;
	}

	if(ans == 1)
		for(auto i : v1) 
			for(auto j : v2)
				if(ok(i, j)) {
					cout << get(i, j);
					return 0;
				}

	for(int i = 0; i < v1.size(); i++)
		for(int j = 0; j < v2.size(); j++) {
			if(ok(v1[i], v2[j])) {
				int nr = get(v1[i], v2[j]);
				if(use1[i] != 0) {
					if(use1[i] != nr)
						return cout << -1 << '\n', 0;
				} else
					use1[i] = nr;

				if(use2[j] != 0) {
					if(use2[j] != nr)
						return cout << -1 << '\n', 0;
				}	else
					use2[j] = nr;
			}
		}

		set<int> s;
		for(int i = 0; i < 12; i++)
			if(use1[i]) 
				s.insert(use1[i]);

		for(int i = 0; i < 12; i++)
			if(use2[i]) 
				s.insert(use2[i]);

		if(s.size() == 1) {
			cout << *s.begin() << '\n';
			return 0;
		}

	cout << "0\n";
	return 0;
}