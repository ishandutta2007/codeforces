#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sd(x) scanf("%d", &(x))
namespace bitmatrix {
typedef unsigned long long ull;
struct mat {
  int n, m;
  vector<vector<ull>> x;
  mat(){}
  mat(int m, int n) : m(m), n(n), x(1+m/8, vector<ull>(1+n/8)) { }
  bool get(int i, int j) const { 
    return x[i/8][j/8] & (1ull << (8*(i%8)+(j%8)));
  }
  void set(int i, int j, int b) {
    if (b) x[i/8][j/8] |=  (1ull << (8*(i%8)+(j%8))); 
    else   x[i/8][j/8] &= ~(1ull << (8*(i%8)+(j%8)));
  } 
};
ostream &operator<<(ostream &os, const mat &A) {
  for (int i = 0; i < A.m; ++i) {
    for (int j = 0; j < A.n; ++j) 
      os << A.get(i, j);
    os << endl;
  }
  return os;
}
mat eye(int n) {
  mat I(n, n);
  for (int i = 0; i < I.x.size(); ++i) 
    I.x[i][i] = 0x8040201008040201;
  return I;
}
mat zero(int n){
	mat I(n, n);
  for (int i = 0; i < I.x.size(); ++i) 
    I.x[i][i] = 0;
  return I;
}
mat add(mat A, const mat &B) { 
  for (int i = 0; i < A.x.size(); ++i)
    for (int j = 0; j < A.x[0].size(); ++j) 
      A.x[i][j] |= B.x[i][j];
  return A;
}

void disp(ull a) {
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      printf("%d", !!(a & 1));
      a >>= 1;
    }
    printf("\n");
  }
}

ull mul(ull a, ull b) { // C[i][j] |= A[i][k] & B[k][j]
  const ull u = 0xff, v = 0x101010101010101;
  ull c = 0;
  for (;a && b; a >>= 1, b >>= 8)
    c |= (((a & v) * u) & ((b & u) * v));
  return c;
}
mat mul(mat A, mat B) {
  mat C(A.n, B.m);
  for (int i = 0; i < A.x.size(); ++i) 
    for (int k = 0; k < B.x.size(); ++k) 
      for (int j = 0; j < B.x[0].size(); ++j) 
        C.x[i][j] |= mul(A.x[i][k], B.x[k][j]);
  return C;
}
bool is_row_zero(mat A, int i){
	for(int j = 0; j < A.n; j++) if(A.get(i, j)) return 0;
	return 1;	
}
}
using namespace bitmatrix;
const int logN = 64;
mat seedha[logN], ulta[logN];
int main(){
	int n, m; sd(n); sd(m);
	int u, v, t;
	seedha[0] = ulta[0] = zero(n);
	for(int i = 1; i <= m; i++){
		sd(u), sd(v), sd(t); u--, v--;
		if(t == 0) seedha[0].set(u, v, 1);
		else ulta[0].set(u, v, 1);
	}
	for(int i = 1; i < logN; i++){
		seedha[i] = mul(seedha[i - 1], ulta[i - 1]);
		ulta[i] = mul(ulta[i - 1], seedha[i - 1]);
	}
	if(!is_row_zero(seedha[60], 0)){
		printf("-1\n");
		return 0;
	}
	mat A = eye(n);ll ans = 0; bool b = 1;
	for(int i = 60; i >= 0; i--){
		mat Q = b ? seedha[i] : ulta[i];
		mat P = mul(A, Q);
		if(!is_row_zero(P, 0)){
			A = P; b ^= 1; ans += (1LL << i);
		}
	}
	if(ans > 1e18) ans = -1;
	printf("%lld\n", ans);
}