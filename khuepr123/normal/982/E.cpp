/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
*/
// lethal option

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define fi first
#define se second
#define ii pair<int, int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const int maxN = 300005;
const ll oo = 1e18 + 7;
int x, y, z, k;
int vx, vy;

int fk = 0;
void output(int nn, int mm){
    if(fk == -1){
        cout << "-1\n";
        exit(0);
    }
    if(fk) cout << mm << " " << nn << endl;
    else cout << nn << " " << mm << endl;
    exit(0);
}

int pw(int num, int coef, int md){
    int res = 1;
    while(coef){
        if(coef & 1) res = (res * num) % md;
        num = (num * num) % md;
        coef >>= 1;
    }
    return res;
}

int solve_coef(int n, int coef, int m){
    // b so that n * b = coef(mod m)
    int cop = m;
    int pwer = m;
    for1(i, 2, maxN){
        if(cop % i == 0){
            while(cop % i == 0){
                cop /= i;
            }
            pwer = pwer * (i - 1) / i;
        }
    }
    if(cop > 1) pwer = pwer / cop * (cop - 1);
    return (coef * pw(n, pwer - 1, m)) % m;
}

ii solve(int m, int n, int coef){
    // solve ma + nb = coef
    int a, b;
    if(coef % __gcd(m, n)){
        fk = -1; output(0, 0);
    }
    k = __gcd(m, n);
    m /= k; n /= k; coef /= k;
    b = solve_coef(n, coef, m);
    a = (coef - n * b) / m;
    return ii(a, b);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int m, n, a, b;
    cin >> n >> m >> x >> y >> vx >> vy;
    if(vx == -1){
        vx = 1;
        x = 0 - x;
    }
    if(vy == -1){
        vy = 1;
        y = 0 - y;
    }

    if(vx == 0){
        swap(x, y);
        swap(vx, vy);
        swap(n, m);
        fk = 1;
    }

    if(vy == 0){
        if(y % m){
            fk = -1; output(0, 0);
        }
        if(y == 0){
            if(x <= 0) output(0, 0);
            output(n, 0);
        }
        if(x <= 0) output(0, m);
        output(n, m);
    }
    int coef = y - x;
    // find a, b such that ma - nb = coef
    ii pr = solve(m, n, coef);
    a = pr.fi; b = 0 - pr.se;
    a *= m; b *= n; swap(a, b);
    // condition: a >= x; b >= y;
    a += m * n;
    b += m * n;
    int ds = a - x;
    int len = m * n / __gcd(m, n);
    ds %= len;
    cout << (x + ds) % (n * 2) << " ";
    cout << (y + ds) % (m * 2) << " ";

}