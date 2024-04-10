#include "bits/stdc++.h"
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
typedef vector<int> vi;
typedef vector<ll> vl;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const ll inf=0x3f3f3f3f3f3f3f3f;
const int mn=5e5+10;
const ll mod=1e9+7;

int p[mn];
int f(int x){return x==p[x]?x:(p[x]=f(p[x]));}

int main(){
#ifdef LOCAL
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
freopen("error.txt","w",stderr);
#endif
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    vector<int>ans;
    iota(p,p+mn,0);
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        vector<int>v(k);
        for(int j=0;j<k;j++)cin>>v[j],v[j]=f(v[j]);
        sort(v.begin(),v.end());
        if(k==1){
            if(v[0]){
                p[v[0]]=0;
                ans.push_back(i);
            }
        }
        else{
            if(v[0]^v[1]){
                p[v[1]]=v[0];
                ans.push_back(i);
            }
        }
    }
    ll num=1;
    for(int i=0;i<ans.size();i++)num<<=1,num%=mod;
    printf("%lld %lld\n",num,ans.size());
    for(int x:ans)printf("%d ",x+1);
}