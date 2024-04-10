const long long MOD = 1e9 + 7;
const long long INF = 1e9;
const long long INFLL = 1e18;

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef complex<double> cd;

#define forn(i, n) for (int i = 0; (i) != (n); (i)++)
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

int cx[4] = {-1, 0, 1, 0};
int cy[4] = {0, -1, 0, 1};
string Yes[2] = {"No\n", "Yes\n"};
string YES[2] = {"NO\n", "YES\n"};
string Possible[2] = {"Impossible\n", "Possible\n"};
string POSSIBLE[2] = {"IMPOSSIBLE\n", "POSSIBLE\n"};

//source: https://codeforces.com/contest/1017/submission/41391483

const int A = 2e7 + 5;

bitset<A / 3 + 100> prime_of_6_1;
bitset<A / 3 + 100> prime_of_6_5;

bool prime_test(ll x)
{
    if (x == 2)
        return 1;
    if (x == 3)
        return 1;
    if (x % 6 == 1)
    {
        return prime_of_6_1[(x - 1) / 6] ^ 1;
    }
    if (x % 6 == 5)
    {
        return prime_of_6_5[(x + 1) / 6] ^ 1;
    }
    return 0;
}

void solve()
{
    for (int i = 4; i * i <= A; i++)
    {
        if (i % 6 == 1)
        {
            if (prime_of_6_1[(i - 1) / 6] == 0)
            {
                for (int j = 2; j * i <= A; j++)
                {
                    if ((i * j) % 6 == 1)
                    {
                        prime_of_6_1[((i * j) - 1) / 6] = 1;
                    }
                    if ((i * j) % 6 == 5)
                    {
                        prime_of_6_5[((i * j) + 1) / 6] = 1;
                    }
                }
            }
        }
        if (i % 6 == 5)
        {
            if (prime_of_6_5[(i + 1) / 6] == 0)
            {
                for (int j = 2; j * i <= A; j++)
                {
                    if ((i * j) % 6 == 1)
                    {
                        prime_of_6_1[((i * j) - 1) / 6] = 1;
                    }
                    if ((i * j) % 6 == 5)
                    {
                        prime_of_6_5[((i * j) + 1) / 6] = 1;
                    }
                }
            }
        }
    }

    int n;
    cin >> n;
    vector<ll> cnt(A);
    forn(i, n)
    {
        int a;
        cin >> a;
        cnt[a]++;
    }
    vector<int> primes;
    for (int i = 2; i < A; i++)
    {
        if (prime_test(i) == 1)
        {
            primes.push_back(i);
            //cout << i << "\n";
        }
    }
    //cout << "/" << endl;
    vector<int> cnt_divisible(A);
    for (int i = 2; i < A; i++)
    {
        for (int j = i; j < A; j += i)
        {
            cnt_divisible[i] += cnt[j];
        }
    }
    //cout << "/" << endl;
    vector<ll> dp(A);
    for (int i = 1; i < A; i++)
    {
        for (auto e : primes)
        {
            ll j = 1ll * e * i;
            if (j >= A)
                break;
            ll val = j;
            dp[j] = max(dp[j], dp[i] + cnt_divisible[val] * (j - i));
        }
    }
    //for (int i = 1; i < A; i ++)
    //    cout << dp[i] << " ";
    cout << n + *max_element(all(dp)) << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}

/* Note:
Check constants at the beginning of the code (MOD, INF, INFLL)
Check corner cases.
    N = 1
No def int long long for now.
Add something here.
*/