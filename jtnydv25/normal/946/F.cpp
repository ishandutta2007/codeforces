#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif
const int mod = 1e9 + 7;
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
const int inv2 = (mod + 1) >> 1;
struct data{
	int F[105][105];
	int G[105][105];
	int H[105][105];
	int I[105][105];
	int l;
};

data D[105];
string s;
int n;
data merge(const data & A, const data & B){
	data ret;
	ret.l = mul(A.l, B.l);
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			ret.F[i][j] = add(mul(B.l, A.F[i][j]), mul(A.l, B.F[i][j]));
			ret.G[i][j] = add(mul(A.l, B.G[i][j]), A.G[i][j]);
			ret.H[i][j] = add(B.H[i][j], mul(B.l, A.H[i][j]));
			ret.I[i][j] = add(A.I[i][j], B.I[i][j]);
			for(int k = i; k < j; k++){
				ret.F[i][j] = add(ret.F[i][j], mul(A.G[i][k], B.H[k + 1][j]));
				ret.G[i][j] = add(ret.G[i][j], mul(A.G[i][k], B.I[k + 1][j]));
				ret.H[i][j] = add(ret.H[i][j], mul(A.I[i][k], B.H[k + 1][j]));
				ret.I[i][j]= add(ret.I[i][j], mul(A.I[i][k], B.I[k + 1][j]));
			}
		}
	}
	return ret;
}

int main(){
	int x;
	cin >> n >> x;
	cin >> s;
	s = "0" + s;
	for(int i = 1; i <= n; i++){
		int k = s[i] - '0';
		D[k].F[i][i] = D[k].G[i][i] = D[k].H[i][i] = D[k].I[i][i] = 1;
	}
	D[0].l = D[1].l = 2;
	for(int i = 2; i <= x; i++){
		D[i] = merge(D[i - 1], D[i - 2]);
	}
	cout << D[x].F[1][n] << endl;
}