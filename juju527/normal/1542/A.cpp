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
        int n;
        n=read();
        int n1=0,n2=0;
        for(int i=1;i<=2*n;i++)if(read()&1)n1++;else n2++;
        if(n1==n2)puts("Yes");
        else puts("No");
    }
    return 0;
}