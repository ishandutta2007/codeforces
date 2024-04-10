#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;

int n,m,k;
char s[105][105];
int cx[222],cy[222];
int sx,sy,ex,ey;
char str[10000];
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++){
            char c;
            while((c=getchar())!='#' && (c<'1'||c>'9') && (c<'a'||c>'z'));
            s[i][j]=c;
            if(c>='a' && c<='z')cx[c]=i,cy[c]=j;
        }
    scanf("%d%d",&sx,&sy);
    scanf("%s",str+1);int len=strlen(str+1);
    scanf("%d%d",&ex,&ey);
    int cur=1;
    int nx=cx[str[1]],ny=cy[str[1]];
    while(1){
        if(sx==nx && sy==ny){
            cur++;
            if(cur>len)nx=ex,ny=ey;
            else nx=cx[str[cur]],ny=cy[str[cur]];
        }
        if(s[sx][sy]>='a' && s[sx][sy]<='z')k--;
        else k-=s[sx][sy]-'0';
        if(k<0)break;
        if(nx>sx)sx++;
        else if(nx<sx)sx--;
        else if(ny>sy)sy++;
        else if(ny<sy)sy--;
        else break;
    }
    printf("%d %d\n",sx,sy);
    return 0;
}