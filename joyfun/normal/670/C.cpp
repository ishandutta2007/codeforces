#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
map<int, int> cnt;

const int N = 200005;
int n, a;

pair<pair<int, int>, int> sb[N];
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &a);
        cnt[a]++;
    }
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &a);
        sb[i].first.first = cnt[a];
        sb[i].second = i;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &a);
        sb[i].first.second = cnt[a];
    }

    sort(sb, sb + m);
    printf("%d\n", sb[m - 1].second + 1);
    return 0;
}