// hloya template v20

// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 

#include <bits/stdc++.h>
#include <valarray>
using namespace std;

bool dbg = 0;

clock_t start_time = clock();
#define current_time fixed<<setprecision(6)<<(ld)(clock()-start_time)/CLOCKS_PER_SEC

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

template<typename T> void read(T& a) { a = input<T>(); }
template<typename T> void read(T& a, T& b) { read(a), read(b); }
template<typename T> void read(T& a, T& b, T& c) { read(a, b), read(c); }
template<typename T> void read(T& a, T& b, T& c, T& d) { read(a, b), read(c, d); }

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
const long double eps = 1e-12;
const int maxn = 5e3 + 10, base = 1e9 + 7;
const ll llinf = 4e18 + 5;

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

char g[5001][5001];
char used[5001];
int n;
vector<int> st;

void print(vector<int>& a) {
    for (int i:a)
        printf("%d ", i + 1);
    exit(0);
}

void ans(int v) {
    reverse(all(st));
    while (st.back() != v)
        st.pop_back();
    reverse(all(st));

    while (st.size() != 3) {
        int v = st[0], u = st[2];
        if (g[v][u]) {
            st.erase(st.begin() + 1);
        } else {
            while (st.size() != 3)
                st.pop_back();
        }
    }

    print(st);
}

void dfs(int v) {
    st.pb(v);
    used[v] = 2;
    for (int i = 0; i < n; i++)
        if (g[v][i]) {
            if (used[i] == 2) {
                ans(i);
            }
            if (used[i] == 0) {
                dfs(i);
            }
        }
    st.pop_back();
    used[v] = 1;
}

int main() {
    read(n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            char c = endl;
            while (c == endl)
                c = getchar();
            g[i][j] = c - '0';
        }
    for (int i = 0; i < n; i++) {
        if (!used[i])
            dfs(i);
    }
    bad("-1");
    return 0;
}