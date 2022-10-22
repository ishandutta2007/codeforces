#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
map<int,int>mp;
int main()
{
    ios::sync_with_stdio(0);
int t,n;
int x,a,b;
cin>>t;
while(t--)
{
    mp.clear();
    int s=0,d=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        if(mp[x]==0)d++;
        mp[x]++;
        s=max(s,mp[x]);
    }
  if(s>d){cout<<d<<endl;continue;}
  cout<<min(s,d-1)<<endl;
}
    return 0;
}