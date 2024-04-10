#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 10, mod = 1e9 + 7;
int fact[N], invfact[N];
inline int add(int x, int y){ x += y; if(x >= mod) x -= mod; return x;}
inline int sub(int x, int y){ x -= y; if(x < 0) x += mod; return x;}
inline int mul(int x, int y){ return (((ll) x) * y) % mod;}
inline int powr(int a, ll b){
	int x = 1 % mod;
	while(b){
		if(b & 1) x = mul(x, a);
		a = mul(a, a);
		b >>= 1;
	}
	return x;
}
inline int inv(int a){ return powr(a, mod - 2);}
void pre(){
	fact[0] = invfact[0] = 1;
	for(int i = 1;i < N; i++) fact[i] = mul(i, fact[i - 1]);
	invfact[N - 1] = inv(fact[N - 1]);
	for(int i = N - 2; i >= 1; i--) invfact[i] = mul(invfact[i + 1], i + 1);
	assert(invfact[1] == 1);
}
inline int C(int n, int k){
	if(n < k || k < 0) return 0;
	return mul(fact[n], mul(invfact[k], invfact[n - k]));
}
int get(int n){
	int ret = 1;
	for(int i = 2; i * i <= n; i++){
		if(n % i == 0){
			int k = 0;
			while(n % i == 0){
				n /= i;
				k ^= 1;
			}
			if(k) ret *= i;
		}
	}
	if(n) ret *= n;
	return ret;
}
#define sd(x) scanf("%d", &(x))
map<int, int> freq;
#define vi vector<int>
void mul(vi & a, vi & b){
	vi c(a.size() + b.size() - 1);
	for(int i = 0; i < a.size(); i++)
		for(int j = 0; j < b.size(); j++)
			c[i + j] = add(c[i + j], mul(a[i], b[j]));
	a = c;
}
vi pmul(vector<vi> & v){
	if(v.size() == 0){ return {1};}
	if(v.size() == 1) return v[0];
	int mid = (v.size() >> 1);
	vector<vi> lft(v.begin(), v.begin() + mid);
	vector<vi> rgt(v.begin() + mid, v.end());
	vi X = pmul(lft);
	vi Y = pmul(rgt);
	mul(X, Y);
	return X;
}
vector<vector<int> > V;
int main(){
	pre();
	int n; sd(n);
	for(int i = 1; i <= n; i++){
		int x; sd(x); freq[get(x)]++;
	}
	vector<int> vec;
	int ans = 1;
	for(auto it : freq) vec.push_back(it.second), ans = mul(ans, fact[it.second]);
	int m = vec.size();
	for(int i = 0; i < m; i++){
		int xi = vec[i];
		vector<int> v;
		for(int j = 0; j < xi; j++){
			v.push_back(mul(C(xi - 1, j), invfact[xi - j]));
		}
		V.push_back(v);
	}
	vector<int> v = pmul(V);
	int ANS = 0;
	for(int i = 0; i < v.size(); i++){
		int val = mul(fact[n - i], v[i]);
		if(i & 1){
			ANS = sub(ANS, val);
		}
		else ANS = add(ANS, val);
	}
	printf("%d\n", mul(ans, ANS));
}