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

bool isGood(string s) {
    int n = s.size();
    int x = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(')
            ++x;
        else 
            --x;
        if (x < 0)
            return 0;
    }
    return (x == 0);
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (isGood(s)) {
        cout << "Yes\n";
        return;
    }
    int pos = s.find(')');
    if (pos == string::npos) {
        cout << "No\n";
        return;
    }
    string s1 = s.substr(0, pos) + s.substr(pos + 1, n - pos - 1) + ")";
    pos = s.rfind('(');
    if (pos == string::npos) {
        cout << "No\n";
        return;
    }
    string s2 = "(" + s.substr(0, pos) + s.substr(pos + 1, n - pos - 1);
    if (isGood(s1) || isGood(s2)) {
        cout << "Yes\n";
        return;
    }
    cout << "No\n";
    return;


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