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
int n,a[M],b[M],dp[M];
int top,s[M];
int main(){
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    for(int i=n;i>=1;--i){
        b[a[i]]=max(b[a[i]],i);
    }
    int l=1,r=0;
    for(int i=1;i<=n;++i){
        while(l<=r&&i>=b[a[s[l]]])l++;
        dp[i]=dp[i-1];
        if(l<=r)dp[i]=max(dp[i],dp[s[l]-1]+i-s[l]);
        if(b[a[i]]>b[a[s[r]]])s[++r]=i;
    }
    cout<<dp[n]<<endl;
    return 0;
}
/*
7
1 2 2 2 2 1 2
*/