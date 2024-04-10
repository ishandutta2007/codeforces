#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 100005;
const ll INF = ll(1e16);

int n;
char a[N];
ll sx, sy, ex, ey;

int f(ll x){
    ll A = 0, B = 0, C = 0, D = 0;
    for(int i = 0; i < n; i++){
        ll t = x / n + (x % n > i);
        if(a[i] == 'L' || a[i] == 'D') A -= 2 * t;
        else C += 2 * t;
        if(a[i] == 'L' || a[i] == 'U') B -= 2 * t;
        else D += 2 * t;
    }
    return (A <= ex && ex <= C && B <= ey && ey <= D);
}

int main(){
    scanf("%lld%lld%lld%lld%d%s", &sx, &sy, &ex, &ey, &n, a);
    sx = ex - sx;
    sy = ey - sy;
    ex = sx + sy;
    ey = sx - sy;
    ll s = 0, e = INF;
    while(s <= e){
        ll m = (s + e) / 2;
        if(f(m)) e = m - 1;
        else s = m + 1;
    }
    if(s >= INF) puts("-1");
    else printf("%lld\n", s);
}