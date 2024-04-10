#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#define _USE_MATH_DEFINES
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<utility>
#include<map>
#include<ctime>
#include<cstdio>
#include<cassert>
#include<functional>




using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<char, char> pcc;
typedef pair<double, double> pdd;

#define show(x) cerr << x
#define debug(x) show(#x << ": " << (x) << endl)

const long double PI = 3.14159265358979323846;
const long double eps = 1e-5;
const int INF = numeric_limits<int>::max();
const ll LINF = numeric_limits<ll>::max();
const ll mod = 1000 * 1000 * 1000 + 7;

vector<vector<vector<double> > > d;
vector<vector<double> > p;

double get(int st, int loglen, int win) {
    if (d[st][loglen][win] > -0.5)
        return d[st][loglen][win];
    int len = 1 << loglen;
    if (len == 1)
        return 0;
    double res = p[win][loglen] * len / 2;
    len /= 2;
    int gid = st / len;
    int gidNei = gid ^ 1;
    if ((win >= gidNei * len) && (win < (1 + gidNei) * len))
        swap(gid, gidNei);
    double mx = 0;
    for (int j = gidNei * len; j < (gidNei + 1) * len; ++j) {
        mx = max(mx, get(gidNei * len, loglen - 1, j));
    }
    res = res + mx + get(gid * len, loglen - 1, win);
    d[st][loglen][win] = res;
    return res;

}

void solve() {
    int N;
    cin >> N; 
    int n = 1 << N;
    vector<vector<int> > pr(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> pr[i][j];
    p.assign(n, vector<double>(N + 1, 0));
    for (int i = 0; i < n; ++i)
        p[i][0] = 1;
    for (int r = 1; r <= N; ++r) {
        int g = 1 << (r - 1);
        for (int i = 0; i < n; ++i) {
            int gid = i / g;
            int gidNei = (i / g) ^ 1;
            for (int j = gidNei * g; j < (gidNei + 1) * g; ++j) {
                p[i][r] = p[i][r] + pr[i][j] * 0.01 * p[j][r - 1];
            }
            p[i][r] *= p[i][r - 1];
        }
    }
    d.assign(n, vector<vector<double> >(N + 1, vector<double>(n, -1)));
    for (int i = 0; i < n; ++i)
        get(0, N, i);
    double res = 0;
    for (int i = 0; i < n; ++i)
        res = max(res, d[0][N][i]);
    cout.precision(18);
    cout << res << endl;
}



//#define LOCAL

int main() {
    ios_base::sync_with_stdio(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    solve();


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
    return 0;
}