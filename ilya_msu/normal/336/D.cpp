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

 
using namespace std; 
 
typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<char, char> pcc;

const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-7;
const int INF = 1000 * 1000 * 1000 + 1;
const int N = 1000 * 1000 * 1000;
const ll MOD = 1000 * 1000 * 1000 + 7;

struct mask {
    int m, n, g;
    mask(int nn, int mm, int gg) : n(nn), m(mm), g(gg) {}
    bool operator<(const mask& b) {
        return (m < b.m) || ((m == b.m) && (n < b.n)) || ((m == b.m) && (n == b.n) && (g < b.g));
    }
};

bool operator<(const mask& a, const mask& b) {
    return (a.m < b.m) || ((a.m == b.m) && (a.n < b.n)) || ((a.m == b.m) && (a.n == b.n) && (a.g < b.g));
}

map<mask, ll> ans;
vector<ll> f, obr;
ll c(int n, int k) {
    return (((f[n] * obr[k]) % MOD) * obr[n - k]) % MOD;
}

ll solve(mask m) {
    if (ans.find(m) != ans.end())
        return ans[m];
    if (m.m == 0) {
        ans[m] = m.g ^ (m.n & 1);
        return ans[m];
    }
    if (m.n == 0) {
        ans[m] = (m.g == (m.m == 1));
        return ans[m];
    }
    if (m.g == 1) {
        ans[m] = solve(mask(m.n - 1, m.m, 0));
        return ans[m];
    }
    ans[m] = (solve(mask(m.n - 1, m.m, 1)) + c(m.n + m.m - 1, m.n)) % MOD;
    return ans[m];
}

int power(ll a, int n) {
    ll res = 1;
    while(n) {
        if (n & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        n /= 2;
    }
    return res;
}

int main() {
    //std::ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.out", "w", stdout);
    int m, n, g;
    cin >> n >> m >> g;
    int N = m + n + 10;
    f.resize(N);
    obr.resize(N);
    obr[0] = f[0] = 1;
    for (int i = 1; i < N; ++i) {
        f[i] = (f[i - 1] * i) % MOD;
        obr[i] = power(f[i], MOD - 2);
    }    
    cout << solve(mask(n, m, g)) << endl;
    return 0;
}