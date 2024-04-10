#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) (int) (a).size()
#define all(a) (a).begin(), (a).end()

using namespace std;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    map<int, vector<int> > Map;
    for (int i = 0; i < n; ++i) {
        int f;
        scanf("%d", &f);
        Map[f].pb(i + 1);
    }

    vector<int> ans(m);
    bool amb = false;
    for (int i = 0; i < m; ++i) {
        int b;
        scanf("%d", &b);
        if (!Map.count(b)) {
            printf("Impossible\n");
            return 0;
        }
        if (sz(Map[b]) > 1) {
            amb = true;
            continue;
            return 0;
        }
        ans[i] = Map[b][0];
    }
    if (amb) {
        printf("Ambiguity\n");
        return 0;
    }
    printf("Possible\n");
    for (int i = 0; i < m; ++i) {
        printf("%d ", ans[i]);
    }
}