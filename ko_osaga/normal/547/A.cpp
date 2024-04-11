#include <cstdio>
#include <cstdlib>

int func1[1000005], func2[1000005];
int dep1[1000005], dep2[1000005];
bool vis[1000005], vis2[1000005];

int m;
int h1, a1, x1, y1;
int h2, a2, x2, y2;

void solve(){
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    // x1 = cycle length, y1 = first cycle insertion.
    vis[h1] = 1;
    while (1) {
        if (!vis[func1[h1]]) {
            vis[func1[h1]] = 1;
            dep1[func1[h1]] = dep1[h1] + 1;
            h1 = func1[h1];
        }
        else{
            if(!vis[a1]){
                puts("-1");
                exit(0);
            }
            y1 = dep1[a1];
            if(y1 < dep1[func1[h1]]){
                x1 = -1;
            }
            else x1 = dep1[h1] - dep1[func1[h1]] + 1;
            break;
        }
    }
    vis2[h2] = 1;
    while (1) {
        if (!vis2[func2[h2]]) {
            vis2[func2[h2]] = 1;
            dep2[func2[h2]] = dep2[h2] + 1;
            h2 = func2[h2];
        }
        else{
            if(!vis2[a2]){
                puts("-1");
                exit(0);
            }
            y2 = dep2[a2];
            if(y2 < dep2[func2[h2]]){
                x2 = -1;
            }
            else x2 = dep2[h2] - dep2[func2[h2]] + 1;
            break;
        }
    }
    if(x2 == -1 && x1 == -1){
        if(y1 == y2){
            printf("%d\n",y1);
            return;
        }
        else puts("-1");
        return;
    }
    if(x2 == -1){
        if(y1 % x1 == y2 % x1 && y2 >= y1) printf("%d",y2);
        else puts("-1");
        return;
    }
    if(x1 == -1){
        if(y2 % x2 == y1 % x2 && y1 >= y2) printf("%d",y1);
        else puts("-1");
        return;
    }
    for (int i=0; i <= 2000000; i++) {
        if(((1ll * x2 * i + y2 - y1) % x1) == 0 && (1ll * x2 * i + y2) >= y1){
            printf("%I64d\n",1ll * x2 * i + y2);
            return;
        }
    }
    puts("-1");
}

int main(){
    scanf("%d %d %d %d %d %d %d %d %d",&m,&h1,&a1,&x1,&y1,&h2,&a2,&x2,&y2);
    for (int i=0; i<m; i++) {
        func1[i] = (1ll * x1 * i + y1) % m;
        func2[i] = (1ll * x2 * i + y2) % m;
    }
    solve();
}