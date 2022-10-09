#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char S[500005];
int PSR[500005],PSK[500005];
int N,Kuce,Radnje,T;
int XK[500005],XR[500005];

void ucitaj(){
    scanf("%d%d",&N,&T);
    int i,j;
    scanf("%s",S+1);
    while (S[N]=='.') N--;
    for (i=1; i<=N; i++){
        if (S[i]=='H'){
            Kuce++;
            XK[Kuce] = i;
        } else
        if (S[i]=='S'){
            Radnje++;
            XR[Radnje] = i;
        }
    }
    for (i=N; i>=1; i--){
        PSK[i] = PSK[i+1];
        PSR[i] = PSR[i+1];
        if (S[i]=='H'){
            PSK[i]=i;
        }
        if (S[i]=='S'){
            PSR[i]=i;
        }
    }
}

void debug(){
    int i,j;
    for (i=1; i<=N; i++) printf("%d %d %d\n",i,PSK[i],PSR[i]);
}

int Vrat[500005];
int SumaPlusDva[500005],SumaPlusJedan[500005];

void resi(){
    int l,r,k,i,j,p,kk,joskuca,o,pob,Nus,naj;
    long long vreme;
    l=Kuce-Radnje;
    if (l<0) l=0;
    r=N;
    o=-1;
    while (l<=r){
        kk = (l+r)/2;
        k=kk;
        joskuca = Kuce;
        vreme=0;
        //printf("%d\n",joskuca);
        //kod gouz hir
        memset(Vrat,0,sizeof(Vrat));
        for (i=1; i<=N && (joskuca>0 || k<0); i++){
            vreme++;
            Nus=i;
            if (S[i]=='H'){
                k--;
                joskuca--;
            } else
            if (S[i]=='S'){
                k++;
            }
            if (k<0){
                Vrat[i]=1;
            }
        }
        memset(SumaPlusDva,0,sizeof(SumaPlusDva));
        memset(SumaPlusJedan,0,sizeof(SumaPlusJedan));
        for (i=1; i<=Nus; i++){
            SumaPlusDva[i] = SumaPlusDva[i-1] + 2*Vrat[i];
        }
        for (i=Nus-1; i>=1; i--){
            SumaPlusJedan[i] = SumaPlusJedan[i+1] + 1;
        }
        naj = 999999999;
        if (Nus<=1) naj=0;
        for (i=0; i<Nus; i++){
            if (SumaPlusDva[i] + SumaPlusJedan[i+1] < naj){
                naj = SumaPlusDva[i] + SumaPlusJedan[i+1];
            }
        }
        vreme += naj;
        //printf("%d %lld\n",kk,vreme);
        if (vreme <= T){
            jee:
            o=kk;
            r=kk-1;
        } else {
            maukurac:
            l=kk+1;
        }
    }
    printf("%d\n",o);
}

int main(){
    ucitaj();
    //debug();
    resi();
    return 0;
}