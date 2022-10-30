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
 
const int inf = 1e9;
const double eps = 1e-9;
const int maxn = 1e6 + 3, base = 1073676287;
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

map<ll, int> used;
map<ll, ll> edge;

int main() {
    int q;
    read(q);

    int curColor = 1;
    for (int i = 0; i < q; i++, curColor++) {
        int t;
        read(t);

        if (t == 1) {
            ll v, u, w;
            read<ll>(v, u, w);

            ll kek, mda;
            kek = v, mda = u;

            while (v) {
                used[v] = curColor;
                v /= 2;
            }
            while (u && used[u] != curColor) {
                used[u] = curColor;
                u /= 2;
            }

            ll lca = u;
            v = kek, u = mda;

            while (u != lca) {
                edge[u] += w;
                u /= 2;
            }
            while (v != lca) {
                edge[v] += w;
                v /= 2;
            }
        } else { 
            ll v, u;
            read<ll>(v, u);

            ll kek, mda;
            kek = v, mda = u;

            while (v) {
                used[v] = curColor;
                v /= 2;
            }
            while (u && used[u] != curColor) {
                used[u] = curColor;
                u /= 2;
            }

            ll lca = u;
            v = kek, u = mda;

            ll ans = 0;

            while (u != lca) {
                ans += edge[u];
                u /= 2;
            }
            while (v != lca) {
                ans += edge[v];
                v /= 2;
            }

            cout << ans << endl;
        }
    }
    return 0;
}