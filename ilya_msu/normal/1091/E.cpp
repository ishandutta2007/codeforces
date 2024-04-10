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
#include <random>
#include <chrono>


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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    
    ll l = 0, r = n;
    vector<ll> sum(n + 1, 0);
    vector<ll> tail(n + 1, 0);
    
    for (int i = 0; i < n; ++i) {
        sum[i + 1] = sum[i] + a[i];
    }
    ll j = 0;
    for (ll i = n - 1; i >= 0; --i) {
        if (a[i] <= i) {
            tail[i] = sum[n] - sum[i];
            continue;
        }
        j = max(i, j);
        while ((j < n) && (a[j] > i)) {
            ++j;
        }
        tail[i] = sum[n] - sum[j] + (j - i) * i;
        //cerr << i << " " << tail[i] << "\n";
    }


    for (ll k = 1; k < n + 1; ++k) {
        ll m = a[k - 1];
        ll tr = k * (k - 1) + tail[k] + min(a[k - 1], k) - sum[k - 1];
        ll tl = sum[k] - k * (k - 1) - tail[k];
        //cout << tl << " " << tr << endl;
        if (tl > k)
            tl = m;
        if (tr < m) {
            tr = m - 1;
        }
        if (tl >= m) {
            tl = m;
        }
        r = min(r, tr);
        l = max(l, tl);
        //cout << l << " " << r << endl;
    }
    if ((l ^ sum[n]) & 1)
        ++l;
    if (l > r) {
        cout << -1 << endl;
        return;
    }
    for (int i = l; i <= r; i += 2) 
        cout << i << " ";
    cout << endl;
    return;
    
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