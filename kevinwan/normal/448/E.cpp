#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=1e5+10;
const ll mod=1e6+3;
int num=1e5;
ll x,k;
ll hail=0;
vector<ll>fact;
vector<vector<ll>>sf;
void solve(ll x,ll k){
    if(!num)return;
    if(!k){
        printf("%lld ",fact[x]);
        num--;
        return;
    }
    printf("1 ");
    num--;
    if(!num)return;
    if(!x)return;
    for(ll y:sf[x]){
        if(!y)continue;
        solve(y,k-1);
    }
}
int main(){
    scanf("%lld%lld",&x,&k);
    vector<ll>rev;
    for(ll i=1;i*i<=x;i++){
        if(x%i==0){
            fact.push_back(i);
            if(i*i!=x)rev.push_back(x/i);
        }
    }
    for(ll i=(ll)rev.size()-1;i>=0;i--)fact.push_back(rev[i]);
    sf.resize(fact.size());
    for(ll i=0;i<fact.size();i++){
        for(ll j=0;j<=i;j++){
            if(fact[i]%fact[j]==0)sf[i].push_back(j);
        }
    }
    solve(fact.size()-1,k);
}