// In the name of god
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <assert.h>
#include <ctime>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <bitset>
#include <bits/stdc++.h>
#define sqr(a) ((a)*(a))
#define all(a) (a).begin(), (a).end()
using namespace std;

template <typename T>
T next_int() {
    T x = 0, p = 1;
    char ch;
    do { ch = getchar(); } while(ch <= ' ');
    if(ch == '-') {
        p = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return p * x;
}

string next_token() {
    char ch;
    string ans = "";
    do { ch = getchar(); } while(ch <= ' ');
    while(ch > ' ') {
        ans += ch;
        ch = getchar();
    }
    return ans;
}

const long long INF = (long long)1e18;
const int INFINT = (int)1e9 + 227 + 1;
const int maxn = (int)1e6 + 227 + 1;
const int MOD = (int)1e9 + 7;
const long double EPS = 1e-9;

long long bin_pow(long long a, long long b) {
    if(!b) return 1;
    long long ans = bin_pow(a, b / 2);
    ans = ans * ans;
    if(b % 2) ans = ans * a;
    return ans;
}

int l[111];
int r[111];
bool vis[111];

int main() {
//    freopen("input.txt", "r", stdin);
//    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> l[i] >> r[i];
    vector<int> g;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        vis[i] = 1;
        vector<int> v;
        int p = i;
        while (true) {
            if (l[p] == 0) break;
            vis[l[p]] = 1;
            v.push_back(l[p]);
            p = l[p];
        }
        reverse(v.begin(), v.end());
        v.push_back(i);
        p = i;
        while (true) {
            if (r[p] == 0) break;
            vis[r[p]] = 1;
            v.push_back(r[p]);
            p = r[p];
        }
        for (int j = 0; j < v.size(); j++) {
                g.push_back(v[j]);
         //   cout << v[j] << " ";
        }
      //  cout << endl;
    }
    for (int i = 0; i < n; i++) {
        if (i == 0) l[g[i]] = 0;
        else l[g[i]] = g[i - 1];
        if (i == n - 1) r[g[i]] = 0;
        else r[g[i]] = g[i + 1];
    }
    for (int i = 1; i <= n; i++) cout << l[i] << " " << r[i] << "\n";

    return 0;
}