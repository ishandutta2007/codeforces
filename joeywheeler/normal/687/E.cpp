#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n, m;
vector<int> u[5005];
int d[5005][5005];
int q[5005], qs, qe;
int l[5005], o[5005];

int main() {
    scanf("%d %d", &n, &m);
    FO(z,0,m) {
        int x, y; scanf("%d %d", &x, &y);
        u[x-1].push_back(y-1);
    }
    FO(i,0,n) {
        FO(j,0,n) d[i][j] = 1e6;
        qs = qe = 0;
        q[qe++] = i;
        d[i][i] = 0;
        while (qs != qe) {
            int f = q[qs++];
            for (int j : u[f]) if (d[i][j] > 1e5) {
                d[i][j] = d[i][f]+1;
                q[qe++] = j;
            }
        }
    }
    FO(i,0,n) FO(j,0,i+1) if (d[i][j]+d[j][i] < 1e5) {
        l[i] = j;
        break;
    }
    FO(i,0,n) o[l[i]] = 1e6;
    FO(i,0,n) FO(j,0,n) if (i != j && d[i][j] < 1e5) {
        if (l[i] != l[j]) o[l[i]] = -1;
        else o[l[i]] = min(o[l[i]],
                d[i][j]+d[j][i]);
    }
    FO(i,0,n) if (o[l[i]] > 1e5) o[l[i]] = -1;
    int res = n;
    FO(i,0,n) if (i == l[i] && o[i] != -1) {
        res += 998 * o[i] + 1;
    }
    printf("%d\n", res);
}