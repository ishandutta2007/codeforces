#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N,K;
int D[1005],F[1005];

void ucitaj(){
    scanf("%d%d",&N,&K);
    int i;
    for (i=1; i<=N; i++) scanf("%d",D+i);
    for (i=1; i<=N; i++) scanf("%d",F+i);
}

int MF[1005];

void resi(){
    int i;
    long long time,fuel;
    for (i=1; i<=N; i++){
        MF[i] = max(MF[i-1],F[i]);
    }
    time=0;
    fuel=0;
    for (i=1; i<=N; i++){
        fuel += F[i];
        while (fuel < D[i]){
            time+=K;
            fuel+=MF[i];
        }
        time+=D[i];
        fuel-=D[i];
    }
    printf("%I64d\n",time);
}

int main(){
    ucitaj();
    resi();
    return 0;
}