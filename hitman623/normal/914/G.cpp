#include <bits/stdc++.h>
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<int,pii>    
#define aint(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int expo(int base,int exponent,int mod){                                //return base^exponent modulo modulus
    int ans=1;
    while(exponent!=0){
        if((exponent&1)==1){
            ans=(1LL*ans*base)%mod;
        }
        base=(1LL*base*base)%mod;
        exponent>>=1;
    }
    return ans;
}
int s[1<<17],n,saorsb[1<<17],sc[1<<17],sdxorse[1<<17],f[1<<17],inv=expo(1<<17,hell-2,hell);
int mod=hell,lim=(1<<17);
void xorFWHT(int *data,int dim,bool inverse){
    int len,i,j,u,v;
    for(len=1;2*len<=dim;len<<=1){
        for(i=0;i<dim;i+=2*len){
            for(j=0;j<len;j++){
                u=data[i+j];
                v=data[i+len+j];
                if(!inverse){
                    data[i+j]=(u+v)%mod;
                    data[i+len+j]=(u-v+mod)%mod;
                } 
                else{
                    data[i+j]=(u+v)%mod;
                    data[i+len+j]=(u-v+mod)%mod;
                }
            }
        }
    }
}
void andFWHT(int *data,int dim,bool inverse){
    int len,i,j,u,v;
    for(len=1;2*len<=dim;len<<=1){
        for(i=0;i<dim;i+=2*len){
            for(j=0;j<len;j++){
                u=data[i+j];
                v=data[i+len+j];
                if(!inverse){
                    data[i+j]=v;
                    data[i+len+j]=(u+v)%mod;
                } 
                else{
                    data[i+j]=(v-u+mod)%mod;
                    data[i+len+j]=u;
                }
            }
        }
    }
}
void solve()
{
    int ans=0;
    cin>>n;
    rep(i,0,n){
        int x;
        cin>>x;
        s[x]++;
        saorsb[x]=s[x];
        sc[x]=s[x];
        sdxorse[x]=s[x];
    }
    f[0]=0;
    f[1]=1;
    rep(i,2,1<<17){
        f[i]=(f[i-1]+f[i-2])%hell;
    }
    rep(i,0,1<<17){
        saorsb[i]=(1LL*s[i]*s[0])%hell;
        for(int j=i;j>0;j=i&(j-1)){
            saorsb[i]=(saorsb[i]+1LL*s[j]*s[i^j])%hell;
        }
    }
    rep(i,0,1<<17){
        saorsb[i]=(1LL*saorsb[i]*f[i])%hell;
    }
    rep(i,0,1<<17){
        sc[i]=(1LL*sc[i]*f[i])%hell;
    }
    xorFWHT(sdxorse,1<<17,0);
    rep(i,0,1<<17){
        sdxorse[i]=(1LL*sdxorse[i]*sdxorse[i])%hell;
    }
    xorFWHT(sdxorse,1<<17,1);
    rep(i,0,1<<17){
        sdxorse[i]=(1LL*sdxorse[i]*inv)%hell;
        sdxorse[i]=(1LL*sdxorse[i]*f[i])%hell;
    }
    andFWHT(saorsb,1<<17,0);
    andFWHT(sc,1<<17,0);
    andFWHT(sdxorse,1<<17,0);
    rep(i,0,1<<17){
        sc[i]=(1LL*sc[i]*saorsb[i])%hell;
        sc[i]=(1LL*sc[i]*sdxorse[i])%hell;
    }
    andFWHT(sc,1<<17,1);
    rep(i,0,17){
        sc[i]=(1LL*sc[i]*inv)%hell;
        ans=(ans+sc[1<<i])%hell;
    }
    cout<<ans;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--)
        solve();
    return 0;
}