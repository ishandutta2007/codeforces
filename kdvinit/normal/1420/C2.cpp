/*
K.D. Vinit  |,,|
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
#define int long long

int ans=0;
int n,q;
int a[300002];
int mx[300002];
int infy=300002;

void assign_mx(int pos)
{
    int i=pos;
    if(i==0 || i==n+1) return;
    if(a[i]>a[i-1] && a[i]>a[i+1]) mx[i]=1;
    else if(a[i]<a[i-1] && a[i]<a[i+1]) mx[i]=-1;
    else mx[i]=0;
}

int val(int strt,int nd)
{
    int valmx=0;
    for(int i=strt;i<=nd;i++) valmx+=a[i]*mx[i];
    return valmx;
}

void swaplr(int l,int r)
{
    int val1=0;
    val1+=val(l-1,l+1);
    val1+=val(r-1,r+1);

    if(l+1==r) val1-=val(l,r);
    if(l+2==r) val1-=val(l+1,l+1);

    swap(a[l],a[r]);
    for(int i=l-1;i<=l+1;i++) assign_mx(i);
    for(int i=r-1;i<=r+1;i++) assign_mx(i);

    int val2=0;
    val2+=val(l-1,l+1);
    val2+=val(r-1,r+1);

    if(l+1==r) val2-=val(l,r);
    if(l+2==r) val2-=val(l+1,l+1);

    ans-=val1;
    ans+=val2;
}

void solve()
{
    cin>>n>>q;
    ans=0;

    for(int i=1;i<=n;i++) cin>>a[i];
    a[0]=0; a[n+1]=0;

    for(int i=1;i<=n;i++) assign_mx(i);

    mx[0]=0; mx[n+1]=0;
    for(int i=1;i<=n;i++) ans+=(mx[i]*a[i]);

    cout<<ans<<endl;

    for(int i=1;i<=q;i++)
    {
        int l,r;
        cin>>l>>r;
        swaplr(l,r);
        cout<<ans<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}