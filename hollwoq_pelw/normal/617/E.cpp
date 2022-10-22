#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6;
struct d{int l,r,i;int t(){return l/316;}}q[N];
bool p(d a, d b){return a.t()!=b.t()?a.t()<b.t():a.t()&1?a.r>b.r:a.r<b.r;}
ll a[N],c[N],z[N],x,n,m,k,pl,pr=-1,i,l,r;
void o(int v){x+=c[v^k];c[v]++;}
void w(int v){c[v]--;x-=c[v^k];}
int main(){cin>>n>>m>>k;for(i=1;i<=n;i++)cin>>a[i],a[i]^=a[i-1];for(i=0;i<m;i++)cin>>q[i].l>>q[i].r,q[i].i=i;sort(q,q+m,p);for(i=0;i<m;i++){l=q[i].l-1,r=q[i].r;while(pl>l)o(a[--pl]);while(pr<r)o(a[++pr]);while(pl<l)w(a[pl++]);while(pr>r)w(a[pr--]);z[q[i].i]=x;}for(i=0;i<m;i++)cout<<z[i]<<"\n";}