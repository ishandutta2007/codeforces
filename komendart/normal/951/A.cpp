#include <bits/stdc++.h>

using namespace std;

#define sqr(x) ((x)*(x))
#define I(i, a) for (auto i: (a))
#define F(i, st, en) for (auto i = (st); i < (en); ++i)
#define DF(i, st, en) for (auto i = (st); i > (en); --i)
#define E(i, st, en) for (auto i = (st); i <= (en); ++i)
#define fin(st) freopen(st, "r", stdin)
#define fout(st) freopen(st, "w", stdout)
#define pb push_back
#define mp make_pair
#define cont continue
#define ret return
#define ins insert
#define sz(a) ((int)(a).size())
#define X first
#define Y second
#define all(x) (x).begin(),(x).end()
#define sync ios_base::sync_with_stdio(0);cin.tie(0)

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair <int, int> pii;
typedef vector <int> vi;

const int maxn = (int)1e5 + 5;
const int mod = (int)1e9 + 7;
const dbl eps = 1e-8;
const int inf = 1e9;
const ll linf = 1e18;


int main() {
//    fin("t.in");
    sync;
    string s;
    cin >> s;
    int l = 1, l0 = -1, l1;
    int ans = 0;
    for (int i = 1; i < sz(s); ++i) {
        if (s[i] != s[i - 1]) {
            ++l;
         } else {
            ans = max(ans, l);
            if (l0 == -1)
                l0 = l;
            l = 1;
        }
    }
    ans = max(ans, l);
    l1 = l;
    if (ans == sz(s)) {
        cout << ans << endl;
        exit(0);
    }
    if (s[0] != s[sz(s) - 1])
        ans = max(ans, l0 + l1);
    cout << ans << endl;
    return 0;
}