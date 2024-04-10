#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> adjr[200000];
vector<int> adjc[200000];

bool visr[200000], visc[200000];

void dfsr(int);
void dfsc(int);

void dfsr(int r) {
    visr[r] = true;
    for (int c : adjr[r])
        if (!visc[c])
            dfsc(c);
}
void dfsc(int c) {
    visc[c] = true;
    for (int r : adjc[c])
        if (!visr[r])
            dfsr(r);
}

int main() {
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < q; i++) {
        int r, c;
        scanf("%d%d", &r, &c);
        r--, c--;
        adjr[r].push_back(c);
        adjc[c].push_back(r);
    }

    int comp = 0;

    for (int i = 0; i < n; i++)
        if (!adjr[i].empty() && !visr[i]) {
            comp++;
            dfsr(i);
        }

    int ans = count(visr, visr + n, false) +
        count(visc, visc + m, false) + comp - 1;

    printf("%d\n", ans);
}