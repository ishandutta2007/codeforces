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

const int maxn = 200500;

char s[maxn], t[maxn];

void norm(char s[], int l, int r) {
    if ((r-l)%2) {
        return;
    }
    int m = (r+l)/2;
    norm(s, l, m);
    norm(s, m, r);
    if (!lexicographical_compare(s+l, s+m, s+m, s+r)) {
        forn(i, r-m) swap(s[l+i], s[m+i]);
    }
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    cin >> s >> t;
    int n = string(s).length();
    norm(s, 0, n);
    norm(t, 0, n);
    if (string(s) == string(t)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }


#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}