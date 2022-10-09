#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char S[1005];
char R[1005];
int FS[256],N,l,r,m,o,Lr,L,i,j;

int main(){
    scanf("%s%d",S+1,&N);
    L = strlen(S+1);
    for (i=1; i<=L; i++) FS[S[i]]++;
    l=1;
    r=L;
    o=-1;
    while (l<=r){
        m = (l+r)/2;
        //m je broj shitova
        Lr = 0;
        for (i='a'; i<='z'; i++){
            Lr += (FS[i]+m-1)/m;
        }
        if (Lr <= N){
            o = m;
            r = m-1;
        } else {
            l = m+1;
        }
    }
    //sad ga pravimo
    Lr=0;
    for (i='a'; i<='z'; i++){
        for (j=1; j<=(FS[i]+o-1)/o; j++){
            Lr++;
            R[Lr] = i;
        }
    }
    while (Lr < N){
        Lr++;
        R[Lr] = 'a';
    }
    if (o==-1) printf("-1\n"); else
    printf("%d\n%s\n",o,R+1);
    return 0;
}