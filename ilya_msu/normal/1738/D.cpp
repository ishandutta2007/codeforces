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
#include<unordered_set>
#include<chrono>
#include<random>



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
const int INF = 1000 * 1000 * 1000 + 1;
const ll LINF = (ll)1000 * 1000 * 1000 * 1000 * 1000 * 1000;
const ll mod = 998244353;


bool test() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int n = uniform_int_distribution<int>(1, 10)(rng);
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        a[i] = i + 1;
    shuffle(a.begin(), a.end(), rng);
    int kk = uniform_int_distribution<int>(0, n)(rng);
    cout << kk << "\n";
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << "\n";

    vector<int> b(n + 1);
    int big = n + 1, small = 0;
    for (int i = 0; i < n; ++i) {
        int x = a[i];
        if (x <= kk) {
            b[x] = big;
            small = x;
        }
        else {
            b[x] = small;
            big = x;
        }
    }
        
    vector<int> minl(n + 1);
    minl[1] = b[1];
    for (int i = 2; i <= n; ++i) {
        minl[i] = min(minl[i - 1], b[i]);
    }
    vector<int> maxr(n + 1);
    maxr[n] = b[n];
    for (int i = n - 1; i >= 1; --i)
        maxr[i] = max(maxr[i + 1], b[i]);
    if (maxr[1] == 0) {
        return (kk == 0);
    }
    if (minl[n] == n + 1) {
        return (kk == n);
    }
    int k = -1;
    for (int i = 1; i < n; ++i) {
        if ((minl[i] > i) && (maxr[i + 1] <= i))
            k = i;
    }
    if (k != kk)
        return 0;
    vector<int> an(n);
    int id = 0;
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if ((b[i] == 0) || (b[i] == n + 1))
            q.push(i);
    }
    vector<vector<int> > rb(n + 1);
    for (int i = 1; i <= n; ++i) {
        if ((b[i] > 0) && (b[i] <= n)) {
            rb[b[i]].push_back(i);
        }
    }
    while (!q.empty()) {
        int x = -1;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            if (rb[v].size() == 0) {
                an[id] = v;
                ++id;
            }
            else {
                x = v;
            }
        }
        if (x != -1) {
            an[id] = x;
            ++id;
            for (int i = 0; i < rb[x].size(); ++i) {
                q.push(rb[x][i]);
            }
        }
    }
    
    vector<int> bn(n + 1);
    big = n + 1, small = 0;
    for (int i = 0; i < n; ++i) {
        int x = an[i];
        if (x <= kk) {
            bn[x] = big;
            small = x;
        }
        else {
            bn[x] = small;
            big = x;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (b[i] != bn[i])
            return 0;
    }
    return 1;

}

void solve() {
    
    int n;
    cin >> n;
    vector<int> b(n + 1);
    for (int i = 0; i < n; ++i)
        cin >> b[i + 1];
    vector<int> minl(n + 1);
    minl[1] = b[1];
    for (int i = 2; i <= n; ++i) {
        minl[i] = min(minl[i - 1], b[i]);
    }
    vector<int> maxr(n + 1);
    maxr[n] = b[n];
    for (int i = n - 1; i >= 1; --i)
        maxr[i] = max(maxr[i + 1], b[i]);
    if (maxr[1] == 0) {
        cout << 0 << "\n";
        for (int i = 0; i < n; ++i)
            cout << i + 1 << " ";
        cout << "\n";
        return;
    }
    if (minl[n] == n + 1) {
        cout << n << "\n";
        for (int i = 0; i < n; ++i)
            cout << i + 1 << " ";
        cout << "\n";
        return;
    }
    int k = -1;
    for (int i = 1; i < n; ++i) {
        if ((minl[i] > i) && (maxr[i + 1] <= i))
            k = i;
    }
    assert(k != -1);
    cout << k << "\n";
    vector<int> a(n);
    int id = 0;
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if ((b[i] == 0) || (b[i] == n + 1))
            q.push(i);
    }
    vector<vector<int> > rb(n + 1);
    for (int i = 1; i <= n; ++i) {
        if ((b[i] > 0) && (b[i] <= n)) {
            rb[b[i]].push_back(i);
        }
    }
    while (!q.empty()) {
        int x = -1;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            if (rb[v].size() == 0) {
                a[id] = v;
                ++id;
            }
            else {
                x = v;
            }
        }
        if (x != -1) {
            a[id] = x;
            ++id;
            for (int i = 0; i < rb[x].size(); ++i) {
                q.push(rb[x][i]);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << "\n";

}

int main() {
    //while (test()) {}
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
        solve();



#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
    return 0;
}