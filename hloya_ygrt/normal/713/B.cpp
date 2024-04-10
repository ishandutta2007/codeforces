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

const int inf = 1e9;
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

// int ans1[4], ans2[4];

// int query(int x1, int y1, int x2, int y2) {
//     int a = (x1 <= ans1[0] && y1 <= ans1[1] && x2 >= ans1[2] && y2 >= ans1[3]);
//     int b = (x1 <= ans2[0] && y1 <= ans2[1] && x2 >= ans2[2] && y2 >= ans2[3]);
//     return a + b;
// }
// int kek_query(int y1, int x1, int y2, int x2) {
//     int a = (x1 <= ans1[0] && y1 <= ans1[1] && x2 >= ans1[2] && y2 >= ans1[3]);
//     int b = (x1 <= ans2[0] && y1 <= ans2[1] && x2 >= ans2[2] && y2 >= ans2[3]);
//     return a + b;
// }

// set<pair<pii, pii> > used;

int query(int x1, int y1, int x2, int y2) {
    cout << "? " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
    cout.flush();
    int x;
    cin >> x;
    return x;
}

int kek_query(int y1, int x1, int y2, int x2) {
    cout << "? " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
    cout.flush();
    int x;
    cin >> x;
    return x;
}

int res1[4], res2[4];

int main() {
    int n;
    cin >> n;

    int l = 1, r = n;
    // cout << "143\n";
    while (r - l > 1) {
        int m = (l + r) >> 1;
        if (query(1, 1, m, n) >= 1)
            r = m;
        else
            l = m;
    }

    if (query(1, 1, l, n) >= 1)
        r = l;

    int ans1_r = r; //   - 
    int f1 = query(1, 1, ans1_r, n);

    // cout << "157\n";
        l = 1, r = n;
    while (r - l > 1) {
        int m = (l + r) >> 1;
        if (query(m, 1, n, n) >= 1)
            l = m;
        else
            r = m;
    }

    if (query(r, 1, n, n) >= 1)
        l = r;

    int ans1_l = l; //   - 
    int f2 = query(ans1_l, 1, n, n);

    // cout << ans1_l << ' ' << ans1_r << ' ' << f1 << ' ' << f2 << endl;
    // exit(0);
    // 1
    if (f1 == 1 && f2 == 1) {
        //    ans1_l .. ans1_r - 
        bool found1 = 1;
        if (ans1_l <= ans1_r)
            found1 = query(ans1_l, 1, ans1_r, n);
        else
            found1 = 0;

        if (found1) {
            res1[0] = ans1_l;
            res1[2] = ans1_r;

            int l = 1, r = n;
            while (r - l > 1) {
                int m = (l + r) >> 1;
                if (query(1, 1, m, n) >= 2)
                    r = m;
                else
                    l = m;
            }

            if (query(1, 1, l, n) >= 2)
                r = l;

            res2[2] = r;

            l = 1, r = n;
            while (r - l > 1) {
                int m = (l + r) >> 1;
                if (query(m, 1, n, n) >= 2)
                    l = m;
                else
                    r = m;
            }

            if (query(r, 1, n, n) >= 2)
                l = r;

            res2[0] = l;
        } else {
            //    ans1_r
            int l = 1, r = ans1_r;
            while (r - l > 1) {
                int m = (l + r) >> 1;
                if (query(m, 1, ans1_r, n) >= 1)
                    l = m;
                else
                    r = m;
            }

            if (query(r, 1, ans1_r, n) >= 1)
                l = r;

            res1[0] = l;
            res1[2] = ans1_r;

            //    ans1_l
                l = ans1_l, r = n;
            while (r - l > 1) {
                int m = (l + r) >> 1;
                if (query(ans1_l, 1, m, n) >= 1)
                    r = m;
                else
                    l = m;
            }

            if (query(ans1_l, 1, l, n) >= 1)
                r = l;

            res2[0] = ans1_l;
            res2[2] = r;
        }
    }

    if (f2 == 2 && f1 == 1) {
        res1[0] = ans1_l;
        res2[0] = ans1_l;

        //    1
        int l = ans1_l, r = n;
        while (r - l > 1) {
            int m = (l + r) >> 1;
            if (query(ans1_l, 1, m, n) >= 1)
                r = m;
            else
                l = m;
        }

        if (query(ans1_l, 1, l, n) >= 1)
            r = l;
        res1[2] = r;

            l = ans1_l, r = n;
        while (r - l > 1) {
            int m = (l + r) >> 1;
            if (query(ans1_l, 1, m, n) >= 2)
                r = m;
            else
                l = m;
        }

        if (query(ans1_l, 1, l, n) >= 2)
            r = l;
        res2[2] = r;
    }

    if (f1 == 2 && f2 == 1) {
        res1[2] = ans1_r;
        res2[2] = ans1_r;

        //    1
        int l = 1, r = ans1_r;
        while (r - l > 1) {
            int m = (l + r) >> 1;
            if (query(m, 1, ans1_r, n) >= 1)
                l = m;
            else
                r = m;
        }

        if (query(r, 1, ans1_r, n) >= 1)
            l = r;
        res1[0] = l;

            l = 1, r = ans1_r;
        while (r - l > 1) {
            int m = (l + r) >> 1;
            if (query(m, 1, ans1_r, n) >= 2)
                l = m;
            else
                r = m;
        }

        if (query(r, 1, ans1_r, n) >= 2)
            l = r;
        res2[0] = l;
    }

    if (f2 == 2 && f1 == 2) {
        res1[0] = res2[0] = ans1_l;
        res1[2] = res2[2] = ans1_r;
    }



    /// ////////////////////////////
    //
    //
    //

    //




      l = 1, r = n;
    while (r - l > 1) {
        int m = (l + r) >> 1;
        if (kek_query(1, 1, m, n) >= 1)
            r = m;
        else
            l = m;
    }

    if (kek_query(1, 1, l, n) >= 1)
        r = l;

     ans1_r = r; //   - 
     f1 = kek_query(1, 1, ans1_r, n);

        l = 1, r = n;
    while (r - l > 1) {
        int m = (l + r) >> 1;
        if (kek_query(m, 1, n, n) >= 1)
            l = m;
        else
            r = m;
    }

    if (kek_query(r, 1, n, n) >= 1)
        l = r;

     ans1_l = l; //   - 
     f2 = kek_query(ans1_l, 1, n, n);


    // 1
    if (f1 == 1 && f2 == 1) {
        //    ans1_l .. ans1_r - 
        bool found1 = 1;
        if (ans1_l <= ans1_r)
            found1 = kek_query(ans1_l, 1, ans1_r, n);
        else
            found1 = 0;

        if (found1) {
            res1[1] = ans1_l;
            res1[3] = ans1_r;

            int l = 1, r = n;
            while (r - l > 1) {
                int m = (l + r) >> 1;
                if (kek_query(1, 1, m, n) >= 2)
                    r = m;
                else
                    l = m;
            }

            if (kek_query(1, 1, l, n) >= 2)
                r = l;

            res2[3] = r;

            l = 1, r = n;
            while (r - l > 1) {
                int m = (l + r) >> 1;
                if (kek_query(m, 1, n, n) >= 2)
                    l = m;
                else
                    r = m;
            }

            if (kek_query(r, 1, n, n) >= 2)
                l = r;

            res2[1] = l;
        } else {
            //    ans1_r
            int l = 1, r = ans1_r;
            while (r - l > 1) {
                int m = (l + r) >> 1;
                if (kek_query(m, 1, ans1_r, n) >= 1)
                    l = m;
                else
                    r = m;
            }

            if (kek_query(r, 1, ans1_r, n) >= 1)
                l = r;

            res1[1] = l;
            res1[3] = ans1_r;

            //    ans1_l
                l = ans1_l, r = n;
            while (r - l > 1) {
                int m = (l + r) >> 1;
                if (kek_query(ans1_l, 1, m, n) >= 1)
                    r = m;
                else
                    l = m;
            }

            if (kek_query(ans1_l, 1, l, n) >= 1)
                r = l;

            res2[1] = ans1_l;
            res2[3] = r;

        }
    }

    if (f2 == 2 && f1 == 1) {
        res1[1] = ans1_l;
        res2[1] = ans1_l;

        //    1
        int l = ans1_l, r = n;
        while (r - l > 1) {
            int m = (l + r) >> 1;
            if (kek_query(ans1_l, 1, m, n) >= 1)
                r = m;
            else
                l = m;
        }

        if (kek_query(ans1_l, 1, l, n) >= 1)
            r = l;
        res1[3] = r;

            l = ans1_l, r = n;
        while (r - l > 1) {
            int m = (l + r) >> 1;
            if (kek_query(ans1_l, 1, m, n) >= 2)
                r = m;
            else
                l = m;
        }

        if (kek_query(ans1_l, 1, l, n) >= 2)
            r = l;
        res2[3] = r;
    }

    if (f1 == 2 && f2 == 1) {
        res1[3] = ans1_r;
        res2[3] = ans1_r;

        //    1
        int l = 1, r = ans1_r;
        while (r - l > 1) {
            int m = (l + r) >> 1;
            if (kek_query(m, 1, ans1_r, n) >= 1)
                l = m;
            else
                r = m;
        }

        if (kek_query(r, 1, ans1_r, n) >= 1)
            l = r;
        res1[1] = l;

            l = 1, r = ans1_r;
        while (r - l > 1) {
            int m = (l + r) >> 1;
            if (kek_query(m, 1, ans1_r, n) >= 2)
                l = m;
            else
                r = m;
        }

        if (kek_query(r, 1, ans1_r, n) >= 2)
            l = r;
        res2[1] = l;
    }

    if (f2 == 2 && f1 == 2) {
        res1[1] = res2[1] = ans1_l;
        res1[3] = res2[3] = ans1_r;
    }

    if (query(res1[0], res1[1], res1[2], res1[3]) == 0)
        swap(res1[1], res2[1]), swap(res1[3], res2[3]);

    cout << "! ";
    cout << res1[0] << ' ' << res1[1] << ' ' << res1[2] << ' ' << res1[3] << ' ';
    cout << res2[0] << ' ' << res2[1] << ' ' << res2[2] << ' ' << res2[3] << endl;
    cout.flush();
    return 0;
}