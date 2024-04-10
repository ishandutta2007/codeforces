#include<bits/stdc++.h>
using namespace std;
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
        int n,m,k;
        n=read();m=read();k=read();
        if((n-1+n*(m-1))==k)puts("YES");
        else puts("NO");
    }
    return 0;
}