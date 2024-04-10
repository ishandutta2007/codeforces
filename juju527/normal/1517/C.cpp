#include<bits/stdc++.h>
using namespace std;
const int maxn=505;
int p[maxn];
int l[maxn],a[maxn][maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int main(){
    int n;
    n=read();
    for(int i=1;i<=n;i++)a[i][i]=p[i]=read();
    for(int i=1;i<=n;i++)l[i]=0;
    for(int i=1;i<=n;i++){
        if(p[i]==1)continue;
        int k=i,num=p[i],pos=i;
        while(num){
            num-=pos-l[k];
            for(int j=l[k]+1;j<=pos;j++)a[k][j]=p[i];
            int P=pos;
            pos=l[k]+1;
            l[k]=P;
            k++;
        }
    }
    for(int i=1;i<=n;i++,puts(""))for(int j=1;j<=i;j++)printf("%d ",a[i][j]);
    return 0;
}