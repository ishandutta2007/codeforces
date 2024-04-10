#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=105;
int b[maxn][maxn];
struct node{
    int id,data;
    bool operator <(node i)const{
        return data<i.data;
    }
}mn[maxn];
int res[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int main(){
    int T;
    T=read();
    while(T--){
        int n,m;
        n=read();m=read();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)b[i][j]=read();
            sort(b[i]+1,b[i]+m+1);
        }
        for(int i=1;i<=m;i++){
            mn[i]=(node){i,b[1][i]};
            printf("%d ",b[1][i]);
        }
        puts("");
        for(int i=2;i<=n;i++){
            for(int j=1;j<=m;j++){
                mn[m-j+1].data=min(mn[m-j+1].data,b[i][j]);
                res[mn[m-j+1].id]=b[i][j];
            }
            sort(mn+1,mn+m+1);
            for(int j=1;j<=m;j++)printf("%d ",res[j]);
            puts("");
        }
    }
    return 0;
}