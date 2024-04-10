#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n,k;
vector<ll>a;
int main()
{
 ios::sync_with_stdio(0);
    cin>>n>>k;
    ll x;
    for(int i=0;i<n;i++){cin>>x;a.push_back(x);}
    sort(a.begin(),a.end());
    ll i=0,j=n-1;
    while(k>0&&j>i)
    {
        if(a[i]==a[j]){cout<<0;return 0;}
        if(i+1<n-j)
        {
            if(k>=(a[i+1]-a[i])*(i+1)){k-=(a[i+1]-a[i])*(i+1);i++;continue;}
            cout<<a[j]-(a[i]+(k/(i+1)));
            return 0;
        }

            if(k>=(a[j]-a[j-1])*(n-j)){k-=(a[j]-a[j-1])*(n-j);j--;continue;}
            cout<<a[j]-(k/(n-j))-a[i];
            return 0;
    }
    cout<<a[j]-a[i];
    return 0;
}