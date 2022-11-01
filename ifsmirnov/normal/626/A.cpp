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

int n;
string t;
int s[5050];

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    cin >> n >> t;
    int res = 0;
    forn(i, n) {
        int s = i ? ::s[i-1] : 0;
        if (t[i] == 'U') s += 1000;
        else if (t[i] == 'D') s -= 1000;
        else if (t[i] == 'R') ++s;
        else --s;
        if (s == 0) ++res;
        forn(j, i) if (::s[j] == s) ++res;
        ::s[i] = s;
    }
    cout << res << endl;

#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}