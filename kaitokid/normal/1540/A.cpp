#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll d[100009],n, suf[100009];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
    cin>>n;
    suf[n]=0;
    for(int i=0;i<n;i++)cin>>d[i];
    sort(d,d+n);
    ll ans=d[n-1];
    for(int i=n-1;i>=0;i--)suf[i]=suf[i+1]+d[i];
    for(int i=0;i<n;i++)
    {

        ans-=suf[i+1];
        ans+= d[i]*(n-i-1);
    }
    cout<<ans<<endl;
    }
    return 0;
}