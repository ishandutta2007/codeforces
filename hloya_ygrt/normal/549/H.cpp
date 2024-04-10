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
 
const int inf = 2e9;
const double eps = 1e-9;
const int maxn = 5e5 + 3, base = 1e9 + 7;
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

ld a, b, c, d;

bool intersect(ld L, ld R, ld l, ld r) {
    return (L <= l && l <= R) || (l <= L && L <= r);
}

ld min(ld x, ld y, ld z, ld k) {
    return min(min(x, y), min(z, k));
}

ld max(ld x, ld y, ld z, ld k) {
    return max(max(x, y), max(z, k));
}

bool can(ld m) {
    ld L1 = min((a - m) * (d - m), (a + m) * (d + m), 
               (a + m) * (d - m), (a - m) * (d + m));
    ld R1 = max((a - m) * (d - m), (a + m) * (d + m), 
               (a + m) * (d - m), (a - m) * (d + m));


    ld L2 = min((b - m) * (c - m), (b + m) * (c + m), 
               (b + m) * (c - m), (b - m) * (c + m));
    ld R2 = max((b - m) * (c - m), (b + m) * (c + m), 
               (b + m) * (c - m), (b - m) * (c + m));
    

    return intersect(L1, R1, L2, R2);    
}

int main() {
    cin >> a >> b >> c >> d;

    ld l = 0, r = (ld)2 * inf;

    for (int it = 0; it < 400; it++) {
        ld m = (ld)(l + r) / (ld)2;
        
        if (can(m))
            r = m;
        else
            l = m;
    }

    cout << fixed << setprecision(20) << l;
    return 0;
}