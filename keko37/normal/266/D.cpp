#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 505;
const llint INF = 1000000000000000000LL;

llint n, m, sol = INF, ea, eb, ec;
llint w[MAXN][MAXN], d[MAXN][MAXN];
llint bio[MAXN], dist[MAXN], par[MAXN];
vector <pi> v[MAXN];
vector <int> st;

void precompute () {
    for (int i = 1; i <= n; i++) {
        w[i][i] = d[i][i] = 0;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (d[i][k] + d[k][j] < d[i][j]) d[i][j] = d[i][k] + d[k][j];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            v[i].push_back({d[i][j], j});
        }
        sort(v[i].begin(), v[i].end());
    }
}

void calc (int a, int b) {
    st.clear();
    for (auto par : v[a]) {
        int h = d[b][par.second];
        while (!st.empty() && d[b][st.back()] <= h) st.pop_back();
        st.push_back(par.second);
    }
    for (int i = 1; i < st.size(); i++) {
        int jen = st[i], dva = st[i - 1];
        llint val = w[a][b] + d[b][jen] - d[a][dva];
        if (0 <= val && val <= w[a][b] * 2 && w[a][b] + d[b][jen] + d[a][dva] < sol) {
            sol = w[a][b] + d[b][jen] + d[a][dva];
            ea = a; eb = b; ec = w[a][b] + d[b][jen] - d[a][dva];
        }
    }
}

void ispis () {
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }
    dist[ea] = ec;
    if (eb != -1) dist[eb] = 2 * w[ea][eb] - ec;
    for (int i = 1; i <= n; i++) {
        llint mn = INF, ind;
        for (int j = 1; j <= n; j++) {
            if (bio[j] == 0 && dist[j] < mn) {
                mn = dist[j];
                ind = j;
            }
        }
        bio[ind] = 1;
        for (int j = 1; j <= n; j++) {
            if (bio[j] == 0 && dist[ind] + 2 * w[ind][j] < dist[j]) {
                par[j] = ind;
                dist[j] = dist[ind] + 2 * w[ind][j];
            }
        }
    }
    cout << fixed << setprecision(15) << (double) sol / 2;
    //cout << sol << '\n';
    /*if (eb != -1) cout << ea << " " << eb << '\n';
    for (int i = 1; i <= n; i++) {
        if (i != ea && i != eb) {
            cout << i << " " << par[i] << '\n';
        }
    }*/
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            w[i][j] = d[i][j] = INF;
        }
    }
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        w[a][b] = w[b][a] = c;
        d[a][b] = d[b][a] = c;
    }
    precompute();
    for (int i = 1; i <= n; i++) {
        if (v[i].back().first * 2 < sol) {
            sol = v[i].back().first * 2;
            ea = i; eb = -1; ec = 0;
        }
        for (int j = i + 1; j <= n; j++) {
            calc(i, j);
        }
    }
    ispis();
    return 0;
}