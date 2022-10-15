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
    int n, w, h;
    cin >> n >> w >> h;
    vector<int> gg, pp, tt;
    vector<pii> a;
    for (int i = 0; i < n; ++i) {
        int g, xy, t;
        cin >> g >> xy >> t;
        gg.push_back(g);
        pp.push_back(xy);
        tt.push_back(t);
        a.push_back(pii(xy - t, i));
    }
    sort(a.begin(), a.end());
    vector<vector<int> > gr;
    for (int i = 0; i < a.size(); ++i) {
        if ((i == 0) || (a[i].first != a[i - 1].first))
            gr.push_back(vector<int>(1, a[i].second));
        else
            gr.back().push_back(a[i].second);
    }
    vector<pii> res(n);
    for (int i = 0; i < gr.size(); ++i) {
        vector<pii> a1, a2;
        for (int j = 0; j < gr[i].size(); ++j) {
            int ind = gr[i][j];
            if (gg[ind] == 2) {
                a1.push_back(pii(pp[ind], ind));
                a2.push_back(pii(pp[ind] - w, w));
            }
            else {
                a1.push_back(pii(-pp[ind], ind));
                a2.push_back(pii(h - pp[ind], pp[ind]));
            }
        }
        sort(a1.begin(), a1.end());
        sort(a2.begin(), a2.end());
        for (int j = 0; j < a1.size(); ++j) {
            res[a1[j].second] = pii(a2[j].second, a2[j].first + a2[j].second);
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << res[i].first << " " << res[i].second << "\n";
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