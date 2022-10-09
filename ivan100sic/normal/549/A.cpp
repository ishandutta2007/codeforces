#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

bool isface(char a,char b,char c,char d){
    char s[5];
    s[0] = a;
    s[1] = b;
    s[2] = c;
    s[3] = d;
    sort(s,s+4);
    return s[0]=='a' && s[1]=='c' && s[2]=='e' && s[3]=='f';
}

char A[55][55];
int N,M,sol;

int main(){
    scanf("%d%d",&N,&M);
    for (int i=1; i<=N; i++){
        scanf("%s",A[i]+1);
    }
    for (int i=1; i<N; i++){
        for (int j=1; j<M; j++){
            if (isface(A[i][j],A[i+1][j],A[i][j+1],A[i+1][j+1])){
                sol++;
            }
        }
    }
    printf("%d\n",sol);
    return 0;
}