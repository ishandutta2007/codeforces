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
#define vi vector<int>
#define pii pair<int,int>
#define endl '\n'

using namespace std;
 
void bad(string mes = "Impossible"){cout << mes;exit(0);}
template<typename ... T> void shit(T& ... x){}
template<typename ... T> void dec(T& ... x){shit(--x...);}
template<typename ... T> void inc(T& ... x){shit(++x...);}
#include <unordered_map>
#include <unordered_set>

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
T input(){
    T ans = 0, m = 1;
    char c = ' ';
    while (!((c >= '0' && c <= '9') || c == '-'))
        c = getchar();
    if (c == '-')
        m = -1, c = getchar();
    while (c >= '0' && c <= '9'){
        ans = ans * 10 + (c - '0'), c = getchar();
    }
    return ans * m;
}

template<typename T>
void read(T& a) {
    a = input<T>();
}

template<typename T>
void read(T& a, T& b) {
    read(a), read(b);
}

template<typename T>
void read(T& a, T& b, T& c) {
    read(a, b), read(c);
}

template<typename T>
void read(T& a, T& b, T& c, T& d) {
    read(a, b), read(c, d);
}
 
const int inf = 1e9;
const double eps = 1e-9;
const int maxn = 2e5 + 5, base = 1e9 + 7;
const int sigm = 26;
const ll llinf = 1e18 + 1;

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

vector<int> gr1[maxn], gr2[maxn];
vector<int> candidatesFrom, candidatesTo;

int main() {
    int n, m;
    read(n, m);

    for (int i = 0; i < m; i++) {
        int f, t;
        read(f, t);
        dec(f, t);

        gr1[f].pb(t);
        gr2[t].pb(f);
    }

    for (int i = 0; i < n; i++){
        sort(gr1[i].begin(), gr1[i].end());
        sort(gr2[i].begin(), gr2[i].end());
    }

    ll ans = 0;
    for (int b = 0; b < n; b++)
        for (int d = b + 1; d < n; d++) {
            candidatesFrom.clear();
            candidatesTo.clear();

            set_intersection(gr1[b].begin(), gr1[b].end(),
                             gr1[d].begin(), gr1[d].end(),
                             back_inserter(candidatesTo));

            set_intersection(gr2[b].begin(), gr2[b].end(),
                             gr2[d].begin(), gr2[d].end(),
                             back_inserter(candidatesFrom));
            ans += 1LL * candidatesTo.size() * candidatesFrom.size();
            int pt1 = 0, pt2 = 0;
            while (pt1 < candidatesFrom.size() && pt2 < candidatesTo.size()) {
                while (pt2 < candidatesTo.size() && candidatesTo[pt2] < candidatesFrom[pt1])
                    pt2++;
                if (pt2 < candidatesTo.size() && candidatesFrom[pt1] == candidatesTo[pt2])
                    ans--;
                pt1++;
            }
        }
    cout << ans;
    return 0;
}