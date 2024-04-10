#include <cstdio>
#include <bitset>
using namespace std;
char s[100001];
int main() {
    int n;
    scanf("%d", &n);

    bitset<26> mask;
    mask.set();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        char t[2];
        scanf("%s %s", t, s);

        // printf("%d\n", (int) mask.count());

        if (*t == '!' || (*t == '?' && i < n - 1))
            if (mask.count() == 1)
                ans++;

        if (*t == '!') {
            bitset<26> mask2;
            mask2.reset();
            for (int j = 0; s[j]; j++)
                mask2[s[j] - 'a'] = true;
            mask &= mask2;
        } else {
            for (int j = 0; s[j]; j++)
                mask[s[j] - 'a'] = false;
        }
    }
    printf("%d\n", ans);
}