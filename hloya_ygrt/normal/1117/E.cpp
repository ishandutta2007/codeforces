#include <bits/stdc++.h>
using namespace std;
  
bool dbg = 0;
  
clock_t start_time = clock();
#define current_time fixed<<setprecision(6)<<(ld)(clock()-start_time)/CLOCKS_PER_SEC
  
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
  
#define ll long long int
#define ld long double
#define pii pair<int,int>
  
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define files files1;files2
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0)
  
#define endl '\n'
#define ln(i,n) " \n"[(i) == (n) - 1]
  
void bad(string mes = "Impossible"){cout << mes;exit(0);}
void bad(int mes){cout << mes;exit(0);}
  
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
bool upmax(T& x, T y) {
    if (x < y) {
        x = y;
        return true;
    }
    return false;
}
  
template<typename T>
bool upmin(T& x, T y) {
    if (x > y) {
        x = y;
        return true;
    }
    return false;
}

inline int popcount(int x){
    int count = 0;
    __asm__ volatile("POPCNT %1, %0;":"=r"(count):"r"(x):);
    return count;
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

ll gcd (ll a, ll b) { while (b) { a %= b; swap (a, b); } return a; }
  
template<typename T> void read(T& a) { a = input<T>(); }
template<typename T> void read(T& a, T& b) { read(a), read(b); }
template<typename T> void read(T& a, T& b, T& c) { read(a, b), read(c); }
template<typename T> void read(T& a, T& b, T& c, T& d) { read(a, b), read(c, d); }
  
const int inf = 1e9 + 20;
const short short_inf = 3e4 + 20;
const long double eps = 1e-12;
const int maxn = (int)1e5 + 100, base = 1e9 + 7;
const ll llinf = 2e18 + 5;
  
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

int l[maxn], r[maxn];
vector<int> positions[26];
int blocksize[3];

#define index fskasf

int index[maxn][3];
int f[maxn];

void solve(int n) {
    string t;
    blocksize[0] = (n + 25) / 26;
    for (int i = 1; i < 3; i++)
        blocksize[i] = (blocksize[i - 1] + 25) / 26;

    for (int i = 0; i < n; i++)
        index[i][0] = i / blocksize[0];

    int lastb = -1, lastpos = -1;
    for (int i = 0; i < n; i++) {
        if (index[i][0] != lastb) {
            lastb = index[i][0];
            lastpos = i;
        }
        int len = i - lastpos;
        index[i][1] = len / blocksize[1];
    }

    lastb = -1;
    int lastb2 = -1;
    lastpos = -1;

    for (int i = 0; i < n; i++) {
        if (index[i][0] != lastb || index[i][1] != lastb2) {
            lastb = index[i][0];
            lastb2 = index[i][1];
            lastpos = i;
        }
        int len = i - lastpos;
        index[i][2] = len / blocksize[2];
    }

    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < 26; i++)
            positions[i].clear();

        int prev_block = -1;
        int prev_start;

        t.clear();

        for (int i = 0; i < n; i++) {
            int cur = index[i][j];

            positions[cur].pb(i);

            char c = 'a' + cur;
            t += c;
            assert(c >= 'a' && c <= 'z');
        }

        cout << "? " << t << endl;
        cout.flush();

        string s;
        cin >> s;

        for (int i = 0; i < s.size(); i++) {
            int cur = s[i] - 'a';
            int it1 = lower_bound(all(positions[cur]), l[i]) - positions[cur].begin();
            int it2 = upper_bound(all(positions[cur]), r[i]) - positions[cur].begin() - 1;

            l[i] = positions[cur][it1];
            r[i] = positions[cur][it2];
        }
    }

    for (int i = 0; i < n; i++) {
        assert(l[i] == r[i]);
        f[l[i]] = i;
    }
}

int main() {
    // files1;
    fast_io;

    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++)
        l[i] = 0, r[i] = s.size() - 1;

    solve(s.size());

    cout << "! ";
    for (int i = 0; i < s.size(); i++)
        cout << s[f[i]];
    cout << endl;
    return 0;
}