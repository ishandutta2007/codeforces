
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

int n;

int can(int r1, int c1, int r2, int c2) {
    assert((r2 - r1) + (c2 - c1) >= (n - 1));
    cout << "? " << r1 << " " << c1 << " " << r2 << " " << c2 << endl;
    string res;
    cin >> res;
    if (res == "BAD")
        exit(0);
    return res == "YES";
}


int main() {
    sync;
    cin >> n;
    string st = "";
    int x = 1; int y = 1;
    while ((n - x) + (n - y) > (n - 1)) {
        if (can(x, y + 1, n, n)) {
            st += 'R';
            y = y + 1;
        } else {
            st += 'D';
            x = x + 1;
        }
    }
    string en = "";
    int enx = x, eny = y;
    x = n; y = n;
    while (x != enx || y != eny) {
        assert((x - 1) + (y - 1) > (n - 1));
        if (can(1, 1, x - 1, y)) {
            en += 'D';
            x = x - 1;
        } else {
            en += 'R';
            y = y - 1;
        }
    }
    reverse(all(en));
    cout << "! " << st << en << endl;
    return 0;
}