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


void solve() {
    string s;
    cin >> s;
    vector<vector<int> > a;
    vector<int> zeros, ones;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '1') {
            if (zeros.empty()) {
                cout << -1 << endl;
                return;
            }
            int id = zeros.back();
            zeros.pop_back();
            a[id].push_back(i);
            ones.push_back(id);
        }
        else {
            if (ones.empty()) {
                int id = a.size();
                a.push_back({ i });
                zeros.push_back(id);
            }
            else {
                int id = ones.back();
                ones.pop_back();
                a[id].push_back(i);
                zeros.push_back(id);
            }
        }
    }
    if (!ones.empty()) {
        cout << -1 << endl;
        return;
    }
    cout << a.size() << endl;
    for (int i = 0; i < a.size(); ++i) {
        cout << a[i].size();
        for (int j = 0; j < a[i].size(); ++j) {
            cout << " " << a[i][j] + 1;
        }
        cout << "\n";
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