#include<bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

int n, mx, ind;
int par[MAXN], dub[MAXN];
set <int> st[MAXN];
vector <int> sol, red;

void dfs (int x) {
    if (x == 0) return;
    int p = par[x];
    if (st[p].size() == 1) {
        dfs(p);
        return;
    }
    sol.push_back(x);
    auto it = st[p].begin();
    int ch = (*it != x ? *it : *(++it));
    st[p].erase(x); st[ch].insert(x);
    par[x] = ch;
    dfs(x);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> par[i];
        st[par[i]].insert(i);
        dub[i] = 1 + dub[par[i]];
        if (dub[i] > mx) {
            mx = dub[i];
            ind = i;
        }
    }
    dfs(ind);
    for (int i = 0; i < n; i++) {
        red.push_back(ind);
        ind = par[ind];
    }
    reverse(red.begin(), red.end());
    reverse(sol.begin(), sol.end());
    for (auto x : red) cout << x << " "; cout << endl;
    cout << sol.size() << endl;
    for (auto x : sol) cout << x << " "; cout << endl;
    return 0;
}