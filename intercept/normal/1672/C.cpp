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
const int M=2e5+9;
int n;
int a[M];
void work(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    int ma=0,mi=0;
    for(int i=1;i<n;++i){
        if(a[i]==a[i+1])ma=i;
    }
    for(int i=n;i>1;--i){
        if(a[i]==a[i-1])mi=i;
    }
    if(ma){
        if(ma==mi)puts("1");
        else printf("%d\n",max(ma-mi,0));
    }
    else puts("0");
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--)work();
    return 0;
}
/*
6
2
1 2
3
1 1 2
4
1 2 1 2
5
1 1 1 2 2
6
1 1 2 2 2 2
*/