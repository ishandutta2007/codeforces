#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

const int N = 100005;

int n, m;
char name[20];

struct SB {
    string name;
    int val;
    bool operator < (const SB& c) const {
        return val > c.val;
    }
};

vector<SB> g[N];

int main() {
    scanf("%d%d", &n, &m);
    int a, b;
    for (int i = 1; i <= n; i++) {
        scanf("%s%d%d", name, &a, &b);
        SB tmp;
        tmp.name = name;
        tmp.val = b;
        g[a].push_back(tmp);
    }
    for (int i = 1; i <= m; i++) {
        sort(g[i].begin(), g[i].end());
        if (g[i].size() == 2) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < g[i][j].name.length(); k++) {
                    printf("%c", g[i][j].name[k]);
                }
                if (j == 0) printf(" ");
                else printf("\n");
            }
        } else {
            if (g[i][1].val != g[i][2].val) {
                for (int j = 0; j < 2; j++) {
                    for (int k = 0; k < g[i][j].name.length(); k++)
                        printf("%c", g[i][j].name[k]);
                      if (j == 0) printf(" ");
                        else printf("\n");
                }
            } else printf("?\n");
        }
    }
    return 0;
}