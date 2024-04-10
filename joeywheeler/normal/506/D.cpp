#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

#define RT 340
#define NN 100005

using namespace std;

struct Graph {
    int p[NN];
    int n;

    void init(int _n) {
        n = _n;
        FO(i,0,n) p[i] = i;
    }

    int gl(int x) {
        return x == p[x] ? x : p[x] = gl(p[x]);
    }

    void addedge(int x, int y) {
        x = gl(x); y = gl(y);
        p[x] = y;
    }

    bool connected(int x, int y) {
        return gl(x) == gl(y);
    }
};

vector<pair<int,int> > edges[NN];
int n, m;
unordered_map<int,int> qv[NN];
int qa[NN], qb[NN], qr[NN];

Graph tmp;

int main() {
    scanf("%d %d", &n, &m);
    FO(i,0,m) {
        int a, b, c; scanf("%d%d%d", &a, &b, &c); a--; b--; c--;
        edges[c].emplace_back(a,b);
    }
    int q; scanf("%d", &q);
    FO(i,0,q) {
        scanf("%d %d", qa+i, qb+i);
        qa[i]--; qb[i]--;
        qv[qa[i]][qb[i]] = 0;
    }
    FO(i,0,m) if (sz(edges[i]) >= RT) {
        tmp.init(n);
        for (auto x : edges[i]) {
            int a,b;
            tie(a,b) = x;
            tmp.addedge(a,b);
        }
        FO(j,0,q) if (tmp.connected(qa[j],qb[j])) qr[j]++;
    } else {
        vector<int> nd;
        for (auto x : edges[i]) {
            int a,b;
            tie(a,b) = x;
            nd.push_back(a);
            nd.push_back(b);
            tmp.p[a] = a;
            tmp.p[b] = b;
        }
        sort(nd.begin(),nd.end());
        nd.resize(unique(nd.begin(),nd.end())-nd.begin());
        tmp.init(sz(nd));
        for (auto x : edges[i]) {
            int a,b;
            tie(a,b) = x;
            tmp.addedge(a,b);
        }
        for (int a : nd) for (int b : nd) if (a != b) {
            if (tmp.connected(a,b)) {
                auto it = qv[a].find(b);
                if (it != qv[a].end()) it->second++;
            }
        }
    }
    FO(i,0,q) {
        printf("%d\n", qv[qa[i]][qb[i]] + qr[i]);
    }
}