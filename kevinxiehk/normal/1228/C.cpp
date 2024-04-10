#include<bits/stdc++.h>
using namespace std;
const int MOD=1000000007;
long long bigmod(long long a,long long p,int m){
    if(p==0)return 1; 
    if(p%2)return((a%MOD)*(bigmod(a,p-1,MOD)))%MOD; 
    else{
        long long c=bigmod(a,p/2,MOD); 
        return ((c%MOD)*(c%MOD))%MOD;
    }
}
int main(){
    long long n,m;
    cin>>n>>m;
    unsigned long long ans=1;
    queue<long long>q;
    for(int i=2;i*i<=n;i++){
        if(n%i==0)q.push(i);
        while(n%i==0)n/=i;
    }
    if(n!=1)q.push(n);
    while(!q.empty()){
        for(long long i=q.front();i<=m;i*=q.front()){
            //cout<<i<<" "<<m/i<<endl;
            ans*=bigmod(q.front(),m/i,MOD);
            ans%=MOD;
            if(log(1.0*i*q.front())>log(1.0*m))break;
        }
        q.pop();
    }
    cout<<ans<<endl;
    return 0;
}