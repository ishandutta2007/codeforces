#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 1000000000;

const int MAXN = 500000;

int bit[MAXN+5];

map <int, int> posl;
int a[MAXN+5];

void upd(int x, int val){
    while(x <= MAXN){
        bit[x] = min(bit[x], val);
        x += x & -x;
    }
}

int query(int x){
    int res = INF;
    while(x){
        res = min(res, bit[x]);
        x -= x & -x;
    }
    return res;
}

vector <pair <int, int>> queries[MAXN+5];

int sol[MAXN+5];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, m;
    cin >> n >> m;
    for(int i=1; i<=MAXN; i++) bit[i] = INF;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    for(int i=1; i<=m; i++){
        int l, r;
        cin >> l >> r;
        queries[r].push_back({l, i});
    }
    for(int i=1; i<=n; i++){
        if(posl[a[i]]){
            upd(n+1-posl[a[i]], i - posl[a[i]]);
        }
        for(auto c : queries[i]){
            sol[c.second] = query(n+1-c.first);
        }
        posl[a[i]] = i;
    }
    for(int i=1; i<=m; i++){
        cout << (sol[i] == INF ? -1 : sol[i]) << "\n";
    }
    return 0;
}