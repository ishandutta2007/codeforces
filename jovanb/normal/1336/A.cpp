#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

vector <int> graf[200005];
int sz[200005];
int dpt[200005];

void dfs_size(int v, int par, int dept){
    sz[v] = 1;
    dpt[v] = dept;
    for(auto c : graf[v]){
        if(c == par) continue;
        dfs_size(c, v, dept+1);
        sz[v] += sz[c];
    }
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, k;
    cin >> n >> k;
    for(int i=1; i<n; i++){
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    ll res = n-1;
    dfs_size(1, 0, 0);
    priority_queue <pair <int, int>> pq;
    for(auto c : graf[1]){
        pq.push({(sz[c]-1)-dpt[c], c});
    }
    k = n-k-1;
    while(k--){
        pair <int, int> x = pq.top();
        pq.pop();
        res += x.first;
        for(auto c : graf[x.second]){
            if(dpt[c] < dpt[x.second]) continue;
            pq.push({(sz[c]-1)-dpt[c], c});
        }
    }
    cout << res;
    return 0;
}