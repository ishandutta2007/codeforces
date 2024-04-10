#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=1e5+10;
struct nd{
    nd* c[2];
};
nd* trie;
ll a[mn],p[mn],s[mn];
void add(nd*&n,int p,ll x){
    if(p==-1)return;
    bool k=(x>>p)&1;
    if(!n->c[k])n->c[k]=new nd();
    add(n->c[k],p-1,x);
}
ll fin(nd*&n,int p,ll x){
    if(p==-1)return 0;
    bool k=(x>>p&1);
    if(n->c[!k])return (1LL<<p)+fin(n->c[!k],p-1,x);
    else return fin(n->c[k],p-1,x);
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,i;
    cin>>n;
    for(i=0;i<n;i++)cin>>a[i];
    p[0]=a[0];
    for(i=1;i<n;i++)p[i]=p[i-1]^a[i];
    s[n-1]=a[n-1];
    for(i=n-2;i>=0;i--)s[i]=a[i]^s[i+1];
    trie=new nd();
    add(trie,40,0);
    ll ans=0;
    for(i=n-1;i>=0;i--){
        ans=max(ans,fin(trie,40,p[i]));
        add(trie,40,s[i]);
    }
    ans=max(ans,fin(trie,40,0));
    cout<<ans;
}