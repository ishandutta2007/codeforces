#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n,k,x;
vector<ll> a;
int main()
{
    ios::sync_with_stdio(0);
 cin>>n>>k;
 for(int i=0;i<n;i++){cin>>x;a.push_back(x);}
 sort(a.begin(),a.end());
 int d=1;
 for(int i=n/2;i<n-1;i++)
 {
     if((a[i+1]-a[i])*d<=k){k-=(a[i+1]-a[i])*d;d++;continue;}
     cout<<a[i]+k/d;
     return 0;
 }
 cout<<a[n-1]+k/d;
    return 0;
}