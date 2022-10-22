#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n,x;
bool bl[1000009];
vector<ll>a;
int main()
{
    ios::sync_with_stdio(0);
   cin>>n>>x;
   a.push_back(0);
   ll u=1<<n;
   for(int i=1;i<u;i++)
   {
       if(bl[i]||i==x)continue;
       a.push_back(i);
       bl[(i^x)]=true;
   }
   cout<<a.size()-1<<"\n";
   for(int i=1;i<a.size();i++)cout<<(a[i]^a[i-1])<<" ";

    return 0;
}