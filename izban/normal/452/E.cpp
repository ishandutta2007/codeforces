#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>
#include <cstring>


using namespace std; 

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 300200;
const int inf = 1000000007;
const int mod = 1000000007;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

string a, b, C, s;
int n;
int p[maxn], pn[maxn], c[maxn], cn[maxn], cnt[maxn], lcp[maxn], o[maxn];

void getArray() {
    n = s.length();
    
    for (int i = 0; i < 255; i++) cnt[i] = 0;
    for (int i = 0; i < n; i++) cnt[s[i]]++;
    for (int i = 1; i < 255; i++) cnt[i] += cnt[i - 1];
    for (int i = n - 1; i >= 0; i--) p[--cnt[s[i]]] = i;

    c[p[0]] = 0;
    int cls = 1;
    for (int i = 1; i < n; i++) {
        cls += s[p[i]] != s[p[i - 1]];
        c[p[i]] = cls - 1;
    }

    for (int len = 1; len < n; len <<= 1) {
        for (int i = 0; i < cls; i++) cnt[i] = 0;
        for (int i = 0; i < n; i++) {
            pn[i] = (p[i] - len + n) % n;
            cnt[c[i]]++;
        }
        for (int i = 1; i < cls; i++) cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; i--) p[--cnt[c[pn[i]]]] = pn[i];

        cn[p[0]] = 0;
        cls = 1;
        for (int i = 1; i < n; i++) {
            cls += c[p[i]] != c[p[i - 1]] || c[(p[i] + len) % n] != c[(p[i - 1] + len) % n];
            cn[p[i]] = cls - 1;
        }
        for (int i = 0; i < n; i++) c[i] = cn[i];
    }    
    
    
    for (int i = 0; i < n; i++) o[p[i]] = i;

    int z = 0;
    for (int i = 0; i < n; i++) {
        int j = o[i];
        if (j == n - 1) {
            z = 0;
            lcp[j] = z;
        } else {
            while (s[i + z] == s[p[j + 1] + z]) z++;
            lcp[j] = z;
            z -= z > 0;
        }
    }   
}


int lal(int x) {
    if (x < a.length()) return 0;
    if (x > a.length() && x < a.length() + b.length() + 1) return 1;
    if (x > a.length() + b.length() + 1 && x < a.length() + b.length() + C.length() + 2) return 2;
    return 3;
}

ll ss[maxn];
ll llol[maxn][4];

void add(int l, int r, ll toadd) {
    if (l > r) return;
    ss[l] = (ss[l] + toadd) % mod;
    ss[r + 1] = (ss[r + 1] - toadd + mod) % mod;
}

ll get(int l, int r) {
    ll ans = 1;
    for (int i = 0; i < 3; i++) {
        ans *= (llol[r][i] - (l ? llol[l - 1][i] : 0) + mod) % mod;
        ans %= mod;
    }
    return ans;
}

ll solve() {
    s = "";
    s += a;
    s += (char)(37);
    s += b;
    s += (char)(36);
    s += C;
    s += (char)(35);
        
    getArray();
            
    vector<pair<int, int> > v;
    v.push_back(make_pair(-2, -1));
    
    int ans = 0, pans = 0;
    for (int i = 0; i <= n; i++) ss[i] = 0;
    lcp[n - 1] = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            llol[i][j] = 0;
        }
        llol[i][lal(p[i])] = 1;
        for (int j = 0; j < 3; j++) {
            if (i > 0) {
                llol[i][j] += llol[i - 1][j];
            }
        }        
    }
    
    for (int i = 0; i < n; i++) {
        while (!v.empty() && v.back().first >= lcp[i]) {
            int l = v[(int)v.size() - 2].second + 1, r = i;
            ll toadd = get(l, r);
            add(max(v[(int)v.size() - 2].first + 1, lcp[i] + 1), v.back().first, toadd);
            //add(max(v[(int)v.size() - 2].first.first + 1, lcp[i] + 1), v.back().first.first, v.back().second + v[(int)v.size() - 2].second - lol(p[v[(int)v.size() - 2].first.second + 1]));
            //cc = cc + v.back().second + v[(int)v.size() - 2].second - lol(p[v[(int)v.size() - 2].first.second + 1]);
            v.pop_back();
        }
        v.push_back(make_pair(lcp[i], i));
    }
    for (int i = 1; i <= min(a.length(), min(b.length(), C.length())); i++) {
        ss[i] = (ss[i - 1] + ss[i]) % mod;
        cout << ss[i] << " ";
    }
    cout << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    
    while (cin >> a >> b >> C) {
        solve();
    }
    
    return 0;
}