#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

const int p = 998244353, inv2 = 499122177;

inline int fpow(int x, int y){
	int ans = 1;
	while(y){
		if(y & 1) ans = 1ll * ans * x % p;
		x = 1ll * x * x % p, y >>= 1;
	}
	return ans;
}

const int deg = 17;
struct poly{
	
	int a[deg];
	
	poly():a(){}
	
	inline int & operator [] (const int &i){
		return a[i];
	}

	inline poly operator + (const poly &b) const{
		poly c;
		for(int i = 0;i < deg;i++) c[i] = a[i] + b.a[i], c[i] -= c[i] > p ? p : 0;
		return c;
	}
	
	inline poly operator - (const poly &b) const{
		poly c;
		for(int i = 0;i < deg;i++) c[i] = a[i] + p - b.a[i], c[i] -= c[i] > p ? p : 0;
		return c;
	}
	
	inline poly operator * (const poly &b) const{
		poly c;
		for(int i = 0;i < deg;i++) for(int j = 0;i + j < deg;j++) c[i + j] = (c[i + j] + 1ll * a[i] * b.a[j]) % p;
		return c;
	}
	
	inline poly operator * (const int &b) const{
		poly c;
		for(int i = 0;i < deg;i++) c[i] = 1ll * a[i] * b % p;
		return c;
	}
	
};

inline void XOR(vector<poly> &a, int lim, int type){
	for(register int mid = 1;mid < lim;mid <<= 1){
		for(register int i = mid << 1, j = 0;j < lim;j += i){
			for(register int k = 0;k < mid;k++){
				a[j + k] = a[j + k] + a[j + k + mid];
				a[j + k + mid] = a[j + k] - a[j + k + mid] - a[j + k + mid];
				if(type == -1) a[j + k] = a[j + k] * inv2, a[j + k + mid] = a[j + k + mid] * inv2;
			}
		}
	}
}

int n, k, c;
int x;
vector<int> v[maxn << 2];
int cnt[maxn << 2];
int pcnt[maxn], sum[maxn], inv[maxn];

#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)

vector<poly> build(int x, int l, int r){
	if(l == r){
		vector<poly> v(1);
		v[0][0] = 1;
		return v;
	}
	int mid = l + r >> 1;
	vector<poly> L = build(ls(x), l, mid), R = build(rs(x), mid + 1, r);
	int lim = r - l + 1;
	L.resize(lim), R.resize(lim);
	if(cnt[rs(x)] & 1){
		for(int i = 0;i < lim / 2;i++){
			for(int j = 0;j <= k;j++){
				swap(R[i][j], R[i + lim / 2][j]);
			}
		}
	}
	cnt[x] = cnt[ls(x)] + cnt[rs(x)];
	XOR(L, lim, 1), XOR(R, lim, 1);
	for(int i = 0;i < lim;i++) L[i] = L[i] * R[i];
	vector<int> w;
	for(int i = 0;i < v[ls(x)].size();i++){
		int val = v[ls(x)][i];
		if(val - k >= l) w.push_back(val);
		else v[x].push_back(val);
	}
	for(int i = 0;i < v[rs(x)].size();i++){
		int val = v[rs(x)][i];
		if(val - k >= l) w.push_back(val);
		else v[x].push_back(val);
	}
	for(int t = 0;t < w.size();t++){
		int val = w[t] & (lim - 1);
		vector<poly> v(lim);
		for(int i = 0;i < lim;i++){
			for(int j = 0;j <= k;j++){
				v[i][j] = pcnt[i & (val - j)] & 1 ? p - inv[j] : inv[j];
			}
		}
		for(int i = 0;i < lim;i++) L[i] = L[i] * v[i];
	}
	cnt[x] += w.size();
	XOR(L, lim, -1);
	return L;
}                                      


int main(){
	sum[0] = 1;for(int i = 1;i < maxn;i++) sum[i] = 1ll * sum[i - 1] * i % p;
	inv[maxn - 1] = fpow(sum[maxn - 1], p - 2);
	for(int i = maxn - 2;~i;i--) inv[i] = 1ll * inv[i + 1] * (i + 1) % p;
	for(int i = 1;i < maxn;i++) pcnt[i] = pcnt[i >> 1] + (i & 1);
	scanf("%d%d%d", &n, &k, &c);
	for(int i = 1;i <= n;i++){
		scanf("%d", &x);
		v[x + (1 << c)].push_back(x);
	}
	vector<poly> v = build(1, 0, (1 << c) - 1);
	int val = 1ll * sum[k] * fpow(fpow(n, k), p - 2) % p;
	for(int i = 0;i < (1 << c);i++) printf("%d ", 1ll * v[i][k] * val % p);
}