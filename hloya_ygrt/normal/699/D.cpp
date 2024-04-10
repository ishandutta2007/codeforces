#include <algorithm>
#include <assert.h>
#include <bitset>
// #include <bits/stdc++.h>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
 
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
    while (!(c >= '0' && c <= '9') || c == '-') {
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
 
const int inf = 1e9;
const double eps = 1e-9;
const int maxn = 2e5 + 3, base = 1e9;
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

int ans = 0;
int p[maxn];
int used[maxn];

vector<int> g[maxn];

vector<int> roots;

void dfs1(int v) {
    used[v] = 1;
    for (int to:g[v])
        if (!used[to])
            dfs1(to);
}

void findCycle(int v) {
    used[v] = 2;

    for (int to:g[v]) {
        if (used[to] == 2) {
            //v -> to
            ans++;
            roots.push_back(v);
            p[v] = v;
        }
        if (!used[to])
            findCycle(to);
    }

    used[v] = 1;
}

int main() {
    int n;
    read(n);

    for (int i = 0; i < n; i++){
        read(p[i]);
        p[i]--;
        g[p[i]].push_back(i);
    }

    int cntPyr = 0;
    for (int i = 0; i < n; i++)
        if (i == p[i]){
            roots.push_back(i);
            cntPyr++;
            dfs1(i);
        }

    for (int i = 0; i < n; i++)
        if (!used[i]) {
            findCycle(i);
        }
    
    assert(roots.size());

    int root = roots.front();

    for (int i = 0; i < n; i++)
        if (p[i] == i)
            p[i] = root;
    ans += cntPyr;
    if (cntPyr != 0)
        ans--;
    
    printf("%d\n", ans);
    for (int i = 0; i < n; i++)
        printf("%d ", p[i] + 1);
    return 0;
}