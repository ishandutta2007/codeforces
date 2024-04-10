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
    int n, m, l;
    cin >> n >> m >> l;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    a.push_back(0);
    int lft = -1, r = -1;
    set<pii> s;

    for (int i = 0; i <= n; ++i) {
        if (a[i] > l) {
            if (lft == -1) {
                lft = i;
            }
        }
        else {
            if (lft != -1) {
                s.insert(pii(lft, i));
                //cerr << lft << " " << i << endl;

                lft = -1;
            }
        }
    }
    int t, p, d;
    for (int i = 0; i < m; ++i) {
        cin >> t;
        if (t == 0) {
            cout << s.size() << "\n";
        }
        else {
            cin >> p >> d;
            --p;
            if (a[p] > l) {
                continue;
            }
            a[p] += d;
            if (a[p] <= l)
                continue;
            auto it = s.insert(pii(p, p + 1)).first;
            auto it1 = it;
            ++it1;
            if (it1 != s.end()) {
                if (it1->first == p + 1) {
                    pii v(p, it1->second);
                    s.erase(it1);
                    s.erase(it);
                    it = s.insert(v).first;
                }
            }
            if (it != s.begin()) {
                auto it2 = it;
                --it2;
                if (it2->second == p) {
                    pii v(it2->first, it->second);
                    s.erase(it2);
                    s.erase(it);
                    s.insert(v);
                }
            }
            /*for (auto e:s) {
                cerr << e.first << " " << e.second << "\n";
            }
            cerr << endl;*/
        }


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