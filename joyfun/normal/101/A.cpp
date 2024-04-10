#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100005;
char str[N];
int k, cnt[26], id[26];

bool cmp(int a, int b) {
    return cnt[a] < cnt[b];
}

int main() {
    scanf("%s%d", str, &k);
    int len = strlen(str);
    for (int i = 0; i < 26; i++) id[i] = i;
    for (int i = 0; i < len; i++)
            cnt[str[i] - 'a']++;
    sort(id, id + 26, cmp);
    for (int i = 0; i < 26; i++) {
        int use = min(cnt[id[i]], k);
        cnt[id[i]] -= use;
        k -= use;
    }
    int ans = 0;
    for (int i = 0; i < 26; i++)
        if (cnt[i]) ans++;
    printf("%d\n", ans);
    for (int i = 0; i < len; i++) {
        if (cnt[str[i] - 'a']) {
            printf("%c", str[i]);
            cnt[str[i] - 'a']--;
        }
    }
    printf("\n");
    return 0;
}