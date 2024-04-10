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
typedef pair<char, char> pcc;

const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
//const long double eps = 1e-5;
//const int INF = 50000;
//const int N = 100 * 1000 + 10;
const ll mod = 1000 * 1000 * 1000;


int main() {
    //std::ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<ll> f(n + 5);
    f[0] = f[1] = 1;
    for (int i = 2; i < f.size(); ++i)
        f[i] = (f[i - 1] + f[i - 2]) % mod;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < m; ++i) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, v;
            cin >> x >> v;
            a[x - 1] = v;
            continue;
        }
        if (t == 2) {
            int l, r;
            cin >> l >> r;
            ll res = 0;
            for (int i = 0; i <= r - l; ++i)
                res = (res + f[i] * a[l + i - 1]) % mod;
            cout << res << "\n";
            continue;
        }
    }
    return 0;
}