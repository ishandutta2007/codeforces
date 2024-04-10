#include <bits/stdc++.h>
using namespace std;
#define ll long long
// F(i, j) = F(i, j - 1) * F(i - 1, j - 1)
const int mod = 1e9 + 7;
void mul(vector<int> & a, vector<int> & b){
	vector<int> c(a.size() + b.size() - 1);
	for(int i = 0; i < a.size(); i++)
		for(int j = 0; j < b.size(); j++)
			c[i + j] = (c[i + j] + a[i] * 1ll * b[j]) % mod;
	a = c;		
}
void transform(vector<int> & a, int m){
	if(a.size() <= m) return;
	for(int i = m; i < a.size(); i++){
		a[i % m] += a[i];
		if(a[i % m] >= mod) a[i % m] -= mod;
	}
	if(a.size() > m) a.resize(m);
}
void power(vector<int> & a, int n, int m){
	vector<int> x = {1};
	transform(a, m);
	while(n){
		if(n & 1) mul(x, a);
		mul(a, a);
		transform(x, m);
		transform(a, m);
		n >>= 1;
	}
	a = x;
}
const int N = 1e6 + 10;
vector<int> a, b, c;
int A[N], B[N], C[N];
int main(){
	int l, n, m, v;
	scanf("%d %d %d", &n, &l, &m);
	a.resize(m); b.resize(m); c.resize(m);
	for(int i = 1; i <= n; i ++){
		scanf("%d", &v); a[v % m]++;
		A[i] = v;
	}
	for(int i = 1; i <= n; i ++){
		scanf("%d", &v); b[v % m]++;
		B[i] = v;
	}
	for(int i = 1; i <= n; i ++){
		scanf("%d", &v);
		C[i] = v;
		c[(v + B[i]) % m]++;
	}
	if(l == 1){
		int ans = 0;
		for(int i = 1; i <= n; i++) if((A[i] + C[i]) % m == 0) ans++;
		printf("%d\n", ans);
	}
	power(b, l - 2, m);
	mul(a, b);
	transform(a, m);
	mul(a, c);
	transform(a, m);
	printf("%d\n", a[0]);
}