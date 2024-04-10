#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n;
int v[305];
char adj[305][305];

bool seen[305];
vector<int> u,w;

void dfs(int i) {
    if (seen[i]) return;
    seen[i] = 1;
    w.push_back(i);
    u.push_back(v[i]);
    FO(j,0,n) if (adj[i][j]=='1') dfs(j);
}

int main() {
    scanf("%d", &n);
    FO(i,0,n) scanf("%d", v+i);
    FO(i,0,n) FO(j,0,n) scanf(" %c ", &adj[i][j]);
    FO(i,0,n) if (!seen[i]) {
        dfs(i);
        sort(w.begin(),w.end());
        sort(u.begin(),u.end());
        FO(i,0,sz(w)) v[w[i]] = u[i];
        w.clear(); u.clear();
    }
    FO(i,0,n) printf("%d ", v[i]);
    printf("\n");
}