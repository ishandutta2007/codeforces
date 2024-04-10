#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
#define x first
#define y second

const int N = 100005, SZ = 131072, L = 17;
ll M = ll(1e9) + 7, MM = 998244353, ISZ = 742744451, ISZZ = 998236737;

int Rev(int x) {
    int i, r = 0;
    for (i = 0; i < L; i++) {
        r = r << 1 | x & 1;
        x >>= 1;
    }
    return r;
}
 
void FFT(ll *a, bool f, ll M, ll ISZ) {
    int i, j, k, z;
    for (i = 0; i < SZ; i++) {
        j = Rev(i);
        if (i < j) {
            z = a[i];
            a[i] = a[j];
            a[j] = z;
        }
    }
    for (i = 1; i < SZ; i <<= 1) for (j = 0; j < SZ; j += i << 1) for (k = 0; k < i; k++) {
        z = a[i + j + k];
        a[i + j + k] = (a[j + k] - z + M) % M;
        (a[j + k] += z) %= M;
    }
    if (f) for (i = 0; i < SZ; i++) a[i] = a[i] * ISZ % M;
}

int n, m, p[N], tt;
vector<pii> e[N];
ll a[SZ], b[SZ], aa[SZ], bb[SZ];

int f(int x){
    if(x == p[x]) return x;
    return p[x] = f(p[x]);
}

int g(int x, int y, int z){
    if(x == z) return 1;
    for(pii &i : e[x]){
        if(i.x == y) continue;
        if(!g(i.x, x, z)) continue;
        b[i.y]++;
        return 1;
    }
    return 0;
}

void h(){
    memcpy(bb, b, sizeof(b));
    FFT(b, 0, M, ISZ);
    FFT(bb, 0, MM, ISZZ);
    for(int i = 0; i < SZ; i++) (a[i] *= b[i]) %= M;
    for(int i = 0; i < SZ; i++) (aa[i] *= bb[i]) %= MM;
}

int main(){ ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    iota(p, p+n+1, 0);
    a[0] = aa[0] = 1;
    FFT(a, 0, M, ISZ);
    FFT(aa, 0, MM, ISZZ);
    for(int x, y, z; m--; ){
        cin >> x >> y >> z;
        tt ^= z;
        if(f(x) != f(y)){
            p[f(y)] = f(x);
            e[x].emplace_back(y, z);
            e[y].emplace_back(x, z);
        }
        else{
            memset(b, 0, sizeof(b));
            b[z]++;
            g(x, 0, y);
            h();
        }
    }
    memset(b, 0, sizeof(b));
    b[tt] = 1;
    h();
    FFT(a, 1, M, ISZ);
    FFT(aa, 1, MM, ISZZ);
    for(int i = 0; ; i++) if(a[i] || aa[i]){
        cout << i << ' ' << a[i] << '\n';
        return 0;
    }
}