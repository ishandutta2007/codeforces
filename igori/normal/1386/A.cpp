const int LG = 21;
const int N = 400005;
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
const long long INFLL = 1e18;

#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define int long long

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;

#define forn(i, n) for (int (i) = 0; (i) != (n); (i)++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define popcount(x) __builtin_popcount(x)
#define popcountll(x) __builtin_popcountll(x)
#define fi first
#define se second
#define re return
#define pb push_back
#define uniq(x) sort(all(x)); (x).resize(unique(all(x)) - (x).begin())

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << " " << #x << " " << x << endl
#define ln cerr << __LINE__ << endl
#else
#define dbg(x) void(0)
#define ln void(0)
#endif // LOCAL

void solve(int n)
{
    for (int st = max(1LL, n / 3 - 3); st <= min(n, n / 3 + 3); st++)
    {
        int okay = 1;
        for (int c = 1; okay && c <= 1 && c <= n; c++)
        {
            int L = 0, R = n;
            map<int, int> vis;
            int we = st, fl = 1;
            vis[we] = 1;
            while (L + 1 < R)
            {
                int M = (L + R) / 2;
                if (fl == 1)
                {
                    we += M;
                }
                else
                {
                    we -= M;
                }
                fl ^= 1;
                if (vis[we] || !(1 <= we && we <= n))
                {
                    okay = 0;
                    break;
                }
                vis[we] = 1;
                if (M >= c) R = M;
                else L = M;
            }
        }
        for (int c = max(1ll, n); okay && c <= n; c++)
        {
            int L = 0, R = n;
            map<int, int> vis;
            int we = st, fl = 1;
            vis[we] = 1;
            while (L + 1 < R)
            {
                int M = (L + R) / 2;
                if (fl == 1)
                {
                    we += M;
                }
                else
                {
                    we -= M;
                }
                fl ^= 1;
                if (vis[we] || !(1 <= we && we <= n))
                {
                    okay = 0;
                    break;
                }
                vis[we] = 1;
                if (M >= c) R = M;
                else L = M;
            }
        }
        if (okay)
        {
        //	cout << n / 3 - st << endl;
        //	re;
            cout << "? " << st << endl;
            int x;
            cin >> x;
            int fl = 1;
            int L = 0, R = n;
            int we = st;
            int anytime = 1;
            while (L + 1 < R)
            {
                int M = (L + R) / 2;
                if (fl == 1)
                {
                    we += M;
                }
                else
                {
                    we -= M;
                }
                fl ^= 1;
                cout << "? " << we << endl;
                cin >> x;
                if (x) R = M, anytime = 1;
                else L = M;
            }
            cout << "= " << R << endl;
            return;
        }
    }
    cout << "bad " << n << endl;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
    	int n;
    	cin >> n;
    	solve(n);
    }
}

/* Note:
Check constants at the beginning of the code.
    N is set to 4e5 but be careful in problems with large constant factor.
    Setting N in every problem is more effective.
Check corner cases.
    N = 1
No def int long long for now.
Add something here.
*/