#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <set>
#include <cstdlib>
#include <assert.h>
#include <map>
#include <cstring>
#include <bitset>

#define FOR(a,b,c) for (int c = (int)(a); c < (int)(b); ++c)
#define REP(n,i) FOR(0,n,i)
#define pb push_back
#define ll long long
#define pii pair < int, int >
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

int n, m;
string p;

vector < ll > h;
const int H = 101;
const int Mod = 1000000007;
ll Pot[1000005];

ll Hash(int lo, int hi){
    ll t = (h[hi] - h[lo-1] * Pot[hi-lo+1]) % Mod;
    if (t < 0) return t + Mod;
    return t;
}

int main(){
    Pot[0] = 1;
    REP(1000000,i) Pot[i+1] = (Pot[i] * H) % Mod;
    cin >> n >> m >> p;
    if (m == 0){
        ll r = 1;
        REP(n,i) r = (r * 26) % Mod;
        printf("%d\n", (int)r);
        return 0;
    }
    h.pb(0);
    for (auto x : p) h.pb((h.back() * H + x) % Mod);
    int prev, cnt = 0;
    cin >> prev;
    cnt += prev-1;
    REP(m-1,i){
        int y;
        cin >> y;
        if (y - prev >= p.size()) cnt += y - prev - p.size();
        else { // presjek
            int l = p.size() - y + prev;
            if (Hash(1, l) != Hash((int)p.size()-l+1, (int)p.size())){printf("0\n"); return 0;}
        } prev = y;
    } cnt += n - prev - p.size() + 1;
    ll r = 1;
    REP(cnt,i) r = (r * 26) % Mod;
    printf("%d\n", (int)r);
    return 0;
}