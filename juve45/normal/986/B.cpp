 #include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const int N = 1001000;
int n, k, p[N], nr, use[N];

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

int dfs(int k) {
	use[k] = 1;
	if(!use[p[k]])
		return 1 + dfs(p[k]);
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i =1 ;i <= n; i++) {
		cin >> p[i];
	}

	for(int i = 1; i <= n; i++)
		if(!use[i])
			nr += dfs(i) - 1;

	if((nr % 2) == (n % 2)) {
		cout << "Petr\n";
	}
	else cout << "Um_nik\n";

}