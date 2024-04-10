#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <map>
#include <set>

#define fo(i,a,b) for (int i=(a); i<(b); i++)
#define sz(v) int(v.size())
#define mp make_pair

using namespace std;

vector<int> u[100005];
vector<int> ru[100005];
vector<int> nds;
bool sn[100005];
int cmp[100005];
int ci;

void go(int i) {
    if (sn[i]) return;
    sn[i] = true;
    fo(j,0,sz(u[i])) go(u[i][j]);
    nds.push_back(i);
}

void gor(int i) {
    cmp[i] = ci;
    fo(j,0,sz(ru[i])) if (cmp[ru[i][j]] == 0) gor(ru[i][j]);
}

bool bd[100005];
int op[100005];
int siz[100005];

int main() {
    int n, m, h;
    scanf("%d %d %d", &n, &m, &h);
    fo(i,0,n) scanf("%d", op+i);
    fo(i,0,m) {
        int x, y; scanf("%d %d", &x, &y); x--; y--;
        if ((op[x]+1) % h == op[y]) {
            u[y].push_back(x);
            ru[x].push_back(y);
        }
        swap(x,y);
        if ((op[x]+1) % h == op[y]) {
            u[y].push_back(x);
            ru[x].push_back(y);
        }
    }
    fo(i,0,n) go(i);
    fo(i,0,n) if (cmp[nds[n-1-i]] == 0) ++ci, gor(nds[n-1-i]);
    fo(i,0,n) fo(j,0,sz(u[i])) if (cmp[i] != cmp[u[i][j]]) bd[cmp[u[i][j]]] = true;
    fo(i,0,n) siz[cmp[i]]++;
    int ans = n;
    fo(i,1,ci+1) if (!bd[i]) {
        ans = min(ans, siz[i]);
    }
    fo(i,1,ci+1) if (!bd[i] && ans == siz[i]) {
        printf("%d\n", ans);
        fo(j,0,n) if (cmp[j] == i) {
            printf("%d ", j+1);
        }
        printf("\n");
        return 0;
    }
}