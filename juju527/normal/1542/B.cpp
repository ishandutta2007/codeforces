#include<bits/stdc++.h>
#define ll long long
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
        int n,a,b;
        n=read();a=read();b=read();
        if(a==1){
            if((n-1)%b==0)puts("Yes");
            else puts("No");
            continue;
        }
        ll s=1;
        bool tag=0;
        while(s<=n){
            if((n-s)%b==0){tag=1;break;}
            s*=a;
        }
        if(tag)puts("Yes");
        else puts("No");
    }
    return 0;
}