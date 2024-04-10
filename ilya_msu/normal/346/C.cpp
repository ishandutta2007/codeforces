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
typedef pair<long double, long double> pdd;

typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
//const long double eps = 1e-5;
const int INF = 10000000;
//const int N = 1000 * 1000 * 1000 + 10;
const int MOD = 1000 * 1000 * 1000 + 7;

int main() {
	//ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x[i]);
    }
    int a, b;
    scanf("%d %d", &a, &b);
    sort(x.begin(), x.end());
    vector<int> d(a - b + 1, 1);
    for (int i = 0; i < x.size(); ++i) {
        if ((i) && (x[i] == x[i - 1])) 
            continue;
        for (int q = (b + x[i] - 1) / x[i] * x[i]; q <= a; q += x[i]) {
            d[q - b] = max(d[q - b], x[i] - 1);
        }
    }
    int up = 1;
    int res = 0;
    int l = 0;
    while(up <= a - b) {
        ++res;
        int r = l + 1;
        for (; l < up; ++l)
            r = max(r, l + d[l]);
        up = r + 1;        
    }
    cout << res << endl;
    
    return 0;
}