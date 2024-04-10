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
const int maxn = 2e5 + 12, base = 1e9 + 7;
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

int t[40];
bool dp[31][6][315][315][8];
// i len x y dir
bool ans[315][315];

const int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int main() {
    int n;
    read(n);

    for (int i = 0; i < n; i++)
        read(t[i]);
    dp[0][t[0]][152][152][0] = 1;
    int nx, ny;
    int dir2;

    for (int i = 0; i < n; i++)
        for (int len = t[i]; len >= 1; len--)
            for (int x = 1; x < 315; x++)
                for (int y = 1; y < 315; y++)
                    for (int dir = 0; dir < 8; dir++) {
                        if (!dp[i][len][x][y][dir])
                            continue;
                        ans[x][y] |= 1;
                        if (i != n - 1 && len == 1) {
                            dir2 = dir + 1;
                            if (dir2 == 8)
                                dir2 = 0;
                            nx = x + dx[dir2];
                            ny = y + dy[dir2];
                            dp[i + 1][t[i + 1]][nx][ny][dir2] = 1;

                            dir2 = dir - 1;
                            if (dir2 < 0)
                                dir2 = 7;
                            nx = x + dx[dir2];
                            ny = y + dy[dir2];
                            dp[i + 1][t[i + 1]][nx][ny][dir2] = 1;
                        } else {
                            nx = x + dx[dir];
                            ny = y + dy[dir];
                            dp[i][len - 1][nx][ny][dir] = 1;
                        }
                    }
    int res = 0;
    for (int x = 1; x < 315; x++)
        for (int y = 1; y < 315; y++)
            if (ans[x][y])
                res++;
    cout << res;
    return 0;
}