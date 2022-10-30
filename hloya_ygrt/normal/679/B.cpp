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
#define str(x) #x

using namespace std;
 
void bad(string mes = "Impossible"){cout << mes;exit(0);}

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
 
const int inf = 1e9;
const double eps = 1e-9;
const int maxn = 1e5 + 10, base = 1e9 + 7;
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

vector<ll> cubes;
int check(ll x)
{
    int ans = 0;
    for (int i = cubes.size() - 1; i >= 0; i--)
        while (cubes[i] <= x) {
            x -= cubes[i];
            ans++;
        }
    return ans;
}

ll depow(ll x)
{
    ll l = 1, r = 100000LL;
    while (r - l > 1) {
        ll m = (l + r) / 2LL;
        if (m * m * m <= x)
            l = m;
        else
            r = m;
    }
    if (r * r * r <= x)
        return r;
    if (l * l * l <= x)
        return l;
    exit(x);
}

ll pw(ll x)
{
    return x * x * x;
}

vector<ll> get(ll x)
{
    vector<ll> ans;
    while (x) {
        ll mx = depow(x);
        x -= pw(mx);
        ans.pb(pw(mx));
    }
    return ans;
}

int main()
{
    for (ll i = 1; i <= 100001; i++){
        cubes.pb(i * i * i);
    }

    ll m;

    // ll res = 0, res1;
    // for (int i = 1; i <= m; i++)
    //     if (check(i) >= res)
    //         res = check(i), res1 = i;
    // cout << res << ' ' << res1 << endl;
    cin >> m;
    if (m <= 6)
        return cout << m << ' ' << m, 0;
    // if (m >= 7 && m <= 22) {
    //     if (m <= 14)
    //         cout << 7 << ' ' << m;
    //     else
    //         cout << 8 << ' ' << m;
    //     return 0;
    // }

    const int sz = 18;
    ll oeis[sz] = {1,2,3,4,5,6,7,15,23,50,114,330,1330,10591,215970,19464802,16542386125LL,409477218238718LL};

    ll pref;
    for (int i = 0; i < sz; i++)
        if (oeis[i] <= m)
            pref = oeis[i];
    vector<ll> cur = get(pref);
    for (int i = 0; i < cur.size(); i++) {
        while (1) {
            ll newPref = pref - cur[i] + pw(depow(cur[i]) + 1LL);
            if (newPref <= m && get(newPref).size() == cur.size()) {
                pref = newPref;
                cur[i] = pw(depow(cur[i]) + 1);
            } else break;
        }
    }

    cout << cur.size() << ' ' << pref;
    return 0;
}