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
const ll mod = 998244353;


void solve() {
    int n;
    cin >> n;
    if (n == 2) {
        cout << -1 << endl;
        return;
    }
    int a = 1;
    while (a * a < n) ++a;
    if (a * a == n) {
        cout << a << endl;
        for (int i = 0; i < a; ++i) {
            for (int j = 0; j < a; ++j) {
                cout << 'o';
            }
            cout << endl;
        }
        return;
    }
    int k = a * a - n;
    if (k & 1) {
        cout << a << endl;
        int l = a - (k / 2) - 1;
        for (int i = 0; i < l; ++i) {
            cout << 'o';
        }
        for (int i = l; i < a; ++i) {
            cout << '.';
        }
        cout << endl;
        for (int i = 1; i < a - l; ++i) {
            for (int j = 0; j < a - 1; ++j) {
                cout << 'o';
            }
            cout << '.' << endl;
        }
        for (int i = a - l; i < a; ++i) {
            for (int j = 0; j < a; ++j) {
                cout << 'o';
            }
            cout << endl;
        }
        return;
    }
    vector<int> res(a, a);
    if (k == 2) {
    res[0] = a + 1;
    res.push_back(1);
    res[a - 1] = a - 2;
    res[a - 2] = a - 2;
    }
    else {
    k -= 4;
    res[a - 1] = a - 2;
    res[a - 2] = a - 2;
    int id = 3;
    while (k > 0) {
        k -= 2;
        res[a - 1]--;
        res[a - id]--;
        ++id;
    }
    }
    int sz = res.size();
    reverse(res.begin(), res.end());
    cout << sz << endl;
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i]; ++j) {
            cout << 'o';
        }
        for (int j = res[i]; j < sz; ++j) {
            cout << '.';
        }
        cout << endl;
    }

}

//#define LOCAL

int main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
/*for (int n = 1; n <= 100; ++n) {
    cout << n << ":\n";
solve(n);
cout << endl << endl;
};*/
solve();


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
    return 0;
}