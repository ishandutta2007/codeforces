#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll b[200009];
int main()
{
    ios::sync_with_stdio(0);
ll t,n;
cin>>t;
while(t--)
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>b[i];
     ll u=n,v=n;
     for(int i=0;i<n;i++)
     {
         ll d=b[i]-i-1;
         u=min(u,n-i-1+d);
         ll g=2*n-b[i]-(n-i-1);
         v=min(v,i+g);
     }
     //cout<<u<<" "<<v<<endl;
  v=n-v;
  if(v>u)cout<<0<<endl;
  else cout<<u-v+1<<endl;

}

    return 0;
}