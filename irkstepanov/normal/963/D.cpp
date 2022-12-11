#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <cstring>
#include <random>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const int sigma = 26;

struct node {
    int to[sigma];
    int link;
    int id;
    int slink;
    node() {
        memset(to, -1, sizeof(to));
        link = -1;
        slink = -1;
        id = -1;
    }
};

vector<node> t;

void add(const string& s, int id) {
    int curr = 0;
    for (int i = 0; i < sz(s); ++i) {
        int c = s[i] - 'a';
        if (t[curr].to[c] == -1) {
            t.pb(node());
            t[curr].to[c] = sz(t) - 1;
        }
        curr = t[curr].to[c];
    }
    t[curr].id = id;
}

void bfs() {
    t[0].link = 0;
    for (int c = 0; c < sigma; ++c) {
        if (t[0].to[c] == -1) {
            t[0].to[c] = 0;
        }
    }
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int c = 0; c < sigma; ++c) {
            int to = t[v].to[c];
            if (t[to].link != -1) {
                continue;
            }
            if (v == 0) {
                t[to].link = 0;
            } else {
                t[to].link = t[t[v].link].to[c];
            }
            for (int d = 0; d < sigma; ++d) {
                if (t[to].to[d] != -1) {
                    continue;
                }
                t[to].to[d] = t[t[to].link].to[d];
            }
            if (t[t[to].link].id != -1) {
                t[to].slink = t[to].link;
            } else {
                t[to].slink = t[t[to].link].slink;
            }
            q.push(to);
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    t.pb(node());

    string s;
    cin >> s;

    int n;
    cin >> n;

    vector<string> a(n);
    vector<int> k(n);
    for (int i = 0; i < n; ++i) {
        cin >> k[i] >> a[i];
        add(a[i], i);
    }

    bfs();

    vector<vector<int> > pos(n);

    int curr = 0;
    for (int i = 0; i < sz(s); ++i) {
        int c = s[i] - 'a';
        curr = t[curr].to[c];
        int x = curr;
        if (t[x].id == -1) {
            x = t[x].slink;
        }
        while (x != -1) {
            pos[t[x].id].pb(i);
            x = t[x].slink;
        }
    }

    /*for (int i = 0; i < n; ++i) {
        cout << "F:";
        for (int x : pos[i]) {
            cout << x << " ";
        }
        cout << "\n";
    }*/

    for (int i = 0; i < n; ++i) {
        if (k[i] > sz(pos[i])) {
            cout << "-1\n";
            continue;
        }
        int ans = sz(s);
        for (int j = 0; j + k[i] - 1 < sz(pos[i]); ++j) {
            ans = min(ans, pos[i][j + k[i] - 1] - pos[i][j] + sz(a[i]));
        }
        cout << ans << "\n";
    }

}