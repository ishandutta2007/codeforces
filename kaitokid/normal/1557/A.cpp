#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
double a[100009];
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
int t;
cin>>t;
while(t--)
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    double ans=a[n-1],d=0;
    for(int i=0;i<n-1;i++)d+=a[i];
    d/=(n-1.0);
    ans+=d;
    cout<<fixed<<setprecision(7)<<ans<<endl;
}
  return 0;
}