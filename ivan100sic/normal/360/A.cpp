#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N,M,Q2;
int QueryVector[5005][5005],QL[5005],QR[5005];
int QueryVal[5005];
int CurrVector[5005];
int TotalMaximum[5005];
int Out[5005];

int main(){
    int i,j,k,t,l,r,v;
    scanf("%d%d",&N,&M);
    for (j=1; j<=M; j++){
        scanf("%d%d%d%d",&t,&l,&r,&v);
        if (t==1){
            for (i=l; i<=r; i++) CurrVector[i] += v;
        } else {
            Q2++;
            for (i=1; i<=N; i++){
                QueryVector[Q2][i] = CurrVector[i];
            }
            QL[Q2] = l;
            QR[Q2] = r;
            QueryVal[Q2] = v;
        }
    }
    //TotalMaximum
    for (i=1; i<=N; i++) TotalMaximum[i] = 1000000000;
    for (i=1; i<=N; i++) Out[i] = -1000000000;
    for (i=1; i<=Q2; i++){
        for (j=QL[i]; j<=QR[i]; j++){
            TotalMaximum[j] = min(TotalMaximum[j] , QueryVal[i] - QueryVector[i][j]);
        }
    }
    //Find satisf
    for (i=1; i<=Q2; i++){
        bool ok = false;
        for (j=QL[i]; j<=QR[i]; j++){
            //pokusacemo da namestimo ovog
            if (QueryVal[i] - QueryVector[i][j] == TotalMaximum[j]){
                Out[j] = TotalMaximum[j];
                ok = true;
            }
        }
        if (!ok){
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    for (i=1; i<=N; i++) printf("%d%c",Out[i],i==N?'\n':' ');
    return 0;
}