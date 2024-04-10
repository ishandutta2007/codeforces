#include <cstdio>
#include <cstring>
#include <algorithm>
#define OFFS 500000
using namespace std;

int A[200005],FirstSeen[1000005];
char S[200005];
int sol,solc,N;

int charval(char x){
    if (x=='a' || x=='e' || x=='i' || x=='o' || x=='u' ||
        x=='A' || x=='E' || x=='I' || x=='O' || x=='U') return -1; else return 2;
}

void ucitaj(){
    scanf("%s",S+1);
    N = strlen(S+1);
    int i;
    for (i=1; i<=N; i++) A[i] = charval(S[i]);
    for (i=1; i<=N; i++) A[i] += A[i-1];
    //for (i=1; i<=N; i++) printf("%d ",A[i]);
    //puts("");
}

void pushsol(int x){
    if (x>sol){
        sol = x;
        solc = 1;
    } else if (x==sol){
        solc++;
    }
}

void nadjiposumi(){
    int i;
    memset(FirstSeen,255,sizeof(FirstSeen));
    for (i=0; i<=N; i++){
        if (FirstSeen[A[i] + OFFS] != -1){
            pushsol(i-FirstSeen[A[i] + OFFS]);
        } else FirstSeen[A[i] + OFFS] = i;

    }
}

void nadjipokraju(){
    int i;
    for (i=1; i<=N; i++){
        if (A[i]>0) pushsol(i);
        if (A[N]-A[i-1] > 0) pushsol(N-i+1);
    }
}

int main(){
    ucitaj();
    nadjiposumi();
    nadjipokraju();
    if (sol==N) solc=1;
    if (sol==0) printf("No solution\n"); else
    printf("%d %d\n",sol,solc);
    return 0;
}