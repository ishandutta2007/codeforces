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
    while (c != endl && c != ' ' && c != '\0')
        ans += c, c = getchar();
    s = ans;
}

const int inf = 1e9;
const double eps = 1e-9;
const int maxn = 3e3 + 10, base = 1e9 + 7;
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

bool used[30];

int main() {
    //files1;
    int k = input<int>();
    string s;
    reads(s);
    int n = s.size();

    for (int i = 0, j = n - 1; i <= j; i++, j--) {
        if (s[i] != '?' && s[j] != '?' && s[i] != s[j])
            bad("IMPOSSIBLE");
        if (s[i] == '?' && s[j] != '?')
            s[i] = s[j];
        if (s[i] != '?' && s[j] == '?')
            s[j] = s[i];
        if (s[i] != '?' && s[j] != '?')
            used[s[i] - 'a'] = 1;
    }

    for (int i = (n - 1)/2, j = n/2; i >= 0; i--, j++) {
        if (s[i] == '?' && s[j] == '?') {
            int cur = 0;
            for (int h = k - 1; h >= 0; h--)
                if (!used[h]) {
                    cur = h;
                    break;
                }
            used[cur] = 1;
            s[i] = s[j] = cur + 'a';
        }
    }
    for (int i = 0; i < k; i++)
        if (!used[i])
            bad("IMPOSSIBLE");
    cout << s;
    return 0;
}