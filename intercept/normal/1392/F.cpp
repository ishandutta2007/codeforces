#include<bits/stdc++.h>
#define ll long long 
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int mod=1e9+7;
const double eps=1e-9;
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
const int M=1e6+9;
int n;
ll a[M];
int top=0;
int s[M];
ll bit[M];
void add(int x,ll v){
    for(;x<=n;x+=x&-x)bit[x]+=v;
}
ll ask(int x,ll rex=0){
    for(;x;x-=x&-x)rex+=bit[x];
    return rex;
}
void change(int l,int r,ll v){
    add(l,v);
    add(r+1,-v);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
    change(1,1,a[1]);
    for(int i=2;i<=n;++i){
        while(top){
            if(a[i]>=ask(i-1)+1+i-s[top]){
                change(s[top],i-1,1);
                a[i]-=i-s[top];
                top--;
            }
            else{
                ll v=ask(i-1);
                if(a[i]>v+1){
                    change(s[top],s[top]+a[i]-v-2,1);
                    s[top]+=a[i]-v-1;
                    a[i]-=a[i]-v-1;
                }
                break;
            }
        }
        if(top==0){
            ll k=(a[i]-ask(i-1))/i;
            change(1,i-1,k);
            
            a[i]-=k*(i-1);
            ll v=ask(i-1);
            if(a[i]>v+1){
                change(1,1+a[i]-v-2,1);
                s[++top]=a[i]-v;
                a[i]-=a[i]-v-1;
            }
        }
        if(a[i]==ask(i-1))s[++top]=i;
        
        change(i,i,a[i]);
    }
    for(int i=1;i<=n;++i)printf("%lld ",ask(i));
    return 0;
}
/*

0 0 1 1 2 3
*/