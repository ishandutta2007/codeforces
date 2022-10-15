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
    int n;
    cin >> n;
    vector<string> a;
    string s1, s2, s = "", t;
    vector<string> as, at;
    vector<pii> pos;
    vector<string> w1(n), w2(n);
    for (int i = 0; i < n; ++i) 
        cin >> w1[i];
    for (int i = 0; i < n; ++i) 
        cin >> w2[i];
    for (int i = 0; i < n; ++i) {
        s1 = w1[i];
        s2 = w2[i];
        if (s1 == s2) {
            a.push_back(s1);
            continue;
        }
        int st = s1.size(), en = 0;
        for (int j = 0; j < s1.size(); ++j) {
            if (s1[j] != s2[j]) { 
                st = min(st, j);
                en = max(en, j);
            }
        }
        ++en;
        if (s != "") {
            if (s != string(s1.begin() + st, s1.begin() + en)) {
                cout << "NO\n";
                return;
            }
            if (t != string(s2.begin() + st, s2.begin() + en)) {
                cout << "NO\n";
                return;
            }
        }
        else {
            s = string(s1.begin() + st, s1.begin() + en);
            t = string(s2.begin() + st, s2.begin() + en);
        }
        as.push_back(s1);
        at.push_back(s2);
        pos.push_back(pii(st, en));
    }
    while (true) {
        bool ok = 1;
        for (int i = 0; i < as.size(); ++i) {
            if ((pos[i].first == 0) || (as[i][pos[i].first - 1] != as[0][pos[0].first - 1]) || 
                (at[i][pos[i].first - 1] != at[0][pos[0].first - 1])) {
                    ok = 0;
                    break;
                }
        }
        if (!ok)
            break;
        for (int i = 0; i < as.size(); ++i) {
            --pos[i].first;
        }
    }

    while (true) {
        bool ok = 1;
        for (int i = 0; i < as.size(); ++i) {
            if ((pos[i].second == as[i].size()) || (as[i][pos[i].second] != as[0][pos[0].second]) || 
                (at[i][pos[i].second] != at[0][pos[0].second])) {
                    ok = 0;
                    break;
                }
        }
        if (!ok)
            break;
        for (int i = 0; i < as.size(); ++i) {
            ++pos[i].second;
        }
    }

    s = string(as[0].begin() + pos[0].first, as[0].begin() + pos[0].second);
    t = string(at[0].begin() + pos[0].first, at[0].begin() + pos[0].second);
    for (int i = 0; i < a.size(); ++i) {
        if (a[i].find(s) != string::npos) {
            cout << "NO\n";
            return;
        }
    }
    for (int i = 0; i < as.size(); ++i) {
        if (as[i].find(s) != pos[i].first) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    cout << s << endl << t << endl;


    

    

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