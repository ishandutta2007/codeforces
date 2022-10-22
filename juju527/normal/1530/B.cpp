#include<bits/stdc++.h>
using namespace std;
const int maxn=25;
int a[maxn][maxn];
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
        memset(a,0,sizeof(a));
        for(int i=1;i<=m;i++)a[1][i]=(i&1);
        for(int i=3;i<=n;i++)a[i][m]=(i&1);
        for(int i=m-2;i>=1;i--)a[n][i]=((m-i+1)&1);
        for(int i=n-2;i>=3;i--)a[i][1]=((n-i+1)&1);
        for(int i=1;i<=n;i++,puts(""))
            for(int j=1;j<=m;j++)
                printf("%d",a[i][j]);
    }
    return 0;
}