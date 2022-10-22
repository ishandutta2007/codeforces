#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5;
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
        if(n==1){
            if(!a[1])puts("1 2");
            else puts("2 1");
            continue;
        }
        bool flag=0;
        int pos;
        for(int i=1;i<n;i++)if(a[i]<a[i+1]){flag=1;pos=i;break;}
        if(flag){
            for(int i=1;i<=pos;i++)printf("%d ",i);
            printf("%d ",n+1);
            for(int i=pos+1;i<=n;i++)printf("%d ",i);
            puts("");
            continue;
        }
        if(a[n]<a[1]){
            printf("%d %d ",n,n+1);
            for(int i=1;i<n;i++)printf("%d ",i);
            puts("");
            continue;
        }
        if(a[n]){
            printf("%d ",n+1);
            for(int i=1;i<=n;i++)printf("%d ",i);
        }
        else
            for(int i=1;i<=n+1;i++)printf("%d ",i);
        puts("");
    }
    return 0;
}