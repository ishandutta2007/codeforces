#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod= 998244353;
ll p2[300009],p3[300009],n;
vector<int>add[300009],rm[300009];
ll ans;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>n;
  p2[0]=p3[0]=1;
  for(int i=1;i<=n;i++)p2[i]=(p2[i-1]*2)%mod,p3[i]=(p3[i-1]*3)%mod;
  for(int i=1;i<=n;i++)
  {int l,r;
   cin>>l>>r;
   add[l].push_back(i);
   rm[r+1].push_back(i);
   }
   set<int>st;
   for(int i=0;i<=300000;i++)
    {
     for(auto u :add[i])st.insert(u);
     for(auto u :rm[i])st.erase(u);
     if(st.empty())continue;
     set<int>::iterator it=st.end();
     it--;
     int g=(*it);
     ll h=1;
    if(g==1)ans=(ans+p2[n-1])%mod;
    else{
     h=p3[g-2];
     ans+=h*p2[n-g+1];
    //cout<<i<<" "<<g<<" "<<ans<<endl;
     ans%=mod;
      }

      }
    cout<<ans;

return 0;
}