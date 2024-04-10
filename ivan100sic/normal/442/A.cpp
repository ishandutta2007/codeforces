#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int tonum(char x){
    if (x=='R') return 1;
    if (x=='G') return 2;
    if (x=='B') return 3;
    if (x=='Y') return 4;
    if (x=='W') return 5;
    return x-48;
}

int A[10][10],N,i,j,k;
char S[10];

bool RS[10],CS[10],K1[10][10],K2[10][10];

bool sweep(){
    int i,j,k,l,c;
    bool nastavi = true;
    memset(K1,0,sizeof(K1));
    memset(K2,0,sizeof(K2));
    for (i=1; i<=5; i++){
        for (j=1; j<=5; j++){
            if (RS[i]) K1[i][j] = true;
            if (CS[j]) K2[i][j] = true;
        }
    }
    while (nastavi){ //nesto se desava
        nastavi = false;
        //1
        /*
        for (i=1; i<=5; i++){
            c=0;
            for (j=1; j<=5; j++){
                if (A[i][j] && !K1[i][j] && K2[i][j]){
                    c++;
                    k=j;
                }
            }
            if (c==1){
                nastavi = true;
                K1[i][k] = true;
            }
        }
        */
        //2
        for (i=1; i<=5; i++){
            c=0;
            for (j=1; j<=5; j++){
                if (A[i][j] && !K2[i][j] && K1[i][j]){
                    c++;
                    k=j;
                }
            }
            if (c==1){
                nastavi = true;
                K2[i][k] = true;
            }
        }
        //3
        for (j=1; j<=5; j++){
            c=0;
            for (i=1; i<=5; i++){
                if (A[i][j] && !K1[i][j] && K2[i][j]){
                    c++;
                    k=i;
                }
            }
            if (c==1){
                nastavi = true;
                K1[k][j] = true;
            }
        }
        /*
        //4
        for (j=1; j<=5; j++){
            c=0;
            for (i=1; i<=5; i++){
                if (A[i][j] && !K2[i][j] && K1[i][j]){
                    c++;
                    k=i;
                }
            }
            if (c==1){
                nastavi = true;
                K2[k][j] = true;
            }
        }
        */
        //specijalac
        c = 0;
        for (i=1; i<=5; i++){
            for (j=1; j<=5; j++){
                if (A[i][j] && !K1[i][j] && !K2[i][j]){
                    c++;
                    k = i;
                    l = j;
                }
            }
        }
        if (c==1){
            nastavi = true;
            K1[k][l] = true;
            K2[k][l] = true;
        }
    }
    for (i=1; i<=5; i++){
        for (j=1; j<=5; j++){
            if (A[i][j] && !(K1[i][j] && K2[i][j])) return false;
        }
    }
    /*
    for (i=1; i<=5; i++){
        for (j=1; j<=5; j++){
            printf("%c%c",K1[i][j]+48,j==5?'\n':' ');
        }
    }
    */
    return true;
}

int main(){
    scanf("%d",&N);
    for (i=1; i<=N; i++){
        scanf("%s",S);
        j = tonum(S[0]);
        k = tonum(S[1]);
        A[j][k] = 1;
    }
    int hmask,vmask,i,j,mn=N;
    for (hmask=0; hmask<32; hmask++){
        for (vmask=0; vmask<32; vmask++){
            for (i=0; i<5; i++) RS[i+1] = (hmask & (1<<i))>0;
            for (i=0; i<5; i++) CS[i+1] = (vmask & (1<<i))>0;
            j=0;
            for (i=0; i<5; i++){
                if ((hmask & (1<<i))>0) j++;
                if ((vmask & (1<<i))>0) j++;
            }
            if (sweep()) mn = min(mn , j);
            //if (sweep() && j == 1) printf("%d %d\n",hmask,vmask);
        }
    }
    printf("%d\n",mn);
    return 0;
}