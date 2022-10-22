#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int f1[maxn],f2[maxn];
int len;
int res[maxn][2];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int find1(int x){return x==f1[x]?x:f1[x]=find1(f1[x]);}
int find2(int x){return x==f2[x]?x:f2[x]=find2(f2[x]);}
int main(){
    int n,m1,m2;
    n=read();m1=read();m2=read();
    for(int i=1;i<=n;i++)f1[i]=f2[i]=i;
    for(int i=1;i<=m1;i++){
        int u,v;
        u=find1(read());v=find1(read());
        f1[u]=v;
    }
    for(int i=1;i<=m2;i++){
        int u,v;
        u=find2(read());v=find2(read());
        f2[u]=v;
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(find1(i)==find1(j)||find2(i)==find2(j))continue;
            f1[find1(i)]=find1(j);
            f2[find2(i)]=find2(j);
            res[++len][0]=i;res[len][1]=j;
        }
    }
    printf("%d\n",len);
    for(int i=1;i<=len;i++)
        printf("%d %d\n",res[i][0],res[i][1]);
    return 0;
}