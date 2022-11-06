#include<bits/stdc++.h>
using namespace std;
const int N=5555;
int b,q,m,n,w[N],a[N][N],t[N];
int gb(){
    int a=0;char ch=getchar();
    while(!(ch==48||ch==49))ch=getchar();
    while(ch==48||ch==49)a=(a<<1)|(ch^48),ch=getchar();
    return a;
}
int main(){
    scanf("%d%d%d",&b,&m,&q),n=1<<b;
    for(int i=1;i<=b;i++)scanf("%d",&w[b-i]);
    while(m--){
        int v=gb();
        //printf("v=%d\n",v);
        ++t[v];
    }
    for(int i=0;i<n;i++)for(int j=0;j<n;j++){
        int wu=0;
        for(int k=0;k<b;k++)if((1<<k&i)==(1<<k&j))wu+=w[k];
        a[i][wu]+=t[j];//printf("%d %d %d\n",i,wu,j);
    }
    for(int i=0;i<n;i++)for(int j=1;j<N;j++)a[i][j]+=a[i][j-1];
    while(q--){
        int s=gb(),b;scanf("%d",&b);
        printf("%d\n",a[s][b]);
    }
    return 0;
}