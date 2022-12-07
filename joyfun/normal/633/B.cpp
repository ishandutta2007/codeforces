#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int m;
vector<int> ans;

int main() {
    scanf("%d", &m);
    int cnt = 0;
    for (int i = 1; i <= 5 * (m + 1); i++) {
        int sb = i;
        while (sb % 5 == 0) {
            cnt++;
            sb /= 5;
        }
        if (cnt == m) ans.push_back(i);
        if (cnt > m) break;
    }
    int sz = ans.size();
    printf("%d\n", sz);
    for (int i = 0; i < sz; i++) printf("%d ", ans[i]);
    return 0;
}