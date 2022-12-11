#pragma GCC optimize(3)
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <algorithm>
#define re register
#define ll long long
using namespace std;
const int N = 603030;
const int P = 998244353;
const int G = 3, Gi = (P + 1) / 3;

template <typename T>
void read(T &x) {
    x = 0; bool f = 0;
    char c = getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=1;
    for (;isdigit(c);c=getchar()) x=x*10+(c^48);
    if (f) x=-x;
}

ll fpw(ll x, ll mi) {
	ll res = 1;
	while (mi) {
		if (mi & 1) res = res * x % P;
		x = x * x % P;
		mi >>= 1;
	}
	return res;
}

ll lim, L;
int r[N];


ll gg[23][N];
void NTT(ll*a,int f){
	for (re int i = lim - 1; ~i; --i) if(i<r[i]) swap(a[i],a[r[i]]);
    for(int i=0;i<L;++i){
        const ll*G=gg[i],c=1<<i;
        for(int j=0;j<lim;j+=c<<1)
        for(int k=0;k<c;++k){
            const int x=a[j+k],y=a[j+k+c]*G[k]%P;
            (a[j+k]+=y)%=P,a[j+k+c]=(x-y+P)%P;
        }
    }
    if(f==-1){
    	ll inv = fpw(lim, P - 2);
    	for (re int i = lim - 1; ~i; --i) (a[i] *= inv) %= P;
//        for(int i=0;i<lim;++i)a[i]=a[i]*inv%P;
        reverse(a+1,a+lim);
    }
}

ll X[N], Y[N];

inline void mod(ll &x) {
	if (x >= P) x %= P;
}	

void mul(ll *a, ll *b, int n, int m) {
	lim = 1, L = 0;
	while (lim <= n + m) lim <<= 1, L++;
	re int i;
	for (i = 1;i < lim; i++)
		r[i] = (r[i>>1]>>1) | ((i&1) << (L-1));
	for (i = n - 1; ~i; --i) X[i] = a[i];
	for (i = m - 1; ~i; --i) Y[i] = b[i];
	NTT(X, 1); NTT(Y, 1);
	for (i = lim - 1; ~i; --i) mod(X[i] *= Y[i]);
	NTT(X, -1);
	for (i = n + m - 1; ~i; --i) a[i] = X[i];
	for (i = lim - 1; ~i; --i) X[i] = Y[i] = 0;
}

ll f[N], g[N];
void get_ans(int l, int r) {
	int L = (l - 1) * 2, R = (r - 1) * 2 + 1;
	if (l == r) return f[L] = l - 1, f[R] = 1, void();
	int mid = (l + r) >> 1, mm = mid * 2;
	get_ans(l, mid), get_ans(mid + 1, r);
	mul(f + L, f + mm, (mid - l + 1) * 2, (r - mid) * 2);
}

template <typename T>
void write(T x) {
    if (x >= 10) write(x / 10);
    putchar('0' + x % 10);
}

ll C(ll n, ll m) {
	if (m > n || m < 0) return 0;
	ll tmp = 1;
	for (int i = n;i > n - m; i--) 
		tmp = tmp * i % P;
	for (int i = 1;i <= m; i++) tmp = tmp * fpw(i, P - 2) % P;
	return tmp;
}

int main() {
    for (re int i = 0;i <= 20; ++i) {
        ll *G = gg[i];
        G[0] = 1;
        const int gi = G[1] = fpw(3, (P - 1) / (1 << (i+1)));
        for(re int j = 2;j < 1 << i; ++j) mod(G[j] = G[j-1] * gi);
    }
    int n, a, b; cin >> n >> a >> b; 
	if (n != 1) get_ans(1, n - 1);
	else f[0] = 1;
	printf ("%lld\n", f[a + b - 2] * C(a + b - 2, a - 1) % P);
	return 0;
}
/*
262144

*/