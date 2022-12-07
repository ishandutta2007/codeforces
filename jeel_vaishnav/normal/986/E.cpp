#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define ll long long

const int N = 100000;
const int MAX = 1e7 + 1;
const ll mod = 1e9 + 7;

class Query {
public:
    int u, v, x, lca, ind;
};

int sieve[MAX], depth[N], parent[N][17], a[N], invP[664579], pos[MAX];
vector<int> adj[N], req[N], primes;
Query query[N];
map<int, ll> ans[N];
ll cans[664579][25];

ll fast_pow(ll a, ll b) {
    if(b == 0)
        return 1LL;
    ll val = fast_pow(a, b / 2LL);
    if(b % 2 == 0)
        return val * val % mod;
    else
        return val * val % mod * a % mod;
}

void preprocessSieve() {
    for(int i = 0; i < MAX; ++i)
        sieve[i] = 0;
    for(int i = 2; i < MAX; ++i) {
        if(sieve[i] == 0) {
            pos[i] = primes.size();
            primes.pb(i);
            for(int j = i; j < MAX; j += i) {
                sieve[j] = i;
            }
        }
    }
}

void dfsFindParentAndDepth(int i, int par, int curDepth) {
    parent[i][0] = par;
    depth[i] = curDepth;
    for(int j : adj[i]) {
        if(j != par) {
            dfsFindParentAndDepth(j, i, curDepth + 1);
        }
    }
}

void computeParents(int n) {
    for(int j = 1; j < 17; ++j) {
        for(int i = 0; i < n; ++i) {
            if(parent[i][j - 1] != -1) {
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
            }
            else
                parent[i][j] = -1;
        }
    }
}

int walk(int u, int dist) {
    for(int i = 16; i >= 0; --i) {
        if(dist >= (1 << i)) {
            u = parent[u][i];
            dist -= (1 << i);
        }
    }
    return u;
}

int findLCA(int u, int v) {
    if(depth[u] > depth[v])
        return findLCA(walk(u, depth[u] - depth[v]), v);
    if(depth[v] > depth[u])
        return findLCA(u, walk(v, depth[v] - depth[u]));

    if(u == v) {
        return u;
    }

    for(int i = 16; i >= 0; --i) {
        if(parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }

    return parent[u][0];
}

void dfsCompleteRequests(int i, int par) {
    int temp = a[i];
    while(temp != 1) {
        ll curPrime = sieve[temp];
        int cnt = 0;
        while(temp % curPrime == 0) {
            cans[pos[curPrime]][cnt] = 1LL * cans[pos[curPrime]][cnt] * curPrime % mod;
            cnt++;
            temp /= curPrime;
        } 
    }

    for(auto pair : ans[i]) {
        temp = pair.first;
        ll ccans = 1LL;
        while(temp != 1) {
            ll curPrime = sieve[temp];
            int cnt = 0;
            while(temp % curPrime == 0) {
                ccans = 1LL * cans[pos[curPrime]][cnt] * ccans % mod;
                cnt++;
                temp /= curPrime;
            } 
        }
        ans[i][pair.first] = ccans;
    }

    for(int j : adj[i]) {
        if(j != par) 
            dfsCompleteRequests(j, i);
    }

    temp = a[i];
    while(temp != 1) {
        ll curPrime = sieve[temp];
        int cnt = 0;
        while(temp % curPrime == 0) {
            cans[pos[curPrime]][cnt] = 1LL * cans[pos[curPrime]][cnt] * invP[pos[curPrime]] % mod;
            cnt++;
            temp /= curPrime;
        } 
    }
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    // cerr.tie(0);

    preprocessSieve();

    for(int i = 0; i < 664579; ++i) {
        invP[i] = fast_pow(primes[i], mod - 2);
    }

    int n;
    cin >> n;

    for(int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    for(int i = 0; i < n; ++i)
        cin >> a[i];

    dfsFindParentAndDepth(0, -1, 0);
    computeParents(n);

    int q;
    cin >> q;

    for(int i = 0; i < q; ++i) {
        cin >> query[i].u >> query[i].v >> query[i].x;
        query[i].u--;
        query[i].v--;
        query[i].lca = findLCA(query[i].u, query[i].v);
        ans[query[i].u][query[i].x] = 0;
        ans[query[i].v][query[i].x] = 0;
        ans[query[i].lca][query[i].x] = 0;
    }

    for(int i = 0; i < 664579; ++i)
        for(int j = 0; j < 25; ++j)
            cans[i][j] = 1LL;

    dfsCompleteRequests(0, -1);

    for(int i = 0; i < q; ++i) {
        int u = query[i].u, v = query[i].v, lca = query[i].lca, x = query[i].x;
        ll fans = __gcd(a[lca], x);
        fans = fans * ans[u][x] % mod * ans[v][x] % mod;
        fans = fans * fast_pow(1LL * ans[lca][x] * ans[lca][x] % mod, mod - 2) % mod;
        cout << fans << "\n";
    }

    return 0;
}