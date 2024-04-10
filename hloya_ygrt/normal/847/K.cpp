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

pair<string, string> s[555];
int cost[555];

int main() {
//    freopen(".in", "r", stdin);
    ios_base::sync_with_stdio(0);

    int n, a, b, k, f;
    cin >> n >> a >> b >> k >> f;
    for (int i = 0; i < n; i++) {
        cin >> s[i].first >> s[i].second;
        cost[i] = a;
        if (i > 0 && s[i - 1].second == s[i].first) cost[i] = b;
    }

    vector<pair<int, pair<string, string> > > v;

    for (int i = 0; i < n; i++) {
        pair<string, string> p = s[i];
        if (p.first > p.second) swap(p.first, p.second);

        bool found = 0;

        for (int j = 0; j < (int)v.size(); j++)
            if (p == v[j].second) {
                v[j].first += cost[i];
                found = 1;
            }

        if (!found) {
            v.push_back(make_pair(cost[i], p));
        }

    }

    int ans = 0;
    for (int i = 0; i < n; i++) ans += cost[i];

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    for (int i = 0; i < min(k, (int)v.size()); i++) {
        if (f >= v[i].first) break;
        ans -= v[i].first;
        ans += f;
    }

    cout << ans << endl;

    return 0;
}