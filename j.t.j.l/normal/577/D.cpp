#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1E6 + 10;
int len[MAXN],a[MAXN],vis[MAXN];
int x;

int main(){
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        scanf("%d",&a[i]);
        vis[i] = 0;
    }
    for(int i = 1; i <= n; i++)
        if (!vis[i]){
            x = i;
            len[i] = 1;
            while(a[x] != i){
                vis[x] = 1;
                x = a[x];
                len[i]++;
            }
        }
    for(int i = 1; i <= n; i++)
        if (len[i] == 1){
            puts("YES");
            for(int j = 1; j <= n; j++)
                if (j!=i)
                    printf("%d %d\n", i, j);
            return 0;
        }
    for(int i = 1; i <= n; i++)
        if (len[i] == 2){
            int flag = 1;
            for(int j = 1; j <= n; j++)
                if (len[j]&1){
                    flag = 0;
                    break;
                }
            if (flag){
                puts("YES");
                printf("%d %d\n",i,a[i]);
                for(int j = 1; j <= n; j++)
                    vis[j] = 0;
                vis[i] = 1;
                vis[a[i]] = 1;
                for(int j = 1; j <= n; j++)
                    if (!vis[j]){
                        x = j;
                        do{
                            vis[x] = 1;
                            printf("%d %d\n", i, x);
                            x = a[x];
                            vis[x] = 1;
                            printf("%d %d\n", a[i], x);
                            x = a[x];
                        }while(x != j);
                    }
                return 0;
            }
        }
    puts("NO");
    return 0;
}