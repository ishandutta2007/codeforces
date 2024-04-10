#include<bits/stdc++.h>
using namespace std;
inline long long read(){
    long long x=0;
    char zf=1,ch=getchar();
    while(ch!='-'&&!isdigit(ch))ch=getchar();
    if(ch=='-')zf=-1,ch=getchar();
    while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
    return x*zf;
}
int i,j,k,n,m,x,y,z,cnt,sum;
char ch[1010][1010];
int fa[2010];
struct node{
    int x,y;
}Q[2000010];int t;
int bj[2000010];
int len[2000010];
int num[2000010];
int a[2000010];
int dushu[2000010];
int ans[2000010];
int Find(int x){
    return (x==fa[x])?x:(fa[x]=Find(fa[x]));
}
void Do(int x,int y){
    int p=Find(x),Q=Find(y);
    if(p!=Q)fa[Q]=p;
}
void add(int x,int y){
    a[++k]=y;dushu[y]++;
    if(!bj[x])bj[x]=k;
    else num[len[x]]=k;
    len[x]=k;
}
int Qu[2000010],h;
bool TTT[2000010];
int main(){
    n=read();m=read();
    for(i=1;i<=n+m;i++)fa[i]=i;
    for(i=1;i<=n;i++)scanf("%s",ch[i]+1);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(ch[i][j] == '=')Do(i,j+n);
            else if(ch[i][j]=='<')Q[++t]={i,j+n};
    else Q[++t]=(node){j+n,i};
    for(i=1;i<=t;i++){
        int x=Find(Q[i].x),y=Find(Q[i].y);
        add(x,y);
        if(x==y){
            printf("No\n");
            exit(0);
        }
    }
    h=t=0;
    for(i=1;i<=n+m;i++)
        if( !dushu[i] && i ==Find(i) ){
            Qu[++t]=i;
            ans[i]=1;
        }
    while(h<t){
        x=Qu[++h];TTT[x]=1;
        for(i=bj[x];i;i=num[i]){
            ans[a[i]]=max(ans[a[i]],ans[x]+1);
            if(!--dushu[a[i]])Qu[++t]=a[i];
        }
    }
    for(i=1;i<=n+m;i++)
        if(i==Find(i)&&dushu[i]){
            puts("No");
            return 0;
        }
    printf("Yes\n");
    for(i=1;i<=n;i++)
		printf("%d ",ans[Find(i)]);
    printf("\n");
    for(i=n+1;i<=n+m;i++)
		printf("%d ",ans[Find(i)]);
    printf("\n");
    return 0;
}