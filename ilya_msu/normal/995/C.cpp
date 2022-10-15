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


vector<int> res;
vector<pll> p;

ll norm(const pll& x) {
    return x.first * x.first + x.second * x.second;
}

int first[6] = {0, 0, 0, 0, 1, 1};
int second[6] = {1, 1, 2, 2, 2, 2};
int third[6] = {2, 2, 1, 1, 0, 0};

const ll N = (ll)(1000000) * 1000000;
void solve(int n) {
    //cerr << n << endl;
    if (n == 1) {
        res[0] = 1;
        return;
    }
    if (n == 2) {
        res[0] = res[1] = 1;
        pll v1(p[0].first + p[1].first, p[0].second + p[1].second);
        pll v2(p[0].first - p[1].first, p[0].second - p[1].second);
        if (norm(v2) < norm(v1))
            res[1] = -1; 
        return;
    }
    int id = -1;
    for (int i = 0; i < 6; ++i) {
        
        pll v1 = p[n - first[i] - 1];
        pll v2 = p[n - second[i] - 1];
        pll v3 = p[n - third[i] - 1];
        
        pll v;
        if (i & 1) {
            v = pll(v1.first + v2.first, v1.second + v2.second);
        }
        else {
            v = pll(v1.first - v2.first, v1.second - v2.second);
        }
        if (norm(v) <= N) {
            id = i;
            p.pop_back();p.pop_back();p.pop_back();
            p.push_back(v3);
            p.push_back(v);
            break;
        }

    }
    solve(n - 1);
    
    int r3 = res[n - 3];
    int r = res[n - 2];
    res[n - third[id] - 1] = r3;
    res[n - first[id] - 1] = r;
    if (id & 1)
        res[n - second[id] - 1] = r;
    else
        res[n - second[id] - 1] = -r;
  
}


void solve() {
    int n;
    cin >> n;
    p.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> p[i].first >> p[i].second;
    vector<pll> pp(p.begin(), p.end());
    res.assign(n, 0);
    solve(n);
    pll x(0, 0);
    for (int i = 0; i < n; ++i) {
        x.first += pp[i].first * res[i];
        x.second += pp[i].second * res[i];

    }
    //cout << norm(x) << endl;
    for (int i = 0; i < n; ++i)
        cout << res[i] << " ";
    cout << endl;
    
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