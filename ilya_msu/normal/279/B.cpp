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
    int n, t;
    cin >> n >> t;
    vector<int> a(n), s(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        s[i] = a[i];
        if (i)
            s[i] += s[i - 1];
    }
    int res = 0;
    int r = 0;
    for (int i = 0; i < n; ++i) {
        r = max(r, i);
        int cur = 0;
        if (r)
            cur = s[r - 1];
        if (i)
            cur -= s[i - 1];
        while((r < n) && (a[r] + cur <= t)) {
            cur += a[r];
            ++r; 
        }
        res = max(res, r - i);
    }
    cout << res << endl;
    return 0;
}