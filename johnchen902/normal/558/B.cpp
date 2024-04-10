#include <cstdio>
using namespace std;
int a[100000];
int cnt[1000001];
int min_loc[1000001];
int max_loc[1000001];
int main() {
    int n;
    scanf("%d", &n);
    int beauty = 0;
    for(int i = 0; i < n; i++) {
        scanf("%d", a + i);
        if(cnt[a[i]] == 0)
            min_loc[a[i]] = i;
        max_loc[a[i]] = i;
        cnt[a[i]]++;
        if(cnt[a[i]] > beauty)
            beauty = cnt[a[i]];
    }
    int length = n, l = 1, r = n;
    for(int i = 1; i <= 1000000; i++) {
        if(cnt[i] == beauty) {
            int len = max_loc[i] - min_loc[i] + 1;
            if(len < length) {
                length = len;
                l = min_loc[i] + 1;
                r = max_loc[i] + 1;
            }
        }
    }
    printf("%d %d\n", l, r);
}