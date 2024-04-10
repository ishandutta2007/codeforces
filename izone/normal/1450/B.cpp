#include<cstdio>
#include<algorithm>
using namespace std;
int n, K;
struct point{
    int x, y;
}w[110];
void Solve(){
    scanf("%d%d",&n,&K);
    int i, j;
    for(i=1;i<=n;i++){
        scanf("%d%d",&w[i].x,&w[i].y);
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(abs(w[j].x-w[i].x)+abs(w[j].y-w[i].y)>K)break;
        }
        if(j==n+1){
            puts("1");
            return;
        }
    }
    puts("-1");
}
int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}