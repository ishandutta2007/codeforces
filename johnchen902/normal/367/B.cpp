#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int a[200000];

int main() {
    int n, m, p;
    scanf("%d %d %d", &n, &m, &p);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);

    map<int, int> b;
    for (int j = 0; j < m; j++) {
        int x;
        scanf("%d", &x);
        b[x]++;
    }

    vector<int> ans;
    for (int i = 0; i < p; i++) {
        if (i + (m - 1LL) * p >= n)
            break;

        map<int, int> b2 = b;
        for (int j = i; j < n; j += p) {
            if (--b2[a[j]] == 0)
                b2.erase(a[j]);
            int fst = j - (m - 1) * p;
            if (fst >= 0) {
                if (b2.empty())
                    ans.push_back(fst);
                if (++b2[a[fst]] == 0)
                    b2.erase(a[fst]);
            }
        }
    }

    sort(ans.begin(), ans.end());

    int nans = ans.size();
    printf("%d\n", nans);
    for (int i = 0; i < nans; i++)
        printf("%d%c", ans[i] + 1, i == nans - 1 ? '\n' : ' ');
}