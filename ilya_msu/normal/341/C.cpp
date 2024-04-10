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
const int INF = 500000;
//const int N = 1000 * 1000 * 1000 + 10;
const int MOD = 1000 * 1000 * 1000 + 7;

vector<vector<int> > ans;

ll solve(int n, int k) {
    if (n < 0)
        return 0;
    if (ans[n][k] != -1)
        return ans[n][k];
    if (k == 0) {
        if (n <= 1)
            return 1;
        ans[n][k] = (solve(n - 1, k) * n) % MOD;
        return ans[n][k];
    }        
    int x;
    if (k == 1)
        x = (solve(n - 1, k - 1) * (n - k)) % MOD;
    else
        x = (solve(n - 1, k - 1) * (n - k) + solve(n - 1, k - 2) * (k - 1)) % MOD;
    ans[n][k] = x;
    return x;
}

int main() {
	//ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector<int> p(n);
    int d1 = 0, d2 = 0;
    set<int> no;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &p[i]);
        if (p[i] == -1) {
            ++d1;
            no.insert(i + 1);
        }
    }
    d2 = d1;
    for (int i = 0; i < n; ++i) {
        if (no.find(p[i]) != no.end())
            --d2;
    }
    ans.assign(d1 + 1, vector<int> (d2 + 1, -1));
    cout << solve(d1, d2) << endl;

    
    return 0;
}