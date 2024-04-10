#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <ctime>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;
const int inf = 1e9+100500;

const int maxn = 100500;

string s, t;
int p;
vi a, b;
string r;
int n;

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    cin >> n >> p >> s >> t;
    r = string(s.length(), '.');
    forn(i, s.length()) {
        if (s[i] == t[i]) a.pb(i);
        else b.pb(i);
    }
    while (p && !b.empty() && ((int)b.size())/2 <= p-1) {
        int i = b.back(); b.pop_back();
        fore(c, 'a', 'z') if (s[i] != c && t[i] != c) {
            r[i] = c;
            break;
        }
        --p;
    }

    if ((int)b.size()/2 > p) {
        cout << -1 << endl;
        return 0;
    }

    if (b.size()%2) {
        cout << -1 << endl;
        return 0;
    }

    forn(i, b.size()) {
        if (i%2) r[b[i]] = s[b[i]], --p;
        else r[b[i]] = t[b[i]];
    }

    forn(i, a.size()) r[a[i]] = s[a[i]];
    forn(i, p) r[a[i]] = 'a'+(s[a[i]]-'a'+1)%26;


    cout << r << endl;

#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}