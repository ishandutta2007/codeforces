 #include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const int N = 100100;
int n, k, a, b;

vector <int> v[N], l1, l3;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i < n; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(int i = 1; i <= n; i++) {
		if(v[i].size() > 2)
			l3.push_back(i);
		if(v[i].size() == 1)
			l1.push_back(i);
	}

	if(l3.size() > 1) {
		cout << "No\n";
		return 0;
	}
	if(l3.size() == 1) {
		cout << "Yes\n";
		cout << l1.size() << '\n';
		for(int i = 0; i < l1.size(); i++)
			cout << l3[0] << ' ' << l1[i] << '\n';
		return 0;
	}
	if(l3.size() == 0) {
		cout << "Yes\n";
		if(l1.size() != 2) {
			return -1;
		}
		cout << 1 << '\n';
		cout << l1[0] << ' ' << l1[1] << '\n';
		return 0;
	}


}