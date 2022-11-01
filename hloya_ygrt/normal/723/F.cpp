#include <bits/stdc++.h>
#include <valarray>

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
 
const int inf = 2e9;
const double eps = 1e-9;
const int maxn = 4e5 + 10, base = 1073676287;
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

#define rank sadsasad
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
 
bool union_sets (int a, int b) {
    a = find_set (a);
    b = find_set (b);
    if (a != b) {
        if (rank[a] < rank[b])
            swap (a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            ++rank[a];
        return true;
    }
    return false;
}

vector<pair<int, int> > e, ans;
bool have_edge[maxn][2];

int main() {
    int n, m;
    read(n, m);

    for (int i = 0; i < n; i++)
        make_set(i);

    for (int i = 0; i < m; i++) {
        int f, t;
        read(f, t);
        t--, f--;
        e.pb({f, t});
    }

    int s, t, mx_s, mx_t;
    read(s, t, mx_s, mx_t);
    s--, t--;

    for (auto E:e) {
        if (E.f!=s&&E.f!=t&&E.s!=s&&E.s!=t&&union_sets(E.f, E.s))
            ans.pb(E);
    }

    for (auto E:e) {
        if ((E.f==s&&E.s==t)||(E.f==t&&E.s==s))
            continue;
        if (E.f == s) have_edge[find_set(E.s)][0]=1;
        if (E.s == s) have_edge[find_set(E.f)][0]=1;
        if (E.f == t) have_edge[find_set(E.s)][1]=1;
        if (E.s == t) have_edge[find_set(E.f)][1]=1;
    }

    if (find_set(s) != find_set(t)) {
        for (int i = 0; i < n; i++)
            if (have_edge[i][0] && have_edge[i][1]) {
                for (auto E:e)
                    if ((find_set(E.f)==i&&E.s==s) || (find_set(E.s)==i&&E.f==s)) {
                        ans.pb(E);
                        break;
                    }
                for (auto E:e)
                    if ((find_set(E.f)==i&&E.s==t) || (find_set(E.s)==i&&E.f==t)) {
                        ans.pb(E);
                        break;
                    }              
                mx_s--;
                mx_t--;
                union_sets(i, s);
                union_sets(i, t);
                break;
            }
    }
    
    if (find_set(s) != find_set(t)) {
        ans.pb({s, t});
        mx_t--;
        mx_s--;
        union_sets(t, s);
    }

    for (auto E:e)
        if (find_set(E.f) != find_set(E.s)) {
            int cmp = find_set(E.f) == find_set(s) ? find_set(E.s) : find_set(E.f);
            if (have_edge[cmp][0] ^ have_edge[cmp][1]) {
                ans.pb(E);
                if (have_edge[cmp][0]) mx_s--;
                else                   mx_t--;
                union_sets(E.f, E.s);
            }
        }

    for (auto E:e)
        if (find_set(E.f) != find_set(E.s)) {
            int cmp = find_set(E.f) == find_set(s) ? find_set(E.s) : find_set(E.f);
            int tp = E.f == t || E.s == t;

            if (have_edge[cmp][0] && have_edge[cmp][1]) {
                if ((tp == 0 && mx_s > 0) || (tp == 1 && mx_t > 0)) {
                    ans.pb(E);
                    if (tp) mx_t--;
                    else    mx_s--;
                    union_sets(E.f, E.s);
                }
            }
        }

    for (int i = 0; i < n; i++)
        if (find_set(i) != find_set(s)) {
            puts("No");
            exit(0);
        }
    if (mx_s >= 0 && mx_t >= 0) {
        puts("Yes");
        for (auto e:ans)
            cout << e.f + 1 << ' ' << e.s + 1 << endl;
    } else puts("No");
    return 0;
}