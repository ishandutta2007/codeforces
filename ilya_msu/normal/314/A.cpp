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
//const int N = 1000 * 1000 * 1000 + 10;


int main() {
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    ll n, k;
    cin >> n >> k;
    vector<pii> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    vector<int> res;
    ll cur = 0;
    ll m = 1;
    for (int i = 0; i < n; ++i) {
        cur = cur - (ll)(m - 1) * (n - res.size() - m) * a[i].first;
        if (cur < k) {
            cur = cur + (m - 1) * (n - res.size() - m) * a[i].first; 
            res.push_back(a[i].second);
        }
        else {
            cur = cur + (m - 1) * (n - res.size() - m) * a[i].first + (m - 1) * a[i].first;
            ++m;
        }
    }
    for (int i = 0; i < res.size(); ++i)
        cout << res[i] << "\n";    
    return 0;
}