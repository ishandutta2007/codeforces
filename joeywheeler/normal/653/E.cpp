#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

set<int> unseen;
set<int> uadj[300005];
int ci[300005], C;
int nin[300005];
int n, m, k;

void go(int i, int cn) {
    //printf("i=%d\n", i);
    ci[i] = cn;
    unseen.erase(unseen.find(i));
    int j = 0;
    while (1) {
        auto it = unseen.lower_bound(j+1);
        if (it == unseen.end()) break;
        j = *it;

        if (!uadj[i].count(j)) {
            go(j, cn);
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    FO(i,0,m) {
        int x, y; scanf("%d%d", &x, &y);
        uadj[x].insert(y);
        uadj[y].insert(x);
    }
    FO(i,2,n+1) unseen.insert(i);
    FO(i,2,n+1) if (ci[i] == 0) {
        go(i,++C);
    }
    FO(i,2,n+1) {
        //printf("ci[%d]=%d\n", i, ci[i]);
        if (!uadj[1].count(i)) nin[ci[i]]++;
    }
    int tsum = 0;
    FO(i,1,C+1) {
        tsum += nin[i];
        if (nin[i] == 0) {
            printf("impossible\n");
            return 0;
        }
    }
    if (C <= k && k <= tsum) {
        printf("possible\n");
    } else {
        printf("impossible\n");
    }
}