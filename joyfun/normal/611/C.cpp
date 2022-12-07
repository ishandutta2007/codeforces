#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 505;

int h, w;
char g[N][N];
int ans[N][N];

struct Q {
    int l, r, id;
    Q() {}
    Q(int l, int r, int id){
        this->l =l;
        this->r = r;
        this->id =id;
    }
};

vector<Q> s1[2][N], s2[2][N];

int out[100005];

int main() {
    scanf("%d%d", &h, &w);
    for (int i = 1; i <= h; i++)
        scanf("%s", g[i] + 1);
    int q;
    int r1, c1, r2, c2;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
        s1[0][r1 - 1].push_back(Q(c1, c2, i));
        s1[1][r2].push_back(Q(c1, c2, i));
        s2[0][c1 - 1].push_back(Q(r1, r2, i));
        s2[1][c2].push_back(Q(r1, r2, i));
    }
    for (int i = 1; i <= h; i++) {
        for (int l = 1; l <= w; l++) {
            int cnt = 0, sum = 0;
            for (int r = l; r <= w; r++) {
                if (g[i][r] == '#') {
                    sum += max(0, cnt - 1);
                    cnt = 0;
                } else cnt++;
                ans[l][r] += sum + max(0, cnt - 1);
            }
        }
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < s1[j][i].size(); k++) {
                int id = s1[j][i][k].id;
                if (j) out[id] += ans[s1[j][i][k].l][s1[j][i][k].r];
                else out[id] -= ans[s1[j][i][k].l][s1[j][i][k].r];
            }
        }
    }
    memset(ans, 0, sizeof(ans));
    for (int i = 1; i <= w; i++) {
        for (int l = 1; l <= h; l++) {
            int cnt = 0, sum = 0;
            for (int r = l; r <= h; r++) {
                if (g[r][i] == '#') {
                    sum += max(0, cnt - 1);
                    cnt = 0;
                } else cnt++;
                ans[l][r] += sum + max(0, cnt - 1);
            }
        }
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < s2[j][i].size(); k++) {
                int id = s2[j][i][k].id;
                if (j) out[id] += ans[s2[j][i][k].l][s2[j][i][k].r];
                else out[id] -= ans[s2[j][i][k].l][s2[j][i][k].r];
            }
        }
    }
    for (int i = 0; i < q; i++) printf("%d\n", out[i]);
    return 0;
}