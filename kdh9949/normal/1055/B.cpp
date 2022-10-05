#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 100005;

int n, q, b[N], r;
ll a[N], l;

int f(int x){
    return b[x] && !b[x-1];
}

void u(int x, ll y){
    r -= f(x) + f(x+1);
    a[x] += y;
    b[x] = (a[x] > l);
    r += f(x) + f(x+1);
}

int main(){
    scanf("%d%d%lld", &n, &q, &l);
    for(int i = 1; i <= n; i++){
        ll x; scanf("%lld", &x);
        u(i, x);
    }
    for(int t; q--; ){
        scanf("%d", &t);
        if(t==0) printf("%d\n", r);
        else{
            int i; ll x; scanf("%d%lld", &i, &x);
            u(i, x);
        }
    }
    return 0;
}