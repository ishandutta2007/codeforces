#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[50009][7];
bool win(int x,int y)
{
    int f=0;
    for(int i=0;i<5;i++)
        if(a[x][i]<a[y][i])f++;
    return (f>2);
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
     cin>>n;
     int u=1;
     for(int i=1;i<=n;i++)
     {for(int j=0;j<5;j++)cin>>a[i][j];
     if(win(i,u))u=i;}
     bool res=true;
     for(int i=1;i<=n;i++)
     {
         if(i==u)continue;
         if(!win(u,i)){res=false;break;}
     }
     if(res)cout<<u<<endl;
     else cout<<-1<<endl;


         }
    return 0;
}