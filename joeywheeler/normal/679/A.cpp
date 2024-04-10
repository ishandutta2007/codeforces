#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

bool pr[105];
char ans[20];

vector<int> p;

int main() {
    FO(i,2,105) pr[i] = true;
    int t = 0;
    FO(i,2,105) if (pr[i]) {
        p.push_back(i);
        for (int j = 2*i; j < 105; j += i) {
            pr[j] = false;
        }
    }
    set<int> s;
    for (int i : p) {
        if (i <= 50) s.insert(i);
        if (i*i <= 100) s.insert(i*i);
    }
    for (int i : p) {
        if (i <= 50) {
            printf("%d\n", i);
            fflush(stdout);
            scanf(" %s", ans);
            if (ans[0] == 'y') {
                t++;
            }
        }
        if (i*i <= 100) {
            printf("%d\n", i*i);
            fflush(stdout);
            scanf(" %s", ans);
            if (ans[0] == 'y') {
                printf("composite\n");
                return 0;
            }
        }
    }
    printf(t > 1 ? "composite\n" : "prime\n");
}