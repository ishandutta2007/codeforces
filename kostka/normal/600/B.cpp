#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
vector <ll>a;
vector<ll>b;
ll n,m;
 
void binSearch(ll b)
{
    ll p=-1; ll k=n;
    while(k-p!=1)
    {
        ll m=(p+k)/2;
        if(a[m]<=b)p=m;
        else k=m;
    }
    cout<<p+1<<" ";
}
 
int main()
{
    cin>>n>>m;
    for(ll i=0;i<n;i++)
    {
        ll tmp;
        cin>>tmp;
        a.push_back(tmp);
    }
    for(ll j=0;j<m;j++)
    {
        ll tmp;
        cin>>tmp;
        b.push_back(tmp);
    }
    sort(a.begin(),a.end());
   
    for(ll i=0;i<m;i++)
    {
        binSearch(b[i]);
    }
   
   
    return 0;
}