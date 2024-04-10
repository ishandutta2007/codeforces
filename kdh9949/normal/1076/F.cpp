#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N=300005;

int n;
ll k, a[N], b[N], am=1, bm=1;

ll f(ll a, ll x, ll y, int z){
    if(z==0){
        if(x>=y){
            return max(1LL, x-y*k+a);
        }
        else{
            if(y<=k*x) return 1;
            return k+1;
        }
    }
    else{
        if(x>=y){
            if(x<=k*y-a) return 1;
            return k+1;
        }
        else{
            return max(1LL, y-x*k);
        }
    }
}

int main(){
    scanf("%d%lld", &n, &k);
    for(int i=0; i<n; i++) scanf("%lld", a+i);
    for(int i=0; i<n; i++) scanf("%lld", b+i);
    for(int i=0; i<n; i++){
        ll nam=k+1, nbm=k+1;
        if(am<=k){
            nam=min(nam, f(am, a[i], b[i], 0));
            nbm=min(nbm, f(am, a[i], b[i], 1));
        }
        if(bm<=k){
            nam=min(nam, f(bm, b[i], a[i], 1));
            nbm=min(nbm, f(bm, b[i], a[i], 0));
        }
        am=nam; bm=nbm;
        if(am>k&&bm>k){ puts("NO"); return 0; }
    }
    puts("YES");
}