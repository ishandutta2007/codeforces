#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char S[100005];
int Braket[100005],NB[100005],N,i,j,k,l,Sh,optp,opts;
int Suma[100005];

struct zagrada{
    int poz;
    char x;
};

zagrada Stek[100005];

char otvarajuca(char x){
    if (x==')') return '(';
    if (x==']') return '[';
    if (x=='}') return '{';
    return '!';
}

int main(){
    scanf("%s",S+1);
    N = strlen(S+1);
    for (i=1; i<=N; i++){
        if (Stek[Sh].x == otvarajuca(S[i])){
            Braket[ Stek[Sh].poz ] = i;
            Sh--;
        } else {
            Sh++;
            Stek[Sh].poz = i;
            Stek[Sh].x = S[i];
        }
    }
    for (i=1; i<=N; i++){
        if (S[i]=='[') Suma[i]++;
    }

    for (i=1; i<=N; i++) if (Braket[i]!=0){
        while (Braket[Braket[i]+1] != 0){
            j = Braket[i]+1;
            Braket[i] = Braket[j];
            Braket[j] = 0;
        }
    }

    for (i=1; i<=N; i++) Suma[i]+=Suma[i-1];
    for (i=1; i<=N; i++){
        if (Braket[i] != 0){
            if (Suma[Braket[i]] - Suma[i-1] > opts){
                optp = i;
                opts = Suma[Braket[i]] - Suma[i-1];
            }
        }
    }
    if (optp == 0){
        printf("0\n\n");
        return 0;
    }
    printf("%d\n",opts);
    for (i=optp; i<=Braket[optp]; i++){
        putchar(S[i]);
    }
    puts("");
    return 0;
}