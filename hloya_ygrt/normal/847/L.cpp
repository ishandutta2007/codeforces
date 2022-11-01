// In the name of god
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <assert.h>
#include <ctime>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <bitset>
#include <bits/stdc++.h>
#define sqr(a) ((a)*(a))
#define all(a) (a).begin(), (a).end()
using namespace std;

template <typename T>
T next_int() {
    T x = 0, p = 1;
    char ch;
    do { ch = getchar(); } while(ch <= ' ');
    if(ch == '-') {
        p = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return p * x;
}

string next_token() {
    char ch;
    string ans = "";
    do { ch = getchar(); } while(ch <= ' ');
    while(ch > ' ') {
        ans += ch;
        ch = getchar();
    }
    return ans;
}

const long long INF = (long long)1e18;
const int INFINT = (int)1e9 + 227 + 1;
const int MAXN = (int)1e6 + 227 + 1;
const int MOD = (int)1e9 + 7;
const long double EPS = 1e-9;

long long bin_pow(long long a, long long b) {
    if(!b) return 1;
    long long ans = bin_pow(a, b / 2);
    ans = ans * ans;
    if(b % 2) ans = ans * a;
    return ans;
}

vector<set<int> > q[MAXN];
vector<int> last[MAXN];
multiset<int> e[MAXN];

vector<pair<int, int> > w[MAXN];

bool check(int v) {
    if(e[v].size() == 1)
        return 1;
    return (*--(--e[v].end()) == 0);
}

vector<pair<int, int> > edge;

vector<int> gg[MAXN];

bool used[MAXN];

void go(int v) {
    if(used[v]) return;
    used[v] = 1;

    for(int i = 0; i < gg[v].size(); i++) {
        go(gg[v][i]);
    }
}

int main() {
//    freopen(".in", "r", stdin);
//    ios_base::sync_with_stdio(0);

    int n; cin >> n;

    for(int i = 0; i < n; i++) {
        string a = next_token();

        int kek = 0;
        vector<int> lol;
        for(int j = 0; j <= a.size(); j++) {
            if(j == a.size() || (a[j] < '0' || a[j] > '9')) {
                lol.push_back(kek);
                kek = 0;
            } else {
                kek = kek * 10 + (a[j] - '0');
            }
        }

        int mda = 0;
        for(int j = 0; j < lol.size(); j++) {
            if(mda == 0) {
                mda = lol[j];
                q[i].push_back(set<int>());
                last[i].push_back(-1);
                e[i].insert(mda);
            } else {
                mda--;

                w[lol[j] - 1].push_back(make_pair(i, q[i].size() - 1));
                q[i].back().insert(lol[j] - 1);
            }
        }
    }

    vector<int> us(n, 0);
    for(int it = 0; it < n; it++) {
        int p = -1;
        for(int i = 0; i < n; i++) {
            if(us[i]) continue;

            if(check(i)) {
                p = i;
            }
        }

        if(p == -1) {
            puts("-1");
            return 0;
        }

        us[p] = 1;

        int i = p;

        for(int j = 0; j < q[i].size(); j++) {
            if(q[i][j].size() == 0) {
                edge.push_back(make_pair(i, last[i][j]));
            }
        }

        for(int j = 0; j < w[i].size(); j++) {
            int lol = q[w[i][j].first][w[i][j].second].size();

            if(lol == 1) {
                last[w[i][j].first][w[i][j].second] = *q[w[i][j].first][w[i][j].second].begin();
            }

            q[w[i][j].first][w[i][j].second].erase(i);
            e[w[i][j].first].erase(e[w[i][j].first].lower_bound(lol));
            e[w[i][j].first].insert(lol - 1);
        }

//        cout << i << "\n";
//
//        for(int i = 0; i < n; i++) {
//            for(auto j : e[i]) {
//                cout << j << " ";
//            }
//            puts("");
//        }
    }

    if(edge.size() != n - 1) {
        puts("-1");
        return 0;
    }

    for(int i = 0; i < edge.size(); i++) {
        gg[edge[i].first].push_back(edge[i].second);
        gg[edge[i].second].push_back(edge[i].first);
    }

    go(0);

    bool ans = 1;
    for(int i = 0; i < n; i++) {
        ans &= used[i];
    }

    if(!ans) {
        puts("-1");
        return 0;
    }

    cout << edge.size() << "\n";
    for(int i = 0; i < edge.size(); i++)
        cout << edge[i].first + 1 << " " << edge[i].second + 1 << "\n";

    return 0;
}