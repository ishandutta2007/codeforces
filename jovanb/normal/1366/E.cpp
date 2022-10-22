#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MOD = 998244353;

int add(int a, int b){
    a += b;
    if(a >= MOD) a -= MOD;
    return a;
}

int mul(int a, int b){
    return (1LL*a*b)%MOD;
}

int a[200005];
int b[200005];
pair <int, int> d[200005];
map <int, int> posl;
int maxl[200005];
int minr[200005];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        a[i] *= 2;
        d[i].first = a[i];
        d[i].second = i;
    }
    for(int i=1; i<=m; i++){
        cin >> b[i];
        b[i] *= 2;
    }
    sort(d+1, d+1+n);
    if(d[1].first < b[1]){
        cout << 0;
        return 0;
    }
    int tj = 1;
    for(int i=1; i<=m; i++){
        while(tj <= n && d[tj].first < b[i]){
            a[d[tj].second] = b[i-1] + 1;
            tj++;
        }
        while(tj <= n && d[tj].first == b[i]) tj++;
    }
    for(int i=1; i<=n; i++){
        posl[a[i]] = i;
    }
    for(int i=1; i<=m; i++){
        minr[i] = max(posl[b[i]], posl[b[i]+1]);
        maxl[i] = posl[b[i]];
    }
    int res = 1;
    if(!maxl[1]){
        cout << 0;
        return 0;
    }
    for(int i=1; i<m; i++){
        if(minr[i] >= maxl[i+1]){
            cout << 0;
            return 0;
        }
        res = mul(res, maxl[i+1] - minr[i]);
    }
    cout << res;
    return 0;
}