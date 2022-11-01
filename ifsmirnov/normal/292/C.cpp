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

char out[1000];
vector<vi> ans;

int dmask[300];
void gendmask()
{
    forn(i, 10)
        dmask[i] = 1<<i;
    fore(i, 10, 99)
        dmask[i] = (1<<(i%10)) | (1<<(i/10));
    fore(i, 100, 255)
        dmask[i] = (1<<(i%10)) | (1<<(i/100)) | (1<<((i/10)%10));
}

int mask;
int cur[5];

bool check()
{
    static int s[20];
    int pos = 0;
    ford(i, 4) {
        int x = cur[i];
        if (x == 0) s[pos++] = 0;
        while(x) {
            s[pos++] = x%10;
            x /= 10;
        }
    }
    forn(i, pos/2)
        if (s[i] != s[pos-i-1])
            return false;
    return true;
}
bool check1(int d)
{
    static int s[20];
    int pos = 0;
    pos += d;
    ford(i, 3) {
        int x = cur[i];
        if (x == 0) s[pos++] = 0;
        while(x) {
            s[pos++] = x%10;
            x /= 10;
        }
    }
    for (int i = d; i < pos/2; i++)
        if (s[i] != s[pos-i-1]) {
            if (d == 1) return false;
            return check1(d-1);
        }
    return true;
}

void go(int pos, int curmask) {
    if (pos == 3) {
        if (!check1(3))
            return;
        if (__builtin_popcount(curmask^mask) > 3)
            return;
    }
    if (pos == 4) {
        if (curmask == mask && check()) {
            ans.pb(vi(cur, cur+4));     
        }
        return;
    }
    forn(i, 256) if ( (dmask[i] & mask) == dmask[i] ) {
        cur[pos] = i;
        go(pos+1, curmask|dmask[i]);
    }
}

void solve()
{
    int k;
    cin >> k;
    if (k > 6) {
        cout << 0 << endl;
        return;
    }
    int t;
    forn(i, k) {
        cin >> t;
        mask |= (1<<t);
    }
    go(0, 0);
    
    cout << ans.size() << endl;
    forn(i, ans.size()) {
        forn(j, 4) cout << ans[i][j] << ".\n"[j == 3];
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    gendmask();
    solve();

#ifdef HOME
    cerr << "time = " << clock()/1000 << " ms" << endl;
#endif
    return 0;
}