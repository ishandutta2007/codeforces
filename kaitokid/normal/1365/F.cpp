#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int t,n,m;
int a[505],b[505];
vector<pair<int,int> >v1,v2;
int main()
{
ios::sync_with_stdio(0);
cin>>t;
while(t--)
{v1.clear();
v2.clear();
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    if(n%2&&a[n/2]!=b[n/2]){cout<<"No\n";continue;}
    for(int i=0;i<n/2;i++){v1.push_back({min(a[i],a[n-i-1]),max(a[i],a[n-i-1])});v2.push_back({min(b[i],b[n-i-1]),max(b[i],b[n-i-1])});}
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    bool ans=true;
    for(int i=0;i<n/2;i++)if(v1[i]!=v2[i]){ans=false;break;}
    if(ans)cout<<"Yes\n";
    else cout<<"No\n";
}
    return 0;
}