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

int p[200];
int was[200];
int d[200];
int ct;

ll gcd (ll a, ll b) { re a ? gcd (b % a, a) : b; }

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) scanf ("%d", &p[i]);
    ll res = 1;
    int least = 1;
    for (int i = 0; i < n; i++) {
        ct++;
        int k = i;
        for (int j = 0; ; j++) {
            if (was[k] == ct) {
                int pred = d[k];
                int per = j - pred;
                res = res / gcd (res, per) * per;
                least = max (least, pred);
                break;
            }
            was[k] = ct;
            d[k] = j;
            k = p[k] - 1;
        }
    }
    ll ans = 0;
    while (ans < least) ans += res;
    cout << ans << endl;
    return 0;
}