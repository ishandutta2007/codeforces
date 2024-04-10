#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

set<int> prime;

void getf(int x) {
    for (int i = 2; i < 32000; i++) {
        if (x == 1) return;
        if (x%i == 0) {
            prime.insert(i);
            x /= i;
            while (x%i == 0) x /= i;
        }
    }
    if (x > 1) prime.insert(x);
}

int n, m;
int val[101];
vector<int> adj[101];

int tv[101];
int uses[101][101];
bool seen[101];

void buildg(int p) {
    FO(i,0,n) {
        tv[i] = 0;
        int cv = val[i];
        while (cv%p == 0) {
            tv[i]++;
            cv /= p;
        }
    }
    FO(i,0,n) FO(j,0,n) uses[i][j] = 0;
}

bool aug(int cur) {
    if (seen[cur]) return false;
    seen[cur] = true;
    if (cur%2 == 1 && tv[cur]) {
        tv[cur]--;
        return true;
    } else {
        if (cur%2 == 0) {
            FO(i,0,sz(adj[cur])) {
                int o = adj[cur][i];
                if (aug(o)) {
                    uses[cur][o]++;
                    uses[o][cur]++;
                    return true;
                }
            }
        } else {
            FO(i,0,sz(adj[cur])) {
                int o = adj[cur][i];
                if (uses[cur][o] && aug(o)) {
                    uses[cur][o]--;
                    uses[o][cur]--;
                    return true;
                }
            }
        }
    }
    return false;
}

int solve() {
    int res = 0;
rep:;
    memset(seen,false,sizeof seen);
    FO(i,0,n) if (i%2 == 0 && tv[i] && aug(i)) {
        tv[i]--;
        res++;
        goto rep;
    }
    return res;
}

int main() {
    scanf("%d %d", &n, &m);
    FO(i,0,n) {
        scanf("%d", val+i);
        getf(val[i]);
    }
    FO(i,0,m) {
        int a, b; scanf("%d %d", &a, &b); a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int res = 0;
    for (set<int>::iterator it=prime.begin(); it != prime.end(); it++) {
        int v = *it;
        //printf("GO WITH %d\n", v);
        buildg(v);
        res += solve();
    }
    printf("%d\n", res);
}