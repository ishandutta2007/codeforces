#include <iostream>
#include <fstream>
// #include <bits/stdc++.h>
#include <sstream>
#include <list>
#include <unordered_set>
#include <stack>
#include <deque>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <assert.h>
#include <bitset>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <iterator>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <complex>
 
#define f first
#define s second
#define ll long long
#define ld long double
#define pb push_back
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define files files1;files2
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0)
#define forn() for(int i=0;i<n;i++)
#define vi vector<int>
#define pii pair<int,int>
#define endl '\n'
#define fill(x) memset((x), 0, sizeof((x)))
#define str(x) #x

using namespace std;
 
void bad(string mes = "Impossible"){cout << mes;exit(0);}
void runTime(int code = 3){exit(code);}
void timeLimit(){while(1);}

template<typename ... T> void shit(T& ... x){}
template<typename ... T> void dec(T& ... x){shit(--x...);}
template<typename ... T> void inc(T& ... x){shit(++x...);}

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
void putOff(T collection, char separator = ' ', char terminator = '\n')
{
    int flag = 0;
    for (auto i:collection){
        if (flag++) cout << separator;
                    cout << i; 
    }
    cout << terminator;
}
 
template<typename T>
T dcm(string & s)
{
    T x = 0;
    for (int i = 0; i < s.size(); i++){
        x = (x * 2) + (s[i] == '1');
    }
    return x;
}
 
template<typename T>
T input(){
    T ans = 0, m = 1;
    char c = ' ';
    while (!((c >= '0' && c <= '9') || c == '-'))
        c = getchar();
    if (c == '-')
        m = -1, c = getchar();
    while (c >= '0' && c <= '9'){
        ans = ans * 10 + int(c - '0'), c = getchar();
    }
    return ans * m;
}

template<typename T>
T parseNumber(string & s)
{
    T ans = 0, m = 1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '-')
            m = -1;
        else {
            assert(s[i] >= '0' && s[i] <= '9');
            ans = (ans * (ll)10) + s[i] - '0';
        }
    }
    return ans * m;
}
 
const int inf = 1e9;
const double eps = 1e-9;
const int maxn = 505 + 1, base = 1e9 + 7;
const int sigm = 26;
const ll llinf = 1e18;

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

int n, k;
int cmp[maxn][maxn], sum[maxn][maxn], sizeOfComponent[maxn * maxn];

inline int getSum(const int& xl, const int& xr, const int& yl, const int& yr) {
    assert(xl > 0 && xr > 0 && yl > 0 && yr > 0);
    return sum[xr][yr] - sum[xl - 1][yr] - sum[xr][yl - 1] + sum[xl - 1][yl - 1];
}

bool a[maxn][maxn], used[maxn][maxn];

int mx[4] = {1, 0, -1, 0};
int my[4] = {0, 1, 0, -1};

void dfs(int x, int y, int col) {
    used[x][y] = 1;
    cmp[x][y] = col;
    sizeOfComponent[col]++;
    for (int i = 0; i < 4; i++) {
        int nx = x + mx[i], ny = y + my[i];
        if (a[nx][ny] && !used[nx][ny])
            dfs(nx, ny, col);
    }
}
void __init__() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            char c = endl;
            while (c == endl)
                c = getchar();
            a[i][j] = (c == '.');
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1]
                        + (c == 'X');
        }

    int curCmp = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (!used[i][j] && a[i][j]){
                dfs(i, j, curCmp++);
            }
                // cout << cmp[i][j] << ' ';
        }
            // cout << endl;
        }
}

int cntOfComponent[maxn * maxn], curAns;

inline void add(const int& x, const int& y) {
    int cur = cmp[x][y];
    if (cur && cntOfComponent[cur]++ == 0)
        curAns += sizeOfComponent[cur];
}

inline void ers(const int& x, const int& y) {
    int cur = cmp[x][y];
    if (!cntOfComponent[cur]) return;
    if (--cntOfComponent[cur] == 0)
        curAns -= sizeOfComponent[cur];
}

int main() {
    n = input<int>(), k = input<int>();

    __init__();

    int ans = 0;
    for (int xl = 1; xl + k - 1 <= n; xl++) {
        int xr = xl + k - 1;
        int yl = 1, yr = k;

        //first qu
        for (int i = xl; i <= xr; i++)
            for (int j = yl; j <= yr; j++)
                add(i, j);
        for (int i = yl; i <= yr; i++)
            add(xl - 1, i), add(xr + 1, i);
        for (int i = xl; i <= xr; i++)
            add(i, yr + 1);

        while (yr <= n) {
            ans = max(ans, curAns + getSum(xl, xr, yl, yr));
            for (int i = xl; i <= xr; i++)
                ers(i, yl - 1);
            ers(xl - 1, yl);
            ers(xr + 1, yl);

            yl++, yr++;
            add(xl - 1, yr);
            add(xr + 1, yr);
            for (int i = xl; i <= xr; i++)
                add(i, yr + 1);
        }

        for (int i = xl - 1; i <= xr + 1; i++)
            for (int j = yl - 1; j <= yr + 1; j++)
                ers(i, j);
    }

    cout << ans;
    return 0;
}