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

int main() {
    //std::ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.out", "w", stdout);
    ll m, r;
    cin >> m >> r;
    double res = 0;
    for (ll i = 0; i < m - 1; ++i)
        res += 2.0 * i * ((m - i - 1) * 2 * r + 2.0 * sqrt(2.0) * r);
    res += m * 2 * r;
    res += 2 * (m - 1) * (2 * r + sqrt(2.0) * r);
    res /= m * m;
    cout.precision(12);
    cout << res << endl;
    return 0;
}