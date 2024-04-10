#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
#define x first
#define y second

const int N = 200005;

int n, q, a[N], s[N], e[N], c[N], p[N], r;
vector<pair<pii, int>> v;

int f(int x){
    if(x == p[x]) return x;
    return p[x] = f(p[x]);
}

void u(int x, int y){
    x = f(x); y = f(y);
    if(x == y) return;
    p[y] = x;
    c[x] = max(c[x], c[y]);
}

int main(){ ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(!s[a[i]]) s[a[i]] = i;
        e[a[i]] = i;
        c[a[i]]++;
    }
    for(int i = 1; i < N; i++) if(s[i]) v.push_back(make_pair(pii(s[i], e[i]), i));
    sort(v.begin(), v.end());
    iota(p, p + N, 0);
    int l = v[0].y;
    for(auto &i : v){
        if(i.x.x <= e[l]) u(l, i.y);
        if(e[l] < i.x.y) l = i.y; 
    }
    r = n;
    for(int i = 1; i < N; i++) if(f(i) == i) r -= c[i];
    cout << r << '\n';
}