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

const ii mod = mp (1000*1000*1000+7, 1000*1000*1000+9);
const ii hmul = mp (23917, 17239);

int n;
int m;
string s;
string t;
ii hs[200010];
ii p[200010];
ii ht[26];
int jump[200010][26];
int last[26];
int q[26];
int was[26];
vi res;

ii mul (ii a, ii b) {
    re mp (((ll)a.fi * b.fi) % mod.fi, ((ll)a.se * b.se) % mod.se);
}

ii add (ii a, ii b) {
    re mp ((a.fi + b.fi) % mod.fi, (a.se + b.se) % mod.se);
}

ii sub (ii a, ii b) {
    re mp ((a.fi - b.fi + mod.fi) % mod.fi, (a.se - b.se + mod.se) % mod.se);
}

int main () {
    cin >> n >> m;
    cin >> s;
    cin >> t;
    p[0] = mp (1, 1);
    for (int i = 1; i < n; i++)
        p[i] = mul (p[i - 1], hmul);
    hs[n] = mp (0, 0);
    for (int i = 0; i < 26; i++)
        last[i] = n;
    for (int i = n - 1; i >= 0; i--) {
        hs[i] = add (mul (hs[i + 1], hmul), mp (s[i], s[i]));
        last[s[i] - 'a'] = i;
        for (int j = 0; j < 26; j++)
            jump[i][j] = last[j];
    }
    for (int i = 0; i < m; i++)
        ht[t[i] - 'a'] = add (ht[t[i] - 'a'], p[i]);
    for (int i = 0; i + m <= n; i++) {
        for (int j = 0; j < 26; j++) {
            q[j] = j;
            was[j] = 0;
        }
        int j = i;
        while (j < i + m) {
            int a = t[j - i] - 'a';
            int b = s[j] - 'a';
            q[a] = b;
            q[b] = a;
            was[a] = was[b] = 1;
            int k = n;
            for (int t = 0; t < 26; t++)
                if (!was[t])
                    k = min (k, jump[j][t]);
            j = k;
        }
        int ok = 1;
        ii cur (0, 0);
        for (int t = 0; t < 26; t++) {
            if (q[q[t]] != t) {
                ok = 0;
                break;
            }
            cur = add (cur, mul (ht[t], mp (q[t] + 'a', q[t] + 'a')));
        }
        if (ok && cur == sub (hs[i], mul (hs[i + m], p[m]))) res.pb (i + 1);
    }
    printf ("%d\n", sz (res));
    for (int i = 0; i < sz (res); i++)
        printf ("%d ", res[i]);
    printf ("\n");
    return 0;
}