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
const int maxn = 100500;

string s;
int c[3][maxn];

int get(int k, int i, int j) {
    return c[k][j] - (i ? c[k][i-1] : 0);
}

int main()
{
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);

    cin >> s;
    int n = s.length();
    forn(i, n) {
        c[s[i]-'x'][i]++;
    }
    forn(i, n) forn(j, 3) if (i) c[j][i] += c[j][i-1];
    int m;
    cin >> m;
    forn(i, m) {
        int a, b;
        cin >> a >> b;
        int mn = 100000000, mx = -1;
        forn(k, 3) {
            int t = get(k, a-1, b-1);
            mn = min(mn, t);
            mx = max(mx, t);
        }
        if (b-a <= 1 || mx - mn <= 1) cout << "YES\n";
        else cout << "NO\n";
    }

#ifdef HOME
    std::cerr << "Time = " << clock()/1000 << " ms" << std::endl;
#endif
    return 0;
}