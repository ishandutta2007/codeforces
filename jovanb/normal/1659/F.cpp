#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 200000;

vector <int> graf[N+5];

int bit[N+5];
int p[N+5];

void bit_add(int x, int d){
    while(x <= N){
        bit[x] += d;
        x += x & -x;
    }
}

int bit_get(int x){
    int res = 0;
    while(x){
        res += bit[x];
        x -= x & -x;
    }
    return res;
}

void solve(){
    int n, x;
    cin >> n >> x;
    for(int i=1; i<=n; i++) graf[i].clear();
    for(int i=1; i<n; i++){
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    for(int i=1; i<=n; i++) cin >> p[i];
    int root = 0;
    for(int i=1; i<=n; i++){
        if(graf[i].size() == n - 1) root = i;
    }
    if(!root){
        cout << "Alice\n";
        return;
    }
    if(p[root] != root){
        if(x == root || x == p[root]){
            cout << "Bob\n";
            return;
        }
        for(int i=1; i<=n; i++){
            if(p[i] == root){
                swap(p[i], p[root]);
                break;
            }
        }
        x = root;
    }
    int num = 0;
    for(int i=1; i<=n; i++) if(p[i] != i) num++;
    if(num == 2){
        bool moze = 1;
        for(int i=1; i<=n; i++){
            if(p[i] != i) moze &= (p[i] != x);
        }
        if(moze){
            cout << "Alice\n";
            return;
        }
    }
    ll res = 1LL*n*(n-1)/2;
    for(int i=1; i<=n; i++){
        res -= bit_get(p[i]);
        bit_add(p[i], 1);
    }
    for(int i=1; i<=n; i++){
        bit_add(p[i], -1);
    }
    if(res == 0){
        cout << "Alice\n";
        return;
    }
    if(res%2 == 0){
        if(x == root) cout << "Bob\n";
        else cout << "Alice\n";
    }
    else{
        if(x == root) cout << "Alice\n";
        else cout << "Bob\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}