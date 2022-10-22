#include<bits/stdc++.h>
using namespace std;
const int maxn=55;
int n;
char op[1];
int a[maxn][maxn];
int p[2*maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int t[maxn*maxn];
int pos[maxn];
int v[2*maxn][maxn];
queue<int>q;
void solve(bool op){
    for(int i=1;i<=n;i++){
        int len=0;
        for(int j=1;j<=n*n;j++)t[j]=0;
        for(int j=1;j<=n;j++)t[a[i][j]]=j+n;
        if(!op){for(int j=n*n;j>=1;j--)if(t[j])v[i][++len]=t[j];}
        else{for(int j=1;j<=n*n;j++)if(t[j])v[i][++len]=t[j];}
        len=0;
        for(int j=1;j<=n*n;j++)t[j]=0;
        for(int j=1;j<=n;j++)t[a[j][i]]=j;
        if(!op){for(int j=1;j<=n*n;j++)if(t[j])v[i+n][++len]=t[j];}
        else{for(int j=n*n;j>=1;j--)if(t[j])v[i+n][++len]=t[j];}
        q.push(i);p[i]=p[i+n]=0;pos[i]=1;
    }
    while(!q.empty()){
        int k=q.front();
        q.pop();
        for(int i=pos[k];i<=n;i++){
            int j=v[k][i];
            if(!p[j]){p[k]=j,p[j]=k,pos[k]=i+1;break;}
            else{
                int x=p[j];
                if((a[x][j-n]>a[k][j-n])^op){p[x]=0,p[k]=j,p[j]=k,pos[k]=i+1;q.push(x);break;}
            }
        }
    }
    return ;
}
int main(){
    int T;
    T=read();
    while(T--){
        n=read();
        for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)a[i][j]=read();
        puts("B");fflush(stdout);scanf("%s",op);
        if(op[0]=='I')for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)a[i][j]=n*n+1-a[i][j];
        int x=read();
        solve(x>n);
        while(x!=-1){printf("%d\n",p[x]);fflush(stdout);x=read();}
    }
    return 0;
}