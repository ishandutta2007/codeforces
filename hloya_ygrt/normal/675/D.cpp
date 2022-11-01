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

const int inf = 2e9;
const double eps = 1e-6;
const int maxn = 1e6 + 10, base = 1e9 + 7;
const int sigm = 26;
const ll llinf = 1e18;

void bad(string mes = "Impossible"){cout << mes;exit(0);}

template<typename T>
string bin(T x){
    string ans = "";
    while (x > 0){
        ans += char('0' + x % 2);
        x /= 2;
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
    if (s == 0)
        return 1LL;
    if (s % 2 == 0){
        T b = binpow(n, s / 2) % base;
        return ( 1LL * b * b ) % base;
    } else {
        return (1LL* binpow(n, s - 1) * n) % base;
    }
}

int a[maxn];
vector<int> tmp;
#define less sgopj
int less[maxn], gret[maxn];
int ans[maxn];
map<int, int> sot, pos;
pair<int,int> tmax[4 * maxn], tmin[4 * maxn];


void update_max(int v, int tl, int tr, int pos, int val)
{
    if (tl == tr)
        tmax[v] = mp(val, pos);
    else
    {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update_max(v * 2 + 0, tl, tm, pos, val);
        else
            update_max(v * 2 + 1, tm + 1, tr , pos, val);
        tmax[v] = max(tmax[v * 2], tmax[v * 2 + 1]);
    }
}

void update_min(int v, int tl, int tr, int pos, int val)
{
    if (tl == tr)
        tmin[v] = mp(val, pos);
    else
    {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update_min(v * 2 + 0, tl, tm, pos, val);
        else
            update_min(v * 2 + 1, tm + 1, tr , pos, val);
        tmin[v] = min(tmin[v * 2], tmin[v * 2 + 1]);
    }
}

pair<int,int> get_max(int v, int tl, int tr, int l, int r)
{
    if (l > r)

        return mp(-inf, -1);
    if (tl == l && tr == r)
        return tmax[v];
    int tm = (tl + tr) / 2;
    return max(get_max(v * 2 + 0, tl, tm, l, min(r, tm)), get_max(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r));
}

pair<int,int> get_min(int v, int tl, int tr, int l, int r)
{
    if (l > r)
        return mp(inf, -1);
    if (tl == l && tr == r)
        return tmin[v];
    int tm = (tl + tr) >> 1;
    return min(get_min( (v << 1) + 0, tl, tm, l, min(r, tm)), get_min((v << 1) + 1, tm + 1, tr, max(tm + 1, l), r));
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", a + i);
        tmp.pb(a[i]);
    }

    sort(tmp.begin(), tmp.end());
    for (int i = 0; i < tmp.size(); i++)
        sot[tmp[i]] = i;
    for (int i = 0; i < n; i++){
        int new_ = sot[a[i]];
        pos[new_] = a[i];
        a[i] = new_;
    }
    for (int i = 0; i < n; i++)
        less[i] = n - 1, gret[i] = 0;

    ans[0] = 1;

    for (int i = 1; i < n; i++){
        update_min(1, 0, n - 1, a[i], i);
    }

    for (int i = 0; i < n; i++){
//        int cur = a[i];
        pair<int,int> left_son = get_min(1, 0, n - 1, gret[i], a[i] - 1);
        if (left_son.f != inf){
            int nxt = left_son.f;
            ans[nxt] = pos[a[i]];
            gret[nxt] = gret[i];
            less[nxt] = a[i] - 1;
            update_min(1, 0, n - 1, left_son.s, inf);
        }
        pair<int,int> right_son = get_min(1, 0, n - 1, a[i] + 1, less[i]);
        if (right_son.f != inf){
            int nxt = right_son.f;
            ans[nxt] = pos[a[i]];
            gret[nxt] = a[i] + 1;
            less[nxt] = less[i];
            update_min(1, 0, n - 1, right_son.s, inf);
        }
    }

    for (int i = 1; i < n; i++)
        cout << ans[i] << ' ';

    return 0;
}