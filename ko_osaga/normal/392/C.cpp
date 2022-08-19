#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;

const int MAXN = 85;
struct matrix{
	int adj[MAXN][MAXN];
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
					c.adj[j][k] += 1ll * adj[j][i] * a.adj[i][k] % mod;
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

lint bino[44][44];
lint n, k;

int main(){
	cin >> n >> k;
	for(int i=0; i<=k; i++){
		bino[i][0] = 1;
		for(int j=1; j<=i; j++){
			bino[i][j] = (bino[i-1][j-1] + bino[i-1][j]) % mod;
		}
	}
	matrix ret(2*k+2, 0), piv(2*k+2, 0);
	for(int i=0; i<=k; i++){
		for(int j=i; j<=k; j++){
			piv.adj[i][j] = bino[k-i][j-i];
			piv.adj[i][j+k+1] = bino[k-i][j-i] * ((1ll << (j - i)) % mod) % mod;
		}
	}
	for(int i=0; i<=k; i++){
		piv.adj[i+k+1][i] = 1;
	}
	matrix sum(2*k+2, 1), up(2*k+2, 1);
	for(int i=0; i<60; i++){
		if((n >> i) & 1){
			ret = ret + sum * up;
			up = up * piv;
		}
		sum = sum + sum * piv;
		piv = piv * piv;
	}
	int dap = ret.adj[0][2*k+1];
	for(int i=0; i<=k; i++){
		dap += ret.adj[0][i];
		dap %= mod;
	}
	cout << dap;
}