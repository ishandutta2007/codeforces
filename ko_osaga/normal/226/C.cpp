#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

int mod;
lint l, r, k;
const int MAXN = 2;
struct matrix{
	lint adj[MAXN][MAXN];
	int n;
	matrix(int _n, int c){
		n = _n;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				adj[i][j] = (i == j ? c : 0);
			}
		}
	}
	matrix operator*(const matrix &a)const{
		matrix c(n, 0);
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				for(int k=0; k<n; k++){
					c.adj[j][k] += adj[j][i] * a.adj[i][k] % mod;
					c.adj[j][k] %= mod;
				}
			}
		}
		return c;
	}
	matrix operator+(const matrix &a)const{
		matrix c(n, 0);
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				c.adj[i][j] = (adj[i][j] + a.adj[i][j]) % mod;
			}
		}
		return c;
	}
	matrix operator-(const matrix &a)const{
		matrix c(n, 0);
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				c.adj[i][j] = (adj[i][j] + mod - a.adj[i][j]) % mod;
			}
		}
		return c;
	}
};


lint fib(lint x){
	matrix ret(2, 1), piv(2, 0);
	piv.adj[0][0] = piv.adj[0][1] = piv.adj[1][0] = 1;
	while(x){
		if(x&1) ret = ret * piv;
		piv = piv * piv;
		x >>= 1;
	}
	return ret.adj[1][0];
}
lint solve(lint l, lint r, lint k){
	lint ret = 0;
	for(int i=1; i<=200000; i++){
		lint s = 1, e = 1e13;
		while(s != e){
			lint m = (s+e+1)/2;
			if(r / m >= i) s = m;
			else e = m-1;
		}
		lint ts = s, te = 1e13;
		while(ts != te){
			lint tm = (ts + te + 1) / 2;
			if(r / tm - (l - 1) / tm >= k) ts = tm;
			else te = tm-1;
		}
		if(r / ts - (l-1) / ts >= k) ret = max(ret, ts);
	}
	return ret;
}
int main(){
	cin >> mod >> l >> r >> k;
	lint ret = 0;
	for(int i=1; i<=10000000 && i<=r-l+1; i++){
		if((r / i) - ((l - 1) / i) >= k){
			ret = i;
		}
	}
	ret = max(ret, solve(l, r, k));
	cout << fib(ret) << endl;
}