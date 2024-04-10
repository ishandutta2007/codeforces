#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char S[105];
int N,i,j,k,l;
int Ce,Pe;

int main(){
    scanf("%s",S+1);
    N = strlen(S+1);
    for (i=1; i<=N; i++){
        if (S[i]=='C'){
            Ce++;
        } else Pe++;
        if (Ce*Pe >= 1 || Ce>5 || Pe>5){
            Ce=0;
            Pe=0;
            l++;
            i--;
        }
    }
    l++;
    printf("%d\n",l);
    return 0;
}