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
        int n,k;
        n=read();k=read();
        if(n&1)printf("%d %d %d\n",1,(n-1)/2,(n-1)/2);
        else{
            if(n%4==0)printf("%d %d %d\n",n/2,n/4,n/4);
            else printf("%d %d %d\n",2,(n-2)/2,(n-2)/2);
        }
    }
    return 0;
}