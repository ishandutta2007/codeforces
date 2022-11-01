#include <functional>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <string>
#include <vector>
#include <ctime>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); i++)
#define ford(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define eq(x, y) (abs((x)-(y))<eps)
#define lt(x, y) ((x)<(y)-eps)
#define le(x, y) ((x)<=(y)+eps)
#define gt(x, y) ((x)>(y)+eps)
#define ge(x, y) ((x)>=(y)-eps)
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int inf = 1e9+100500;
const int maxn = 100500;

string bin(int x, int n) {
    string s = "";
    forn(i, n) s += '0'+x%2, x /= 2;
    return string(s.rbegin(), s.rend());
}

void scan()
{
}

int solve(int x, int n)
{
    int res = 0;
    forn(b, 1<<n) forn(a, b)
        res += ((a^x) > (b^x));
    return res;
}

void solve() {
    int n;
    string x;
    cin >> x;
    n = x.length();

    i64 mod = 1000000007;
    i64 res = 0;
    i64 t = 1;
    ford(i, n) {
        if (x[i] == '1') 
            res = (res + t) % mod;
        t = t*2ll%mod;
    }
    forn(i, n-1) res = res*2ll%mod;
    cout << res << endl;
}

int main()
{
    solve();
    //int n = 5;
    //forn(i, 1<<n) cout << bin(i, n) << " " << i << ": " << solve(i, n) << endl;

#ifdef HOME
    cerr << "time = " << clock()/1000 << " ms" << endl;
#endif
    return 0;
}