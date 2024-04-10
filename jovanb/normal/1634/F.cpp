#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 300000;
int MOD;

int add(int a, int b){ a += b; if(a >= MOD) a -= MOD; return a; }
int sub(int a, int b){ return add(a, MOD - b); }

int a[N+5];
int fib[N+5];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, qrs;
    cin >> n >> qrs >> MOD;
    for(int i=1; i<=n; i++) cin >> a[i];
    fib[1] = fib[2] = 1%MOD;
    for(int i=3; i<=n; i++) fib[i] = add(fib[i-1], fib[i-2]);
    int nule = 0;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        a[i] = sub(a[i], x);
    }
    for(int i=n; i>=1; i--){
        if(i >= 2) a[i] = sub(a[i], a[i-1]);
        if(i >= 3) a[i] = sub(a[i], a[i-2]);
        if(a[i] == 0) nule++;
    }
    while(qrs--){
        char c;
        int l, r;
        cin >> c >> l >> r;
        if(a[l] == 0) nule--;
        if(c == 'A') a[l] = add(a[l], 1);
        else a[l] = sub(a[l], 1);
        if(a[l] == 0) nule++;
        if(r + 1 <= n){
            if(a[r+1] == 0) nule--;
            if(c == 'A'){
                a[r+1] = sub(a[r+1], fib[r-l+1]);
                a[r+1] = sub(a[r+1], fib[r-l]);
            }
            else{
                a[r+1] = add(a[r+1], fib[r-l+1]);
                a[r+1] = add(a[r+1], fib[r-l]);
            }
            if(a[r+1] == 0) nule++;
        }
        if(r + 2 <= n){
            if(a[r+2] == 0) nule--;
            if(c == 'A') a[r+2] = sub(a[r+2], fib[r-l+1]);
            else a[r+2] = add(a[r+2], fib[r-l+1]);
            if(a[r+2] == 0) nule++;
        }
        if(nule == n) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}