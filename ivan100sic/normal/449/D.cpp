#include <cstdio>
#include <cstring>
#include <algorithm>
#define MOD 1000000007
using namespace std;

int D[1<<20][20];
int F[1<<20],N;

void ucitaj(){
    int i,x;
    scanf("%d",&N);
    for (i=1; i<=N; i++){
        scanf("%d",&x);
        D[x][0]++;
    }
}

int PC[1<<20];

void propagiraj(){
    int i,j,k,b,z;
    PC[1] = 1;
    for (i=2; i<(1<<20); i++) PC[i] = PC[i/2] + i%2;
    for (k=20; k>=1; k--){
        for (i=1; i<(1<<20); i++) if (PC[i]==k){
            for (j=2; j<=20-k; j++) if (D[i][j] > 0) D[i][j] /= j;
            if (k>1){
                for (b=1; b<=(1<<19); b*=2) if (i & b){
                    for (z=0; z<=20-k; z++){
                        D[i ^ b][z+1] += D[i][z];
                    }
                }
            }
        }
    }
    for (i=1; i<(1<<20); i++){
        for (j=0; j<20; j++) F[i] += D[i][j];
    }
    //for (i=1; i<(1<<20); i++) if (F[i]>0) printf("%d %d\n",i,F[i]);
}

int Stepen[1000005];

void resi(){
    int i,j,k;
    long long sol=0;
    Stepen[0] = 1;
    for (i=1; i<=N; i++){
        Stepen[i] = 2*Stepen[i-1];
        if (Stepen[i] >= MOD) Stepen[i] -= MOD;
    }
    sol = Stepen[N] - 1;
    for (i=1; i<(1<<20); i++){
        if (PC[i]%2==1){
            //izbacujemo
            sol -= (Stepen[F[i]]-1);
        } else {
            sol += (Stepen[F[i]]-1);
        }
    }
    sol %= MOD;
    if (sol < 0) sol += MOD;
    printf("%lld\n",sol);
}

int main(){
    ucitaj();
    propagiraj();
    resi();
    return 0;
}