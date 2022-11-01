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
#define ll long long

void bad() {
    cout << "Impossible";
    exit(0);
}

int main() {
//    freopen(".in", "r", stdin);
    ios_base::sync_with_stdio(0);

    int n;
    long long k;
    cin >> n >> k;

    if (1ll * n * (n - 1) / 2 < k)
        bad();

    int j = 1;
    while (1ll * j * (j - 1) / 2 < k) {
        j++;
    }
    if (1ll * j * (j - 1) / 2 != k)
        j--;

    ll need = k - 1ll * j * (j - 1) / 2;

    if (need > j - 1) {
        return 228;
    }

    string s = "";
    for (int i = 0; i < j; i++) {
        s += '(';
        if (i + 1 == need) {
            s += "()";
        }
    }
    for (int i = 0; i < j; i++) {
        s += ')';
    }
//    cout << j << endl;
    n -= j;
    if (need != 0)
        n--;
    if (n < 0)
        bad();
    for (int i = 0; i < n; i++)
        s += "()";
    cout << s;
    return 0;
}