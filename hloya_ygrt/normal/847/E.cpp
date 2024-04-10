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

string a;
vector<int> p, p2;

bool check(int c) {
    int pe = 0;

    for(int i = 0; i < p2.size() && pe < p.size(); i++) {
        int kek = c;
        int po = p2[i];

        if(p[pe] < p2[i]) {
            if(abs(p[pe] - p2[i]) > c)
                return 0;
            po = p[pe];

            int lol = abs(p[pe] - p2[i]);

            int mda = c - lol * 2;

            int pos[2] = {0, 0};
            pos[0] = lower_bound(all(p), p2[i] + mda + 1) - p.begin();
            pos[1] = lower_bound(all(p), p2[i] + (c - lol) / 2 + 1) - p.begin();

            pe = lower_bound(all(p), p2[i]) - p.begin();
            pe = max(pe, max(pos[0], pos[1]));
        } else {
            pe = max(pe, (lower_bound(all(p), po + kek + 1) - p.begin()));
        }
    }

    return (pe == p.size());
}

int main() {
//    freopen(".in", "r", stdin);
//    ios_base::sync_with_stdio(0);

    int n; cin >> n;
    a = next_token();

    for(int i = 0; i < n; i++) {
        if(a[i] == '*') {
            p.push_back(i);
        }

        if(a[i] == 'P') {
            p2.push_back(i);
        }
    }

    int l = 0;
    int r = n * 2;

    while(r - l > 1) {
        int c = (l + r) / 2;

        if(check(c)) {
            r = c;
        } else {
            l = c;
        }
    }

    if(check(l))
        cout << l << "\n";
    else
        cout << r << "\n";

    return 0;
}