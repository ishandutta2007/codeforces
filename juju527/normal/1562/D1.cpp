#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+5;
char s[maxn];
int sum[maxn];
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
        int n,q;
        n=read();q=read();
        scanf("%s",s+1);
        for(int i=1;i<=n;i++){
            int x=(s[i]=='+'?0:1);
            x^=((i&1)^1);
            if(!x)sum[i]=sum[i-1]+1;
            else sum[i]=sum[i-1]-1;
        }
        for(int i=1;i<=q;i++){
            int l,r;
            l=read();r=read();
            if(sum[r]==sum[l-1])puts("0");
            else if((r-l+1)&1)puts("1");
            else puts("2");
        }
    }
    return 0;
}