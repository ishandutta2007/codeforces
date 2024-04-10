#include <bits/stdc++.h>
#define maxn 400086

using namespace std;

const int p = 998244353;

int t, n, m, c;
int a[maxn];

inline void add(int x, int y){
	for(;x < maxn;x += x & -x) a[x] += y;
}

inline int query(int x){
	int sum = 0;
	for(;x;x -= x & -x) sum += a[x];
	return sum;
}

inline int get(int x){
	int id = 0;
	for(int i = 20;~i;i--){
		if(id + (1 << i) < maxn && x - a[id + (1 << i)] > 0) id += 1 << i, x -= a[id];
	}
	return id + 1;
}

bool tag[maxn];
vector<int> v, w;
int x[maxn], y[maxn];
int sum[maxn], inv[maxn];
inline int C(int n, int m){
	if(n < m || n < 0 || m < 0) return 0;
	return 1ll * sum[n] * inv[m] % p * inv[n - m] % p;
}


int main(){
	scanf("%d", &t);
	sum[0] = 1;for(int i = 1;i < maxn;i++) sum[i] = 1ll * sum[i - 1] * i % p, add(i, 1);
	inv[0] = inv[1] = 1;for(int i = 2;i < maxn;i++) inv[i] = 1ll * (p - p / i) * inv[p % i] % p;
	for(int i = 2;i < maxn;i++) inv[i] = 1ll * inv[i] * inv[i - 1] % p;
	while(t--){ 
		scanf("%d%d", &n, &m), c = 0;
		for(int i = 1;i <= m;i++) scanf("%d%d", &x[i], &y[i]);
		for(int i = m;i;i--){
			int a = get(y[i]), b = get(y[i] + 1);
			add(a, -1), c += !tag[b], tag[b] = true;
			v.push_back(a), w.push_back(b); 
		}
		printf("%d\n", C(n * 2 - 1 - c, n));
		while(!v.empty()) add(v.back(), 1), v.pop_back();
		while(!w.empty()) tag[w.back()] = false, w.pop_back();
	}
}