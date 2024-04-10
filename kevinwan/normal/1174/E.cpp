#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
mt19937_64 rngll(rng());
const int mn=1e6+10;
const ll mod=1e9+7;
int num[mn][2];
ll hail(vector<int>v){
    ll ans=1,cur=0;
    for(int x:v){
        if(x==0)return 0;
        ans*=x,ans%=mod;
        cur++;
        for(int i=0;i<x-1;i++,cur++){
            ans*=cur,ans%=mod;
        }
    }
    return ans;
}
int main(){
    int n;
    scanf("%d",&n);
    int l=31-__builtin_clz(n);
    ll ans=0;
    for(int i=0;i<=l;i++){
        num[i][0]=(n>>i)-(n>>(i+1)),num[i][1]=((n/3)>>i)-((n/3)>>(i+1));
    }
    vector<int>v;
    for(int i=0;i<=l;i++)v.push_back(num[i][0]);
    ans+=hail(v);
    v.clear();
    for(int i=0;i<l;i++){
        for(int j=0;j<i;j++){
            v.push_back(num[j][0]);
        }
        int vesh=0;
        for(int j=i;j<=l;j++)vesh+=num[j][0]-num[j][1];
        v.push_back(vesh);
        for(int j=i;j<l;j++)v.push_back(num[j][1]);
        ans+=hail(v),ans%=mod;
        v.clear();
    }
    printf("%lld",ans);
}