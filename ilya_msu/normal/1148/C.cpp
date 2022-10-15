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
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        --p[i];
    }
    vector<int> pos(n);
    for (int i = 0; i < n; ++i) {
        pos[p[i]] = i;
    }
    vector<int> ord(n);
    for (int i = n / 2; i < n; ++i) {
        ord[2 * i - n] = i;
    }
    for (int i = n / 2 - 1; i >= 0; --i) {
        ord[n - 2 * i - 1] = i;
    }
    /*for (int i = 0; i < n; ++i) {
        cout << ord[i] <<  " ";
    }*/
    vector<pii> res;
    for (int i = 0; i < ord.size(); ++i) {
        int id = ord[i];
        if (pos[id] == id)
            continue;
        int cid = pos[id];
        if (id < n / 2) {
            if (cid >= n / 2) {
                swap(p[0], p[cid]);
                pos[p[0]] = 0;
                pos[p[cid]] = cid;
                res.push_back(pii(0, cid));
                cid = 0;
            }
            swap(p[cid], p[n - 1]);
            pos[p[n - 1]] = n - 1;
            pos[p[cid]] = cid;
            if (cid != n - 1)
                res.push_back(pii(cid, n - 1));
            cid = n - 1;
            swap(p[cid], p[id]);
            pos[p[id]] = id;
            pos[p[cid]] = cid;
            if (cid != id)
                res.push_back(pii(cid, id));
        }
        else {
            if (cid < n / 2) {
                swap(p[n - 1], p[cid]);
                pos[p[n - 1]] = n - 1;
                pos[p[cid]] = cid;
                res.push_back(pii(n - 1, cid));
                cid = n - 1;
            }
            swap(p[cid], p[0]);
            pos[p[0]] = 0;
            pos[p[cid]] = cid;
            if (cid != 0)
            res.push_back(pii(cid, 0));
            cid = 0;
            swap(p[cid], p[id]);
            pos[p[id]] = id;
            pos[p[cid]] = cid;
            if (cid != id)
                res.push_back(pii(cid, id));
        }
    }
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i].first + 1 << " " << res[i].second + 1 << "\n";
    }

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