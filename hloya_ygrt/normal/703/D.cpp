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
#define ln(i,n) " \n"[(i) == (n) - 1]

using namespace std;
 
void bad(string mes = "Impossible"){cout << mes;exit(0);}
// template<typename ... T> void shit(T& ... x){}
// template<typename ... T> void dec(T& ... x){shit(--x...);}
// template<typename ... T> void inc(T& ... x){shit(++x...);}
// #include <unordered_map>
// #include <unordered_set>

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

    while (!((c >= '0' && c <= '9') || c == '-')) {
        c = getchar();
    }

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
 
const int inf = 2e9;
const double eps = 1e-9;
const int maxn = 1e6 + 5, base = 1e9 + 7;
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

int pref[maxn], a[maxn];

int res[maxn];
vector<pair<int, pair<int, int> > > query;

map<int, int> R;

int t[maxn * 2];
int n;
void update(int p, int value) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] ^ t[p^1];
}

int findXor(int l, int r) {  // sum on interval [l, r)
  int res = 0;
  r++;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res ^= t[l++];
    if (r&1) res ^= t[--r];
  }
  return res;
}

int main() {

    read(n);

    for (int i = 0; i < n; i++){
        read(a[i]);
        if (i)
            pref[i] = pref[i - 1];
        pref[i] ^= a[i];
    }

    int q;
    read(q);

    for (int i = 0; i < q; i++) {
        int l, r;
        read(l, r);
        l--, r--;
        query.push_back(make_pair(r, make_pair(l, i)));
    }

    sort(query.begin(), query.end());

    int curR = -1;
    for (int i = 0; i < q; i++) {
        int l, r, it;
        r = query[i].first, l = query[i].s.f, it = query[i].s.s;

        while (curR < r) {
            curR++;
            int x = a[curR];
            if (R.count(x))
                update(R[x], 0);
            R[x] = curR;
            update(R[x], x);
        }

        int ans = findXor(l, r);
        int old = pref[r] ^ (l == 0 ? 0 : pref[l - 1]);
        res[it] = ans ^ old;
    }

    for (int i = 0; i < q; i++)
        printf("%d\n", res[i]);
    return 0;
}