#include <bits/stdc++.h>
#define eprintf(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
using namespace std;
typedef long long ll;



int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif

    int n;
    while (scanf("%d", &n) == 1) {
        n++;
        vector<int> a(n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);

        int id = -1;
        for (int i = 1; i < n - 1; i++) {
            if (a[i] > 1 && a[i + 1] > 1) {
                id = i;
                break;
            }
        }

        if (id == -1) {
            printf("perfect\n");
            continue;
        }
        printf("ambiguous\n");
        int k = 0;
        for (int x : a) k += x;

        vector<int> pr1(k, -1), pr2(k, -1);
        int csum = 0;
        int cur = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < a[i]; j++) {
                pr1[cur++] = csum;
            }
            csum += a[i - 1];
        }

        csum = 0;
        cur = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < a[i]; j++) {
                pr2[cur++] = csum;
                if (i == id + 1 && j > 0) pr2[cur - 1]++;
            }
            csum += a[i - 1];
        }

        for (int i = 0; i < k; i++) printf("%d%c", pr1[i] + 1, " \n"[i + 1 == k]);
        for (int i = 0; i < k; i++) printf("%d%c", pr2[i] + 1, " \n"[i + 1 == k]);
    }

#ifdef HOME
    eprintf("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}