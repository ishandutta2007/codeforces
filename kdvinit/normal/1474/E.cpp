/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=2e5;
int p[N],cnt,mov[N][2],ans;

void swp(int l,int r)
{
    ans+=((r-l)*(r-l));
    mov[cnt][0]=l;
    mov[cnt][1]=r;
    swap(p[l],p[r]);
    cnt--;
}

void solve()
{
    int n;
    cin>>n;

    int m=(n+1)/2;
    ans=0;

    for(int i=1;i<=n;i++) p[i]=i;

    cnt=n-1;

    swp(1,n);
    for(int i=2;i<=m;i++) swp(i,n);
    for(int i=m+1;i<n;i++) swp(i,1);

    cout<<ans<<endl;
    for(int i=1;i<=n;i++) cout<<p[i]<<" ";
    cout<<endl;
    cout<<n-1<<endl;
    for(int i=1;i<n;i++) cout<<mov[i][0]<<" "<<mov[i][1]<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}