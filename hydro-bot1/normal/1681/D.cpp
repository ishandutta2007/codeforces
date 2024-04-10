// Hydro submission #62c7c845c3a9fda5622c48fe@1657260102419
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pf push_first
#define F first 
#define S second
#define pof pop_front
#define pob pop_back
map<int,int> mp;
int f(int n,int x){
    if(mp[x])return mp[x];
    int b[10];
    for(int i=0;i<10;i++)b[i]=0;
    int n1=x,k=0;
    while(n1>0){
        b[(n1%10)]=1;
        n1/=10;
        k++;
    }
    if(k>n)return 100;
    if(k==n)return 0;
    int ans=100;
    for(int i=9;i>=2;i--){
        if(b[i]==1){ans=min(ans,1+f(n,i*x));}
    }
    return mp[x]=ans;
}
void solve(int ttt){
   int n,x;
   cin>>n>>x;
   int ans=f(n,x);
   if(ans>=100)cout<<-1<<endl;
   else cout<<ans<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve(1);
}