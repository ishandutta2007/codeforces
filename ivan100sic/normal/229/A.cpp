#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int A[105][10005],N,M;
char S[10005];


void ucitaj(){
    int i,j;
    scanf("%d%d",&N,&M);
    for (i=1; i<=N; i++){
        scanf("%s",S+1);
        for (j=1; j<=M; j++) A[i][j] = S[j]-48;
    }
    for (i=1; i<=N; i++){
        for (j=1; j<=M; j++) A[i][j] += A[i][j-1];
    }
}

int inrange(int row,int xc,int w){
    if (2*w+1 >= M) return A[row][M] - A[row][0];
    int l1,r1,l2,r2;
    if (xc-w < 1){
        l1 = 1;
        r1 = xc+w;
        l2 = M-w+xc;
        r2 = M;
    } else
    if (xc+w > M){
        l1 = xc-w;
        r1 = M;
        l2 = 1;
        r2 = xc+w-M;
    } else {
        l1 = xc-w;
        r1 = xc+w;
        l2 = 1;
        r2 = 0;
    }
    //printf("%d %d %d %d %d %d\n",xc,w,l1,r1,l2,r2);
    return A[row][r1] - A[row][l1-1] + A[row][r2] - A[row][l2-1];
}

bool postoji(){
    int i;
    for (i=1; i<=N; i++){
        if (A[i][M]==0) return false;
    }
    return true;
}

int minw(int row,int xc){
    int l,r,o,m;
    l=0;
    r=(M+3)/2;
    o=-1;
    while (l<=r){
        m = (l+r)/2;
        if (inrange(row,xc,m)>0){
            o = m;
            r = m-1;
        } else {
            l = m+1;
        }
    }
    //printf("%d %d %d\n",row,xc,o);
    return o;
}

int main(){
    int opt,i,j,k,sol;
    opt = 1000000000;
    ucitaj();
    if (!postoji()){
        printf("-1\n");
        return 0;
    }
    for (j=1; j<=M; j++){
        sol = 0;
        for (i=1; i<=N; i++) sol+=minw(i,j);
        //printf("%d %d\n",j,sol);
        if (sol < opt) opt = sol;
    }
    printf("%d\n",opt);
    return 0;
}