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


int get(const string& s) {
    int res = 0;
    for (int i = 0; i < s.size(); ++i) {
        res = res * 2 + (s[i] == '1');
    }
    return res;
}

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> w(n);
    for (int i = 0; i < n; ++i)
        cin >> w[i];
    string s;
    int N = 1 << n;
    vector<int> cnt(N, 0);
    for (int i = 0; i < m; ++i) {
        cin >> s;
        ++cnt[get(s)];
    }
    
    vector<int> cost(N, 0);
    for (int ms = 0; ms < N; ++ms) {
        for (int k = 0; k < n; ++k) {
            if (((ms >> (n - k - 1)) & 1) == 0) {
                cost[ms] += w[k];
            }
        }
    }
    vector<vector<int> > res(N, vector<int>(101, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int d = cost[i ^ j];
            if (d > 100) {
                continue;
            }
            res[i][d] += cnt[j];
        }
        for (int j = 0; j < 100; ++j) {
            res[i][j + 1] += res[i][j];
        }
    }
    for (int i = 0; i < q; ++i) {
        int k;
        cin >> s >> k;
        int id = get(s);
        cout << res[id][k] << "\n";
    }
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