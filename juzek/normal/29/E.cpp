#include <cstdio>
#include <queue>

struct V {
    int a, b;
    int wybor;
};

std::vector<int> v[507];
V prev[507][507][2];
int odl[507][507][2];
bool odw[507][507][2];
std::queue<V> Q;
int wynik[1000007][2];

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    int a, b;
    for (int i = 0; i < M; i++) {
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    Q.push({1, N, 0});
    odw[1][N][0] = true;
    while (!Q.empty()) {
        V ter = Q.front();
        Q.pop();
        if (ter.a == N && ter.b == 1 && ter.wybor == 0)
            break;
        if (ter.a == ter.b && ter.wybor == 0)
            continue;
        a = ter.a, b = ter.b;
        if (ter.wybor == 0) {
            for (auto it : v[a]) {
                if (!odw[it][b][1]) {
                    odw[it][b][1] = true;
                    odl[it][b][1] = odl[ter.a][ter.b][ter.wybor] + 1;
                    prev[it][b][1] = ter;
                    Q.push({it, b, 1});
                }
            }
        } else {
            for (auto it : v[b]) {
                if (!odw[a][it][0]) {
                    odw[a][it][0] = true;
                    odl[a][it][0] = odl[ter.a][ter.b][ter.wybor] + 1;
                    prev[a][it][0] = ter;
                    Q.push({a, it, 0});
                }
            }
        }
    }
    if (odl[N][1][0] == 0) {
        printf("-1");
        return 0;
    }
    int wyn = odl[N][1][0] / 2;
    auto ter = V{N, 1, 0};
    wynik[wyn][1] = 1;
    while (ter.a != 0) {
        wynik[odl[ter.a][ter.b][ter.wybor] / 2][ter.wybor] = ter.wybor ? ter.b : ter.a;
        ter = prev[ter.a][ter.b][ter.wybor];
    }
    printf("%d\n", wyn);
    for (int i = 0; i <= wyn; i++)
        printf("%d ", wynik[i][0]);
    printf("\n");
    for (int i = 0; i <= wyn; i++)
        printf("%d ", wynik[i][1]);
    printf("\n");
    return 0;
}