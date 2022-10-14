#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 100005;
const int LIM = 32;
const int SIZ = 380;
const int MOD = 1000000007;

int n, m, cnt, comp, prvi, prvi_edg, nula;
set <int> st;
queue <int> q;
map <int, int> mp;
int p[SIZ][SIZ], val[MAXN], bio[MAXN], r[MAXN], e[MAXN], dp[SIZ][MAXN];
vector <pi> v[MAXN];

int add (int a, int b) {a += b; if (a >= MOD) return a - MOD; return a;}

int spoji (int a, int b) {
    int mask = a | b;
    for (int i = 0; i < LIM; i++) {
        for (int j = 0; j < LIM; j++) {
            if ((a & (1 << i)) && (b & (1 << j))) mask |= 1 << (i ^ j);
        }
    }
    return mask;
}

void precompute () {
    for (auto a : st) mp[a] = ++cnt;
    for (auto a : st) {
        for (auto b : st) {
            int mask = spoji(a, b);
            if (mask % 2 == 1) p[mp[a]][mp[b]] = 0; else p[mp[a]][mp[b]] = mp[mask];
        }
    }
}

void bfs () {
    q.push(0); st.insert(0);
    while (!q.empty()) {
        int mask = q.front();
        q.pop();
        for (int i = 1; i < LIM; i++) {
            int sus = spoji(mask, 1 << i);
            if (st.find(sus) == st.end() && sus % 2 == 0) q.push(sus), st.insert(sus);
        }
    }
}

void dfs (int x, int rod) {
    bio[x] = 1;
    for (auto par : v[x]) {
        int sus = par.first, w = par.second;
        if (sus == 1) {
            if (x != prvi) e[comp] = mp[1 << (val[x] ^ w ^ prvi_edg)];
            continue;
        }
        if (sus == rod) continue;
        if (bio[sus] == 0) {
            val[sus] = val[x] ^ w;
            dfs(sus, x);
        } else if (bio[sus] == 1) {
            int cik = val[sus] ^ val[x] ^ w;
            //cout << "cik je " << cik << endl;
            r[comp] = p[r[comp]][mp[1 << cik]];
        }
    }
    bio[x] = 2;
}

void gen () {
    memset(r, -1, sizeof r);
    memset(e, -1, sizeof e);
    nula = mp[0];
    bio[1] = 2;
    for (auto par : v[1]) {
        int sus = par.first;
        if (!bio[sus]) {
            prvi = sus; prvi_edg = par.second;
            comp++;
            r[comp] = nula;
            dfs(sus, 1);
        }
    }
    for (int i = 1; i <= comp; i++) if (e[i] != -1) e[i] = p[r[i]][e[i]];
    //for (int i = 1; i <= comp; i++) cout << "bla " << i << "  " << r[i] << " " << e[i] << endl;
}

int calc (int curr, int pos) {
    if (pos > comp) {
        if (curr == 0) return 0; return 1;
    }
    if (dp[curr][pos] != -1) return dp[curr][pos];
    int res = calc(curr, pos + 1);
    res = add(res, calc(p[curr][r[pos]], pos + 1));
    if (e[pos] != -1) {
        res = add(res, calc(p[curr][r[pos]], pos + 1));
        res = add(res, calc(p[curr][e[pos]], pos + 1));
    }
    return dp[curr][pos] = res;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(dp, -1, sizeof dp);
    bfs();
    precompute();
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    gen();
    cout << calc(nula, 1);
    return 0;
}