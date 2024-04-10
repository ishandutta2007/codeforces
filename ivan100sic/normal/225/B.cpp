#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long F[500],K,S,Sol[500],KKK;

void napravi(){
    F[1] = 1;
    int i,j;
    for (i=1; i<=400; i++){
        for (j=i-1; j>=i-K && j>0; j--) F[i]+=F[j];
    }
}

void resi(){
    int i;
    while (S>0){
        i=0;
        while (F[i+1] <= S) i++;
        S -= F[i];
        KKK++;
        Sol[KKK] = F[i];
    }
}

void ispisi(){
    printf("%d\n",KKK+1);
    for (int i=0; i<=KKK; i++) printf("%I64d%c",Sol[i],i==KKK?'\n':' ');
}

void ucitaj(){
    scanf("%I64d%I64d",&S,&K);
}

int main(){
    ucitaj();
    napravi();
    resi();
    ispisi();
    return 0;
}