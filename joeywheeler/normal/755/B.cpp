#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n, m;
set<string> a, b;
char buf[505];

int main() {
    scanf("%d %d", &n, &m);
    FO(i,0,n) {
        scanf(" %s", buf);
        a.insert(buf);
    }
    int na = sz(a);
    int nb = 0;
    int nc = 0;
    FO(i,0,m) {
        scanf(" %s", buf);
        if (a.count(buf)) {
            nc++;
            na--;
        }
        else nb++;
        b.insert(buf);
    }

    int w = 0;
    while (1) {
        if (nc) nc--;
        else {
            if (w == 0) {
                if (na) na--;
                else {
                    printf("NO\n");
                    return 0;
                }
            } else {
                if (nb) nb--;
                else {
                    printf("YES\n");
                    return 0;
                }
            }
        }
        w = !w;
    }
}