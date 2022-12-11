#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int maxn=510;
int n,m,q;
char s[maxn][maxn];
int f[maxn][maxn][252];
bool check(int x,int y,int c){
    for(int i=0;i<c;++i)
        if(s[x-c+1][y-c+1+i]!='R'||s[x-c+1+i][y-c+1]!='R')return false;
    for(int i=0;i<c;++i)
        if(s[x-c+1][y+c-i]!='G'||s[x-c+1+i][y+c]!='G')return false;
    for(int i=0;i<c;++i)
        if(s[x+c][y-c+1+i]!='Y'||s[x+c-i][y-c+1]!='Y')return false;
    for(int i=0;i<c;++i)
        if(s[x+c][y+c-i]!='B'||s[x+c-i][y+c-i]!='B')return false;
    return true;
}
int query(int x1,int y1,int x2,int y2,int c){
    if(x1>x2||y1>y2)return 0;
    if(x1<=0||x2<=0||y1<=0||y2<=0)return 0;
    if(x1>n||x2>n||y1>m||y2>m)return 0;
    return f[x2][y2][c]-f[x1-1][y2][c]-f[x2][y1-1][c]+f[x1-1][y1-1][c];
}
int main(){
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=n;++i)
        scanf("%s",s[i]+1);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            for(int c=1;c;++c){
                if(!check(i,j,c)){
                    for(int L=0;L<c;++L)
                        ++f[i][j][L];
                    break;
                }
            }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            for(int k=0;k<=250;++k)
                f[i][j][k]+=f[i-1][j][k]+f[i][j-1][k]-f[i-1][j-1][k];
    for(int x1,y1,x2,y2;q;--q){
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        int l=0,r=250;
        while(l<r){
            int L=(l+r+1)>>1;
            int Lx=x1+L-1,Ly=y1+L-1;
            int Rx=x2-L,Ry=y2-L;
            if(query(Lx,Ly,Rx,Ry,L))l=L;
            else r=L-1;
        }
        printf("%d\n",(l*l)<<2);
    }
    return 0;
}