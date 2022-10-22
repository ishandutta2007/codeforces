#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n,t;
string s;
queue<int>c[30];
int bit[200009];
int chn(int x,int v)
{
    while(x<200005)
    {
        bit[x]+=v;
        x+=(x&(-x));
    }
}
int sum(int x)
{
    int res=0;
    while(x>0)
    {
        res+=bit[x];
        x-=(x&(-x));
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(0);
    cin>>n>>s;
   string t=s;
   reverse(t.begin(),t.end());
   for(int i=0;i<n;i++)
  c[s[i]-'a'].push(i+1);
   ll ans=0;
   for(int i=0;i<n;i++)
   {

       ll u=c[t[i]-'a'].front();
      // cout<<u<<endl;
       c[t[i]-'a'].pop();

       ll f=u+sum(u);
       //cout<<f<<endl;
       ans+=f-1;
       chn(u,-1);

   }
   cout<<ans;
    return 0;
}