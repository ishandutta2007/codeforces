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
//const int N = 1000 * 1000 + 10;
//const ll mod = 1000 * 1000 * 1000 + 7;;

int count(ll n, int d) {
    int m = 2;
    while (true) {
        ll res = 1;
        for (int i = 0; i < d; ++i)
            res *= m;
        if (res > n)
            return m - 2;
        ++m;
    }
}

int main() {
    //std::ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int nim[] = {0, 1, 2, 1, 4, 3, 2, 1, 5, 6, 2, 1, 8, 7, 5, 9, 8, 7, 3, 4, 7, 4, 2, 1, 10, 9, 3, 6, 11, 12};
    ll n;
    cin >> n;
    vector<int> deg(30, 0);
    int s = 0;
    for (int i = 29; i > 1; --i) {
        deg[i] += count(n, i);
        for (int j = i - 1; j > 1; --j) {
            deg[j] -= deg[i] * (i / j);
        }
        s += deg[i] * i;
    }
    deg[1] = n - s;
    ll res = 0;
    for (int i = 1; i <= 29; ++i) {
        if (deg[i] & 1)
            res = res ^ nim[i];
    }
    if (res == 0)
        cout << "Petya\n";
    else
        cout << "Vasya\n";
    return 0;
}