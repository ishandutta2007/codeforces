#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstdlib>
#include <queue>

#define X first
#define Y second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < ll, ll > pii;
typedef pair < ll, ll > pll;
typedef vector < ll > vi;
typedef vector < ll > vl;

const ll N = 5e5 + 500;
const ll M = 1e6 + 500;
const ll INF = 0x3f3f3f3f;
const ll MOD = 1e9 + 7;
const ll LOG = 20;
const ll OFF = (1 << LOG);
const double EPS = 1e-9;
const double PI = 3.1415926535;

ll fak[N], inv[N];
char A[N], B[N], S[N];
ll x00, x01, x10, x11, n;

inline ll mul(ll A, ll B){
    return A * B % MOD;
}

inline ll add(ll A, ll B){
    if(A + B >= MOD) return A + B - MOD;
    return A + B;
}

inline ll sub(ll A, ll B){
    if(A - B < 0) return A - B + MOD;
    return A - B;
}

inline ll pot(ll A, ll B){

    ll sol = 1, cur = A;
    for(; B ; B >>= 1){
        if(B&1) sol = mul(sol, cur);
        cur = mul(cur, cur);
    }
    return sol;
}

inline ll choose(ll n, ll k){
    if(n < 0){
        if(k % 2 == 0) return 1;
        return -1;
    }
    return mul(fak[n], mul(inv[k], inv[n - k]));
}

ll kol(ll n, ll blok0, ll blok1, ll kol0, ll kol1){
    if(kol0 + kol1 != n || blok0 > kol0 || blok1 > kol1 || (blok0 == 0 && kol0 > 0) || (blok1 == 0 && kol1 > 0)) return 0;
    return mul(choose(kol0 - 1, kol0 - blok0), choose(kol1 - 1, kol1 - blok1));
}

ll kol2(ll c00, ll c01, ll c10, ll c11){
    //prllf("%d %d %d %d\n", c00, c01, c10, c11);
    ll n = c00 + c11 + c01 + c10 + 1;
    if(abs(c01 - c10) > 1) return 0;
    if(c10 - c01 > 0) return 0;
    if(c01 != c10){
        return kol(n, max(c01, c10), max(c01, c10), c00 + max(c01, c10), c11 + max(c01, c10));
    }
    else{
        return kol(n, c01 + 1, c10, c00 + c01 + 1, c11 + c10);
    }
}

ll brute(ll c00, ll c01, ll c10, ll c11, ll l,ll r){
    ll sol = 0;
    for(ll i = l;i<=min(1LL << n, r);i++){
        ll r00 = 0, r01 = 0, r10 = 0, r11 = 0, st = 0;
        if(!(i & ( 1 << (n - 1)))) continue;
        for(ll j = n-2;j>=0;j--){
            ll x = !!(i & (1 << (j + 1))), y = !!(i & (1 << (j)));
            if(!x && !y) r00++;
            if(!x && y) r01++;
            if(x && !y) r10++;
            if(x && y) r11++;
        }
        /**
        if(c00 == r00 && c01 == r01 && c10 == r10 && c11 == r11){
            printf("\n");
            for(ll j = n-1;j>=0;j--) printf("%d", !!(i & (1 << j)));
            printf("\n");
        }
        **/
        sol += (c00 == r00 && c01 == r01 && c10 == r10 && c11 == r11);
    }
    return sol;
}

void precompute(){
    fak[0] = 1, inv[0] = 1;
    for(ll i = 1;i<N;i++){
        fak[i] = mul(i, fak[i - 1]);
        inv[i] = pot(fak[i], MOD - 2);
    }
}

ll solve(ll include){
    ll y00 = x00, y01 = x01, y10 = x10, y11 = x11;
    ll sol = 0;
    for(ll i = 1;i<n;i++){
        if(A[i] == '1'){
            if(A[i - 1] == '0') y00--;
            else y10--;
            if(min(min(y01, y00), min(y10, y11)) >= 0)
                sol = add(kol2(y00, y01, y10, y11), sol);
            if(A[i - 1] == '0') y00++;
            else y10++;
        }
        if(A[i - 1] == '0' && A[i] == '0') y00--;
        if(A[i - 1] == '0' && A[i] == '1') y01--;
        if(A[i - 1] == '1' && A[i] == '0') y10--;
        if(A[i - 1] == '1' && A[i] == '1') y11--;
        if(min(min(y01, y00), min(y10, y11)) < 0) break;
    }
    if(y00 == 0 && y01 == 0 && y10 == 0 && y11 == 0 && include) sol = add(sol, 1);
    return sol;
}

int main(){
    precompute();
    scanf("%s", A);
    scanf("%s", B);
    //prllf("\n%d %d\n", l, r);
    scanf("%lld%lld%lld%lld", &x00, &x01, &x10, &x11);
    n = x00 + x01 + x10 + x11 + 1;
    if(strlen(A) > n){
        printf("0\n");
        return 0;
    }
    if(strlen(B) < n){
        printf("0\n");
        return 0;
    }
    if(n == 1){
        ll sol = (A[0] == '0');
        if(strlen(B) > 1) sol++;
        else if(strlen(B) == 1 && B[0] == '1') sol++;
        printf("%d\n", sol);
        return 0;
    }
    if(strlen(A) < n){
        A[0] = '1';
        A[n] = '\0';
        for(ll i = 1;i<n;i++) A[i] = '0';
    }
    if(strlen(B) > n){
        B[n] = '\0';
        for(ll i = 0;i<n;i++) B[i] = '1';
    }
    ll l = 0, r = 0;
    for(ll i = 0;i<strlen(A);i++) l = 2 * l + A[i] - '0';
    for(ll i = 0;i<strlen(B);i++) r = 2 * r + B[i] - '0';
    ll sol = solve(0);
    swap(A, B);
    sol = sub(solve(1), sol);
    printf("%d\n", sol);
    //printf("Brute : %lld\n", brute(x00, x01, x10, x11, l, r));
    return 0;
}