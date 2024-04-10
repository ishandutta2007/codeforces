#include <cstdio>

int Pinged[105],Rec[105],N,M,i,j,k,l;

int main(){
    scanf("%d",&N);
    while (N--){
        scanf("%d%d%d",&j,&k,&l);
        Pinged[j]++;
        Rec[j]+=k;
    }
    if (Pinged[1]*5 <= Rec[1]) printf("LIVE\n"); else printf("DEAD\n");
    if (Pinged[2]*5 <= Rec[2]) printf("LIVE\n"); else printf("DEAD\n");
    return 0;
}