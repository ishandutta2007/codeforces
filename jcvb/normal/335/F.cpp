#include<cstring>
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<queue>
#include<vector>
#define inf 1000000000000000ll
using namespace std;
typedef long long ll;
int n;
int a[500005];
int tot=0,v[500005],cnt[500005];
priority_queue<ll,vector<ll>,greater<ll> >qu;
ll st[1000005];int top=0;
int main()
{
    scanf("%d",&n); 
    ll ans=0;
    for (int i=1;i<=n;i++)scanf("%d",&a[i]),ans+=a[i];
    sort(a+1,a+1+n,greater<int>());
    for (int i=1;i<=n;i++){
        if(a[i]!=a[i-1]){
            v[++tot]=a[i];
            cnt[tot]=1;
        }else{
            cnt[tot]++;
        }
    }
    for (int i=1,su=0;i<=tot;su+=cnt[i++]){
        int nfree=su-2*qu.size();nfree=min(nfree,cnt[i]);
        top=0;
        for (int j=1;j<=nfree;j++)st[++top]=v[i];
        int into=min(su,cnt[i])-nfree;
        for (int k=1;k<=into;k+=2){
            ll tmp=qu.top();qu.pop();
            if(v[i]>=tmp){
                st[++top]=v[i];
                if(k!=into)st[++top]=v[i];
            }else{
                st[++top]=tmp;
                if(k!=into){
                    st[++top]=2*v[i]-tmp;
                    if(st[top]<0)top--;
                }
            }
        }
        for (int k=1;k<=top;k++)qu.push(st[k]);
    }
    while(!qu.empty())ans-=qu.top(),qu.pop();
    cout<<ans<<endl;
    return 0;
}