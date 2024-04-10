#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[5009],b[5009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];

    for(int i=0;i<n;i++)cin>>b[i];
    sort(a,a+n);
    sort(b,b+n);
    bool ans=true;
    for(int i=0;i<n;i++)if(b[i]!=a[i]&&b[i]!=a[i]+1)ans=false;
    if(ans)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;}
    return 0;
}