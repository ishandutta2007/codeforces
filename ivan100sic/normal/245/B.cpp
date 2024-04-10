#include <cstdio>
#include <cstring>

char S[150],R[150];
int i,j,k,l,m,N;

void add(char x){
    m++;
    R[m] = x;
}

int main(){
    scanf("%s",S+1);
    N = strlen(S+1);
    if (S[1]=='h'){
        add(S[1]);
        add(S[2]);
        add(S[3]);
        add(S[4]);
        add(':');
        add('/');
        add('/');
        k=5;
    } else {
        add(S[1]);
        add(S[2]);
        add(S[3]);
        add(':');
        add('/');
        add('/');
        k=4;
    }
    for (i=k+1; i<N; i++){
        if (S[i]=='r' && S[i+1]=='u') break;
    }
    for (j=k; j<i; j++) add(S[j]);
    add('.');
    add('r');
    add('u');
    if (i<=N-2){
        add('/');
        for (k=i+2; k<=N; k++) add(S[k]);
    }
    printf("%s\n",R+1);
    return 0;
}