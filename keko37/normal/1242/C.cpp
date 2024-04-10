#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXK = 17;
const int MAXN = 5005;

llint k, tot, cnt;
llint sum[MAXK], bt[MAXK * MAXN];
vector <int> v[MAXK];
map <llint, int> box, par, bio;
vector <int> c[MAXK * MAXN];
int dp[1 << MAXK], ind[1 << MAXK], doso[1 << MAXK];
pair <int, int> sol[MAXK];

void gen_graph () {
    for (int i = 0; i < k; i++) {
        for (auto x : v[i]) {
            llint val = tot - sum[i] + x;
            if (box.find(val) == box.end()) continue;
            par[x] = val;
        }
    }
}

void cyc (int x) {
    cnt++;
    int poc = x, mask = 0;
    do {
        int col = box[x];
        if (mask & (1 << col)) {
            c[cnt].clear(); cnt--;
            return;
        }
        mask |= (1 << col);
        c[cnt].push_back(x);
        x = par[x];
    } while (x != poc);
    bt[cnt] = mask;
    ind[mask] = cnt;
}

void dfs (int x) {
    bio[x] = 1;
    if (par.find(x) != par.end()) {
        int sus = par[x];
        if (bio[sus] == 0) {
            dfs(sus);
        } else if (bio[sus] == 1) {
            cyc(sus);
        }
    }
    bio[x] = 2;
}

void gen_cyc () {
    for (auto it : box) {
        int x = it.first;
        if (bio[x] == 0) dfs(x);
    }
}

void calc () {
    dp[0] = 1;
    for (int mask = 1; mask < (1 << k); mask++) {
        int b = 0;
        do {
            if (ind[b] > 0 && dp[mask ^ b]) {
                dp[mask] = 1;
                doso[mask] = b;
                break;
            }
        } while (b = (b - mask) & mask);
    }
}

void ispis () {
    if (dp[(1 << k) - 1] == 0) {
        cout << "No\n";
        return;
    }
    int curr = (1 << k) - 1;
    while (curr > 0) {
        int b = doso[curr];
        int r = ind[b];
        for (int i = 0; i < c[r].size(); i++) {
            int prv = c[r][i == 0 ? c[r].size() - 1 : i - 1];
            sol[box[c[r][i]]] = {c[r][i], box[prv] + 1};
        }
        curr ^= b;
    }
    cout << "Yes\n";
    for (int i = 0; i < k; i++) {
        cout << sol[i].first << " " << sol[i].second << '\n';
    }
}

int main () {
    cin >> k;
    for (int i = 0; i < k; i++) {
        int n; cin >> n;
        for (int j = 0; j < n; j++) {
            int x; cin >> x;
            v[i].push_back(x);
            sum[i] += x;
            box[x] = i;
        }
        tot += sum[i];
    }
    if (tot % k != 0) {
        cout << "No\n";
        return 0;
    }
    tot /= k;
    gen_graph();
    gen_cyc();
    calc();
    ispis();
    return 0;
}