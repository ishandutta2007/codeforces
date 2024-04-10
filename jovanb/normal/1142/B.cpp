#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int last[200005];
int f[18][200005];
int mn[200005];
int a[200005];
int sled[200005];
int x[200005];

int gde(int a, int b){
    for(int j=17; j>=0; j--){
        if((1<<j)&b) a = f[j][a];
    }
    return a;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, m, q;
    cin >> n >> m >> q;
    for(int i=1; i<=n; i++){
        cin >> x[i];
        sled[x[i-1]] = x[i];
    }
    sled[x[n]] = x[1];
    for(int i=1; i<=m; i++){
        cin >> a[i];
    }
    for(int i=n; i>=1; i--){
        last[i] = m+5;
    }
    for(int j=0; j<=17; j++) f[j][m+5] = m+5;
    for(int i=m; i>=1; i--){
        f[0][i] = last[sled[a[i]]];
        last[a[i]] = i;
    }
    for(int j=1; j<18; j++){
        for(int i=1; i<=m; i++){
            f[j][i] = f[j-1][f[j-1][i]];
        }
    }
    mn[m+1] = m+5;
    for(int i=m; i>=1; i--){
        mn[i] = min(mn[i+1], gde(i, n-1));
    }
    while(q--){
        int l, r;
        cin >> l >> r;
        if(mn[l] <= r) cout << 1;
        else cout << 0;
    }
    return 0;
}