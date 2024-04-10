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
#include<unordered_map>
#include<deque>
#include<cmath>





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
const ll INF = numeric_limits<int>::max();
const ll LINF = numeric_limits<ll>::max();
const ll mod = 1000 * 1000 * 1000 + 7;


void solve() {
    int n;
    cin >> n;
    vector<vector<int> > a(2, vector<int>(n, 0));
    int q;
    cin >> q;
    int r, c;
    vector<pii> d;
    for (int i = 0; i < q; ++i) {
        cin >> r >> c;
        --r, --c;
        a[r][c] ^= 1;
        int r1 = 1 - r;
        for (int c1 = max(0, c - 1); c1 < min(n, c + 2); ++c1) {
            if ((a[r][c] == 1) && (a[r1][c1] == 1)) {
                d.push_back({r, c});
                d.push_back({r1, c1});

            }
        }
        while (!d.empty()) {
            int ok = 0;
            pii p = d[d.size() - 1];
            r = p.first;
            c = p.second;
            int r1 = 1 - r;
            for (int c1 = max(0, c - 1); c1 < min(n, c + 1); ++c1) {
                if ((a[r][c] == 1) && (a[r1][c1] == 1)) {
                    ok = 1;
                }
            }
            if (ok) {
                cout << "No\n";
                break;
            }
            d.pop_back();
        }
        if (d.empty()) {
            cout << "Yes\n";
        }
    }

}


//#define LOCAL

int main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();



#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
    return 0;
}