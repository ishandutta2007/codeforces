#include "bits/stdc++.h"
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
typedef vector<int> vi;
typedef vector<ll> vl;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

const int mn=1e6+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;
struct sparse{
    vector<ll>sp[20];
    sparse(vector<ll>v){
        for(int i=1;i<20;i++)sp[i].resize(v.size());
        sp[0]=v;
        for(int i=1;i<20;i++)for(int j=0;j+(1<<i)<=v.size();j++)
                sp[i][j]=max(sp[i-1][j],sp[i-1][j+(1<<(i-1))]);
    }
    ll query(int a,int b){
        a=max(a,0);
        b=min(b,int(sp[0].size())-1);
        if(a>b)return -inf;
        int l=31-__builtin_clz(b-a+1);
        return max(sp[l][a],sp[l][b-(1<<l)+1]);
    }
};
ll f[mn];
int main(){
#ifdef LOCAL
    freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
freopen("error.txt","w",stderr);
#endif
    cin.tie(0);
    cin.sync_with_stdio(0);
    int k,q;
    cin>>k;
    for(int i=0;i<6;i++)cin>>f[i];
    vector<ll>ori={0},ne;
    for(int iii=5;iii>=0;iii--){
        ne=vector<ll>(ori.size()*10);
        vector<ll>nori=ori;
        for(int i=0;i<nori.size();i++)nori[i]-=i*10/3*f[iii];
        vector<ll>nono[3];
        for(int i=0;i<nori.size();i++){
            nono[0].push_back(-inf);
            nono[1].push_back(-inf);
            nono[2].push_back(-inf);
            nono[i%3].back()=nori[i];
        }
        sparse sp[3]={sparse(nono[0]),sparse(nono[1]),sparse(nono[2])};
        for(int i=0;i<ne.size();i++){
            ll lim=i-(9*k-9);
            ll lim10=(lim+9)/10*10;
            ll ex[3];
            for(int j=0;j<3;j++){
                ll mo=i/10*10;
                while((mo/10+3000000)%3!=j)mo-=10;
                ll sub=(i-mo)/3;
                ex[j]=(sub+mo/3)*f[iii];
            }
            ll ans=-inf;
            for(int j=0;j<3;j++)ans=max(ans,ex[j]+sp[j].query(lim10/10,i/10));
            if(lim>=0){
                ll cand=lim/10*10;
                ll diff=i-cand,num;
                if(diff%3==0)num=diff/3;
                else num=3*k-3;
                ans=max(ans,num*f[iii]+ori[cand/10]);
            }
            ne[i]=ans;
        }
        ori=ne;
    }
    cin>>q;
    while(q--){
        int n;
        cin>>n;
        printf("%lld\n",ori[n]);
    }
}