#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sd(x) scanf("%d", &(x))
int mod = 1e9 + 7;
inline int add(int x, int y){ x += y; if(x >= mod) x -= mod; return x;}
inline int sub(int x, int y){ x -= y; if(x < 0) x += mod; return x;}
inline int mul(int x, int y){ return (x * 1ll * y) % mod;}
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

const int N = 2;
struct matrix{
    int B[N][N], n;
    matrix(){ n = N; memset(B,0,sizeof B);}
    matrix(int _n){
        n = _n; memset(B, 0, sizeof B);
    }
    void fib(){ n = 2; B[0][0] = B[0][1] = B[1][0] = 1;}
    void iden(){for(int i = 0; i < n; i++) B[i][i] = 1;}
    void operator += (matrix M){
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) B[i][j] = add(B[i][j], M.B[i][j]);
    }
    void operator -= (matrix M){
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) B[i][j] = sub(B[i][j], M.B[i][j]);
    }
    void operator *= (int b){
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) B[i][j] = mul(b, B[i][j]);
    }
    matrix operator - (matrix M){
        matrix ret = (*this); ret -= M; return ret;
    }
    matrix operator +(matrix M){
        matrix ret   = (*this); ret += M; return ret;
    }   
    matrix operator *(matrix M){
        matrix ret = matrix(n); memset(ret.B, 0, sizeof ret.B);
        for(int i = 0; i < n; i++) 
            for(int j = 0; j < n;j++)
                for(int k = 0; k < n; k++){
                    ret.B[i][j] = add(ret.B[i][j], mul(B[i][k], M.B[k][j]));
                }
        return ret;
    }
    matrix operator *= (matrix M){ *this = ((*this) * M);}
    matrix operator *(int b){
        matrix ret  = (*this); ret *= b; return ret;
    }
    matrix power(ll _n){
        matrix I = matrix(n), A = (*this); I.iden();
        for(;_n != 0; A *= A, _n >>= 1) if(_n & 1) I *= A;
        return I;    
    }
    matrix operator ^ (ll n){ return power(n);}
    int leading_one(int ind){
        for(int i = 0; i < n; i++) if(B[ind][i] == 1) return i;
    }
    bool operator == (matrix M){
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) if(B[i][j] != M.B[i][j]) return 0; return 1;
    }
	void clear(){ memset(B, 0, sizeof B);}
	void print(){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++) cout << B[i][j] << " ";
			cout << "\n";	
		}
	}
};
matrix zero, I;
matrix fibonacci(int n){
	matrix X; X.fib(); 
	X = X ^ n;
	return X;
}
const int M = 1e5 + 10;
int a[M];
matrix tree[3 * M], lazy[3 * M];

void go(int s, int e, int node){
	matrix m = lazy[node];
	tree[node] *= m;
	lazy[node] = I;
	if(s == e) return;
	lazy[2 * node] *= m;
	lazy[2 * node + 1] *= m;
}
matrix make(int s, int e, int ind){
	if(s == e) return tree[ind] = fibonacci(a[s]);
	int mid = (s + e) >> 1;
	return tree[ind] = make(s, mid, 2 * ind) + make(mid + 1, e, 2 * ind + 1);
}
void update(int s, int e, int l, int r, int ind, matrix m){
	go(s, e, ind);
	if(l > e || s > r) return;
	if(s >= l && e <= r){
		lazy[ind] *= m;
		go(s, e, ind);
		return;
	}
	int mid = (s + e) >> 1;
	update(s, mid, l, r, 2 * ind, m);
	update(mid + 1, e, l, r, 2 * ind + 1, m);
	tree[ind] = tree[2 * ind] + tree[2 * ind + 1];
}

matrix get_sum(int s, int e, int l, int r, int ind){
	if(l > e || s > r) return zero;
	go(s, e, ind);
	if(s >= l && e <= r) return tree[ind];
	int mid = (s + e) >> 1;
	return get_sum(s, mid, l, r, 2 * ind) + get_sum(mid + 1, e, l, r, 2 * ind + 1);
}
int main(){
	I.iden();
	for(int i = 0; i < 3 * M; i++) lazy[i] = I;
	int n, m, t, l, r, x;
	sd(n), sd(m);
	for(int i = 1; i <= n; i++) sd(a[i]);
	make(1, n, 1);
	while(m--){
		sd(t), sd(l), sd(r);
		if(t == 1){
			sd(x);
			matrix m = fibonacci(x);
			update(1, n, l, r, 1, m);
		}
		else{
			matrix m = get_sum(1, n, l, r, 1);
			printf("%d\n", m.B[0][1]);
		}
	}
}