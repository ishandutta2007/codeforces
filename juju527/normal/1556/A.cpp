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
        int a,b;
        a=read();b=read();
        if(a==0&&b==0){puts("0");continue;}
        if((a&1)!=(b&1))puts("-1");
        else if(a==b)puts("1");
        else puts("2");
    }
    return 0;
}