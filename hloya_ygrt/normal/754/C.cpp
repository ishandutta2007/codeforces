// hloya template v22

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
void bad(int mes = -1){cout << mes;exit(0);}

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
void amax(T& x, T y) {
    x = max(x, y);
}

template<typename T>
void amin(T& x, T y) {
    x = min(x, y);
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

const int inf = 2e9;
const long double eps = 1e-12;
const int maxn = 5e5 + 12, base = 1e9 + 7;
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

bool dp[105][105];
int p[105][105];
string s[105], name_known[105], mes[105];
set<int> banned[105];

void solve() {
    int n;
    cin >> n;

    map<string, int> sot;

    for (int i = 0; i < n; i++) {
        cin >> s[i];
        sot[s[i]] = i;
    }

    int m;
    cin >> m;
    getline(cin, s[n]);

    for (int i = 0; i < m; i++) {
        getline(cin, mes[i]);
        // cout << mes[i] << endl;
        banned[i].clear();

        if (mes[i][0] == '?') {
            mes[i] = mes[i].substr(2);
            name_known[i] = "";
        } else {
            int pos = mes[i].find(":");
            name_known[i] = mes[i].substr(0, pos);
            mes[i] = mes[i].substr(pos + 1);
        }
        for (int j = 0; j < n; j++) {
            for (int l = 0; l + s[j].size() - 1 < mes[i].size(); l++) {
                if (l == 0 || mes[i][l - 1] == ' ' || mes[i][l - 1] == '?' ||  mes[i][l - 1] == '!' || 
                    mes[i][l - 1] == '.' || mes[i][l - 1] == ',') {
                    
                    if (l + s[j].size() == mes[i].size() || mes[i][l + s[j].size()] == ' ' || 
                            mes[i][l + s[j].size()] == '?' ||  mes[i][l + s[j].size()] == '!' || 
                            mes[i][l + s[j].size()] == '.' || mes[i][l + s[j].size()] == ',') {
                        if (mes[i].substr(l, s[j].size()) == s[j])
                            banned[i].insert(j);
                    }
                }
            }
        }
        // cout << mes[i] << endl;
        // cout << banned[i].size() << endl;
        // for (int e:banned[i])
        //     cout << e << ' ';
        // cout << endl;
    }
    // return;

    memset(dp, 0, sizeof(dp));
    if (name_known[0].empty()) {
        for (int i = 0; i < n; i++)
            if (!banned[0].count(i))
                dp[0][i] = 1;
    } else {
        if (!banned[0].count(sot[name_known[0]]))
            dp[0][sot[name_known[0]]] = 1;
    }

    for (int i = 0; i + 1 < m; i++) {
        for (int last = 0; last < n; last++) {
            // cout << i << ' ' << last << ' ' << dp[i][last] << endl;
            if (!dp[i][last])
                continue;
            if (name_known[i + 1].empty()) {
                for (int k = 0; k < n; k++)
                    if (!banned[i + 1].count(k) && k != last) {
                        dp[i + 1][k] = 1;
                        p[i + 1][k] = last;
                    }
            } else {
                int pos = sot[name_known[i + 1]];
                if (pos != last && !banned[i + 1].count(pos)) {
                    dp[i + 1][pos] = 1;
                    p[i + 1][pos] = last;
                }
            }
        }
    }

    int last = -1;
    for (int i = 0; i < n; i++)
        if (dp[m - 1][i])
            last = i;
    if (last == -1) {
        cout << "Impossible\n";
        return;
    }
    
    int i = m - 1;
    vector<string> res;
    while (i >= 0) {
        res.pb(s[last] + ":" + mes[i]);
        last = p[i][last];
        i--;
    }
    reverse(all(res));
    for (string s:res)
        cout << s << endl;
}

int main() {
    int t;
    fast_io;
    //files1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}