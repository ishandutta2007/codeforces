#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using pli=pair<ll, int>;
#define x first
#define y second

const int N=300005;
const ll inf=ll(1e18);

struct E{ int x; ll c; int i; };

int n, m, k, v[N];
ll d[N];
vector<E> e[N];
vector<int> r;
priority_queue<pli, vector<pli>, greater<pli>> pq;

int main(){
    scanf("%d%d%d", &n, &m, &k);
    for(int i=1; i<=m; i++){
        int x, y; ll z; scanf("%d%d%lld", &x, &y, &z);
        e[x].push_back({y, z, i});
        e[y].push_back({x, z, i});
    }
    fill(d+2, d+n+1, inf);
    pq.push({0, 1});
    while(!pq.empty()){
        int cx=pq.top().y; ll cd=pq.top().x;
        pq.pop();
        if(cd>d[cx]) continue;
        if(v[cx]) r.push_back(v[cx]);
        for(E i:e[cx]){
            if(cd+i.c<d[i.x]){
                d[i.x]=cd+i.c;
                v[i.x]=i.i;
                pq.push({d[i.x], i.x});
            }
        }
    }
    printf("%d\n", min(k, int(r.size())));
    for(int i=0; i<min(k, int(r.size())); i++) printf("%d ", r[i]);
}