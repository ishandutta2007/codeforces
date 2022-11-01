#include <cstdio>
#include <algorithm>
using namespace std;
int a[200000];
int vis[200000];
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", a + i), a[i]--;
    int root = -1;
    for(int i = 0; i < n; i++)
        if(i == a[i]) {
            root = i;
            break;
        }
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            int j = i;
            while(!vis[j]) {
                vis[j] = i + 1;
                j = a[j];
            }
            if(vis[j] == i + 1) {
                if(root == -1)
                    root = j;
                if(a[j] != root) {
                    a[j] = root;
                    count++;
                }
            }
        }
    }
    printf("%d\n", count);
    for(int i = 0; i < n; i++)
        printf("%d%c", a[i] + 1, i == n - 1 ? '\n' : ' ');
}