#include <bits/stdc++.h>
#include <valarray>
using namespace std;
 

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
 
void bad(string mes = "Impossible"){cout << mes;exit(0);}
// template<typename ... T> void shit(T& ... x){}
// template<typename ... T> void dec(T& ... x){shit(--x...);}
// template<typename ... T> void inc(T& ... x){shit(++x...);}
 
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
const int maxn = 1e5 + 10, base = 1e9 + 7;
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

map<int, set<pair<int, int> > > mn, pl;

int XX[maxn], YY[maxn];

set<pair<int, int> > used;
ll ans[maxn];

bool is_angle(int x, int y, int n, int m) {
    return (x == 0 && y == 0) || (x == 0 && y == m) || (x == n && y == 0) || (x == n && y == m);
}

int k;
void print() {
    for (int i = 0; i < k; i++) {
        printf("%lld\n", ans[i]);
    }
    exit(0);
}

int main() {
    int n, m;
    read(n, m, k);

    for (int i = 0; i < k; i++) {
        read(XX[i], YY[i]);
        ans[i] = -1;
    }

    if (m > n) {
        swap(n, m);
        for (int i = 0; i < k; i++)
            swap(XX[i], YY[i]);
    }

    for (int i = 0; i < k; i++) {
        mn[XX[i] - YY[i]].insert(mp(XX[i], i));
        pl[XX[i] + YY[i]].insert(mp(XX[i], i));
    }

    ll curTime = 0;
    int x = 0, y = 0;

    int to_the_right = 1, to_the_bot = 1;

    while (1) {
        if (used.count(mp(x, y)))
            print();
        used.insert(mp(x, y));
        int oldX = x;

        if (to_the_right) {
                if (to_the_bot) {
                    // x - y
                    
                    while (!mn[x - y].empty()) {
                        auto e = mn[x - y].begin();

                        int __x = (*e).first;
                        int pos = (*e).second;
                        ans[pos] = (ll)__x - x + curTime;

                        mn[x - y].erase(e);
                        pl[XX[pos] + YY[pos]].erase(mp(XX[pos], pos));
                    }

                    int delta = min(n - x, m - y);
                    x += delta;
                    y += delta;

                    if (y == m)
                        to_the_bot = 0;
                    if (x == n)
                        to_the_right = 0;
                } else {
                    // x + y;
                    while (!pl[x + y].empty()) {
                        auto e = pl[x + y].begin();

                        int __x = (*e).first;
                        int pos = (*e).second;
                        ans[pos] = (ll)__x - x + curTime;

                        pl[x + y].erase(e);
                        mn[XX[pos] - YY[pos]].erase(mp(XX[pos], pos));
                    }

                    int delta = min(n - x, y);
                    x += delta;
                    y -= delta;

                    if (y == 0)
                        to_the_bot = 1;
                    if (x == n)
                        to_the_right = 0;
                }
        } else {
            if (to_the_bot) {
                // x + y                    
             
                while (!pl[x + y].empty()) {
                    auto e = pl[x + y].begin();

                    int __x = (*e).first;
                    int pos = (*e).second;
                    ans[pos] = (ll)x - __x + curTime;

                    pl[x + y].erase(e);
                    mn[XX[pos] - YY[pos]].erase(mp(XX[pos], pos));
                }

                int delta = min(x, m - y);
                x -= delta;
                y += delta;

                if (y == m)
                    to_the_bot = 0;
                if (x == 0)
                    to_the_right = 1;
            } else {
                while (!mn[x - y].empty()) {
                    auto e = mn[x - y].begin();

                    int __x = (*e).first;
                    int pos = (*e).second;
                    ans[pos] = (ll)x - __x + curTime;

                    mn[x - y].erase(e);
                    pl[XX[pos] + YY[pos]].erase(mp(XX[pos], pos));
                }

                int delta = min(x, y);
                x -= delta;
                y -= delta;

                if (y == 0)
                    to_the_bot = 1;
                if (x == 0)
                    to_the_right = 1;
            }
        }

        curTime += abs(x - oldX);
        if (is_angle(x, y, n, m))
            print();
    }
    return 0;
}