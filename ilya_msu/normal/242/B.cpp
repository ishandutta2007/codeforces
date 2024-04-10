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
	//ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector<pii> a(n);
    int l, r;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
        if (i)
            l = min(l, a[i].first);
        else
            l = a[0].first;
        if (i)
            r = max(r, a[i].second);
        else
            r = a[0].second;
    }
    int ans = -1;
    for (int i = 0; i < n; ++i)
        if ((a[i].first == l) && (a[i].second == r))
            ans = i + 1;
    cout << ans << endl;
    return 0;
}