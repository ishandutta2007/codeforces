#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

bool IsPal[5005][5005];
int CntPal[5005][5005],N,Q;
char S[5005];

void ucitaj(){
    scanf("%s",S+1);
    N = strlen(S+1);
}

void dinamika(){
    int i,j,k;
    for (i=1; i<=N; i++) IsPal[i][i] = true;
    for (i=1; i<N; i++) IsPal[i][i+1] = S[i]==S[i+1];
    for (j=3; j<=N; j++){
        for (i=1; i<=N-j+1; i++){
            //i .. i+j-1
            IsPal[i][i+j-1] = IsPal[i+1][i+j-2] && S[i]==S[i+j-1];
        }
    }
    //cnt
    for (i=1; i<=N; i++) CntPal[i][i] = 1;
    for (i=1; i<N; i++) CntPal[i][i+1] = 2 + (S[i]==S[i+1]);
    for (j=3; j<=N; j++){
        for (i=1; i<=N-j+1; i++){
            //i .. i+j-1
            CntPal[i][i+j-1] = CntPal[i][i+j-2] + CntPal[i+1][i+j-1] - CntPal[i+1][i+j-2] + (IsPal[i][i+j-1]);
        }
    }
}

void resi(){
    scanf("%d",&Q);
    int l,r;
    while (Q--){
        scanf("%d%d",&l,&r);
        printf("%d\n",CntPal[l][r]);
    }
}

int main(){
    ucitaj();
    dinamika();
    resi();
    return 0;
}