//           
//         
//     
//     
//        
//           
#include <bits/stdc++.h>

#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <algorithm>
using namespace std;

#define fst first
#define snd second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back

#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
#define sqr(x) ((x) * (x))

#define ADD_OPERATORS_IN(T, COMP) \
    bool operator < (const T& ot) const { return COMP(ot) == -1; } \
    bool operator > (const T& ot) const { return COMP(ot) == 1; } \
    bool operator == (const T& ot) const { return COMP(ot) == 0; } \
    bool operator != (const T& ot) const { return COMP(ot) != 0; }

#define ADD_OPERATORS_OUT(T, COMP) \
    bool operator < (const T& a, const T& b) const { return COMP(a, b) == -1; } \
    bool operator > (const T& a, const T& b) const { return COMP(a, b) == 1; } \
    bool operator == (const T& a, const T&b) const { return COMP(a, b) == 0; } \
    bool operator != (const T& a, const T&b) const { return COMP(a, b) != 0; }


typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;

mt19937_64 mt_rand(chrono::system_clock::now().time_since_epoch().count());

template<typename T1, typename T2> inline bool upmax(T1& a, T2 b) { return (a < b ? (a = b, true) : false); }
template<typename T1, typename T2> inline bool upmin(T1& a, T2 b) { return (b < a ? (a = b, true) : false); }

const int maxn = (int) 2e5 + 20;
const int maxlog = 21;
const int base = (int) 1e9 + 7;
const ld eps = (ld) 1e-7;
const ld PI = acos(-1.);
//const int pp = 41;

#define next ajksdslk

int d, s;
bool used[5001][501];
int f[5001][501];

int pp[maxn];
pair<int, int> to[5001][501][10];


int main() {
//    freopen("input.txt", "r", stdin);
    cin >> d >> s;
    queue <pii> q;
    pp[0] = 1 % d;
    for (int i = 1; i < maxn; i ++) {
        pp[i] = (pp[i - 1] * 10) % d;
    }

    for (int i = 0; i <= s; i++)
        for (int j = 0; j < d; j++)
            for (int k = 0; k < 10; k++)
                to[i][j][k] = mp(base, base);
//
    for (int i = 0; i <= s; i++)
        for (int j = 0; j < d; j++) {
            f[i][j] = base;
            for (int k = 0; k < 10; k++) {
                if (i + k <= s) {
                    to[i + k][(j * 10 + k) % d][k] = mp(i, j);
                }
            }
        }

    f[s][0] = 0;
    q.push(mp(s, 0));

    while (!q.empty()) {
        int sum = q.front().fst, rem = q.front().snd;
        q.pop();

        if (used[sum][rem]) continue;
        used[sum][rem] = true;

//        cout << sum << ' ' << rem << ' ' << f[sum][rem] << endl;
//        cout << to[sum][rem][5].fst << ' ' << to[sum][rem][5].snd << endl;

        for (int i = 0; i < 10; i++) {
            int new_sum = sum - i;
            if (new_sum >= 0) {
                int new_rem = (rem * 10 + i) % d;
                upmin(f[new_sum][new_rem], f[sum][rem] + 1);
                q.push(mp(new_sum, new_rem));
            }
//            pair<int, int> tt = to[sum][rem][i];
//            if (tt.first == base) continue;
//            f[tt.fst][tt.snd] = min(f[tt.fst][tt.snd], f[sum][rem] + 1);
//            q.push(tt);
        }
    }

//    cout << f[0][0] << endl;

    if (f[0][0] == base) {
        cout << -1;
        return 0;
    }

    int ans = f[0][0];

    string res;

    int sum = 0, rem = 0;
    for (int l = 0; l < ans; l++) {
        for (int i = (l == 0 ? 1 : 0); i < 10; i++) {
            int new_rem = (rem + pp[ans - l - 1] * i) % d;
            if (sum + i <= s && f[sum + i][(d - new_rem) % d] <= ans - l - 1) {
                res += char(i + '0');
                sum += i;
                rem = new_rem;
                break;
            }
        }
    }
    cout << res << "\n";
}