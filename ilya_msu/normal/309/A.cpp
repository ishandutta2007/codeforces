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
    ll n, l, t;
    scanf("%I64d %I64d %I64d", &n, &l, &t);
    ll q = t / l;
    double res = 0.5 * q * n * (n - 1);
    ll tt = t - q * l;
    tt *= 2;
    int r = 0;
    vector<ll> data(n);
    ll count = 0;
    for (int i = 0; i < n; ++i)
        scanf("%I64d", &data[i]);
    for (int i = 0; i < n; ++i) {
        r = max(i, r);
        while((r < n) && (data[r] <= data[i] + tt))
            ++r;
        count += r - i - 1;
    }
    r = 0;
    for (int i = 0; i < n; ++i) {
        r = max(i, r);
        while((r < n) && (data[r] - data[i] < l - tt))
            ++r;
        count += n - r;
    }
    r = 0;
    for (int i = 0; i < n; ++i) {
        r = max(i, r);
        while((r < n) && (data[r] + l <= data[i] + tt))
            ++r;
        count += max(r - i - 1, 0);
    }
    r = 0;
    for (int i = 0; i < n; ++i) {
        r = max(i, r);
        while((r < n) && (data[r] - data[i] < 2 * l - tt))
            ++r;
        count += n - r;
    }
    res += 0.25 * count;
    printf("%0.10f\n", res);
    return 0;
}