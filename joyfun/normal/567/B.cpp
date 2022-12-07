#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int vis[1000005];

int main() {
    int n;
    scanf("%d", &n);
    int Max = 0;
    char op[2];
    int num;
    int in = 0;
    while (n--) {
        scanf("%s%d", op, &num);
        if (op[0] == '-') {
            if (vis[num] == 0) {
                 Max++;
            }
            else {
                vis[num] = 0;
                in--;
            }
        } else {
            vis[num] = 1;
            if (Max == in)
                Max++;
            in++;
        }
    }
    printf("%d\n", Max);
    return 0;
}