#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int Color[105];
int A[105][105],N,M,i,j,k,l;
int Sol[105],SS;
bool bru;

void dfs(int x){
    int i,j;
    for (i=1; i<=N; i++){
        if (A[x][i]==1){
            if (Color[i] != 0 && Color[i] != 3-Color[x]) bru=true;
            if (Color[i] == 0){
                Color[i] = 3-Color[x];
                dfs(i);
            }
        } else
        if (A[x][i]==2){
            if (Color[i] != 0 && Color[i] != Color[x]) bru=true;
            if (Color[i] == 0){
                Color[i] = Color[x];
                dfs(i);
            }
        }
    }
}

int main(){
    scanf("%d%d",&N,&M);
    for (i=1; i<=M; i++){
        scanf("%d%d%d",&j,&k,&l);
        A[j][k] = l+1;
        A[k][j] = l+1;
    }
    for (i=1; i<=N; i++){
        if (Color[i]==0){
            Color[i]=2;
            dfs(i);
        }
    }
    if (bru){
        printf("Impossible\n");
        return 0;
    }
    for (i=1; i<=N; i++) if (Color[i]==1){
        SS++;
        Sol[SS] = i;
    }
    printf("%d\n",SS);
    for (i=1; i<=SS; i++) printf("%d%c",Sol[i],i==N?'\n':' ');
    return 0;
}