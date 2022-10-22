#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=26;
ll fact[mn];
ll num[mn],lim,p[mn];
vector<ll> av[mn],bv[mn];
vector<ll>bs;
ll s;
ll f(ll x){
    if(x>=mn)return s+1;
    return fact[x];
}
int main()
{
    int n,k,i;
    scanf("%d%d%lld",&n,&k,&s);
    //printf("0fkjdshkjfhsd");
    fact[0]=1;
    for(i=1;i<mn;i++){
        fact[i]=fact[i-1]*i;
        if(fact[i]>s){
            fact[i]=s+1;
        }
    }
    for(i=0;i<n;i++)scanf("%lld",num+i);
    p[0]=1;
    for(i=1;i<=n;i++)p[i]=p[i-1]*3;
    int a=n/2,b=n-a,j;
    for(i=0;i<p[a];i++){
        int u=0;
        ll s=0;
        for(j=0;j<a;j++){
            if(i/p[j]%3==1)s+=num[j];
            else if(i/p[j]%3==2)u++,s+=f(num[j]);
        }
        av[u].push_back(s);
    }
    for(i=0;i<p[b];i++){
        int u=0;
        ll s=0;
        for(j=0;j<b;j++){
            if(i/p[j]%3==1)s+=num[a+j];
            else if(i/p[j]%3==2)u++,s+=f(num[a+j]);
        }
        bv[u].push_back(s);
    }
    for(i=0;i<=k;i++)sort(av[i].begin(),av[i].end()),sort(bv[i].begin(),bv[i].end());
    ll ans=0;
    for(i=k;i>=0;i--){
        for(ll x:bv[k-i])bs.push_back(x);
        sort(bs.begin(),bs.end());
        int num=0;
        for(int l=0,r=bs.size()-1;l<av[i].size();l++){
            if(l&&av[i][l]==av[i][l-1]){
                ans+=num;
            }
            else{
                num=0;
                while(r>=0&&bs[r]>=s-av[i][l]){
                    if(av[i][l]+bs[r]==s)num++;
                    r--;
                }
                ans+=num;
            }
        }
    }
    printf("%lld",ans);
}