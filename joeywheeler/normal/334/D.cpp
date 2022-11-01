#include <cstdio>
#include <vector>

#ifdef DEBUG
#define D(x...) fprintf(stderr, x)
#else
#define D(x...)
#endif

#define FO(i,a,b) for (int i = (a); i < (b); i++)

using namespace std;

int n, m;

vector<int> adj[10000];
bool bx[10000], by[10000];

int xval[10000];
int yval[10000];

int gi(int x, int y) {
    if (x == 0) return y;
    if (y == 0) return n+x;
    if (x == n-1) return 2*n+y;
    if (y == n-1) return 3*n+x;
}

int gni(int x, int y) {
    return gi(y, x);
}

bool seen[10000];
int taken[10000];

int f(int curr) {
    if (taken[curr] != 0) return 0;

    bool can_take = true;
    if (bx[xval[curr]] || by[yval[curr]]) can_take = false;
    D("(%d,%d)\n", xval[curr], yval[curr]);
    D("can_take = %d\n", can_take);
    FO(i,0,adj[curr].size()) if (taken[adj[curr][i]] == 1) can_take = false;


    int res = 0;
    int tr = 0;


    taken[curr] = -1;
    FO(i,0,adj[curr].size()) {
        res = max(res, f(adj[curr][i]));
    }

    if (can_take) {
        taken[curr] = 1;
        FO(i,0,adj[curr].size()) {
            res = max(res, 1+f(adj[curr][i]));
        }
    }

    taken[curr] = 0;

    return res;
}

void dfs(int curr) {
    if (seen[curr]) return;
    seen[curr] = true;
    FO(i,0,adj[curr].size()) {
        dfs(adj[curr][i]);
    }
}

int find_unblocked(int curr) {
    if (seen[curr]) return 0;
    int res = f(curr);
    dfs(curr);
    return res;
}

int main() {
    scanf("%d %d", &n, &m);

    FO(i,0,m) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (x != 1 && x != n)
            bx[x-1] = true;
        if (y != 1 && y != n)
            by[y-1] = true;
    }

    FO(i,1,n-1) {
        xval[gi(0,i)] = 0;
        yval[gi(0,i)] = i;
        xval[gi(n-1,i)] = n-1;
        yval[gi(n-1,i)] = i;

        xval[gi(i,0)] = i;
        yval[gi(i,0)] = 0;
        xval[gi(i,n-1)] = i;
        yval[gi(i,n-1)] = n-1;

        adj[gi(0,i)].push_back(gi(n-1,i));

        adj[gi(0,i)].push_back(gi(i,0));
        adj[gi(0,i)].push_back(gi(n-i-1,n-1));
    }

    FO(i,1,n-1) {
        adj[gi(n-1,i)].push_back(gi(0,i));

        adj[gi(n-1,i)].push_back(gi(i,n-1));
        adj[gi(n-1,i)].push_back(gi(n-i-1,0));
    }

    FO(i,1,n-1) {
        adj[gni(0,i)].push_back(gni(n-1,i));

        adj[gni(0,i)].push_back(gni(i,0));
        adj[gni(0,i)].push_back(gni(n-i-1,n-1));
    }

    FO(i,1,n-1) {
        adj[gni(n-1,i)].push_back(gni(0,i));

        adj[gni(n-1,i)].push_back(gni(i,n-1));
        adj[gni(n-1,i)].push_back(gni(n-i-1,0));
    }

    int res = 0;
    FO(i,1,n-1) {
        res += find_unblocked(gi(0,i));
        res += find_unblocked(gi(n-1,i));

        res += find_unblocked(gi(i,0));
        res += find_unblocked(gi(i,n-1));
    }

    printf("%d\n", res);

    return 0;
}