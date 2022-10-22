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
const int M=1e5+9;
int n;
int a[M],b[M];
void work(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    int x=1;
    for(int i=1;i<=n;++i){
        if(i&1)b[i]=a[x],x++;
    }
    for(int i=1;i<=n;++i){
        if((i&1)==0)b[i]=a[x],x++;
    }
    for(int i=1;i<=n;++i){
        int l=(i-2+n)%n+1,r=(i%n)+1;
        if(i&1){
            if(b[l]>b[i]&&b[i]<b[r])continue;
            puts("NO");
            return;
        }
        else{
            if(b[l]<b[i]&&b[i]>b[r])continue;
            puts("NO");
            return;
        }
    }
    puts("YES");
    for(int i=1;i<=n;++i){
        printf("%d%c",b[i]," \n"[i==n]);
    }
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--)work();
    return 0;
}
/*

1
6
1 10 
2 9
5 5

1 5 2 10 5 9

*/