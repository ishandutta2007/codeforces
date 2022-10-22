#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
typedef long long ll;
typedef pair<ll,ll>pll;
const ll mod=998244353;
const int mn=1e6+10;
ll a[mn];
ll ans=1,t;
inline ll gcd(ll a,ll b){
    while(b)t=a%b,a=b,b=t;
    return a;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%lld",a+i);
    ll ans=1;
    for(int i=0;i<10;i++){
        int id=rng()%n;
        vector<ll>f,fn;
        ll x=a[id];
        for(ll j=1;j*j<=x;j++)if(x%j==0){
            f.push_back(j);
            if(j*j!=x)f.push_back(x/j);
        }
        sort(f.begin(),f.end());
        fn.resize(f.size());
        vector<ll>v;
        for(int j=0;j<n;j++)v.push_back(gcd(x,a[j]));
        sort(v.begin(),v.end());
        for(int j=0,k=0;j<n;j++){
            while(f[k]<v[j])k++;
            fn[k]++;
        }
        for(int j=0;j<f.size();j++){
            if(f[j]<ans)continue;
            int cnt=0;
            for(int k=j;k<f.size();k++)if(f[k]%f[j]==0)cnt+=fn[k];
            if(cnt*2>=n)ans=max(ans,f[j]);
        }
    }
    printf("%lld",ans);
}