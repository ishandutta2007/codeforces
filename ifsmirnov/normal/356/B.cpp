#include <functional>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>
#include <ctime>
#include <map>
#include <set>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); i++)
#define ford(i, n) for (int i = (int)(n)-1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
#define se second
#define fi first
#define mp make_pair
#define pb push_back
#define op operator
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned u32;
typedef double ld;
const int maxn = 1000500;

i64 gcd(i64 a, i64 b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

i64 a, b;
int n, m;
char s[maxn], t[maxn];
int cs[200], ct[200];

void scan() {
    cin >> a >> b >> s >> t;
    n = strlen(s); m = strlen(t);
}

i64 solve(const string& s, const string& t) {
    forn(i, 26) cs[i] = ct[i] = 0;
    forn(i, s.length()) ++cs[s[i]-'a'];
    i64 res = 0;
    forn(i, t.length()) {
        res += s.length() - cs[t[i]-'a'];
    }
    return res;
}

void solve() {
    i64 res = 0;
    int g = gcd(n, m);
    forn(i, g) {
        string ns, nt;
        for (int j = i; j < n; j += g) ns += s[j];
        for (int j = i; j < m; j += g) nt += t[j];
        res += solve(ns, nt);
    }
    cout << res * gcd(a, b) << endl;
}

int main()
{
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    scan();
    solve();

#ifdef HOME
    std::cerr << "Time = " << clock()/1000 << " ms" << std::endl;
#endif
    return 0;
}