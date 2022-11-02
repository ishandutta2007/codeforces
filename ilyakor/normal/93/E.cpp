#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <queue>
#include <bitset>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>

#define mp make_pair
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x); }
template<class T> T sqr(T x) {return x * x; }

int64 n;
vector<int64> v;

int64 cnt;

const int BUBEN = 10000;
int64 d[BUBEN][110];

int64 dfs(int64 cur, int t) {
    if (cur <= 0) return 0;
    if (cur < BUBEN && d[cur][t] != -1) return d[cur][t];
    ++cnt;
    int64 res = cur;
    for (int i = t; i < sz(v); ++i) {
        if (cur >= v[i]) res -= dfs(cur / v[i], i + 1);
    }
    if (cur < BUBEN) d[cur][t] = res;
    return res;
}

int gcd(int x, int y) {return y == 0 ? x : gcd(y, x % y);}

int main()
{
    memset(d, -1, sizeof(d));
    cin >> n;
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int64 x;
        cin >> x;
        if (x == 1) {
            printf("0\n");
            return 0;
        }
        v.pb(x);
    }
    
/*  n = 10000000000000LL;
    int cnt = 0;
    for (int i = 2; ; ++i) {
        bool ok = true;
        for (int j = 0; j < sz(v); ++j) if (gcd(v[j], i) != 1) { ok = false;}
        if (!ok) continue;
        ++cnt;
        v.pb(i);
        if (sz(v) >= 100) break;
    }*/
    //cerr << "gen\n";

    sort(all(v));
    v.erase(unique(all(v)), (v).end());
    reverse(all(v));
    int64 res = dfs(n, 0);
    //cerr << (::cnt) << "\n";
    cout << res << "\n";
    return 0;
}