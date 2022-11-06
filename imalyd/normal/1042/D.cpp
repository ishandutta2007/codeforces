//Problem D
#include<bits/stdc++.h>
using namespace std;
const int N=400007;
#define ll long long
int n,tot,tre[N];
ll t,a[N],x[N],ans;
int get(ll a){return lower_bound(x+1,x+tot+1,a)-x;}
void add(int v){for(;v<=tot;v+=v&-v)++tre[v];}
int query(int v){int a=0;for(;v;v-=v&-v)a+=tre[v];return a;}
int main(){
    cin>>n>>t;--t;
    for(int i=1;i<=n;i++)cin>>a[i],a[i]+=a[i-1];
    for(int i=0;i<=n;i++)x[++tot]=a[i],x[++tot]=a[i]-t;
    sort(x+1,x+tot+1);
    tot=unique(x+1,x+tot+1)-x-1;
    //for(int i=1;i<=n  ;i++)cout<<a[i]<<" ";cout<<endl;
    //for(int i=1;i<=tot;i++)cout<<x[i]<<" ";cout<<endl;
    for(int i=n;~i;i--)ans+=query(get(a[i])),add(get(a[i]-t));
    cout<<ans;
    return 0;
}