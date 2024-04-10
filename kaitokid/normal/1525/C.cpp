#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[300009],ans[300009],id[300009],m;
char c[300009];
bool bl(int x,int y)
{
    return a[x]<a[y];
}
void go(int x,int y)
{
    if(c[x]=='R'&&c[y]=='L')
    {
        ans[x]=ans[y]=(a[y]-a[x])/2;
        return;
    }
    if(c[x]=='R'&&c[y]=='R')
    {
        ans[x]=ans[y]=(a[y]-a[x])/2+m-a[y];
        return;
    }
    if(c[x]=='L'&&c[y]=='L')
    {
        ans[x]=ans[y]=(a[y]-a[x])/2+a[x];
        return;
    }
    ans[x]=ans[y]=(a[y]-a[x])/2+a[x]+m-a[y];


}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
int t;
cin>>t;
while(t--)
{
    int n;
    cin>>n>>m;
    deque<int>st[2];
    for(int i=0;i<n;i++)
    {
        ans[i]=-1;
        id[i]=i;
        cin>>a[i];

    }
    sort(id,id+n,bl);
    for(int i=0;i<n;i++)
        cin>>c[i];
      for(int q=0;q<n;q++){
                int i=id[q];
        int k=a[i]%2;
        if(st[k].empty()){st[k].push_back(i);continue;}
        int u=st[k].back();
        if((c[u]=='R')&&(c[i]=='L'))
        {
            st[k].pop_back();
            go(u,i);
            continue;
        }
        st[k].push_back(i);
    }
  for(int k=0;k<2;k++)
  {

      while((st[k].size()>1)){
        int r=st[k].size();
        if((c[st[k][r-1]]!='R')||(c[st[k][r-2]]!='R'))break;
        go(st[k][r-2],st[k][r-1]);
        st[k].pop_back();
        st[k].pop_back();
      }
     while((st[k].size()>1)){
        if((c[st[k][0]]!='L')||(c[st[k][1]]!='L'))break;
        go(st[k][0],st[k][1]);
        st[k].pop_front();
        st[k].pop_front();
      }
    if(st[k].size()>1)go(st[k][0],st[k][1]);
  }
 for(int i=0;i<n;i++)cout<<ans[i]<<" ";
 cout<<endl;
}
    return 0;
}