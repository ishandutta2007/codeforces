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
typedef unsigned int uint; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<char, char> pcc;
typedef pair<double, double> pdd;


const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-7;
const int INF = 1000 * 1000 * 1000 + 1;
const ll N1 = 100 * 1000, N2 = 1000 * 1000 * 1000, N3 = 2000;
const ll MOD = 1000 * 1000 * 1000 + 7;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

ll nok(ll a, ll b) {
    return a / gcd(a, b) * b;
}

int main() {
    //std::ios_base::sync_with_stdio(0);
    //freopen("INPUT.TXT", "r", stdin);
    //freopen("OUTPUT.TXT", "w", stdout);
    ll x, y, a, b;
    cin >> x >> y >> a >> b;
    ll t = nok(x, y);
    ll res = b / t - (a - 1) / t;
    cout << res << endl;
    return 0;
}