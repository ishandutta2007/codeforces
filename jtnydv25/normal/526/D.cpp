#include <bits/stdc++.h>
using namespace std;
#define ll long long

int const N = 1e6 + 10;
int const X = 33533;
ll M1, M2, POW1[N], POW2[N], CPOW1[N], CPOW2[N];

inline ll powr(ll a, ll b, ll mod){
    ll x = 1;
    for(;b;b >>= 1, a = (a * a) % mod) if(b & 1) x = (x * a) % mod;
    return x;
}
inline ll inv(ll a, ll mod){ return powr(a, mod - 2, mod);}
#define Hash ll

inline Hash get_char_Hash(char c){
    return (c - 'a' + 1);
}
std::mt19937 rnd(std::chrono::system_clock::now().time_since_epoch().count());
  
int const HALFBILLION = 500000000;

bool prime(int x){
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

void gen(ll & M) {
  M = rnd() % HALFBILLION + HALFBILLION;
  while (!prime(M)){
      ++M;
  }
}

char A[N];
Hash H[N];
inline Hash get_hash(int l, int r){
    ll x = (H[r] - POW1[r - l + 1] * H[l - 1]) % M1;
    if(x < 0) x += M1;
    return x;
}

#define LSOne(S) (S & (-S))
ll B1[N], B2[N];
ll query(ll* ft, int b) {
    ll sum = 0;
    for (; b; b -= LSOne(b)) sum += ft[b];
    return sum;
}
ll query(int b) {
    return query(B1, b) * b - query(B2, b);
}
ll range_query(int i, int j)    {
    return query(j) - query(i - 1);
}
void update(ll* ft, int k, ll v) {
    for (; k < N; k += LSOne(k)) ft[k] += v;
}
void range_update(int i, int j, ll v)   {
    update(B1, i, v);
    update(B1, j + 1, -v);
    update(B2, i, v * (i - 1));
    update(B2, j + 1, -v * j);
}

int main() {
    gen(M1);
    gen(M2); M2 = M1;
    POW1[0] = POW2[0] = CPOW1[0] = CPOW2[0] = 1;
    for (int i = 1; i < N; i++) {
        POW1[i] = POW1[i - 1] * X % M1;
    }
    int n, k;
    scanf("%d %d", &n, &k);
    scanf("%s", A);
    H[0] = 0;
    for(int i = 1; i <= n; i++) H[i] = (H[i  - 1] * X + get_char_Hash(A[i - 1])) % M1;
    ll pow1 = 1,mul1 = powr(X, k, M1);
    for(int ab = 1; ab * k <= n; ab++){
        pow1 = (pow1 * mul1) % M1;
        ll h1 = H[ab];
        ll H1 = (h1 * (((pow1 - 1) * inv(POW1[ab] - 1, M1)) % M1) ) % M1;
        Hash _H = H1;
        if(H[ab * k] == _H){
            int lo = 0, hi = min(ab, n - (ab * k + 1) + 1);
            while(lo < hi){
                int mid = (lo + hi + 1) >> 1;
                if(get_hash(ab * k + 1, ab * k + mid) == H[mid]) lo = mid;
                else hi = mid - 1;
            }
            range_update(ab * k, ab * k + lo, 1);
        }
    }
    for(int i = 1; i <= n; i++)
        printf("%d", (range_query(i, i) > 0));
}