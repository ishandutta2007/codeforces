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


int main() {
    //std::ios_base::sync_with_stdio(0);
    //freopen("INPUT.TXT", "r", stdin);
    //freopen("OUTPUT.TXT", "w", stdout);
    int n;
    cin >> n;
    vector<pii> a(n);
    int res = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < i; ++j) {
            vector<int> b;
            for (int k = 0; k < n; ++k) {
                if ((k == i) || (k == j))
                    continue;
                int x1 = a[j].first - a[i].first, y1 = a[j].second - a[i].second, x2 = a[k].first - a[i].first, y2 = a[k].second - a[i].second;
                b.push_back(x1 * y2 - x2 * y1);
            }
            sort(b.begin(), b.end());
            res = max(res, -b[0] + b[n - 3]);
        }
    cout.precision(10);
    cout << 0.5 * res << endl;    
    return 0;
}