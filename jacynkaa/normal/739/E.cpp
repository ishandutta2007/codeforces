#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <math.h>
#include <chrono>
using namespace __gnu_pbds;
using namespace std;
//#pragma GCC optimize (-O3)
//#define endl tutaj n
#define mp make_pair
#define st first
#define nd second
#define pii pair<int, int>
#define pb push_back
#define _upgrade ios_base::sync_with_stdio(0), cout.setf(ios::fixed), cout.precision(10) //cin.tie(0); cout.tie(0);
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FWD(i, a, b) for (int i = (a); i < (b); ++i)
#define double long double
#define int long long
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set; // find_by_order(x) <-returns x-th element   order_of_key(x) <- returns order of element x

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

const int sqr = 40;
const int MAXN = 2011;

//unordered_map<int, double> safe_hash_table;
double P[MAXN];
double U[MAXN];
int A[MAXN];
int B[MAXN];
double dp[MAXN][2 * sqr + 5][2 * sqr + 5];
vector<int> X;
int n, a, b;

double get(int i, int x, int y)
{
    if (x < 0 || y < 0)
        return -12345678;
    return dp[i][x - A[i] + sqr][y - B[i] + sqr];
}
pii get_real(int i, int x, int y)
{
    return mp(A[i] + x - sqr, B[i] + y - sqr);
}

void wczytywanie()
{
    cin >> n >> a >> b;
    srand(time(NULL));
    REP(i, n)
    X.push_back(i);

    random_shuffle(X.begin(), X.end());

    REP(i, n)
    cin >> P[X[i] + 1];
    REP(i, n)
    cin >> U[X[i] + 1];
}
void akcja()
{

    for (int i = 1; i <= n; i++)
    {
        A[i] = (((double)a) * ((double)i) / ((double)n));
        B[i] = (((double)b) * ((double)i) / ((double)n));
        for (int j = 0; j < 2 * sqr; j++)
            for (int k = 0; k < 2 * sqr; k++)
            {
                auto Q = get_real(i, j, k);
                dp[i][j][k] = max({get(i - 1, Q.st - 1, Q.nd - 1) + U[i] + P[i] - P[i] * U[i], get(i - 1, Q.st - 1, Q.nd) + P[i], get(i - 1, Q.st, Q.nd - 1) + U[i], get(i - 1, Q.st, Q.nd)});
            }
    }
    cout << get(n, a, b) << endl;
}

main()
{
    _upgrade;
    wczytywanie();
    akcja();
}