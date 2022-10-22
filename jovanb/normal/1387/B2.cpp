#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int n;
vector <int> graf[100005];

int sz[100005];
ll res;

void dfs_size(int v, int p){
    sz[v] = 1;
    for(auto c : graf[v]){
        if(c == p) continue;
        dfs_size(c, v);
        sz[v] += sz[c];
    }
    res += min(sz[v], n-sz[v]);
}

int find_centroid(int v, int p){
    for(auto c : graf[v]){
        if(c != p && sz[c]*2 > n) return find_centroid(c, v);
    }
    return v;
}

int k;
int niz[100005];
int org[100005];
int pm[100005];
int gde[100005];

void shiftuj(int len){
    for(int i=1; i<=n; i++){
        pm[i] = niz[i];
    }
    for(int i=len+1; i<=n; i++){
        niz[i] = pm[i-len];
    }
    for(int i=1; i<=len; i++){
        niz[i] = pm[n-len+i];
    }
}

void dfs(int v, int p){
    niz[++k] = v;
    org[k] = niz[k];
    for(auto c : graf[v]){
        if(c != p) dfs(c, v);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
	cout.precision(10);
	cout << fixed;

    cin >> n;
    for(int i=1; i<n; i++){
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    dfs_size(1, 0);
    int cen = find_centroid(1, 0);
    cout << 2*res << "\n";
    int len = n-sz[cen];
    for(auto c : graf[cen]){
        dfs(c, cen);
        if(sz[c] < sz[cen]) len = max(len, sz[c]);
    }
    niz[++k] = cen;
    org[k] = cen;
    shiftuj(len);
    for(int i=1; i<=n; i++){
        gde[org[i]] = niz[i];
    }
    for(int i=1; i<=n; i++) cout << gde[i] << " ";
    return 0;
}