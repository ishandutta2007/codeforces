#include <iostream>
#include <fstream>
// #include <bits/stdc++.h>
#include <sstream>
#include <list>
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

using namespace std;

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
    while (c == ' ' || c == '\n')
        c = getchar();
    if (c == '-')
        m = -1, c = getchar();
    while (c >= '0' && c <= '9'){
        ans = ans * 10 + int(c - '0'), c = getchar();
    }
    return ans * m;
}

template<typename T>
T binpow(T n, T s)
{
    if (s <= 0)
        return 1LL;
    if (s % 2 == 0){
        T b = binpow(n, s / 2);
        return ( 1LL * b * b );
    } else {
        return (1LL* binpow(n, s - 1) * n);
    }
}
const int inf = 2e9;
const double eps = 1e-9;
const int maxn = 1e5 + 10, base = 1e9 + 7;
const int sigm = 26;
const ll llinf = 1e18;

struct frac
{
    ll a, b;
    frac(){
    }
    frac(ll a, ll b):a(a), b(b){}

    frac stab(frac kek)
    {
        ll gcd = __gcd(kek.a, kek.b);
        return frac(kek.a / gcd, kek.b / gcd);
    }

    frac sum(frac & f)
    {
        ll newB = 1LL * b * f.b;
        ll newA1 = 1LL * a * f.b;
        ll newA2 = 1LL * f.a * b;
        return stab(frac(newA1 + newA2, newB));
    }

    frac divide()
    {
        return stab(frac(a, b * 2LL));
    }
};

frac v[10][10];
int n;

void go(int x, int y, frac water)
{
    frac newCur = v[x][y].sum(water);
    if (newCur.a >= newCur.b) {
        frac fracRest = frac(newCur.a - newCur.b, newCur.b);
        v[x][y] = frac(1, 1);

        if (x + 1 >= n)
            return;
        fracRest = fracRest.divide();
        go(x + 1, y, fracRest);
        go(x + 1, y + 1, fracRest);
    } else v[x][y] = newCur;
}

int main()
{   

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            v[i][j] = frac(0, 1);


    // for (int i = 0; i < 9; i++){
    //     for (int j = 0; j <= i; j++){
    //         frac cur = v[i][j].divide();
    //         cout << v[i][j].a << '/' << v[i][j].b << ' ';

    //         v[i + 1][j] = cur.sum(v[i + 1][j]);
    //         v[i + 1][j + 1] = cur.sum(v[i + 1][j + 1]);
    //     }
    //     cout  << endl;
    // }
    int t;
    cin >> n >> t;

    if (t == 0)
        bad("0");
    for (int i = 0; i < t; i++){
        go(0, 0, frac(1, 1));
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++){
            v[i][j] = v[i][j].stab(v[i][j]);
            if (v[i][j].a == 1 && v[i][j].b == 1)
                ans++;
        }

    cout << ans;
    return 0;
}