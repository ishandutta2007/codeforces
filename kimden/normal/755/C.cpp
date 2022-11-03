#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using ull = unsigned long long;

const int MAXN = 10002;
int pred[MAXN];
int sz[MAXN];
int ans;

void make_set(int u){
    pred[u] = u;
    sz[u] = 1;
    ans++;
}

int get(int u){
    if(pred[u] == u){
        return u;
    }
    return pred[u] = get(pred[u]);
}

void join(int u, int v){
    u = get(u);
    v = get(v);
    if(u == v){
        return;
    }
    if(sz[u] > sz[v]){
        swap(u, v);
    }
    pred[u] = v;
    sz[v] += sz[u];
    ans--;
}



int main() {
    int n;
    cin >> n;
    int p;
    ans = 0;
    for(int i = 0; i < n; i++){
        make_set(i);
    }
    for(int i = 0; i < n; i++){
        cin >> p;
        join(i, p - 1);
    }
    cout << ans << endl;
    return 0;
}