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
//#include<unordered_map>




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
const int negINF = numeric_limits<int>::min();

const ll LINF = numeric_limits<ll>::max();
const ll mod = 1000 * 1000 * 1000 + 7;


void solve() {
    string s, t;
    cin >> s >> t;
    vector<int> bs(s.size() + 1, 0), bt(t.size() + 1, 0);
    vector<int> as(s.size() + 1, 0), at(t.size() + 1, 0);
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'C') {
            s[i] = 'B';
        }
        bs[i + 1] = bs[i] + (s[i] == 'B');
        if (s[i] == 'B')
            as[i + 1] = 0;
        else
            as[i + 1] = as[i] + 1;
    }
    for (int i = 0; i < t.size(); ++i) {
        if (t[i] == 'C') {
            t[i] = 'B';
        }
        bt[i + 1] = bt[i] + (t[i] == 'B');
        if (t[i] == 'B')
            at[i + 1] = 0;
        else
            at[i + 1] = at[i] + 1;
    }
    int q;
    cin >> q;
    string res = "";
    for (int qq = 0; qq < q; ++qq) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int b1 = bs[b] - bs[a - 1];
        int b2 = bt[d] - bt[c - 1];
        if (b1 > b2) {
            res += '0';
            continue;
        }
        if ((b2 - b1) & 1) {
            res += '0';
            continue;
        }
        int la1 = min(as[b], b - a + 1), la2 = min(at[d], d - c + 1);
        if (la1 < la2) {
            res += '0';
            continue;
        }
        if (b1 == 0) {
            if (b2 == 0) {
                if ((la1 - la2) % 3 == 0) {
                    res += '1';
                }
                else
                    res += '0';
                continue;
            }
            if (la1 == la2) {
                res += '0';
            }
            else
                res += '1';
            continue;
        }
        if ((la1 - la2) % 3 == 0) {
            res += '1';
            continue;
        }
        if (b1 == b2) {
            res += '0';
            continue;
        }
        res += '1';
    }
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