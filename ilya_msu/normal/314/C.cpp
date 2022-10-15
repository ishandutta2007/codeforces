#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:128000000")
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

 
using namespace std; 
 
typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
//const long double eps = 1e-5;
//const int INF = 50000;
const int N = 1000 * 1000 + 10;
const ll mod = 1000 * 1000 * 1000 + 7;

struct Fenvick {
    vector<ll> t;
    int n;
    Fenvick(int nn) {
        n = nn;
        t.assign(n, 0);
    }
    ll sum(int r) {
        ll res = 0;
        for (; r >= 0; r = (r & (r+1)) - 1)
            res += t[r];
	return res % mod;
    }
    void inc(int i, ll delta) {
        for (; i < n; i = (i | (i+1)))
		    t[i] = (t[i] + delta) % mod;
    }
    ll sum (int l, int r) {
        return sum(r) - sum(l - 1);
    }
};

int main() {
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    Fenvick f(N);
    vector<ll> data(N, 0);
    data[0] = 1;
    f.inc(0, 1);
    for (int i = 0; i < n; ++i) {
        ll x = (f.sum(a[i]) * a[i]) % mod;
        ll delta = (mod + x - data[a[i]]) % mod;
        f.inc(a[i], delta);
        data[a[i]] = x;
    }
    ll res = 0;
    for (int i = 1; i < N; ++i)
        res += data[i];
    res = res % mod;
    cout << res << endl;
    return 0;
}