#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
    ll x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int main(){
    int T;
    T=read();
    while(T--){
        ll n;
        n=read();
        if(n%2050){puts("-1");continue;}
        n/=2050;
        int res=0;
        while(n)res+=n%10,n/=10;
        printf("%d\n",res);
    }
    return 0;
}