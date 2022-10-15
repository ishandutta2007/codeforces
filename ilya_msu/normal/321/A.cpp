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
const long double eps = 1e-10;


int main() {
	//ios_base::sync_with_stdio(0);
	//freopen("circles.in", "r", stdin);
    //freopen("circles.out", "w", stdout);
    ll a, b;
    cin >> a >> b;
    string s;
    ll x = 0, y = 0;
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'U')
            ++y;
        if (s[i] == 'D')
            --y;
        if (s[i] == 'L')
            --x;
        if (s[i] == 'R')
            ++x;
    }
    ll dx = x, dy = y;
    x = y = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (dx == 0) {
            if (dy == 0) {
                if ((a == x) && (b == y)) {
                    cout << "Yes\n";
                    return 0;
                }
            }
            else {
                ll d = (b - y) / dy;
                if ((d * dy == (b - y)) && (a == x) && (d >= 0)) {
                    cout << "Yes\n";
                    return 0;
                }
            }
        }
        else {
            ll d = (a - x) / dx;
            if ((d * dx == (a - x)) && (d >= 0)) {
                if (d * dy == (b - y)) {
                    cout << "Yes\n";
                    return 0;
                }
            }
        }
        if (s[i] == 'U')
            ++y;
        if (s[i] == 'D')
            --y;
        if (s[i] == 'L')
            --x;
        if (s[i] == 'R')
            ++x;
    }
    cout << "No\n";
    return 0;
}