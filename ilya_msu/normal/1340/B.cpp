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

vector<string> dig = {"1110111",
"0010010", "1011101", "1011011", "0111010", "1101011", "1101111",
"1010010", "1111111", "1111011"};

void solve() {
    int n, k;
    cin >> n >> k;
    vector<string> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vector<vector<int> > d(n + 1, vector<int>(k + 1, 0));
    d[n][0] = 1;
    for (int i = n - 1; i >= 0; --i) {
        vector<int> add;
        for (int j = 0; j < 10; ++j) {
            int ok = 1;
            int x = 0;
            for (int l = 0; l < 7; ++l) {
                if (a[i][l] == dig[j][l])
                    continue;
                if (a[i][l] == '1')
                    ok = 0;
                else 
                    ++x;
            }
            if (ok)
                add.push_back(x);
        }
        for (int l = 0; l <= k; ++l) {
            if (d[i + 1][l] == 0)
                continue;
            for (int j = 0; j < add.size(); ++j) {
                if (add[j] + l <= k) {
                    d[i][add[j] + l] = 1;
                }
            }
        }
    }
    if (d[0][k] == 0) {
        cout << -1 << endl;
        return;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 9; j >= 0; --j) {
            int ok = 1;
            int x = 0;
            for (int l = 0; l < 7; ++l) {
                if (a[i][l] == dig[j][l])
                    continue;
                if (a[i][l] == '1')
                    ok = 0;
                else 
                    ++x;
            }
            if ((ok) && (k >= x) && (d[i + 1][k - x])) {
                cout << j;
                k -= x;
                break;
            }
        }
    }
    cout << endl;

}

//#define LOCAL

int main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
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