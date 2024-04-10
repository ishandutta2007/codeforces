#include <bits/stdc++.h>

using namespace std;
int a[200009],n,x;
multiset<int>b;
int main()
{
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++){cin>>x;b.insert(x);}
    for(int i=0;i<n;i++)
    {
        multiset<int>::iterator it1=b.begin(),it2=b.lower_bound((n-a[i])%n);
if(it2==b.end())it2--;
if(((a[i]+(*it1))%n)<((a[i]+(*it2))%n))
   {
       cout<<((a[i]+(*it1))%n)<<" ";
       b.erase(it1);
   }
   else{cout<<((a[i]+(*it2))%n)<<" ";b.erase(it2);}
    }
    return 0;
}