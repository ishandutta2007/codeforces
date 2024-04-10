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
        int l,r,b;
        l=read();r=read();
        b=(r+1)/2;
        if(b<l)printf("%d\n",r-l);
        else printf("%d\n",b-1);
    }
    return 0;
}