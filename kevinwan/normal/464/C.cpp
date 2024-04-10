#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=1e5+10;
const ll mod=1e9+7;
ll dig[10],v[10];
ll po(ll a,ll b){
    ll ans=1;
    for(;b;b>>=1,a=a*a%mod)if(b&1)ans=ans*a%mod;
    return ans;
}
string qqq[mn];
int main(){
    string s;
    cin>>s;
    int qq,i;
    scanf("%d",&qq);
    for(i=0;i<10;i++)dig[i]=1,v[i]=i;
    for(i=0;i<qq;i++)cin>>qqq[i];
    for(i=0;i<qq;i++){
        string q=qqq[qq-1-i];
        int tar=q[0]-'0';
        ll nv=0,nd=0;
        for(int j=3;j<q.size();j++){
            q[j]-='0';
            nd=(nd+dig[q[j]])%(mod-1);
            nv=(nv*po(10,dig[q[j]])+v[q[j]])%mod;
        }
        dig[tar]=nd,v[tar]=nv;
    }
    ll ans=0;
    for(i=0;i<s.size();i++)s[i]-='0',ans=(ans*po(10,dig[s[i]])+v[s[i]])%mod;
    printf("%lld",ans);
}