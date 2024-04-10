#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char S1[2605],S2[2605];
int D[2605][2605],Tip[2605][2605];
char S[50005];
char Sol[50005];
int F[256];
int N,i,j,k,l,LS;

int main(){
    scanf("%s",S+1);
    N = strlen(S+1);
    if (N>2600){
        for (i=1; i<=N; i++) F[S[i]]++;
        j='a';
        for (i='b'; i<='z'; i++) if (F[i] > F[j]) j = i;
        for (i=1; i<=100; i++) putchar(j);
    } else {
        for (i=1; i<=N; i++) S1[i] = S[i];
        for (i=1; i<=N; i++) S2[i] = S1[N-i+1];
        for (i=1; i<=N; i++){
            for (j=1; j<=N; j++){
                if (S1[i]==S2[j]){
                    D[i][j] = D[i-1][j-1] + 1;
                    Tip[i][j] = 44;
                } else {
                    if (D[i][j-1] > D[i-1][j]){
                        D[i][j] = D[i][j-1];
                        Tip[i][j] = 8;
                    } else {
                        D[i][j] = D[i-1][j];
                        Tip[i][j] = 7;
                    }
                }
            }
        }
        //samo prigrabimo najduzi
        i=N;
        j=N;
        LS=0;
        while (i>0 && j>0){
            if (Tip[i][j] == 44){
                LS++;
                Sol[LS] = S1[i];
                i--;
                j--;
            } else
            if (Tip[i][j] == 7){
                i--;
            } else {
                j--;
            }
        }
        //adjustments za palindrome duze od 100
        if (LS>100){
            if (LS%2==0){
                int izb = (LS-100) / 2;
                for (i=izb+1; i<=LS-izb; i++) putchar(Sol[i]);
            } else {
                int izb = (LS-100) / 2;
                for (i=izb+1; i<=LS/2; i++) putchar(Sol[i]);
                for (i=LS/2+2; i<=LS-izb; i++) putchar(Sol[i]);
            }
        } else {
            printf("%s\n",Sol+1);
        }
    }
    return 0;
}