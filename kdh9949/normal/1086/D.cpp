#include <bits/stdc++.h>
using namespace std;

const int N = 200005, sz = 262144;

struct Seg{
    int d[2 * sz];
    void u(int x, int v){
        for(x += sz; x; x >>= 1) d[x] += v;
    }
    int g(int s, int e){
        int r = 0;
        for(s += sz, e += sz; s <= e; s >>= 1, e >>= 1){
            if( s & 1) r += d[s++];
            if(~e & 1) r += d[e--];
        }
        return r;
    }
    int mn(){
        int x; for(x = 1; x < sz; ){
            if(d[2 * x]) x = 2 * x;
            else x = 2 * x + 1;
        }
        return x - sz;
    }
    int mx(){
        int x; for(x = 1; x < sz; ){
            if(d[2 * x + 1]) x = 2 * x + 1;
            else x = 2 * x;
        }
        return x - sz;
    }
} R, P, S;

int n, q;
char a[N];

void u(char c, int x, int v){
    if(c == 'R') R.u(x, v);
    else if(c == 'P') P.u(x, v);
    else S.u(x, v);
}

int g(char c, int s, int e){
    if(c == 'R') return R.g(s, e);
    if(c == 'P') return P.g(s, e);
    return S.g(s, e);
}

int mn(char c){
    if(c == 'R') return R.mn();
    if(c == 'P') return P.mn();
    return S.mn();
}

int mx(char c){
    if(c == 'R') return R.mx();
    if(c == 'P') return P.mx();
    return S.mx();
}

int f(char r, char p, char s){
    int t = g(r, 1, n);
    int as = mn(p), ae = mn(s);
    int bs = mx(s), be = mx(p);
    if(ae < bs || be < as) return t - g(r, as, ae) - g(r, bs, be);
    return t - g(r, min(as, bs), max(ae, be));
}

int main(){
    scanf("%d%d%s", &n, &q, a + 1);
    for(int i = 1; i <= n; i++) u(a[i], i, 1);
    for(int i = 0; i <= q; i++){
        if(i){
            int x; char c[3];
            scanf("%d%s", &x, c);
            u(a[x], x, -1);
            a[x] = c[0];
            u(a[x], x, 1);
        }
        int r = R.g(1, n), p = P.g(1, n), s = S.g(1, n);
        if(!r && !p || !r && !s || !p && !s){ printf("%d\n", n); continue; }
        if(!r || !p || !s){
            if(!r) printf("%d\n", s);
            else if(!p) printf("%d\n", r);
            else printf("%d\n", p);
            continue;
        }
        printf("%d\n", f('R', 'P', 'S') + f('P', 'S', 'R') + f('S', 'R', 'P'));
    }
}