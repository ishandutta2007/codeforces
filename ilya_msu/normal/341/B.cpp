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


int main() {
	//ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    vector<int> d(n + 1, n + 1);
    d[0] = -1;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        int l = 0, r = n + 1;
        while(r - l > 1) {
            int m = (r + l) / 2;
            if (d[m] < a[i])
                l = m;
            else
                r = m;
        }
        if (l < n) {
            d[l + 1] = a[i];
            res = max(res, l + 1);
        }
    }
    cout << res << endl;
    
    return 0;
}