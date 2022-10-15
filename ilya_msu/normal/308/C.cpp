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

ll up(ll a, ll b) {
    ll q = a / b;
    if (a % b != 0)
        ++q;
    return q;
}

vector<ll> c(30, 0);
void add(ll a) {
    int ind = 0;
    while(a) {
        if (a & 1)
            ++c[ind];
        ++ind;
        a /= 2;
    }
}

int main() {
	//ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    int n, m;
    vector<ll> d(30, 0);
    scanf("%d %d", &n, &m);
    int a, b;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a);
        add(a);        
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d", &b);
        ++d[b];
    }
    ll res = 0;
    for (int i = 0; i < 30; ++i) {
        if (c[i] >= d[i]) {
            res += d[i];
            c[i] -= d[i];
            d[i] = 0;
            continue;
        }
        res += c[i];
        d[i] -= c[i];
        c[i] = 0;
        ll mult = 2;
        int j = i + 1;
        while(j < 30) {
            if (mult * c[j] >= d[i]) {
                res += d[i];
                ll q = up(d[i], mult);
                c[j] -= q;
                add((q * mult - d[i]) << i);
                d[i] = 0;
                break;
            }
            else {
                res += mult * c[j];
                d[i] -= mult * c[j];
                c[j] = 0;
                mult *= 2;
                ++j;
            }
        }
    }
    cout << res << endl;
    return 0;
}