#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll mod=1e9+7;
int main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   ll n;
   cin>>n;
   vector<ll>v;
   v.push_back(1);
   vector<ll>pr;
   pr.push_back(1);
   ll res=1;
   for(ll i=2;i<n;i++)
   {
       if(__gcd(n,i)==1){v.push_back(i);res=(res*i)%n;pr.push_back(res);}
   }
   if(res==1)
   {
   cout<<v.size()<<endl;
       for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
       return 0;
          }
   ll u=v.size()-1,z;
   ll d=1;
   for(ll i=u;i>0;i--)
   {
       if(((pr[i-1]*d)%n)==1){z=i;break;}
       d=(d*v[i])%n;
   }

   cout<<v.size()-1<<endl;
   int q=1;
   for(int i=0;i<v.size();i++)
    if(i!=z){cout<<v[i]<<" ";q=(q*v[i])%n;}


    return 0;
}