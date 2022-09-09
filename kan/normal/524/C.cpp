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

const int MAX = 1000*1000*10;

int n;
int m;
int q;

int x[5000];
bitset<MAX + 1> can;

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &x[i]);
        can[x[i]] = 1;
    }   
    scanf ("%d", &q);
    for (int i = 0; i < q; i++) {
        int x;
        scanf ("%d", &x);
        int ans = m + 1;
        for (int j = 0; j < n; j++)
            for (int k = 1; k <= m; k++) {
                int cur = x - ::x[j] * k;
                if (cur < 0) break;
                if (cur == 0) {
                    ans = min (ans, k);
                } else {
                    for (int t = 1; k + t <= m; t++)
                        if (cur % t == 0 && cur / t <= MAX && can[cur / t]) {
                            ans = min (ans, k + t);
                            break;
                        }
                }
            }
        printf ("%d\n", ans <= m ? ans : -1);
    }
    return 0;
}