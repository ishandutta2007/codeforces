#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 100005;

int n;
ll a[N], g, gf, w, wf, r, ww;
char s[N];

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%lld", a + i);
    scanf("%s", s);
    for(int i = 0; i < n; i++){
        if(s[i] == 'W'){
            w += a[i];
            wf += a[i];
            ww = 1;
        }
        else if(s[i] == 'G'){
            ll t = a[i];
            ll u = min(wf, a[i]);
            t -= u;
            wf -= u;
            w += u;
            gf += 2 * u;

            g += t;
            gf += t;
        }
        else{
            ll t = a[i];
            
            ll u = min(t, wf);
            t -= u;
            wf -= u;
            w += u;

            u = min(t, gf);
            t -= u;
            gf -= u;
            g += u;
            
            if(ww){
                w += 2 * t;
                t = 0;
            }

            g += 2 * t;
            
            r += 2 * a[i];
        }
        //printf("%d : %lld %lld %lld %lld %lld\n", i + 1, r, wf, gf, w, g);
    }
    printf("%lld\n", (r + wf + gf + 3 * w + 5 * g) / 2);
}