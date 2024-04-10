#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char S[1000];
bool W[1000];
int N,i,j,k,l;

int main(){
    scanf("%s",S+1);
    N = strlen(S+1);
    for (i=1; i<=N-2; i++){
        if (S[i]=='W' && S[i+1]=='U' && S[i+2]=='B'){
            W[i]=true;
            W[i+1]=true;
            W[i+2]=true;
        }
    }
    for (i=1; i<=N; i++){
        if (W[i]) S[i]=0;
    }
    for (i=1; i<=N; i++){
        if (S[i]>0 && S[i-1]==0) printf("%s ",S+i);
    }
    return 0;
}