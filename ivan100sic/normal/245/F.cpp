#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

int Days[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};

int dayoftheyear(int m,int d){
    int i,j;
    j=0;
    for (i=1; i<=m-1; i++) j+=Days[i];
    return j+d;
}

int l(char x){
    return x-48;
}

int T[5100005],N,M,i,j,k,KKK,dan,mesec,sat,minut,sekund,t;
int dann[1000005],mesecc[1000005],satt[1000005],minutt[1000005],sekundd[1000005];
char S[5100005];

int main(){
    scanf("%d%d%c",&N,&M,S);
    while (true){
        S[1]=0;
        S[2]=0;
        S[3]=0;
        cin.getline(S+1,5050000);
        if (S[2]==0) break;
        mesec  = l(S[ 6])*10 + l(S[ 7]);
        dan    = l(S[ 9])*10 + l(S[10]);
        sat    = l(S[12])*10 + l(S[13]);
        minut  = l(S[15])*10 + l(S[16]);
        sekund = l(S[18])*10 + l(S[19]);
        t = sekund + 60*minut + 3600*sat + 86400*dayoftheyear(mesec,dan);
        //printf("%d %d %d %d %d %d\n",mesec,dan,sat,minut,sekund,t);
        KKK++;
        T[KKK]=t;
        dann[KKK] = dan;
        mesecc[KKK] = mesec;
        satt[KKK] = sat;
        minutt[KKK] = minut;
        sekundd[KKK] = sekund;
        //if (KKK>=3) break;
    }
    for (i=M; i<=KKK; i++){
        if (T[i]-T[i-M+1] < N){
            printf("2012-%02d-%02d %02d:%02d:%02d\n",mesecc[i],dann[i],satt[i],minutt[i],sekundd[i]);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}