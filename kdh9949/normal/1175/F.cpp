#include <bits/stdc++.h>
using namespace std;

const int N = 300005, SZ = 524288;

struct Seg{
	int d[SZ<<1];
	int g(int s, int e){
		int r = 0;
		for(s += SZ, e += SZ; s <= e; s >>= 1, e >>= 1){
			if( s & 1) r = max(d[s++], r);
			if(~e & 1) r = max(d[e--], r);
		}
		return r;
	}
	void u(int x, int v){
		for(x += SZ; x; x >>= 1) d[x] = max(d[x], v);
	}
} S;

int n, a[N], p[N], bnd[N];
set<pair<int, int>> ss;
vector<int> v;

void f(int l, int x, int r){
	ss.insert(make_pair(x, x));
	for(int i = x - 1; i >= l; i--){
		int t = S.g(i, x);
		if(i + t - 1 > r) continue;
		if(max(t, S.g(i, i + t - 1)) == t) ss.insert(make_pair(i, i + t - 1));
	}
	for(int i = x + 1; i <= r; i++){
		int t = S.g(x, i);
		if(i - t + 1 < l) continue;
		if(max(t, S.g(i - t + 1, i)) == t) ss.insert(make_pair(i - t + 1, i));
	}
}

int main(){
	scanf("%d", &n);
	v.push_back(0);
	for(int i = 1; i <= n; i++){
		scanf("%d", a + i);
		if(a[i] == 1) v.push_back(i);
		S.u(i, a[i]);
	}
	v.push_back(n + 1);
	for(int i = 1; i + 1 < v.size(); i++) f(v[i - 1] + 1, v[i], v[i + 1] - 1);
	
	fill(p + 1, p + n + 1, n + 1);
	bnd[n + 1] = n + 1;
	for(int i = n; i >= 1; i--){
		bnd[i] = bnd[i + 1];
		bnd[i] = min(bnd[i], p[a[i]]);
		p[a[i]] = i;
	}

	int r = 0;
	for(auto i : ss) if(i.second < bnd[i.first]){ r++; }
	printf("%d\n", r);
}