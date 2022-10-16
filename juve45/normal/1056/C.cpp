#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

template<class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> p) {
	return out << '(' << p.st << ' ' << p.nd << ')';  
}

const int N = 2010;
int n, k, m, a, b, v[N], ans, t, p[N];

set <pair<int, int> > must, fre;

void choose(int k) {
	must.erase({p[k], k});
	fre.erase({p[k], k});
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;

	for(int i = 1; i <= 2 * n; i++) {
		cin >> p[i];
		fre.insert({p[i], i});
	}

	for(int i = 1; i <= m; i++) {
		cin >> a >> b;
		v[a] = b;
		v[b] = a;
		must.insert({p[a], a});
		must.insert({p[b], b});
	}

	cin >> t;

	if(t == 1) {
		while(!must.empty()) {
			cout << must.rbegin()->nd << endl;
			choose(must.rbegin()->nd);
			cin >> ans;
			choose(ans);
		}

		while(!fre.empty()) {
			cout << fre.rbegin()->nd << endl;
			choose(fre.rbegin()->nd);
			cin >> ans;
			choose(ans);
		}

	} else {

		for(int i = 1; i <= n; i++) {
			cin >> ans;
			choose(ans);
			if(v[ans]) {
				cout << v[ans] << endl;
				choose(v[ans]);
			} else {
				if(!must.empty()) {
					cout << must.rbegin()->nd << endl;
					v[v[must.rbegin()->nd]] = 0;
					choose(must.rbegin()->nd);
				} else {
					cout << fre.rbegin()->nd << endl;
					choose(fre.rbegin()->nd);
				}
			}
		}

	}
	return 0;
}