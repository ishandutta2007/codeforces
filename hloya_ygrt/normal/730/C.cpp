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

void reads(string & s) {
    string ans = "";
    char c = endl;
    while (c == endl || c == ' ')
        c = getchar();
    while (c != endl && c != ' ' && c)
        ans += c, c = getchar();
    s = ans;
}

const int inf = 1e9;
const double eps = 1e-9;
const int maxn = 5e3 + 10, base = 1e9 + 7;
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

vector<pair<int, pii> > stores;

vector<int> g[maxn];

int n, m;
int dist[maxn];
queue<int> q;

void bfs(int start) {
    for (int i = 0; i < n; i++)
        dist[i] = inf;
    dist[start] = 0;
    q.push(start);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int to:g[v])
            if (dist[to] == inf) {
                dist[to] = dist[v] + 1;
                q.push(to);
            }
    }
}

int main() {
    read(n, m);

    for (int i = 0; i < m; i++) {
        int f, t;
        read(f, t);
        f--, t--;

        g[f].pb(t);
        g[t].pb(f);
    }

    int w;
    read(w);

    for (int i = 0; i < w; i++) {
        int v, k, p;
        read(v, k, p);
        v--;
        stores.pb(mp(p, mp(v, k)));
    }
    
    sort(all(stores));

    int q;
    read(q);

    while (q--) {
        ll v, need, a;
        read(v, need, a);
        v--;
        bfs(v);

        // int l = 1, r = 3;
        int l = -1, r = maxn;
        while (r - l > 1) {
            int c = (l + r) >> 1;
            ll cur = 0, curCost = 0;

            for (auto e:stores) {
                ll v = e.s.f;
                ll cost = e.f, cnt = e.s.s;
                ll curTime = dist[v];

                if (curTime > c)
                    continue;

                ll to_insert = min(cnt, need - cur);
                cur += to_insert;
                curCost += to_insert * cost;

            }

            // return 0;

            if (curCost <= a && cur == need)
                r = c;
            else
                l = c;
        }

        ll ans;
        if (r == maxn)
            ans = -1;
        else
            ans = r;
        printf("%lld\n", ans);
    }
    return 0;
}