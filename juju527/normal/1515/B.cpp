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
        int x=sqrt(n/2),y=sqrt(n/4);
        if(n%2==0&&x*x==n/2||n%4==0&&y*y==n/4)puts("YES");
        else puts("NO");
    }
    return 0;
}