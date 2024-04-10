#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <deque>
#include <memory.h>
#include <assert.h>
#include <cstring>
#include <cmath>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, ll> pll;

const int nmax = 1e6 + 100;

int lf[nmax], rg[nmax];
bool inQueue[nmax];
string s;
queue<int> q;
int level[nmax];

void check(int i, int l) {
    if (inQueue[i]) {
        return;
    }
    if (lf[i] != -1 && s[i] != s[lf[i]]) {
        inQueue[i] = true;
        q.push(i);
        level[i] = l + 1;
        return;
    }
    if (rg[i] != -1 && s[i] != s[rg[i]]) {
        inQueue[i] = true;
        q.push(i);
        level[i] = l + 1;
        return;
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	//ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> s;

    int n = sz(s);
    for (int i = 0; i < n - 1; ++i) {
        rg[i] = i + 1;
    }
    rg[n - 1] = -1;
    lf[0] = -1;
    for (int i = 1; i < n; ++i) {
        lf[i] = i - 1;
    }

    memset(inQueue, false, sizeof(inQueue));

    for (int i = 0; i < n; ++i) {
        check(i, 0);
    }

    vector<int> vis;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        int x = lf[v];
        int y = rg[v];
        lf[v] = rg[v] = -1;
        if (x != -1) {
            rg[x] = y;
            vis.pb(x);
        }
        if (y != -1) {
            lf[y] = x;
            vis.pb(y);
        }
        if (q.empty()) {
            for (int x : vis) {
                check(x, level[v]);
            }
            vis.clear();
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        //cout << level[i] << " ";
        ans = max(ans, level[i]);
    }
    cout << ans << "\n";

}