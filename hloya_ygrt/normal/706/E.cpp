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
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

#define ll long long
#define ld long double
#define pii pair<int,int>

#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define files files1;files2
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0)

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
const int maxn = 2e3 + 5, base = 1e9 + 7;
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

struct node
{
    node * l, * r, * u, * d;
    int x, y;
    node(){}
    node(int x, int y):x(x), y(y) {
        l = 0, r = 0, u = 0, d = 0;
    }
};

node * to_build[maxn][maxn];
int a[maxn][maxn];

void move(node * & a, int x, int y) {
    if (x >= 0)
        while (x--)
            a = a -> d;
    else
        while (x++)
            a = a -> u;

    if (y >= 0)
        while (y--)
            a = a -> r;
    else
        while (y++)
            a = a -> l;
}

void print(int n, int m) {
    node * pos = to_build[0][0];
    while (pos -> l != 0)
        pos = pos -> l;
    while (pos -> u != 0)
        pos = pos -> u;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", a[pos -> x][pos -> y]);
            if (j != m - 1)
                move(pos, 0, 1);
        }
        puts("");
        move(pos, 0, -(m - 1));
        if (i != n - 1)
            move(pos, 1, 0);
    }
}

int main() {
    //files1;
    int n, m, q;
    read(n, m, q);

    for (int i = 0; i < n; i++) // make list
        for (int j = 0; j < m; j++) {
            read(a[i][j]);
            to_build[i][j] = new node(i, j);
        }

    for (int i = 0; i < n; i++) // fix
        for (int j = 0; j < m; j++) {
            if (i)
                to_build[i][j] -> u = to_build[i - 1][j];
            if (j)
                to_build[i][j] -> l = to_build[i][j - 1];
            if (i != n - 1)
                to_build[i][j] -> d = to_build[i + 1][j];
            if (j != m - 1)
                to_build[i][j] -> r = to_build[i][j + 1];
        }

    while (q--) {
        int x1, y1, x2, y2, h, w;
        
        read(x1, y1, x2, y2);
        read(h, w);

        dec(x1, y1, x2, y2);

        node * f = to_build[0][0];
        while (f -> l != 0)
            f = f -> l;
        while (f -> u != 0)
            f = f -> u;

        node * s = f;
        
        move(f, x1, y1);
        move(s, x2, y2);    

        // going down and swapping left
        for (int i = 0; i < h; i++) {
            // cout << f -> x << ' ' << f -> y << endl;
            // cout << s -> x << ' ' << s -> y << endl << endl;
            
            node * fl = f -> l;
            node * sl = s -> l;

            if (fl)
            fl -> r = s;

            if (sl)
            sl -> r = f;

            f -> l = sl;
            s -> l = fl;
            
            if (i != h - 1) {
                move(f, 1, 0);
                move(s, 1, 0);
            }
        }

        // going right and swapping down
        for (int i = 0; i < w; i++) {

            // cout << f -> x << ' ' << f -> y << endl;
            // cout << s -> x << ' ' << s -> y << endl << endl;
            node * fd = f -> d;
            node * sd = s -> d;

            if (fd)
            fd -> u = s;

            if (sd)
            sd -> u = f;

            f -> d = sd;
            s -> d = fd;
            
            if (i != w - 1) {
                move(f, 0, 1);
                move(s, 0, 1);
            }
        }

        // going up and swapping right
        for (int i = 0; i < h; i++) {
            // cout << f -> x << ' ' << f -> y << endl;
            // cout << s -> x << ' ' << s -> y << endl << endl;

            node * fr = f -> r;
            node * sr = s -> r;

            if (fr)
            fr -> l = s;

            if (sr)
            sr -> l = f;

            f -> r = sr;
            s -> r = fr;

            if (i != h - 1) {
                move(f, -1, 0);
                move(s, -1, 0);
            }
        }

        //going left and swapping up
        for (int i = 0; i < w; i++) {
            // cout << f -> x << ' ' << f -> y << endl;
            // cout << s -> x << ' ' << s -> y << endl << endl;
        
            node * fu = f -> u;
            node * su = s -> u;

            if (fu)
            fu -> d = s;

            if (su)
            su -> d = f;

            f -> u = su;
            s -> u = fu;
            
            if (i != w - 1) {
                move(f, 0, -1);
                move(s, 0, -1);
            }
        }
        // print(n, m);
        // return 0;
    }

    print(n, m);
    return 0;
}