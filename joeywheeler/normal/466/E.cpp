#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n, m;
int l[100005];
vector<int> adj[100005];

int gl(int i) {
    return i == l[i] ? i : l[i]=gl(l[i]);
}

int qnd[100005], qdoc[100005];
int docs[100005], doce[100005];

int rs[100005], re[100005];
int cv;

void dfs(int i) {
    rs[i] = ++cv;
    FO(j,0,sz(adj[i])) dfs(adj[i][j]);
    re[i] = cv;
}

bool isp(int p, int c) {
    return rs[p] <= rs[c] && re[c] <= re[p];
}

int main() {
    scanf("%d %d", &n, &m);
    FO(i,1,n+1) l[i] = i;
    int nd = 0;
    FO(i,0,m) {
        int t; scanf("%d", &t);
        qnd[i] = -1;
        if (t == 1) {
            int x, y; scanf("%d %d", &x, &y);
            l[x] = y;
            adj[y].push_back(x);
        } else if (t == 2) {
            int x; scanf("%d", &x);
            docs[++nd] = x;
            doce[nd] = gl(x);
        } else {
            int x, y; scanf("%d %d", &x, &y);
            qnd[i] = x; qdoc[i] = y;
        }
    }
    FO(i,1,n+1) if (gl(i) == i) dfs(i);
    FO(i,0,m) if (qnd[i] != -1) {
        int ql = docs[qdoc[i]];
        int qu = doce[qdoc[i]];
        int qv = qnd[i];
        // qv lie on ql->qu?
        if (isp(qv,ql) && isp(qu,qv)) printf("YES\n");
        else printf("NO\n");
    }
}