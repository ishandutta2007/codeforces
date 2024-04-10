#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int n,k;
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
        n=read();k=read();
        printf("%d\n",n-(k+1)/2);
        for(int i=(k+1)/2;i<=n;i++)if(i!=k)printf("%d ",i);
        puts("");
    }
    return 0;
}