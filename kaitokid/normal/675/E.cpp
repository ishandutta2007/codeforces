#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int spr[100009][19],n;
int a[100009];
ll ans[100009];
int lg[100009];
int cal(int x,int y)
{
    int u=lg[y-x+1];
    if(a[spr[x][u]]>a[spr[y-(1<<u)+1][u]])return spr[x][u];
           else return spr[y-(1<<u)+1][u];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i=2;i<=100000;i++)lg[i]=lg[i/2]+1;
    cin>>n;
    for(int i=0;i<n-1;i++){cin>>a[i];a[i]--;}
    for(int i=0;i<n;i++)spr[i][0]=i;
    for(int j=1;(1<<j)<=n;j++)
      for(int i=0;i+(1<<j)<=n;i++)
        if(a[spr[i][j-1]]>a[spr[i+(1<<(j-1))][j-1]])spr[i][j]=spr[i][j-1];
            else spr[i][j]=spr[i+(1<<(j-1))][j-1];
     ll res=0;
     for(int i=n-2;i>=0;i--)
     {

         int u=cal(i+1,a[i]);
         ans[i]=ans[u]+n-1-i-(a[i]-u);
         res+=ans[i];
     }
     cout<<res;

    return 0;
}