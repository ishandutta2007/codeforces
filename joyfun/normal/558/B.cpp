#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1000005;

int a;
int l[N], r[N], cnt[N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i < N; i++) {
        l[i] = n + 1;
        r[i] = 0;
    }
    int Max = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a);
        cnt[a]++;
        l[a] = min(l[a], i);
        r[a] = max(r[a], i);
        Max = max(cnt[a], Max);
    }
    int Min = n + 1;
    int ansl, ansr;
    for (int i = 1; i < N; i++){
        if (l[i] > r[i]) continue;
        if (cnt[i] == Max) {
            if (Min > r[i] - l[i] + 1) {
                Min = r[i] - l[i] + 1;
                ansl = l[i];
                ansr = r[i];
            }
        }
    }
    printf("%d %d\n", ansl, ansr);
    return 0;
}