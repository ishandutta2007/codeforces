#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
char r[maxn],b[maxn];
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
        scanf("%s",r+1);
        scanf("%s",b+1);
        int t1=0,t2=0;
        for(int i=1;i<=n;i++)if(r[i]>b[i])t1++;else if(r[i]<b[i])t2++;
        if(t1==t2)puts("EQUAL");
        else if(t1>t2)puts("RED");
        else puts("BLUE");
    }
    return 0;
}