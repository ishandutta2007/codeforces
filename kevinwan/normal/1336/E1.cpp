#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int mn=1e5+10;
const int mm=53;
const ll mod=998244353;
ll basis[mm];
int m;
bool add(ll x){
    for(int i=m-1;i>=0;i--)if((x>>i)&1){
        if(basis[i])x^=basis[i];
        else{
            basis[i]=x;
            return 1;
        }
    }
    return 0;
}
ll ans[mm+1],num[mn+1];
ll ch[mm+10][mm+10];
ll ve[mm][mm];
int rep[mm];
ll rehail(ll x){
    ll ans=0;
    for(int i=0;i<m;i++)ans|=((x>>i)&1)<<rep[i];
    return ans;
}
int main(){
    int n,k=0;
    ll ex=1;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        ll x;
        scanf("%lld",&x);
        if(add(x))k++;
        else ex=ex*2%mod;
    }
    vector<ll>bas;
    memset(rep,-1,sizeof(rep));
    int cur=0;
    for(int i=m-1;i>=0;i--)if(basis[i]){
        for(int j=i-1;j>=0;j--)if(basis[j]&&((basis[i]>>j)&1))basis[i]^=basis[j];
    }
    for(int i=0;i<m;i++)if(basis[i])rep[i]=cur++,bas.push_back(basis[i]);
    for(int i=0;i<m;i++)if(!basis[i])rep[i]=cur++;
    for(ll&x:bas)x=rehail(x);
    if(k<=27){
        ll xs=0;
        ans[0]++;
        for(int i=1;i<1<<k;i++){
            for(int j=__builtin_ctz(i);j>=0;j--)xs^=bas[j];
            ans[__builtin_popcountll(xs)]++;
        }
        for(int i=0;i<=m;i++)printf("%lld ",ans[i]*ex%mod);
    }
    else{
        vector<ll>rbas;
        for(int i=k;i<m;i++){
            ll x=0;
            for(int j=0;j<k;j++)x|=((ll)(bas[j]>>i)&1)<<j;
            x|=1LL<<i;
            rbas.push_back(x);
        }
        //for(int i=0;i<k;i++)printf("%lld ",__builtin_popcountll(rbas[0]&bas[i]));
        ch[0][0]=1;
        for(int i=1;i<m+10;i++){
            ch[i][0]=1;
            for(int j=1;j<m+10;j++){
                ch[i][j]=(ch[i-1][j-1]+ch[i-1][j])%mod;
            }
        }
        for(int i=0;i<=m;i++){
            for(int j=0;j<=m;j++){
                for(int l=0;l<=min(i,j);l++){
                    if(l&1){
                        ve[i][j]-=ch[j][l]*ch[m-j][i-l];
                    }
                    else{
                        ve[i][j]+=ch[j][l]*ch[m-j][i-l];
                    }
                    ve[i][j]%=mod;
                }
            }
        }
        num[0]++;
        ll xs=0;
        for(int i=1;i<1<<m-k;i++){
            for(int j=__builtin_ctz(i);j>=0;j--)xs^=rbas[j];
            num[__builtin_popcountll(xs)]++;
        }
        for(int i=0;i<=m;i++){
            for(int j=0;j<=m;j++){
                ans[i]+=num[j]*ve[i][j],ans[i]%=mod;
            }
        }
        for(int i=0;i<m-k;i++)ex*=(mod+1)/2,ex%=mod;
        for(int i=0;i<=m;i++){
            if(ans[i]<0)ans[i]+=mod;
            printf("%lld ",ans[i]*ex%mod);
        }
    }
}