#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

int n, m;
set<int> s;
vector<int> ans;

int main() {
    int x;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        s.insert(x);
    }
    for (int i = 1; i <= 1000000000; i++) {
        if (s.find(i) != s.end()) continue;
        if (m < i) break;
        m -= i;
        ans.push_back(i);
    }
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
    printf("\n");
    return 0;
}