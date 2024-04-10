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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) 
        cin >> a[i];
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        b[i] = 0;
        for (int j = 0; j < i; ++j) {
            if (a[i] >= a[j])
                ++b[i];
        }
        for (int j = i + 1; j < n; ++j) {
            if (a[i] > a[j])
                ++b[i];
        }
    }
    a = b;
    vector<pii> res;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        p[a[i]] = i;
    }
    while (true) {
        int id = 0;
        while ((id < n - 1) && (p[id] <= p[id + 1]))
            ++id;
        if (id == n - 1)
            break;
        res.push_back(pii(p[id], p[id + 1]));
        swap(a[p[id]], a[p[id + 1]]);
        swap(p[id], p[id + 1]);
    }
    /*for (int i = 0; i < n; ++i) {
        cerr << a[i] << " ";
    }
    cerr << "\n";*/
    cout << res.size() << "\n";
    for (int i = 0; i < res.size(); ++i) {
        if (res[i].first > res[i].second)
            swap(res[i].first, res[i].second);
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