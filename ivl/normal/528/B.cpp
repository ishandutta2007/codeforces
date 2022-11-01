#include <bits/stdc++.h>

#define FOR(a,b,c) for (int c = (int)(a); c < (int)(b); ++c)
#define REP(n,i) FOR(0,n,i)
#define pii pair < int, int >
#define x first
#define y second
#define ll long long
#define pb push_back

#define TRACE(x) cerr << #x << " = " << x << endl

using namespace std;

int n;
pii p[200005];

int r[400005];
vector < int > ev[400005];

template < class T >
inline void makemax(T &x, T y){if (x < y) x = y;}

int main(){
    cin >> n;
    REP(n,i){
        int x, y;
        scanf("%d%d", &x, &y);
        p[i] = {x-y, x+y};
    }

    vector < int > V = {-1};
    REP(n,i) V.pb(p[i].x), V.pb(p[i].y);
    sort(V.begin(), V.end());
    auto tmp = unique(V.begin(), V.end()) - V.begin();
    while (V.size() > tmp) V.pop_back();
    REP(n,i) p[i].x = lower_bound(V.begin(), V.end(), p[i].x) - V.begin(), p[i].y = lower_bound(V.begin(), V.end(), p[i].y) - V.begin();

    REP(n,i) ev[p[i].y].pb(i);

    FOR(1,400005,i){r[i] = r[i-1]; for (auto x : ev[i]) makemax(r[i], 1 + r[p[x].x]);}
    cout << r[400004] << endl;

    return 0;
}