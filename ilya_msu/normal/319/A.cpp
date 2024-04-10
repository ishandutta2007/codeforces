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
const int INF = 1000 * 1000 * 1000;
//const int N = 1000 * 1000 * 1000 + 10;
const int mod = 1000 * 1000 * 1000 + 7;

ll pow(ll a, int n, ll mod) {
    ll res = 1;
    while(n) { 
        if (n & 1)
            res = (res * a) % mod;
        n /= 2;
        a = (a * a) % mod;
    }
    return res;
}

int main() {
	//ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    string s;
    cin >> s;
    int n = s.size();
    ll res = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            int k = i + 1;
            ll a = pow(2, 2 * n - k - 1, mod);
            res = (res + a) % mod;
        }
    }
    cout << res << endl;
    return 0;
}