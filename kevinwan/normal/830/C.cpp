#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
mt19937 rng(423978);
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll>pll;
const ll mod=1e9+7;
const int mn=3e5+10;
int a[110];
int th=32000;
int main(){
    int n;
    ll k;
    scanf("%d%lld",&n,&k);
    vector<ll>v;
    v.push_back(0x3f3f3f3f3f3f3f3f);
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
        for(int j=th;j>=1;j--){
            if((a[i]-1)/j>=th)v.push_back({(a[i]-1)/j+1});
        }
    }
    ll ans=0,cur=0,num=0;
    for(ll i=1;i<=th;i++){
        cur=num=0;
        for(int j=0;j<n;j++){
            cur+=i-((a[j]-1)%i+1);
            num+=(a[j]-1)/i+1;
        }
        if(cur<=k)ans=i;
    }
    sort(v.begin(),v.end());
    ll lef=k-cur;
    if(lef>=0)ans=th+lef/num;
    cur+=(v[0]-th)*num;
    for(int i=0;i+1<v.size();i++){
        cur-=v[i];
        num--;
        ll lef=k-cur;
        if(lef>=0)ans=v[i]+lef/num;
        cur+=(v[i+1]-v[i])*num;
    }
    printf("%lld",ans);
}