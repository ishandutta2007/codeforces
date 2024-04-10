#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

vector<int> p;
vector<bool> cycle;
vector<bool> used;
vector<int> depth;
vector<int> root;
vector<int> pos;

void dfs(int v) {
    if (depth[v] != -1) {
        return;
    }
    dfs(p[v]);
    depth[v] = depth[p[v]] + 1;
    root[v] = root[p[v]];
}

const int rmax = 40;
vector<vector<int> > shifts;

int getShift(int v, int num) {
    for (int r = rmax - 1; r >= 0; --r) {
        if ((1LL << r) <= num) {
            v = shifts[r][v];
            num -= (1LL << r);
        }
    }
    return v;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

    int n;
    cin >> n;
    p.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        --p[i];
    }

    /*used.assign(n, false);
    int curr = 0;
    used[curr] = true;
    while (true) {
        curr = p[curr];
        if (used[curr]) {
            break;
        }
        used[curr] = true;
    }

    cycle.assign(n, false);
    int cycleLen = 0;
    depth.assign(n, -1);
    root.assign(n, -1);
    pos.assign(n, -1);
    while (true) {
        if (cycle[curr]) {
            break;
        }
        cycle[curr] = true;
        pos[curr] = cycleLen++;
        root[curr] = curr;
        depth[curr] = 0;
        curr = p[curr];
    }

    for (int i = 0; i < n; ++i) {
        dfs(i);
    }
    return 0;*/

    int leaves = 0;
    used.assign(n, false);
    for (int i = 0; i < n; ++i) {
        used[p[i]] = true;
    }
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            ++leaves;
        }
    }

    vector<int> a(n);
    int maxx = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
        maxx = max(maxx, a[i]);
    }

    assert((maxx - (n - 1)) % leaves == 0);
    int num = (maxx - (n - 1)) / leaves;

    shifts = vector<vector<int> >(rmax, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        shifts[0][i] = p[i];
    }
    for (int r = 0; r + 1 < rmax; ++r) {
        for (int i = 0; i < n; ++i) {
            int j = shifts[r][i];
            shifts[r + 1][i] = shifts[r][j];
        }
    }

    vector<vector<int> > vct(n);
    for (int i = 0; i < n; ++i) {
        int to = getShift(i, num);
        vct[to].pb(i);
    }

    vector<int> place(n, -1);
    for (int i = 0; i < n; ++i) {
        if (a[i] < n) {
            place[a[i]] = i;
        }
    }

    set<int> extra;
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        int v = place[i];
        //cout << i << " " << v << endl;
        if (v == -1) {
            ans[*extra.begin()] = i;
            extra.erase(extra.begin());
            continue;
        }
        ans[vct[v][0]] = i;
        for (int j = 1; j < sz(vct[v]); ++j) {
            extra.insert(vct[v][j]);
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] + 1 << " ";
    }
    cout << "\n";

}