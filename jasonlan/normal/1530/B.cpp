#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<bitset>
using namespace std;
const int maxn=501,maxm=0,mod=0;
int n,m;
int a[maxn][maxn];
inline int read(){
    int res=0;
    char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
    return res;
}
int qmod(int x){
    return x>=mod?x-mod:x;
}
int qdec(int x){
    return x<0?x+mod:x;
}
void proc(){
    n=read();m=read();
    for(int i=0;i<=n+1;++i)
        for(int j=0;j<=m+1;++j)
            a[i][j]=0;
    if(n%2==1&&m%2==1){
        for(int i=1;i<=m;i+=2)a[1][i]=a[n][i]=1;
        for(int i=1;i<=n;i+=2)a[i][1]=a[i][m]=1;
    }
    else if(n%2==0&&m%2==1){
        for(int i=1;i<=m;i+=2)a[1][i]=a[n][i]=1;
        for(int i=1;i<n-1;i+=2)a[i][1]=a[i][m]=1;
    }
    else if(n%2==1&&m%2==0){
        for(int i=1;i<m-1;i+=2)a[1][i]=a[n][i]=1;
        for(int i=1;i<=n;i+=2)a[i][1]=a[i][m]=1;
    }
    else{
        for(int i=1;i<=m;i+=2)a[1][i]=a[n][m-i+1]=1;
        for(int i=1;i<n-1;i+=2)a[i][1]=a[n-i+1][m]=1;
    }
    for(int i=1;i<=n;++i,putchar('\n'))
        for(int j=1;j<=m;++j)
            printf("%d",a[i][j]);
    putchar('\n');
}
int main(){
    int T=read();
    while(T--)proc();
    return 0;
}