#include <cstdio>
#include <numeric>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>
#include <deque>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define fill(x,y) memset(x,y,sizeof(x))
#define prev PREV
#define next NEXT
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }
template<class T> inline T sqr (T x) { re x * x; }

#define filename ""

int n;
int m;

vi v[200000];
ll res[200000][2];
int w[200000];

int go (int x) {
    ll res0 = 0, res1 = -1e18;
    for (int i = 0; i < sz (v[x]); i++) {
        int y = v[x][i];
        go (y);
        ll nres0 = max (res0 + res[y][0], res1 + res[y][1]);
        ll nres1 = max (res0 + res[y][1], res1 + res[y][0]);
        res0 = nres0;
        res1 = nres1;
    }
    res[x][0] = res0;
    res[x][1] = max (res1, res0 + w[x]);
    re 0;
}

int main () {
    scanf ("%d", &n);
    int r = 0;
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf ("%d%d", &x, &y);
        if (x == -1) r = i; else v[x - 1].pb (i);
        w[i] = y;
    }
    go (r);
    cout << max (res[r][0], res[r][1]) << endl;
    return 0;
}