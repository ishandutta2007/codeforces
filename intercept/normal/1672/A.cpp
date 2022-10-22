#include<bits/stdc++.h>
#define ll long long 
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int mod=998244353;
int kpow(int x,int y,int rex=1){
    for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*x*rex%mod;
    return rex;
}
int exgcd(int a,int b,int &x,int &y){
    int t=b?exgcd(b,a%b,y,x):a;
    if(!b)x=1,y=0;
    else y-=a/b*x;
    return t;
}
int n;
void work(){
    scanf("%d",&n);
    int sum=0;
    for(int i=1;i<=n;++i){
        int x;
        scanf("%d",&x);
        x--;
        sum+=x;
    }
    puts(sum&1?"errorgorn":"maomao90");
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--)work();
    return 0;
}