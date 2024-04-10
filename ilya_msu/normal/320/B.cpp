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

vector<pii> g;
vector<int> used;

bool edge(int i, int j) {
    pii a = g[i], b = g[j];
    return (((a.first > b.first) && (a.first < b.second)) || ((a.second > b.first) && (a.second < b.second)));
}

void dfs(int pos) {
    used[pos] = true;
    for (int i = 0; i < g.size(); ++i) {
        if (used[i])
            continue;
        if (edge(pos, i))
            dfs(i);
    }
}

int main() {
	//ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x, a, b;
        cin >> x >> a >> b;
        if (x == 1) {
            g.push_back(pii(a, b));
        }
        else {
            --a;
            --b;
            used.assign(g.size(), false);
            dfs(a);
            if (used[b])
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    return 0;
}