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
const int maxn = 5e5 + 5;
const int sigm = 26;
const ll llinf = 1e18 + 1;

int base;
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

struct Matrix {
    int size;

    vector<vector<int> > data;
    vector<vector<int> > zero, empty;

    Matrix(int __size) {
        size = __size;
        vector<vector<int> > cur(size, vector<int>(size, 0));
        data = zero = empty = cur;

        for (int i = 0; i < size; i++)
            zero[i][i] = 1;
    }

    vector<int> & operator [](const size_t & i) {
        return data[i];
    }

    bool set(vector<int> A) {
        if (A.size() != size * size)
            return false;
        int cur = 0;
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++, cur++)
                data[i][j] = A[cur];
        return true;
    }

    void mult(Matrix m) {
        vector<vector<int> > a = data;
        vector<vector<int> > b = m.data;

        data = empty;
        for (int r = 0; r < size; r++)
            for (int i = 0; i < size; i++)
                for (int j = 0; j < size; j++) {
                    data[i][j] += (1LL * a[i][r] * b[r][j]) % base;
                    if (data[i][j] >= base)
                        data[i][j] -= base;
                }
    }

    void pow(ll s) {
        Matrix a(size);
        a.data = data;

        data = zero;
        while (s) {
            if (s & 1)
                mult(a);
            a.mult(a);
            s >>= 1LL;
        }
    }
};

int main() {
    Matrix fib(2);
    fib.set({1, 1,
             1, 0});

    //files1;
    ll n, k;
    int l;
    cin >> n >> k >> l >> base;

    if (l != 64 && k >= (1ULL << (ll)l))
        bad("0");

    fib.pow(n + 1LL);

    int F = fib[0][0];
    int bN = binpow<ll>(2LL, n);

    int one = (bN - F + base) % base;
    int zero = F;

    int res = 1 % base;
    for (int i = 0; i < l; i++)
        if (k & (1LL << (ll)i))
            res = (1LL * res * one) % base;
        else
            res = (1LL * res * zero) % base;
    cout << res;
    return 0;
}