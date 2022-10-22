#include<bits/stdc++.h>
#define ll long long 
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int mod=1e9+7;
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
int n,k;
void work(){
    ll ans=0;
    cin>>n>>k;
    int t=0;
    priority_queue<int>q;
    for(int i=1;i<=n;++i){
        int x;
        cin>>x;
        ans+=x;
        q.push(x-(n-i));
    }
    ll sum=ans;
    while(!q.empty()&&t<k){
        int x=q.top();
        q.pop();
        sum-=x+t;
        t++;
        ans=min(ans,sum);
    }
    cout<<ans<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--)work();
    return 0;
}

/*
1
4 1
5 10 11 5
*/