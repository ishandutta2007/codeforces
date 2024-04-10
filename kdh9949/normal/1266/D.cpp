#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 100005;

int n, m;
ll a[N];
int p[N], pc, q[N], qc;
vector<tuple<int,int,ll>> v;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y, z;
		cin >> x >> y >> z;
		a[x] += z;
		a[y] -= z;
	}

	for(int i = 1; i <= n; i++){
		if(a[i] > 0) p[pc++] = i;
		if(a[i] < 0) q[qc++] = i;
	}

	int pp = 0, qq = 0;
	while(pp < pc && qq < qc){
		ll t = min(a[p[pp]], -a[q[qq]]);
		v.emplace_back(p[pp], q[qq], t);
		a[p[pp]] -= t;
		a[q[qq]] += t;
		if(a[p[pp]] == 0) pp++;
		if(a[q[qq]] == 0) qq++;
	}

	cout << v.size() << '\n';
	for(auto [a, b, c] : v) cout << a << ' ' << b << ' ' << c << '\n';

}