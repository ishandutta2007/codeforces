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
const ll mod = 1000000007;


void solve() {
    int n;
    cin >> n;
    vector<int> sgn(n + 1, 0);
    for (int i = 3; i <= n; ++i) {
        cout << "2 1 2 " << i << endl;
        cin >> sgn[i];
    }
    vector<ll> sq(n + 1, 0);
    for (int i = 3; i <= n; ++i) {
        cout << "1 1 2 " << i << endl;
        cin >> sq[i];
    }
    vector<pll> pos, neg;
    for (int i = 3; i <= n; ++i) {
        if (sgn[i] == 1) {
            pos.push_back(pll(sq[i], i));
        }
        else {
            neg.push_back(pll(sq[i], i));
        }
    }
    sort(pos.begin(), pos.end());
    vector<int> resp(pos.size());
    if (pos.size() > 0) {
        int lid = 0, rid = pos.size() - 1;
        int s;
        for (int i = 0; i + 1 < pos.size(); ++i) {
            cout << "2 1 " << pos[i].second << " " << pos[i + 1].second << endl;
            cin >> s;
            if (s > 0) {
                resp[lid] = pos[i].second;
                ++lid;
            }
            else {
                resp[rid] = pos[i].second;
                --rid;
            }
        }
        resp[lid] = pos[pos.size() - 1].second;
    }
    sort(neg.begin(), neg.end());
    vector<int> resn(neg.size());
    if (neg.size() > 0) {
        int lid = 0, rid = neg.size() - 1;
        int s;
        for (int i = 0; i + 1 < neg.size(); ++i) {
            cout << "2 1 " << neg[i].second << " " << neg[i + 1].second << endl;
            cin >> s;
            if (s > 0) {
                resn[lid] = neg[i].second;
                ++lid;
            }
            else {
                resn[rid] = neg[i].second;
                --rid;
            }
        }
        resn[lid] = neg[neg.size() - 1].second;
    }
    cout << 0;
    vector<int> res(1, 1);
    for (int i = 0; i < resn.size(); ++i)
        res.push_back(resn[i]);
    res.push_back(2);
    for (int i = 0; i < resp.size(); ++i)
        res.push_back(resp[i]);
    for (int i = 0; i < res.size(); ++i) {
        cout << " " << res[i];
    }
    cout << endl;

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