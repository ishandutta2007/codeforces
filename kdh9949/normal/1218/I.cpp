#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
#define x first
#define y second

const int N = 2005;

char str[N];
int n, a[N][N], b[N], p[4*N], c[4*N], cnt;

int f(int x){
    if(x == p[x]) return x;
    return p[x] = f(p[x]);
}

int main(){ ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> (str+1);
        for(int j = 1; j <= n; j++) a[i][j] = str[j]&1;
    }
    for(int i = 1; i <= n; i++){
        cin >> (str+1);
        for(int j = 1; j <= n; j++) a[i][j] ^= str[j]&1;
    }
    cin >> (str+1);
    for(int i = 1; i <= n; i++) b[i] = str[i]&1;
    iota(p, p + 4*n+3, 0);
    int T = 4*n+1, F = 4*n+2;
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++){
        switch(2*b[i] + b[j]){
        case 0:
            if(a[i][j]){ cout << "-1\n"; return 0; }
            break;
        case 1:
            p[f(i)] = f(a[i][j] ? T : F);
            break;
        case 2:
            p[f(j + n)] = f(a[i][j] ? T : F);
            break;
        case 3:
            if(a[i][j]){
                p[f(i)] = f(j + 3*n);
                p[f(i + 2*n)] = f(j + n);
            }
            else{
                p[f(i)] = f(j + n);
                p[f(i + 2*n)] = f(j + 3*n);
            }
            break;
        }
    }
    c[f(T)] = 1;
    c[f(F)] = -1;
    for(int i = 1; i <= 2*n; i++){
        if(f(i) == f(i + 2*n)){ cout << "-1\n"; return 0; }
        if(c[f(i)] && c[f(i)] == c[f(i + 2*n)]){ cout << "-1\n"; return 0; }
        if(!c[f(i)] && !c[f(i + 2*n)]) c[f(i)] = -1;
        if(!c[f(i)] && c[f(i + 2*n)]) c[f(i)] = -c[f(i + 2*n)];
        if(!c[f(i + 2*n)] && c[f(i)]) c[f(i + 2*n)] = -c[f(i)];
        if(c[f(i)] > 0) cnt++;
    }
    cout << cnt << '\n';
    for(int i = 1; i <= n; i++) if(c[f(i)] > 0) cout << "row " << i-1 << '\n';
    for(int i = 1; i <= n; i++) if(c[f(i + n)] > 0) cout << "col " << i-1 << '\n';
}