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

const int inf = 1e9;
const double eps = 1e-9;
const int maxn = 2e3 + 15, base = 1e9 + 7;
const ll llinf = 1e18 + 1;

template<typename T>
T binpow(T n, T s)
{
    if (s <= 0)
        return 1LL;
    if (s % 2 == 0) {
        T b = binpow(n, s / 2);
        return ( 1LL * b * b ) % base;
    } else {
        return (1LL * binpow(n, s - 1) * n) % base;
    }
}

vector<pair<pii, int> > inSnake[maxn];

bool isOn[maxn];

vector<pair<pair<pii, pii>, int> > Query[maxn];

ll tree[maxn * maxn];
int n, m;

void add(int x, int y, int c) {
    x++, y++;
    for (int i = x; i <= n; i += i & (-i))
        for (int j = y; j <= m; j += j & (-j)) {
            tree[i * m + j] += c;
        }
}

ll sum(int x, int y) {
    x++, y++;
    ll res = 0;
    for (int i = x; i > 0; i -= i & (-i))
        for (int j = y; j > 0; j -= j & (-j)) {
            res += tree[i * m + j];
        }
    return res;
}

void buildTree(int snake, int type) {
    for (auto i:inSnake[snake]) {
        int x = i.first.first, y = i.first.second;
        int c = i.second * type;
        add(x, y, c);
    }
}

ll result[maxn];

int main() {
    int k;
    read(n, m, k);

    for (int i = 0; i < k; i++) {
        isOn[i] = 1;

        int len;
        read(len);
        inSnake[i].resize(len);

        for (int j = 0; j < len; j++) {
            int x, y, c;
            read(x, y, c);
            x--, y--;

            inSnake[i][j] = mp(mp(x, y), c);
        }
    }

    int q, cnt = 0;
    read(q);
    for (int i = 0; i < q; i++) {
        char c = endl;
        while (c == endl)
            c = getchar();
        
        if (c == 'A') {
            int x1, y1, x2, y2;
            read(x1, y1, x2, y2);
            dec(x1, y1, x2, y2);

            for (int j = 0; j < k; j++)
                if (isOn[j])
                    Query[j].pb({ { {x1, y1}, {x2, y2} }, cnt});
            cnt++;
        } else {
            isOn[input<int>() - 1] ^= 1;
        }
    }

    for (int s = 0; s < k; s++) {
        buildTree(s, +1);

        for (auto q:Query[s]) {
            int x1 = q.f.f.f, y1 = q.f.f.s, x2 = q.f.s.f, y2 = q.f.s.s; // BLOOO
            int curTime = q.second;

            result[curTime] += sum(x2, y2) - sum(x2, y1 - 1) - sum(x1 - 1, y2)
                              + sum(x1 - 1, y1 - 1);
        }

        buildTree(s, -1);
    }

    for (int i = 0; i < cnt; i++)
        printf("%I64d\n", result[i]);
    return 0;
}