#include <bits/stdc++.h>
using namespace std;

const int N = 2005, M = 998244353;

int n, k, l, ans, iv[3 * N], cm[N][N];

void add(int &x, int y){ x += y % M; if(x >= M) x -= M; }

void mlt(vector<int> &v, int typ){
	vector<int> r(v.size() + 2, 0);
	if(typ == 0){
		for(int i = 0; i < v.size(); i++){
			add(r[i + 1], 2 * v[i]);
			add(r[i + 2], 2 * (M - v[i]));
		}
	}
	else{
		for(int i = 0; i < v.size(); i++){
			add(r[i], v[i]);
			add(r[i + 1], 2 * (M - v[i]));
			add(r[i + 2], 2 * v[i]);
		}
	}
	v = r;
}

int itg(vector<int> &v){
	int r = 0;
	for(int i = 0; i < v.size(); i++) r = (r + 1LL * v[i] * iv[i + 1]) % M;
	return r;
}

void f(vector<int> v, int x, int y, int s, int e){
	if(s == e){
		if(s < k) return;
		ans = (ans + 1LL * cm[n][s] * itg(v)) % M;
		return;
	}
	vector<int> w = v;
	int m = (s + e) / 2;
	int nx = x, ny = y;
	for(; nx < n - m; nx++) mlt(v, 1);
	f(v, nx, ny, s, m);
	nx = x, ny = y;
	for(; ny < m + 1; ny++) mlt(w, 0);
	f(w, nx, ny, m + 1, e);
}

int pw(int x, int y){
	if(y == 1) return x;
	return 1LL * pw(1LL * x * x % M, y / 2) * (y % 2 ? x : 1) % M;
}

int main(){
	vector<int> t; t.push_back(1);
	for(int i = 1; i < 3 * N; i++) iv[i] = pw(i, M - 2);
	for(int i = 0; i < N; i++){
		cm[i][0] = 1;
		for(int j = 1; j <= i; j++)
			cm[i][j] = (cm[i - 1][j - 1] + cm[i - 1][j]) % M;
	}
	scanf("%d%d%d", &n, &k, &l);
	f(t, 0, 0, 0, n);
	printf("%d\n", 1LL * l * ans % M);
}