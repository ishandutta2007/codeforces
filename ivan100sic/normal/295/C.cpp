#include <cstdio>
#include <cstring>
#include <algorithm>
#define MOD 1000000007
using namespace std;

int to_cvor(int mrsavi,int debeli,int obala){
    return mrsavi + debeli*51 + (obala-1) * 2601 + 1;
}

int Kapacitet,M,D;

long long Binomni[55][55];

void to_komponente(int cvor,int &mrsavi,int &debeli,int &obala){
    cvor--;
    obala = 1 + cvor / 2601;
    cvor %= 2601;
    debeli = cvor / 51;
    cvor %= 51;
    mrsavi = cvor;
}

long long br_nacina(int cvor1,int cvor2){
    int m1,d1,o1,
        m2,d2,o2;
    to_komponente(cvor1,m1,d1,o1);
    to_komponente(cvor2,m2,d2,o2);
    if (o1==o2) return 0;
    if (m1>M || d1>D || m2>M || d2>D) return 0;
    if (o1==1){
        //ako se ide sa 1 na 2
        if (m1<m2) return 0;
        if (d1<d2) return 0;
        if (m1==m2 && d1==d2) return 0;
        if ((m1-m2)*50 + (d1-d2)*100 > Kapacitet) return 0;
        return Binomni[m1][m1-m2]*Binomni[d1][d1-d2];
    } else
    if (o2==1){
        //ako se ide sa 2 na 1
        if (m1>m2) return 0;
        if (d1>d2) return 0;
        if (m1==m2 && d1==d2) return 0;
        if ((m2-m1)*50 + (d2-d1)*100 > Kapacitet) return 0;
        return Binomni[M-m1][m2-m1]*Binomni[D-d1][d2-d1];
    }
}

long long Adj[5300][5300];
int Q[5300],Dst[5300];
long long Nacina[5300];

int main(){
    int i,j,k,l,qs,qe,N;
    scanf("%d%d",&N,&Kapacitet);
    for (i=0; i<=N; i++) Binomni[i][0] = 1;
    for (i=1; i<=N; i++){
        for (j=1; j<=N; j++){
            Binomni[i][j] = Binomni[i-1][j] + Binomni[i-1][j-1];
            Binomni[i][j] %= MOD;
        }
    }
    while (N--){
        scanf("%d",&j);
        if (j==50) M++; else D++;
    }
    for (i=1; i<=5202; i++){
        for (j=1; j<=5202; j++){
            Adj[i][j] = br_nacina(i,j) % MOD;
        }
    }
    Q[1] = to_cvor(M,D,1);
    Dst[Q[1]] = 2011;
    Nacina[Q[1]] = 1;
    qs=1;
    qe=1;
    while (qs<=qe){
        k = Q[qs];
        //printf("pop %d\n",k);
        qs++;
        for (i=1; i<=5202; i++){
            if (br_nacina(k,i)>0){
                if (Dst[i]==0){
                    Dst[i] = Dst[k]+1;
                    Nacina[i] = Nacina[k]*Adj[i][k];
                    Nacina[i] %= MOD;
                    Q[++qe] = i;
                } else
                if (Dst[i]==Dst[k]+1){
                    Nacina[i] += Nacina[k]*Adj[i][k];
                    Nacina[i] %= MOD;
                }
            }
        }
    }
    k = to_cvor(0,0,2);
    if (Dst[k]==0){
        printf("-1\n0\n");
        return 0;
    }
    printf("%d\n%d\n",Dst[k]-2011,(int)Nacina[k]);
    return 0;
}