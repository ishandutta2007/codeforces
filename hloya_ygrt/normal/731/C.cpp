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
const int maxn = 2e5 + 10, base = 1e9 + 7;
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

#define rank safklfsa
int parent[maxn], rank[maxn];

void make_set (int v) {
    parent[v] = v;
    rank[v] = 0;
}
 
int find_set (int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set (parent[v]);
}
 
void union_sets (int a, int b) {
    a = find_set (a);
    b = find_set (b);
    if (a != b) {
        if (rank[a] < rank[b])
            swap (a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            ++rank[a];
    }
}

int c[maxn];

map<int, int> cnt[maxn];
int mxCnt[maxn], sz[maxn];

int main() {
    //files1;
    int n, m, k;
    read(n, m, k);

    for (int i = 0; i < n; i++) {
        read(c[i]);
        make_set(i);
    }

    for (int i = 0; i < m; i++) {
        int l, r;
        read(l, r);
        l--, r--;
        union_sets(l, r);
    }

    for (int i = 0; i < n; i++) {
        int curclr = c[i];
        int curset = find_set(i);

        sz[curset]++;
        cnt[curset][curclr]++;

        if (cnt[curset][curclr] > mxCnt[curset])
            mxCnt[curset] = cnt[curset][curclr];
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += sz[i] - mxCnt[i];
    }
    cout << ans;
    return 0;
}