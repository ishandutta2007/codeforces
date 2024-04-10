// hloya template v25
  
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
#define umap unordered_map<int, int>
  
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
void amax(T& x, T y) {
    x = max(x, y);
}
  
template<typename T>
void amin(T& x, T y) {
    x = min(x, y);
}

// inline int popcount(int x){
//     int count = 0;
//     __asm__ volatile("POPCNT %1, %0;":"=r"(count):"r"(x):);
//     return count;
// }
  
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
  
const int inf = 1e9 + 20;
const short short_inf = 3e4 + 20;
const long double eps = 1e-12;
const int maxn = (int)5e3 + 12, base = 1e9 + 7;
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

set<int> differs_with_first[maxn];
string s[maxn];
bool nunq[maxn];

void gen() {
    int k = 2, n = 2500;
    ofstream cout("input.txt");
    cout << k << ' ' << n << endl;
    string s;
    for (int i = 0; i < n; i++)
        s += char(rand() % 26 + 'a');
    cout << s << endl;
    for (int i = 0; i < 1; i++)
        s[rand() % n] = char(rand() % 26 + 'a');
    cout << s << endl;
    // s[15] = 'a';
    // cout << s << endl;
    // for (int i = 0; i < k; i++) {
    //     string t = s;
    //     int l = rand() % n, r = rand() % n;
    //     while (l == r) r = rand() % n;
    //     swap(t[l], t[r]);
    //     cout << t << "\n";
    // }
}

vector<int> structure_first(26, 0);

int main() {
    
    // gen();
    // return 0;
    // files1;

    int k, n;
    fast_io;
    cin >> k >> n;

    set<char> kek;
    for (int i = 0; i < k; i++) {
        cin >> s[i];
        nunq[i] = 0;

        kek.clear();
        for (int j = 0; j < n; j++) {
            if (kek.count(s[i][j])) {
                nunq[i] = 1;
                break;
            }
            kek.insert(s[i][j]);
        }
    }

    if (k == 1) {
        swap(s[0][0], s[0][1]);
        cout << s[0];
        return 0;
    }

    for (int i = 0; i < n; i++)
        structure_first[s[0][i] - 'a']++;

    for (int i = 1; i < k; i++) {
        vector<int> kek(26, 0);
        for (int j = 0; j < n; j++)
            kek[s[i][j] - 'a']++;
        if (structure_first != kek) {
            cout << -1;
            exit(0);
        }
    }

    for (int i = 1; i < k; i++) {
        for (int j = 0; j < n; j++) {
            if (s[0][j] != s[i][j])
                differs_with_first[i].insert(j);
        }
        if (differs_with_first[i].size() > 4) {
            bad(-1);
        }
    }

    for (int a = 0; a < n; a++)
        for (int b = a + 1; b < n; b++) {
            swap(s[0][a], s[0][b]);
            // s[0] = "acab";
            bool ok = 1;
            for (int i = 1; i < k && ok; i++) {
                bool was_a = differs_with_first[i].count(a);
                bool was_b = differs_with_first[i].count(b);

                differs_with_first[i].erase(a);
                differs_with_first[i].erase(b);

                if (s[0][a] != s[i][a]) {
                    differs_with_first[i].insert(a);
                }
                if (s[0][b] != s[i][b]) {
                    differs_with_first[i].insert(b);
                }

                // cout << differs_with_first[i].size() << endl;
                if (differs_with_first[i].size() == 2) {
                    int l = *differs_with_first[i].begin();
                    int r = *(++differs_with_first[i].begin());

                    bool eq = (s[0][l] == s[i][r]) && (s[0][r] == s[i][l]);
                    if (!eq) {
                        ok = 0;
                    }
                } else if (differs_with_first[i].size() == 0) {
                    if (nunq[i] == 0) {
                        ok = 0;
                    }
                } else ok = 0;

                differs_with_first[i].erase(a);
                differs_with_first[i].erase(b);

                if (was_a)
                    differs_with_first[i].insert(a);
                if (was_b)
                    differs_with_first[i].insert(b);
            }
            // cout << ok;
            // exit(0);
            if (ok) {
                // cout << 
                cout << s[0];
                exit(0);
            }
            swap(s[0][a], s[0][b]);
        }
    cout << -1 << endl;
    
    return 0;
}