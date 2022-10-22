#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MAXN = 1000000;

struct cl{
    ll x, y, a;
    bool operator <(const cl &g){
        return x < g.x;
    }
} niz[MAXN+5];

struct line{
    ll k, n;
    ll eval(ll x){
        return k*x + n;
    }
    ld presek(line g){
        return 1.0*(n - g.n)/(g.k - k);
    }
};

deque <line> lines;

ll query(ll x){
    while(lines.size() > 1 && lines[lines.size()-1].eval(x) <= lines[lines.size()-2].eval(x)) lines.pop_back();
    return lines.back().eval(x);
}

void dodaj(line duz){
    while(lines.size() > 1 && lines[1].presek(lines[0]) <= lines[1].presek(duz)) lines.pop_front();
    lines.push_front(duz);
}

ll dp[MAXN+5];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> niz[i].x >> niz[i].y >> niz[i].a;
    }
    sort(niz+1, niz+1+n);
    ll res = 0;
    line nula;
    nula.k = 0;
    nula.n = 0;
    dodaj(nula);
    for(int i=1; i<=n; i++){
        dp[i] = query(niz[i].y) + niz[i].x*niz[i].y - niz[i].a;
        res = max(res, dp[i]);
        line nv;
        nv.k = -niz[i].x;
        nv.n = dp[i];
        dodaj(nv);
    }
    cout << res << "\n";
    return 0;
}