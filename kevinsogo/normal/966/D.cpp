#include <bits/stdc++.h>
using namespace std;

#define fo(i,a,b) dfo(int,i,a,b)
#define fr(i,n) dfr(int,i,n)
#define fe(i,a,b) dfe(int,i,a,b)
#define fq(i,n) dfq(int,i,n)
#define nfo(i,a,b) dfo(,i,a,b)
#define nfr(i,n) dfr(,i,n)
#define nfe(i,a,b) dfe(,i,a,b)
#define nfq(i,n) dfq(,i,n)
#define dfo(d,i,a,b) for (d i = (a); i < (b); i++)
#define dfr(d,i,n) dfo(d,i,0,n)
#define dfe(d,i,a,b) for (d i = (a); i <= (b); i++)
#define dfq(d,i,n) dfe(d,i,1,n)
#define ffo(i,a,b) dffo(int,i,a,b)
#define ffr(i,n) dffr(int,i,n)
#define ffe(i,a,b) dffe(int,i,a,b)
#define ffq(i,n) dffq(int,i,n)
#define nffo(i,a,b) dffo(,i,a,b)
#define nffr(i,n) dffr(,i,n)
#define nffe(i,a,b) dffe(,i,a,b)
#define nffq(i,n) dffq(,i,n)
#define dffo(d,i,a,b) for (d i = (b)-1; i >= (a); i--)
#define dffr(d,i,n) dffo(d,i,0,n)
#define dffe(d,i,a,b) for (d i = (b); i >= (a); i--)
#define dffq(d,i,n) dffe(d,i,1,n)
#define pf printf
#define sf scanf
#define pln pf("\n")
#define flsh fflush(stdout)

typedef long long ll;

const int N = 311111;
const int E = 311111;
const ll INF = 1LL<<60;

pair<int,int> edges[E];
vector<int> adj[N];
ll dist[N];
int parent[N];
bool take[N];
int n;
void bfs(int s) {
    assert(take[s]);
    for (int i = 0; i < n; i++) {
        parent[i] = -1;
        dist[i] = INF;
    }
    vector<int> que;
    dist[s] = 0;
    parent[s] = s;
    que.push_back(s);
    for (int f = 0; f < que.size(); f++) {
        int i = que[f];
        for (int j : adj[i]) {
            if (take[j] && dist[j] >= INF) {
                dist[j] = dist[i] + 1;
                parent[j] = i;
                que.push_back(j);
            }
        }
    }
}


vector<int> anseq;
void try_cand(vector<int>& v) {
    if (anseq.empty() || anseq.size() > v.size()) {
        anseq = v;
    }
}

int gpar[N];
ll ges[N];
int gsize[N];
int find(int i) {
    return gpar[i] < 0 ? i : gpar[i] = find(gpar[i]);
}

void onion(int i, int j) {
    if ((i = find(i)) == (j = find(j))) return;
    if (gpar[i] == gpar[j]) gpar[j]--;
    if (gpar[i] > gpar[j]) {
        gpar[i] = j;
        ges[j] += ges[i];
        gsize[j] += gsize[i];
    } else {
        gpar[j] = i;
        ges[i] += ges[j];
        gsize[i] += gsize[j];
    }
}

int degs[N];

int main() {
    int e;
    sf("%d%d", &n, &e);
    for (int i = 0; i < n; i++) {
        adj[i].clear();
        gpar[i] = -1;
        ges[i] = 0;
        gsize[i] = 1;
        degs[i] = 0;
        take[i] = true;
    }
    for (int i = 0; i < e; i++) {
        int a, b;
        sf("%d%d", &a, &b);
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        edges[i] = {a, b};
    }
    int dest = n - 1;
    bfs(0);
    if (dist[dest] < INF) {
        vector<int> bfseq;
        for (int i = dest;; i = parent[i]) {
            bfseq.push_back(i);
            if (i == 0) break;
        }
        reverse(bfseq.begin(), bfseq.end());
        try_cand(bfseq);
    }

    bool found = false;
    for (int j = 1; j < n - 1; j++) {
        if (dist[j] == 2) {
            found = true;
            vector<int> staseq = {0, parent[j], j, 0, dest};
            try_cand(staseq);
            break;
        }
    }
    if (!found) {
        for (auto it: edges) {
            int a, b;
            tie(a, b) = it;
            if (a == 0 || a == dest || b == 0 || b == dest) continue;
            degs[a]++;
            degs[b]++;
            onion(a, b);
            ges[find(a)]++;
        }
        for (int i = 0; i < n; i++) {
            if (dist[i] != 1) continue;
            int p = find(i);
            ll sz = gsize[p];
            ll es = ges[p];
            assert(es <= sz * (sz - 1) / 2);
            if (es < sz * (sz - 1) / 2) {
                vector<int> grp;
                for (int j = 0; j < n; j++) {
                    if (take[j] = find(j) == p) {
                        grp.push_back(j);
                    }
                }
                assert(grp.size() == sz);

                bool ok = false;
                for (int j : grp) {
                    assert(degs[j] <= sz - 1);
                    if (degs[j] < sz - 1) {
                        bfs(j);
                        for (int k : grp) {
                            if (dist[k] == 2) {
                                ok = true;
                                vector<int> movseq = {0, j, parent[k], k, j, dest};
                                try_cand(movseq);
                                break;
                            }
                        }
                        break;
                    }
                }
                assert(ok);
                break;
            }
        }
    }

    if (anseq.empty()) {
        pf("-1\n");
    } else {
        pf("%d\n", int(anseq.size()) - 1);
        for (int i = 0; i < anseq.size(); i++) {
            pf("%d%c", anseq[i] + 1, " \n"[i == anseq.size() - 1]);
        }
    }
}