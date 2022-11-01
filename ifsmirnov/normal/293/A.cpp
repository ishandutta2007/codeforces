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

string s, t;
int n;
int c11, c10, c01, c00;

void solve()
{
    cin >> n >> s >> t;
    forn(i, n*2) {
        if (s[i] == '1') {
            if (t[i] == '1') ++c11;
            else ++c10;
        }
        else {
            if (t[i] == '1') ++c01;
            else ++c00;
        }
    }
    int r1 = 0, r2 = 0;
    forn(i, n) {
        if (c11) --c11, ++r1;
        else if (c10) --c10, ++r1;
        else if (c01) --c01;
        else if (c00) --c00;

        if (c11) --c11, ++r2;
        else if (c01) --c01, ++r2;
        else if (c10) --c10;
        else if (c00) --c00;
    }

    if (r1 > r2)
        cout << "First" << endl;
    else if (r1 < r2)
        cout << "Second" << endl;
    else
        cout << "Draw" << endl;
}

int main()
{
    solve();

#ifdef HOME
    cerr << "time = " << clock()/1000 << " ms" << endl;
#endif
    return 0;
}