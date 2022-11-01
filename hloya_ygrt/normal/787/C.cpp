// hloya template v24

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

// clock_t start_time = clock();
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
#define files2 freopen("data.out","w",stdout)
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

const int inf = 2e9 + 20;
const short short_inf = 3e4 + 20;
const long double eps = 1e-12;
const int maxn = 7e3 + 12, base = (int)1e9 + 13;
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

vector<short> p[2];
bool win [maxn][2];
bool loose [maxn][2];
bool used[maxn][2];
short degree[maxn][2];

int n;


void dfs (short v, short v1) {
    used[v][v1] = true;
    for (int i = 0; i < p[v1].size(); i++) {
    	int to = v - p[v1][i];
    	if (to < 0)
    		to += n;
        if (!used[to][v1^1]) {
            if (loose[v][v1])
                win[to][v1^1] = true;
            else if (--degree[to][v1^1] == 0)
                loose[to][v1^1] = true;
            else
                continue;
            dfs (to, v1^1);
        }
    }
}

int main() {
    read(n);

    vector<short> a, b;
    int k1;
    read(k1);
    for (int i = 0; i < k1; i++) {
        int x;
        read(x);
        a.pb(x);
    }
    p[0] = a;

    int k2;
    read(k2);
    for (int i = 0; i < k2; i++) {
        int x;
        read(x);
        b.pb(x);
    }
    p[1] = b;

    for (int i = 0; i < n; i++) {
    	// for ()
    	degree[i][0] = p[1].size();
    	degree[i][1] = p[0].size();
    }


    // win[0] = 1;
    loose[0][0] = 1;
    loose[0][1] = 1;
    // win[n] = 1;

    // for (int i = 0; i < n + n; i++)
    //     degree[i] = g[i].size();

    dfs(0, 0);
    dfs(0, 1);

    for (int i = 1; i < n; i++) {
        if (loose[i][1]) {
            cout << "Lose ";
        } else if (win[i][1]) {
            cout << "Win ";
        } else
        cout << "Loop ";
    }
    cout << endl;


    for (int i = 1; i < n; i++) {
        if (loose[i][0]) {
            cout << "Lose ";
        } else if (win[i][0]) {
            cout << "Win ";
        } else
        cout << "Loop ";
    }
    return 0;
}