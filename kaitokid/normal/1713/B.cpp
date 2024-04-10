#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){

    ll n,mx=0,ans=0;
    cin>>n;
    for(int i=0;i<n;i++){cin>>a[i];mx=max(mx,a[i]);}
    ans=a[0];
    for(int i=1;i<n;i++)if(a[i]>a[i-1])ans+=a[i]-a[i-1];
    if(ans==mx)cout<<"YES"<<endl;
     else cout<<"NO"<<endl;
    }

    return 0;
}