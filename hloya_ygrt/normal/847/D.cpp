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

set<int> cur;
int t[maxn], T;
vector<int> dost[maxn];

int main() {
    int n;
//    freopen(".in", "r", stdin);
    cin >> n >> T;
    T--;

    for (int i = 0 ;i <n; i++)
        cin >> t[i];

    int ans = 0;
    for (int i = 0; i < min(T, n); i++) {
        if (t[i] <= T) {
            cur.insert(i);
            int time_to = min(maxn - 1, T - t[i] + i);
            dost[time_to].push_back(i);
        }
        ans = max(ans, (int)cur.size());
        for (int j = 0; j < dost[i].size(); j++) {
            cur.erase(dost[i][j]);
        }
    }
    cout << ans;
    return 0;
}