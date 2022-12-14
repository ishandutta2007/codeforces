#include <bits/stdc++.h>

using namespace std;

int N, M, P;
int s[14];
int q[14][1000*1000+4][2], f[14], r[14];
char arr[1004][1004];
int cnt = 0, pos, last;
int far[1004][1004];
int wx[4] = {-1, 0, 1, 0}, wy[4] = {0, 1, 0, -1};

int main(){
    scanf("%d %d %d", &N, &M, &P);
    for(int i=1;i<=P;++i) scanf("%d", s+i);
    for(int i=1;i<=N;++i) for(int j=1;j<=M;++j){
        scanf(" %c", arr[i]+j);
        if(arr[i][j]!='.') ++cnt;
        if(arr[i][j]>='1'&&arr[i][j]<='9')
            q[arr[i][j]-'0'][r[arr[i][j]-'0']][0] = i, q[arr[i][j]-'0'][r[arr[i][j]-'0']++][1] = j, far[i][j] = 1;
    }
    while(cnt<N*M){
        last = cnt;
        for(int i=1;i<=P;++i){
            if(cnt==N*M) break;
            pos = far[q[i][f[i]][0]][q[i][f[i]][1]]+s[i];
            while(f[i]<r[i]&&far[q[i][f[i]][0]][q[i][f[i]][1]]<pos){
                for(int x=0;x<4;++x){
                    int nx = q[i][f[i]][0]+wx[x], ny = q[i][f[i]][1]+wy[x];
                    if(!far[nx][ny]&&arr[nx][ny]=='.'){
                        q[i][r[i]][0] = nx, q[i][r[i]++][1] = ny;
                        far[nx][ny] = far[q[i][f[i]][0]][q[i][f[i]][1]]+1; ++cnt;
                    }
                }
                ++f[i];
            }
        }
        if(last==cnt) break;
    }
    for(int i=1;i<=P;++i) printf("%d ", r[i]);
    return 0;
}