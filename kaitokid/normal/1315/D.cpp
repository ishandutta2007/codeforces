#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n;
pair<ll,ll> a[200009];
multiset<ll>st;
ll ans,x,y;
int main()
{
    ios::sync_with_stdio(0);
    cin>>n;
   for(int i=0;i<n;i++)
       cin>>a[i].first;
for(int i=0;i<n;i++)cin>>a[i].second;


   sort(a,a+n);
   int i=0;

   ll u=0;
   x=a[0].first;
   while(i<n||!st.empty())
   {
       while(i<n&&a[i].first==x){u+=a[i].second;st.insert(a[i].second);i++;}
       multiset<ll>::iterator it=st.end();
       it--;
       u-=(*it);
       ans+=u;

       st.erase(it);
       if(!st.empty()){x++;continue;}

       if(i<n)x=a[i].first;

   }
   cout<<ans;
    return 0;
}