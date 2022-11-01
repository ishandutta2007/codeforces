#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int l[300005];
int d[300005];
int n, m, q;

vector<int> adj[300005];

int gl(int i) {
    return l[i]==i?i:l[i]=gl(l[i]);
}

int seen[300005];
int dst[300005];
int S;

int gf(int i) {
    S++;
    queue<int> q;
    q.push(i);
    seen[i] = S; dst[i] = 0;
    int f;
    while (!q.empty()) {
        f = q.front(); q.pop();
        FO(j,0,sz(adj[f])) if (seen[adj[f][j]] != S) {
            seen[adj[f][j]] = S;
            dst[adj[f][j]] = dst[f]+1;
            q.push(adj[f][j]);
        }
    }
    return f;
}

void fd(int i) {
    d[i] = dst[gf(gf(i))];
}

int main() {
    scanf("%d %d %d", &n, &m, &q);
    FO(i,0,n) {
        l[i] = i;
        d[i] = -1;
    }
    FO(i,0,m) {
        int a, b;
        scanf("%d %d", &a, &b); a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        l[gl(a)] = gl(b);
    }
    FO(i,0,n) if (d[gl(i)] == -1) fd(gl(i));
    FO(i,0,q) {
        int t, a, b;
        scanf("%d %d", &t, &a);
        if (t == 1) printf("%d\n", d[gl(a-1)]);
        else {
            scanf("%d", &b); a--; b--;
            a = gl(a); b = gl(b);
            if (a != b) {
                d[a] = max(d[a],max(d[b],(d[a]+1)/2 + 1 + (d[b]+1)/2));
                l[b] = a;
            }
        }
    }
}