#include <bits/stdc++.h>

using namespace std;

int N, M;
int X, Y;
int l, r;
char arr[2004][2004];
int q[2004*2004][5], chk[2004][2004], f, rr;

void enq(int a, int b, int c, int d){
    q[rr][0] = a, q[rr][1] = b, q[rr][2] = c, q[rr++][3] = d;
}

int main(){
    scanf("%d %d %d %d %d %d", &N, &M, &X, &Y, &l, &r);
    for(int i=1;i<=N;++i) for(int j=1;j<=M;++j) scanf(" %c", arr[i]+j);
    for(int i=X;arr[i][Y]=='.';--i){
        chk[i][Y] = 1, enq(i, Y, l, r);
    }
    for(int i=X+1;arr[i][Y]=='.';++i){
        chk[i][Y] = 1, enq(i, Y, l, r);
    }
    while(f<rr){
        if(q[f][2]>=1){
            if(arr[q[f][0]][q[f][1]-1]=='.'&&!chk[q[f][0]][q[f][1]-1]){
                for(int i=q[f][0];arr[i][q[f][1]-1]=='.';--i){
                    chk[i][q[f][1]-1] = 1, enq(i, q[f][1]-1, q[f][2]-1, q[f][3]);
                }
                for(int i=q[f][0]+1;arr[i][q[f][1]-1]=='.';++i){
                    chk[i][q[f][1]-1] = 1, enq(i, q[f][1]-1, q[f][2]-1, q[f][3]);
                }
            }
        }
        if(q[f][3]>=1){
            if(arr[q[f][0]][q[f][1]+1]=='.'&&!chk[q[f][0]][q[f][1]+1]){
                for(int i=q[f][0];arr[i][q[f][1]+1]=='.';--i){
                    chk[i][q[f][1]+1] = 1, enq(i, q[f][1]+1, q[f][2], q[f][3]-1);
                }
                for(int i=q[f][0]+1;arr[i][q[f][1]+1]=='.';++i){
                    chk[i][q[f][1]+1] = 1, enq(i, q[f][1]+1, q[f][2], q[f][3]-1);
                }
            }
        }
        ++f;
    }
    printf("%d", rr);
    return 0;
}