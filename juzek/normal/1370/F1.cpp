#include <bits/stdc++.h>

using namespace std;

const int maxn = 1007;

std::vector<int> v[maxn];

std::vector<int> odl[maxn];
int moj[maxn], mgl[maxn];

std::pair<int, int> pytaj(std::vector<int> x) {
    if (x.size() == 0)
        return {0, 1337133713};
    printf("? %d ", (int) x.size());
    for (auto it : x)
        printf("%d ", it);
    printf("\n");
    fflush(stdout);
    int a, b;
    scanf("%d%d", &a, &b);
    return {a, b};
}

char wtf[100];

void dfs(int a, int oj, int gl = 0) {
    odl[gl].push_back(a);
    moj[a] = oj;
    mgl[a] = gl;
    for (auto it : v[a])
        if (it != oj)
            dfs(it, a, gl + 1);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        std::vector<int> wszystkie = {1};
        for (int i = 2; i <= n; i++) {
            wszystkie.push_back(i);
            int a, b;
            scanf("%d%d", &a, &b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        auto p = pytaj(wszystkie);
        dfs(p.first, -1);
        int l = 0, r = n;
        int cooo = p.first;
        while (l != r - 1) {
            int s = (l + r) / 2;
            auto g = pytaj(odl[s]);
            if (g.second == p.second) {
                cooo = g.first;
                l = s;
            } else
                r = s;
        }
        int co = cooo;
        while (co != -1) {
            odl[mgl[co]].erase(find(odl[mgl[co]].begin(), odl[mgl[co]].end(), co));
            co = moj[co];
        }
        int drugi = p.second - mgl[cooo];
        if (drugi == 0)
            printf("! %d %d\n", p.first, cooo);
        else
            printf("! %d %d\n", pytaj(odl[drugi]).first, cooo);
        for (auto &it : v)
            it.clear();
        for (auto &it : odl)
            it.clear();
        fflush(stdout);
        scanf(" %s", wtf);
        if (wtf[0] != 'C')
            break;
    }
    return 0;
}