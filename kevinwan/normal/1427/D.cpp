#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
typedef vector<int> vi;
typedef vector<ll> vl;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=52+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;
const ll half=(mod+1)/2;
const double PI=acos(-1);
int p[mn],q[mn];
vector<vector<int>>ans;
void reo(vector<int>v){
    if(v.size()==1)return;
    vector<int>pv(v.size());
    ans.push_back(v);
    pv[0]=0;
    for(int i=1;i<v.size();i++)pv[i]=pv[i-1]+v[i-1];
    int ct=0;
    for(int i=v.size()-1;i>=0;i--){
        for(int j=0;j<v[i];j++)q[ct++]=p[pv[i]+j];
    }
    memcpy(p,q,sizeof(p));
}
int main(){
#ifdef LOCAL_PROJECT
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
#else
#endif
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>p[i],p[i]--;
    bool lef=1^(n&1);
    for(int i=0;i<n;i++){
        if(lef){
            if(p[i]==i)continue;
            vector<int>v;
            for(int j=0;j<i;j++)v.push_back(1);
            int pi;
            for(int j=0;j<n;j++)if(p[j]==i)pi=j;
            v.push_back(pi-(i-1));
            if(pi!=n-1)v.push_back(n-1-pi);
            reo(v);
            lef^=1;
        }
        else{
            if(p[n-1-i]==i)continue;
            vector<int>v;
            for(int j=0;j<i;j++)v.push_back(1);
            int pi;
            for(int j=0;j<n;j++)if(p[j]==i)pi=j;
            v.push_back((n-1-(i-1))-pi);
            if(pi!=0)v.push_back(pi);
            reverse(v.begin(),v.end());
            reo(v);
            lef^=1;
        }
    }
    if(!lef){
        vector<int>v;
        for(int i=0;i<n;i++)v.push_back(1);
        reo(v);
        lef^=1;
    }
    printf("%d\n",ans.size());
    for(auto v:ans){
        printf("%d ",v.size());
        for(int x:v)printf("%d ",x);
        printf("\n");
    }
}