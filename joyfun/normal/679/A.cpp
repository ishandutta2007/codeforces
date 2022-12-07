#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int prime[105], vis[105], pn;
char op[15];

int main() {
    vis[0] = vis[1] = 1;
    for (int i = 2; i < 105; i++) {
        if (vis[i]) continue;
        prime[pn++] = i;
        for (int j = i * i; j < 105; j += i) {
            vis[j] = 1;
        }
    }
   // for (int n = 2; n <= 100; n++) {
    int cnt = 0;
    int sb;
    for (int i = 0; i < 19; i++) {
        printf("%d\n", prime[i]);
        fflush(stdout);
        scanf("%s", op);
        if (op[0] == 'y') {
            cnt++;
            sb = prime[i];
        }
        //if (n % prime[i] == 0) {
          //  cnt++;
            //sb = prime[i];
        //}
    }
    if (cnt == 1) {
        if (sb * sb <= 100) {
            printf("%d\n", sb * sb);
            fflush(stdout);
            scanf("%s", op);
            if (op[0] == 'y') {
                cnt++;
            }
            //if (n % (sb * sb) == 0) cnt++;
        }
    }
   // int ca = cnt > 1 ? 1 : 0;
   // if (ca != vis[n]) {
     //   printf("%d %d\n", cnt, n);
    //}
    printf("%s\n", cnt > 1 ? "composite" : "prime");
    fflush(stdout);
//}
    return 0;
}