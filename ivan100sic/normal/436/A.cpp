#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N,x0,x,i,j,kb,mm;
int M[2005],Y[2005],T[2005];
bool U[2005];

int main(){
    scanf("%d%d",&N,&x0);
    for (i=1; i<=N; i++){
        scanf("%d%d%d",T+i,Y+i,M+i);
    }
    //prvo vatamo t=0
    x = x0;
    for (i=1; i<=N+1; i++){
        kb = 0;
        for (j=1; j<=N; j++){
            if (!U[j] && (i-T[j])%2 == 0 && Y[j] <= x){
                if (M[j] >= M[kb]) kb = j;
            }
        }
        if (kb==0){
            mm = i-1;
            break;
        } else {
            U[kb] = true;
            x += M[kb];
        }
    }
    //sad vatamo t=1
    x = x0;
    memset(U,0,sizeof(U));
    for (i=1; i<=N+1; i++){
        kb = 0;
        for (j=1; j<=N; j++){
             if (!U[j] && (i-T[j])%2 != 0 && Y[j] <= x){
                if (M[j] >= M[kb]) kb = j;
            }
        }
        if (kb==0){
            mm = max(mm,i-1);
            break;
        } else {
            U[kb] = true;
            x += M[kb];
        }
    }
    printf("%d\n",mm);
    return 0;
}