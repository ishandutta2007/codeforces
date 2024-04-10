#include <bits/stdc++.h>
using namespace std;

const int N = 150005, B = 350, M = 998244353;

int inv(int x){
	int r = 1;
	for(int i = M-2; i; i /= 2, x = 1LL*x*x%M){
		if(i & 1) r = 1LL*r*x%M;
	}
	return r;
}

struct BIT {
	int d[N];
	void u(int x, int v){
		for(; x < N; x += x & -x) (d[x] += v) %= M;
	}
	void u(int s, int e, int v){
		u(s, v);
		u(e+1, M-v);
	}
	int g(int x){
		int r = 0;
		for(; x; x -= x & -x) (r += d[x]) %= M;
		return r;
	}
} T;

int n, q, ninv, ps[N], pe[N], pc, d[N];
vector<int> e[N], ch[N], big;

void f(int x, int y){
	ps[x] = ++pc;
	for(int i : e[x]){
		if(i == y) continue;
		f(i, x);
		ch[x].push_back(ps[i]);
	}
	ch[x].push_back(pc + 1);
	pe[x] = pc;
}

void u(int x, int d){
	int common = 1LL*ninv*d%M;
	int remain = n - (ch[x].back() - ch[x][0] + 1);
	T.u(1, ch[x][0] - 2, 1LL*(n-remain)*common%M);
	for(int i = 0; i+1 < ch[x].size(); i++){
		int cur = ch[x][i+1] - ch[x][i];
		T.u(ch[x][i], ch[x][i+1]-1, 1LL*(n-cur)*common%M);		
	}
	T.u(ch[x].back(), n, 1LL*(n-remain)*common%M);
}

int g(int x, int y){
	int common = 1LL*ninv*d[x]%M;
	if(y < ch[x][0] - 1 || y >= ch[x].back()) return 1LL*(ch[x].back()-ch[x][0]+1)*common%M;
	int wh = int(upper_bound(ch[x].begin(), ch[x].end(), y) - ch[x].begin());
	return 1LL*(n-ch[x][wh]+ch[x][wh-1])*common%M;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> q;
	ninv = inv(n);
	for(int i = 0; i < n-1; i++){
		int x, y;
		cin >> x >> y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	for(int i = 1; i <= n; i++) if(e[i].size() >= B) big.push_back(i);
	f(1, 0);
	for(int i = 0; i < q; i++){
		int x, y, z;
		cin >> x >> y;
		if(x == 1){
			cin >> z;
			(d[y] += z) %= M;
			if(e[y].size() < B) u(y, z);
		}
		else{
			int r = (d[y] + T.g(ps[y])) % M;
			for(int j : big) if(j != y) (r += g(j, ps[y])) %= M;
			cout << r << '\n';
		}
	}
}