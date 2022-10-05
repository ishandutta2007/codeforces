#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
#define x first
#define y second

const int N = 100005;

int n, m, k, v[N];
vector<int> sp;
vector<pii> e[N];

void g(int x, int z){
    v[x] = 1;
    for(pii i : e[x]){
        if(i.y > z) continue;
        if(!v[i.x]) g(i.x, z);
    }
}

int f(int x){
    fill(v+1, v+n+1, 0);
    g(sp[0], x);
    for(int i : sp) if(!v[i]) return 0;
    return 1;
}

int main(){
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0, x; i < k; i++){ scanf("%d", &x); sp.push_back(x); }
    for(int i = 0, x, y, z; i < m; i++){
        scanf("%d%d%d", &x, &y, &z);
        e[x].push_back({y, z});
        e[y].push_back({x, z});
    }
    int s = 1, e = int(1e9)+5;
    while(s < e){
        int mi = (s+e)/2;
        if(f(mi)) e = mi;
        else s = mi+1;
    }
    for(int i = 0; i < k; i++) printf("%d ", s);
}