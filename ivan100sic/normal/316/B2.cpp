#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int D[1005],N,K,A[1005],i,j,k;
int S[1005],SSS;
bool Moze[1005][1005],Sors[1005],pokk;

int depth(int x){
    if (D[x]!=-1) return D[x];
    if (A[x]==0){
        D[x] = 0;
        return 0;
    } else {
        D[x] = depth(A[x]) + 1;
        return D[x];
    }
}

int main(){
    memset(D,255,sizeof(D));
    scanf("%d%d",&N,&K);
    for (i=1; i<=N; i++) scanf("%d",A+i);
    memset(Sors,1,sizeof(Sors));
    for (i=1; i<=N; i++) depth(i);
    for (i=1; i<=N; i++) Sors[A[i]] = false;
    for (i=1; i<=N; i++) if (Sors[i]){
        k=i;
        pokk=false;
        while (k!=0){
            if (k==K){
                pokk=true;
                break;
            }
            k = A[k];
        }
        if (!pokk){
            SSS++;
            S[SSS] = D[i] + 1;
            //printf("%d %d\n",i,S[SSS]);
        }
    }
    Moze[0][0] = true;
    for (i=0; i<SSS; i++){
        for (j=0; j+S[i+1]<=N; j++){
            Moze[i+1][j] |= Moze[i][j];
            Moze[i+1][j+S[i+1]] |= Moze[i][j];
        }
    }
    for (j=0; j<=N; j++) if (Moze[SSS][j]) printf("%d\n",D[K]+j+1);
    return 0;
}