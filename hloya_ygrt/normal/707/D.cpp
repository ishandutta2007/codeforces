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
const int maxn = 1e5 + 5, base = 1e9 + 7;
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

struct Query
{
    int i, j, type, val;

    Query(){}
    Query(int type):type(type){}
    Query(int type, int i):type(type), i(i){}
    Query(int type, int i, int j, int val):type(type), i(i), j(j), val(val){}
};

vector<int> g[maxn];
Query query[maxn];

vector<int> matrix[(int)1e3 + 5][(int)1e3 + 5];
int flags[(int)1e3 + 5];
int accum[(int)1e3 + 5];

int res[maxn];

int n, m;

void dfs(int v, int sum) {
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++)
    //         cerr << matrix[i][j].back() << ' ';
    //     cerr << endl;
    // }
    // cerr << endl << "---" << endl;
    
    res[v] = sum;
    for (int to:g[v]) {
        int newSum = sum;

        if (query[to].type == 1) {
            int i = query[to].i, j = query[to].j;
            if ((matrix[i][j].back() ^ flags[i]) == 0) {
                newSum++;
                accum[i]++;
            }

            matrix[i][j].pb(1 ^ flags[i]); // check
            
            dfs(to, newSum);

            matrix[i][j].pop_back();
            if ((matrix[i][j].back() ^ flags[i]) == 0) {
                newSum--;
                accum[i]--;
            }
        }

        if (query[to].type == 2) {
            int i = query[to].i, j = query[to].j;

            if ((matrix[i][j].back() ^ flags[i]) == 1) {
                newSum--;
                accum[i]--;
            }

            matrix[i][j].pb(0 ^ flags[i]); // check
            
            dfs(to, newSum);

            matrix[i][j].pop_back();
            if ((matrix[i][j].back() ^ flags[i]) == 1) {
                newSum++;
                accum[i]++;
            }
        }

        if (query[to].type == 3) {
            int i = query[to].i;

            newSum -= accum[i];
            accum[i] = m - accum[i];
            newSum += accum[i];

            flags[i] ^= 1;

            dfs(to, newSum);

            flags[i] ^= 1;

            newSum -= accum[i];
            accum[i] = m - accum[i];
            newSum += accum[i];
        }

        if (query[to].type == 4) {
            dfs(to, newSum);
        }
    }
}

int main() {
    int q;
    read(n, m, q);

    int curQuery = 0;

    for (int h = 1; h <= q; h++) {
        int type;
        read(type);

        if (type == 1) {
            int i, j;
            read(i, j);

            query[h] = Query(type, i - 1, j - 1, 1);
            g[curQuery].push_back(h);
        }

        if (type == 2) {
            int i, j;
            read(i, j);

            query[h] = Query(type, i - 1, j - 1, 0);
            g[curQuery].push_back(h);
        }

        if (type == 3) {
            int i;
            read(i);

            query[h] = Query(type, i - 1);
            g[curQuery].push_back(h);
        }    

        if (type == 4) {
            int k;
            read(k);

            query[h] = Query(type);
            g[k].push_back(h);
        }

        curQuery = h;
    }

    for (int i = 0; i < n; i++) {
        flags[i] = 0;
        for (int j = 0; j < m; j++) {
            matrix[i][j].pb(0);
        }
    }

    dfs(0, 0);

    for (int i = 1; i <= q; i++)
        cout << res[i] << endl;
    return 0;
}