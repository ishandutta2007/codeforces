#include<cstdio>
#include<iostream>
using namespace std;
int a[1000101],v[1000101],b[1000010];
int main() {
    int n, T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int tmp=0,now;
        for (int i = 1;i <= n;i++) {
            scanf("%d", &a[i]);
            if (a[i] == 0&&!tmp) {
                printf("%d\n%d\n", 1, i);
                tmp = 1;
                // break;
            }
        }
        if (tmp)continue;
        for(now=1;!b[now];now=now-a[now]){
            v[++tmp] = now;
            b[now] = tmp;
        }
        bool flag = 0;
        printf("%d\n", tmp - b[now] + 1);
        for (int i = 1;i <= tmp;i++) {
            b[v[i]] = 0;
            if (v[i] == now)flag = 1;
            if (flag)printf("%d ", v[i]);
        }
        puts("");
    }
}