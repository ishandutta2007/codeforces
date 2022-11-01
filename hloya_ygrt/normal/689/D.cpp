#include <iostream>
#include <fstream>
// #include <bits/stdc++.h>
#include <sstream>
#include <list>
#include <stack>
#include <deque>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <assert.h>
#include <bitset>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <iterator>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <complex>
 
#define f first
#define s second
#define ll long long
#define ld long double
#define pb push_back
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define files files1;files2
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0)
#define vi vector<int>
#define pii pair<int,int>
#define endl '\n'

using namespace std;
 
void bad(string mes = "Impossible"){cout << mes;exit(0);}
template<typename ... T> void shit(T& ... x){}
template<typename ... T> void dec(T& ... x){shit(--x...);}
template<typename ... T> void inc(T& ... x){shit(++x...);}
#include <unordered_map>
#include <unordered_set>

template<typename T>
string bin(T x, int st = 2){
    string ans = "";
    while (x > 0){
        ans += char('0' + x % st);
        x /= st;
    }
    reverse(ans.begin(), ans.end());
    return ans.empty() ? "0" : ans;
}

template<typename T>
T input(){
    T ans = 0, m = 1;
    char c = ' ';
    while (!((c >= '0' && c <= '9') || c == '-'))
        c = getchar();
    if (c == '-')
        m = -1, c = getchar();
    while (c >= '0' && c <= '9'){
        ans = ans * 10 + (c - '0'), c = getchar();
    }
    return ans * m;
}

template<typename T>
void read(T& a) {
    a = input<T>();
}

template<typename T>
void read(T& a, T& b) {
    read(a), read(b);
}

template<typename T>
void read(T& a, T& b, T& c) {
    read(a, b), read(c);
}

template<typename T>
void read(T& a, T& b, T& c, T& d) {
    read(a, b), read(c, d);
}
 
const int inf = 2e9 + 1;
const double eps = 1e-9;
const int maxn = 2e5 + 100, base = 1e9 + 7;
const int sigm = 26;
const ll llinf = 1e18 + 1;

template<typename T>
T binpow(T n, T s)
{
    if (s <= 0)
        return 1LL;
    if (s % 2 == 0){
        T b = binpow(n, s / 2);
        return ( 1LL * b * b ) % base;
    } else {
        return (1LL* binpow(n, s - 1) * n) % base;
    }
}

int n; 

int tmax[2 * maxn], tmin[2 * maxn];

void buildmx() {  // build the tree
  for (int i = n - 1; i > 0; --i) tmax[i] = max(tmax[i<<1], tmax[i<<1|1]);
}

int find_max(int l, int r) {  // sum on interval [l, r)
  int res = -inf;
  r++;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = max(res, tmax[l++]);
    if (r&1) res = max(res, tmax[--r]);
  }
  return res;
}

void buildmn() {  // build the tree
  for (int i = n - 1; i > 0; --i) tmin[i] = min(tmin[i<<1], tmin[i<<1|1]);
}

int find_min(int l, int r) {  // sum on interval [l, r)
  int res = inf;
  r++;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = min(res, tmin[l++]);
    if (r&1) res = min(res, tmin[--r]);
  }
  return res;
}

int a[maxn], b[maxn];

int main() {
    // files1;
    read(n);

    for (int i = 0; i < 2 * maxn; i++)
        tmax[i] = -inf, tmin[i] = inf;

    for (int j = 0; j < n; j++){
        read(a[j]);
        tmax[n + j] = a[j];
    }
    for (int j = 0; j < n; j++){
        read(b[j]);
        tmin[n + j] = b[j];
    }

    buildmn();
    buildmx();

    // cout << find_max(0, 0) << endl;
    ll ans = 0;
    for (int L = 0; L < n; L++) {
        int l = L, r = n - 1;
        while (r - l > 1) {
            int m = (l + r) >> 1;
            int x = find_min(L, m);
            int y = find_max(L, m);

            if (x > y)
                l = m;
            else
                r = m;
        }
        int resL = -1;

        int x = find_min(L, l);
        int y = find_max(L, l);
        if (x == y)
            resL = l;
        else
        {
            x = find_min(L, r);
            y = find_max(L, r);
            if (x == y)
                resL = r;
        }

        if (resL == -1)
            continue;

        l = resL, r = n - 1;
        while (r - l > 1) {
            int m = (l + r) >> 1;
            int x = find_min(L, m);
            int y = find_max(L, m);
            if (x >= y)
                l = m;
            else
                r = m;
        }

        int resR = -1;

          x = find_min(L, r);
          y = find_max(L, r);
        if (x == y)
            resR = r;
        else
        {
            x = find_min(L, l);
            y = find_max(L, l);
            if (x == y)
                resR = l;
        }

        assert(resR != -1);
        ans += resR - resL + 1;
    }

    cout << ans;
    return 0;
}