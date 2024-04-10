#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int ans[60],wh[200];
int main()
{
    ios::sync_with_stdio(0);
    int t;

    cin>>t;
    while(t--)
    {


  string s;
  cin>>s;
  for(int i=0;i<=60;i++)ans[i]=-1;
  for(int i='a';i<='z';i++)wh[i]=-1;
  ans[30]=s[0];
  wh[s[0]]=30;
  bool bl=false;
  int mn=30,mx=30;
  for(int i=1;i<s.size();i++)
  {
      if(wh[s[i]]!=-1&&abs(wh[s[i]]-wh[s[i-1]])==1)continue;
      if(wh[s[i]]!=-1){bl=true;break;}
      int u=wh[s[i-1]];
      if(ans[u+1]==-1){ans[u+1]=s[i];wh[s[i]]=u+1;mx=max(mx,u+1);continue;}
      if(ans[u-1]==-1){ans[u-1]=s[i];wh[s[i]]=u-1;mn=min(mn,u-1);continue;}

  bl=true;
  break;
  }
    if(bl){cout<<"NO\n";continue;}
    cout<<"YES\n";
    for(int i=mn;i<=mx;i++)cout<<char(ans[i]);
    for(int i='a';i<='z';i++)if(wh[i]==-1)cout<<char(i);
    cout<<endl;
    }
    return 0;
}