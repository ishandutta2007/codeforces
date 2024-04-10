#include <cstdio>
#include <utility>
using namespace std;

int check(pair<int, int> *a1, pair<int, int> *a2,
          pair<int, int> *b1, pair<int, int> *b2) {
    int ans = 10;
    for (auto a = a1; a != a2; a++)
        for (auto b = b1; b != b2; b++) {
            if (*a != *b) {
                int x;
                if (a->first == b->first || a->first == b->second)
                    x = a->first;
                else if (a->second == b->first || a->second == b->second)
                    x = a->second;
                else
                    continue;
                if (ans == 10)
                    ans = x;
                else if (ans != x)
                    return 0;
            }
        }
    return ans;
}

pair<int, int> a[12], b[12];

int solve(int n, int m) {
    if (int x = check(a, a + n, b, b + m))
        return x;
    for (int i = 0; i < n; i++)
        if (!check(a + i, a + i + 1, b, b + m))
            return -1;
    for (int i = 0; i < m; i++)
        if (!check(a, a + n, b + i, b + i + 1))
            return -1;
    return 0;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a[i].first, &a[i].second);
        if (a[i].first > a[i].second)
            swap(a[i].first, a[i].second);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &b[i].first, &b[i].second);
        if (b[i].first > b[i].second)
            swap(b[i].first, b[i].second);
    }
    printf("%d\n", solve(n, m));
}