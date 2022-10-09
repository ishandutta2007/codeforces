#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char S[200005],Q[200005];
int LastSeen[256];
int Rez1[200005],Rez2[200005];
int N,M,i,j;

void ucitaj(){
    scanf("%s",S+1);
    N = strlen(S+1);
    scanf("%s",Q+1);
    M = strlen(Q+1);
}

void uparuj(int *Rez){
    int i,j;
    j=0;
    memset(LastSeen,0,sizeof(LastSeen));
    for (i=1; i<=N; i++){
        if (S[i] == Q[j+1] && j<M){
            j++;
            LastSeen[S[i]] = j;
            Rez[i] = j;
        } else {
            Rez[i] = LastSeen[S[i]];
        }
    }
}

void debug(int *Rez){
    int i;
    for (i=1; i<=N; i++) printf("%d ",Rez[i]);
    puts("");
}

int main(){
    ucitaj();
    uparuj(Rez1);
    reverse(S+1,S+N+1);
    reverse(Q+1,Q+M+1);
    uparuj(Rez2);
    reverse(Rez2+1,Rez2+N+1);
    for (i=1; i<=N; i++) if (Rez1[i] + Rez2[i] <= M){
        printf("No\n");
        return 0;
    }
    printf("Yes\n");
    return 0;
}