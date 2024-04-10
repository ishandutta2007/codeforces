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

int up[maxn][22];
int weight[maxn];
ll sum[maxn][22];

void addVertex(int v, int newv) {
    for(int i = 21; i >= 0; i--) {
        if (up[v][i] == -1) continue;
        int p = up[v][i];
        if (weight[p] < weight[newv]) {
            v = p;
        }
    }

    if (up[v][0] != -1 && weight[newv] > weight[v]) {
        v = up[v][0];
    }

    if(weight[newv] <= weight[v]) {
        up[newv][0] = v;
        sum[newv][0] = weight[v];
    } else {
        up[newv][0] = -1;
    }

    for (int i = 1; i < 22; i++) {
        int p = up[newv][i - 1];
        if (p == -1) up[newv][i] = -1;
        else {
            up[newv][i] = up[p][i - 1];
            sum[newv][i] = sum[newv][i - 1] + sum[p][i - 1];
        }
    }
}

int main() {
    up[1][0] = -1;
    for(int i = 1; i < 22; i++) {
        up[1][i] = -1;
    }

    // files1;
    int q;
    read(q);

    int last = 0;
    int cnt = 1;

    for (int i = 0; i < q; i++) {
        int t;
        read(t);

        if (t == 1) {
            ll p, q;
            read(p, q);
            ll R = p ^ last;
            cnt++;

            ll W = q ^ last;

            int newv = cnt;
            int v = R;
            weight[newv] = W;

            addVertex(v, newv);
        } else if (t == 2) {
            ll p, q;
            read(p, q);

            ll R = p ^ last;
            ll X = q ^ last;
            int v = R;

            int cur_ans = 0;
            if(weight[v] <= X) {
                cur_ans++;
                X -= weight[v];

                for(int i = 21; i >= 0; i--) {
                    if (up[v][i] == -1) continue;
                    if(sum[v][i] <= X) {
                        X -= sum[v][i];
                        v = up[v][i];
                        // cur_ans |= 1 << i;
                        cur_ans += 1 << i;
                    }
                }
            }

            last = cur_ans;
            cout << last << endl;
        } else exit(228);
        // return 0;
    }
    return 0;
}