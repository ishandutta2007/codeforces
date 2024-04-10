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

const int N = 1000*1000;
const int hmul[2] = {239, 23917};
const int hmod[2] = {1000*1000*1000+7, 1000*1000*1000+9};

int n;
int m;
string s;
multiset<int> all;
int pref[2 * N + 1];
int ht[2][2 * N + 1];
int ho[2][2 * N + 1];
int hc[2][2 * N + 1];
int pm[2][2 * N + 1];
int ans, ai, aj, aop, acl;

char getb (int op, int i, int j, int cl, int k) {
    if (k < op) re '(';
    if (k - op < n) re s[i + k - op];
    re ')';
}

ii gethash (int op, int i, int j, int cl, int k) {
    ii res;
    for (int t = 0; t < 2; t++) {
        int len = 0;
        int tmp;
        tmp = min (op, k);
        int cur = ho[t][tmp];
        len += tmp;
        k -= tmp;
        if (k > 0) {
            tmp = min (n, k);
            cur = ((ll)cur + (ht[t][i] - (ll)ht[t][i + tmp] * pm[t][tmp] % hmod[t] + hmod[t]) * pm[t][len]) % hmod[t];
            if (cur < 0) cur += hmod[t];
            k -= tmp;
            len += tmp;
            if (k > 0) {
                tmp = min (cl, k);
                cur = (cur + (ll)hc[t][tmp] * pm[t][len]) % hmod[t];
                len += tmp;
            }
        }
        if (t == 0) res.fi = cur; else res.se = cur;
    }
    re res;
}

int ls (int op1, int i1, int j1, int cl1, int op2, int i2, int j2, int cl2) {
    int len = op1 + n + cl1;
    int l = 0, r = len + 1;
    while (r - l > 1) {
        int s = (l + r) / 2;
        ii h1 = gethash (op1, i1, j1, cl1, s);
        ii h2 = gethash (op2, i2, j2, cl2, s);
        if (h1 == h2) l = s; else r = s;
    }
    if (r > len) re false;
    re int (getb (op1, i1, j1, cl1, r - 1) < getb (op2, i2, j2, cl2, r - 1));
}

int upd (int op, int i, int j, int cl) {
    if (op + n + cl > ans) re 0;
    if (op + n + cl == ans && !ls (op, i, j, cl, aop, ai, aj, acl)) re 0;
    ans = op + n + cl;
    aop = op;
    ai = i;
    aj = j;
    acl = cl;
    re 0;
}

int main () {
    cin >> s;
    n = sz (s);
    s = s + s;
    for (int i = 0; i < 2 * n; i++)
        pref[i + 1] = pref[i] + int (s[i] == '(') - int (s[i] == ')');
    for (int t = 0; t < 2; t++) {
        ht[t][2 * n] = 0;
        for (int i = 2 * n - 1; i >= 0; i--)
            ht[t][i] = ((ll)ht[t][i + 1] * hmul[t] + s[i]) % hmod[t];
        ho[t][0] = hc[t][0] = 0;
        pm[t][0] = 1;
        for (int i = 1; i <= 2 * n; i++) {
            ho[t][i] = ((ll)ho[t][i - 1] * hmul[t] + int ('(')) % hmod[t];
            hc[t][i] = ((ll)hc[t][i - 1] * hmul[t] + int (')')) % hmod[t];
            pm[t][i] = ((ll)pm[t][i - 1] * hmul[t]) % hmod[t];
        }
    }   
    for (int i = 0; i < n; i++) all.insert (pref[i]);
    ans = 1e9;
    for (int i = 0; i < n; i++) {
        all.insert (pref[i + n]);
        int low = *all.begin ();
        int open = 0, close = 0;
        if (low < pref[i]) open += pref[i] - low;
        if (pref[i + n] - pref[i] + open > 0)
            close += pref[i + n] - pref[i] + open;
        else
            open += -(pref[i + n] - pref[i] + open);
        upd (open, i, i + n, close);
        all.erase (all.find (pref[i]));
    }
    printf ("%s", string (aop, '(').c_str ());
    printf ("%s", s.substr (ai, n).c_str ());
    printf ("%s", string (acl, ')').c_str ());
    printf ("\n");
    cerr << clock () << endl;
    return 0;
}