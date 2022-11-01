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
const int maxn = 1e6 + 10, base = 1e9 + 7;
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

vector<int> s[maxn];
int l[maxn];

int whenstacked(int x, int c) {
    return c - x + 1;
}

int f[maxn];
void addRange(int l, int r) {
    f[l]++;
    f[r + 1]--;
}

int main() {
    //files1;
    int n, c;
    read(n, c);

    for (int i = 0; i < n; i++) {
        read(l[i]);
        s[i].resize(l[i]);

        for (int j = 0; j < l[i]; j++) {
            read(s[i][j]);
        }
    }

    for (int i = 0; i + 1 < n; i++) {
        int pos = 0;
        while (pos < s[i].size() && pos < s[i + 1].size() && 
              s[i][pos] == s[i + 1][pos])
            pos++;
        if (pos == s[i].size()) {
            addRange(0, c - 1);
            continue;
        }   
        if (pos == s[i + 1].size())
            bad("-1");

        int t1 = whenstacked(s[i][pos], c);
        int t2 = whenstacked(s[i + 1][pos], c);

        if (s[i][pos] < s[i + 1][pos]) {
            addRange(0, t2 - 1);
            
            if (t1 <= c - 1)
            addRange(t1, c - 1);
        } else {
            addRange(t1, t2 - 1);
        }
    }

    for (int i = 0; i < c; i++) {
        if (i)
            f[i] += f[i - 1];
        if (f[i] == n - 1) {
            cout << i;
            exit(0);
        }
    }
    cout << -1;
    return 0;
}