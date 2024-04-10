#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int niz[200005];
int p[200005];
int res[200005];
vector <int> vec;
vector <int> graf[200005];

void dfs1(int v, int parent){
    for(auto c : graf[v]){
        if(c == parent) continue;
        res[c] = __gcd(res[v], niz[c]);
        dfs1(c, v);
    }
}

void dfs2(int v, int parent, int g){
    for(auto br : vec){
        if(niz[v]%br == 0) p[br]++;
    }
    for(auto br : vec){
        if(p[br] >= g-1) res[v] = max(res[v], br);
    }
    for(auto c : graf[v]){
        if(c == parent) continue;
        dfs2(c, v, g+1);
    }
    for(auto br : vec){
        if(niz[v]%br == 0) p[br]--;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> niz[i];
    }
    for(int i=1; i<n; i++){
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    res[1] = 0;
    dfs1(1, 0);
    res[1] = niz[1];
    for(int i=1; i<=niz[1]; i++){
        if(niz[1]%i == 0) vec.push_back(i);
    }
    dfs2(1, 0, 1);
    for(int i=1; i<=n; i++) cout << res[i] << " ";
    return 0;
}