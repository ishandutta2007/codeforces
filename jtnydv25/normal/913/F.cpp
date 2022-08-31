#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int> 
#define vll vector<ll>
#define print(s) cerr<<#s<<" : ";for(auto i:(s))cerr<<i<<" ";cerr<<"\n";

const int mod = 998244353;
const ll mod2 = mod * 1ll * mod;
const int CUTOFF = 100;

inline int add(int x, int y){x += y; if(x >= mod) x -= mod; return x;}
inline int sub(int x, int y){x -= y; if(x < 0) x += mod; return x;}
inline int mul(int x, int y){ return (x * 1ll * y) % mod;}
inline void add(ll & x, ll y, ll z){    
    x += y * z;
    if(x >= mod2) x -= mod2;
}

inline void naive_mul(vll & a, vll & b){
    vll c(a.size() + b.size() - 1);
    for(int i = 0; i < a.size(); i++)
        for(int j = 0; j < b.size(); j++)
            add(c[i + j], a[i], b[j]);
    for(int i = 0; i < c.size(); i++) c[i] %= mod;
    a = c;
}

inline void ADD(ll & a, ll b){
    a += b;
    if(a >= mod) a -= mod;
}

inline int get(vector<ll> & v, int i){
    return ((i >= v.size()) ? 0 : v[i]);
}

void Karatsuba(vll & a, vll & b){
    int sa = a.size(), sc = 2 * sa - 1;
    if(sa <= CUTOFF){
        naive_mul(a, b);
        return;
    }
    
    int h = a.size() >> 1;

    vll a2(a.begin(), a.begin() + h);
    vll a1(a.begin() + h, a.end());
    vll b2(b.begin(), b.begin() + h);
    vll b1(b.begin() + h, b.end());
    vll sma(max(a1.size(), a2.size()));

    for(int i = 0; i < a1.size(); i++){
        sma[i] = add(get(a1, i), get(a2, i));
    }

    Karatsuba(a1, b1); // a1 * b1
    Karatsuba(a2, b2); // a2 * b2
    b1.resize(max(b1.size(), b2.size()));
    for(int i = 0; i < b1.size(); i++){
        b1[i] = add(get(b1, i), get(b2, i));
    }

    Karatsuba(sma, b1); // (a1 + a2) * (b1 + b2)
    int sz = sa + sa - 1;
    a.clear();
    a.resize(sz);
    for(int i = 0; i < a1.size(); i++) ADD(a[i + (h << 1)], a1[i]);
    for(int i = 0; i < a2.size(); i++) ADD(a[i], a2[i]);
    for(int i = 0; i < sma.size(); i++){
        ADD(a[i + h], sub(sma[i], add(get(a1, i), get(a2, i))));
    }
}

void karatsuba(vll & a, vll & b){
    int sa = a.size(), sb = b.size(), sc = a.size() + b.size() - 1;
    if(sa * 1ll * sb <= CUTOFF * CUTOFF|| min(sa, sb) <= 10){
        naive_mul(a, b);
        return;
    }
    if(a.size() < b.size()) a.resize((int)b.size());
    else b.resize((int)a.size());
    Karatsuba(a, b);
    a.resize(sc);
}

const int MX = 2005;

vll poly_mul(vll a, vll b){
	karatsuba(a, b);
	if(a.size() >= MX) a.resize(MX);
	return a;
}

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

vll P[MX];
ll powersq[MX * MX], powersp[MX * MX];
vll vec;

int f[MX][MX];
int dp[MX][MX];
int E[MX];
int main(){
	int n, a, b;
	cin >> n >> a >> b;
	int p = mul(a, inv(b));
	int q = sub(1, p);
	powersp[0] = powersq[0] = 1;
	for(int i = 1; i < MX * MX; i++){
		powersp[i]  = mul(powersp[i - 1], p);
		powersq[i]  = mul(powersq[i - 1], q);
	}
	for(int i = 0; i < MX; i++) P[0].push_back(1);
	/*for(int i = 1; i <= n; i++){
		vec.clear();
		vec.resize(MX);
		for(int j = 0; j < MX; j++) vec[j] = powersq[i * j];

		P[i] = poly_mul(P[i - 1], vec);
	}*/
	f[0][0] = 1;
	for(int i = 1; i <= n; i++){
		f[i][0] = 1;
		for(int j = 1; j <= i; j++){
			f[i][j] = add(mul(f[i-1][j], powersq[j]), mul(f[i-1][j-1], powersp[i-j]));
		}
	}
	for(int i = 1; i <= n; i++){
		int sm = 0;
		for(int j = 1; j < i; j++){
			dp[i][j] = mul(dp[j][j], f[i][j]);
			sm = add(sm, dp[i][j]);
		}
		dp[i][i] = sub(1, sm);
	}

	E[1] = E[0] = 0;
	for(int i = 2; i <= n; i++){
		int sm = 0;
		for(int j = 1; j < i; j++){
			int v = add(E[j], add(E[i - j], add(j * (i - j), (j * (j - 1)) / 2)));
			sm = add(sm, mul(dp[i][j], v));
		}
		sm = add(sm, mul(dp[i][i], (i * (i - 1)) / 2));
		E[i] = mul(sm, inv(sub(1, dp[i][i])));
	}
	cout << E[n];
}