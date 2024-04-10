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
  
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <assert.h>
#include <fstream>
#include <map>
#include <cstring>
#include <queue>
#include <iomanip>
#include <time.h>
// #Include
#include <valarray>
using namespace std;
  
bool dbg = 0;
  
clock_t start_time = clock();
#define current_time fixed<<setprecision(6)<<(ld)(clock()-start_time)/CLOCKS_PER_SEC
  
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
  
#define ll long long
#define ld long double
#define pii pair<int,int>
#define umap unordered_map<int, int>
  
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("out2.txt","w",stdout)
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
const long double eps = 1e-15;
const int maxn = (int)4e5 + 12, base = 1e9 + 7;
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
int id[maxn];
vector<int> kek[maxn];

int main(){
    // files1;
    string s;
    cin >> s;

    memset(l, -1, sizeof(l));
    memset(r, -1, sizeof(r));

    set<int> q;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') {
            q.insert(i);
        } else {
            if (q.empty()) {
                puts("-1");
                return 0;
            }
            l[i] = *q.begin();
            q.erase(q.begin());
        }
    }
    q.clear();
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '0') {
            q.insert(i);
        } else {
            if (q.empty()) {
                puts("-1");
                return 0;
            }
            r[i] = *q.begin();
            q.erase(q.begin());
        }
    }

    int cnt = 0;
    memset(id, -1, sizeof(id));

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') {
            if (id[l[i]] == -1) {
                id[l[i]] = cnt++;
            }
            id[i] = id[l[i]];
            id[r[i]] = id[l[i]];
        }
    }
    for (int i = 0; i < s.size(); i++) {
        if (id[i] == -1) {
            id[i] = cnt++;
        }
        kek[id[i]].pb(i);
    }   

    cout << cnt << endl;

    for (int i = 0; i < cnt; i++) {
        cout << kek[i].size() << ' ';
        for (int j : kek[i]) {
            cout << j + 1 << ' ';
        }
        cout << endl;
    }
    return 0;
}