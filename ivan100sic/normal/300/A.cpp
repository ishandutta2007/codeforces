#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

//treba da stavim neparan broj negativnih u drugi i paran u prvi

int A[105],B[105],C[105],D[105],AA,BB,CC,DD,i,j,k,l;
int neg;

int main(){
    scanf("%d",&AA);
    for (i=1; i<=AA; i++) scanf("%d",A+i);
    //nadji nulu i ubaci je u prvi
    for (i=1; i<=AA; i++) if (A[i]==0) DD++;
    //izbroji negativne
    for (i=1; i<=AA; i++) if (A[i]<0) neg++;
    //poredjam ih standardno
    for (i=1; i<=AA; i++){
        if (A[i]>0){
            BB++;
            B[BB] = A[i];
        } else
        if (A[i]<0){
            CC++;
            C[CC] = A[i];
        }
    }
    //prebacim ako treba
    if (neg%2==0) D[++DD] = C[CC--];
    if (BB==0){
        B[++BB] = C[CC--];
        B[++BB] = C[CC--];
    }
    printf("%d",CC);
    for (i=1; i<=CC; i++) printf(" %d",C[i]);
    printf("\n%d",BB);
    for (i=1; i<=BB; i++) printf(" %d",B[i]);
    printf("\n%d",DD);
    for (i=1; i<=DD; i++) printf(" %d",D[i]);
    return 0;
}