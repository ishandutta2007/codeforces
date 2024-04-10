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

int solve(i64 a, i64 b, i64 x)
{
    int cnt = 0;
    while (a < x && b < x) {
        b = a + b;
        swap(a, b);
        ++cnt;
        if (cnt == 1000)
            return -1;
    }
    return cnt;
}

int main()
{
    i64 a, b, x;
    cin >> a >> b >> x;
    if (a >= x || b >= x) 
        cout << 0 << endl;
    else {
        if (a > b) swap(a, b); // a <= b
        if (b <= 0) cout << "-1" << endl;
        else {
            i64 add = 0;
            if (a < 0) {
                add += (-a + (b-1)) / b;
                a += b*add;
            }
            add += min(solve(a, b, x), solve(b, a, x));
            cout << add << endl;
        }
    }

#ifdef HOME
    cerr << "time = " << clock()/1000 << " ms" << endl;
#endif
    return 0;
}