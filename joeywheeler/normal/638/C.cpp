#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n;
vector<int> u[200005];
int col[200005];
map<pair<int,int>, int> ei;
vector<int> sols[200005];
int mcol;

void go(int i, int p, int pc) {
    if (p) {
        // col i-p with pc
        col[ei[make_pair(i,p)]] = pc;
    }
    int cur = 0;
    for (int j : u[i]) if (j != p) {
        if (cur == pc) cur++;
        go(j, i, cur);
        cur++;
    }
}

int main() {
    scanf("%d", &n);
    FO(i,0,n-1) {
        int x, y; scanf("%d%d", &x, &y);
        u[x].push_back(y);
        u[y].push_back(x);
        ei[make_pair(x,y)] = i;
        ei[make_pair(y,x)] = i;
    }
    go(1,0,-1);

    FO(i,0,n-1) {
        mcol = max(mcol, col[i]);
        sols[col[i]].push_back(i+1);
    }
    printf("%d\n", mcol+1);
    FO(i,0,mcol+1) {
        printf("%d", sz(sols[i]));
        for (int j : sols[i]) printf(" %d", j);
        printf("\n");
    }
}