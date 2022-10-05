#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
#define X first
#define Y second

const int N = 500005;

int n, k, m, p[N], t[N], d[N];
ll r;
vector<int> a[N];
vector<pair<ll, pii>> e, q;

int f(int x){
    return p[x] = (x == p[x] ? x : f(p[x])); 
}
void u(int x, int y){
    p[f(y)] = f(x);
}

void g(int x, int p, int z){
    t[x] = p;
    d[x] = z;
    for(int i : a[x]) if(i != p) g(i, x, z + 1);
}

int main(){
    scanf("%d%d%d", &n, &k, &m);
    iota(p + 1, p + n + 1, 1);
    for(int i = 0, x, y; i < k; i++){
        scanf("%d%d", &x, &y);
        u(x, y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for(int i = 0, x, y, z; i < m; i++){
        scanf("%d%d%d", &x, &y, &z);
        e.push_back({ll(z), {x, y}});
    }
    sort(e.begin(), e.end());
    for(auto i : e){
        if(f(i.Y.X) != f(i.Y.Y)){
            u(i.Y.X, i.Y.Y);
            a[i.Y.X].push_back(i.Y.Y);
            a[i.Y.Y].push_back(i.Y.X);
            q.push_back({0, i.Y});
        }
        else q.push_back(i);
    }
    g(1, 0, 0);
    sort(q.begin(), q.end());
    iota(p + 1, p + n + 1, 1);
    for(auto i : q){
        int x = f(i.Y.X), y = f(i.Y.Y);
        while(x != y){
            r += i.X;
            if(d[x] > d[y]) u(t[x], x);
            else u(t[y], y);
            x = f(x); y = f(y);
        }
    }
    for(int i = 2; i <= n; i++) if(f(1) != f(i)){ puts("-1"); return 0;}
    printf("%lld\n", r);
    return 0;
}