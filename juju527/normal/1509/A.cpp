#include<bits/stdc++.h>
using namespace std;
const int maxn=2005;
int a[maxn];
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
        int n;
        n=read();
        for(int i=1;i<=n;i++)a[i]=read();
        for(int i=1;i<=n;i++)if(a[i]&1)printf("%d ",a[i]);
        for(int i=1;i<=n;i++)if(a[i]%2==0)printf("%d ",a[i]);
        puts("");
    }
    return 0;
}