#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n;
int p[100005];
bool s[100005];

vector<int> gc(int i) {
    vector<int> c;
    c.push_back(i);
    for (int j = p[i]; j != i; j = p[j]) c.push_back(j);
    for (int x : c) s[x] = 1;
    return c;
}

int main() {
    scanf("%d", &n);
    FO(i,1,n+1) scanf("%d", &p[i]);
    FO(i,1,n+1) if (p[i]==i) {
        printf("YES\n");
        FO(j,1,n+1) if (i != j) printf("%d %d\n", i, j);
        return 0;
    }
    vector<int> c2;
    FO(i,1,n+1) if (!s[i]) {
        auto cyc = gc(i);
        if (sz(cyc) == 2) c2 = cyc;
        else if (sz(cyc)&1) {
            printf("NO\n");
            return 0;
        }
    }
    memset(s,0,sizeof s);
    if (sz(c2) == 0) {
        printf("NO\n");
        return 0;
    }
    for (int x : c2) s[x] = 1;
    printf("YES\n");
    FO(i,1,n+1) if (!s[i]) {
        auto cyc = gc(i);
        FO(j,0,sz(cyc)) {
            if (j&1) printf("%d %d\n", c2[0], cyc[j]);
            else printf("%d %d\n", c2[1], cyc[j]);
        }
    }
    printf("%d %d\n", c2[0], c2[1]);
}