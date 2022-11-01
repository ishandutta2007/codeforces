#include <cstdio>
#include <algorithm>
using namespace std;
int p[200000], b[200000];
bool vis[200000];
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", p + i);
        p[i]--;
    }
    for(int i = 0; i < n; i++)
        scanf("%d", b + i);
    int cycles = 0;
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            cycles++;
            for(int j = i; !vis[j]; j = p[j])
                vis[j] = true;
        }
    }
    int ans = cycles == 1 ? 0 : cycles;
    if(count(b, b + n, 1) % 2 == 0)
        ans++;
    printf("%d\n", ans);
}