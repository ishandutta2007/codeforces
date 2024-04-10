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

long long pref[100100];
long long suff[100100];
long long prefval[100100];
long long suffval[100100];
int a[100100];
int b[100100];

int main() {
//    freopen(".in", "r", stdin);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], b[i] = a[i];


    int f = a[1];
    pref[1] = 0;
    prefval[1] = a[1];
    for (int i = 2; i <= n; i++) {
        f = a[i - 1];
        prefval[i] = f + 1;
        pref[i] = pref[i - 1];
        if (a[i] < f + 1) pref[i] += f + 1 - a[i], a[i] = f + 1;
        else prefval[i] = a[i];
    }
    for (int i = 1; i <= n; i++) a[i] = b[i];
    f = a[n];
    suff[n] = 0;
    suffval[n] = a[n];
    for (int i = n - 1; i >= 1; i--) {
        f = a[i + 1];
        suffval[i] = f + 1;
        suff[i] = suff[i + 1];
        if (a[i] < f + 1) suff[i] += f + 1 - a[i], a[i] = f + 1;
        else suffval[i] = a[i];
    }

    long long ans = pref[n];
    ans = min(ans, suff[1]);
    for (int i = 1; i < n; i++) {
        long long s = pref[i] + suff[i + 1];
        if (prefval[i] <= suffval[i + 1])
            s += suffval[i + 1] + 1 - prefval[i];
        ans = min(ans, s);
    }
    cout << ans << endl;

    return 0;
}