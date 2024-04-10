#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll mod =1e9+7;
int r[10][10];
//priority_queue <pair<ll,pair<ll,ll> >,vector<pair<ll,pair<ll,ll> >;greater<pair<ll,pair<ll,ll> > >pr;
long double pr[10][10];
int main()
{
    ios::sync_with_stdio(0);
for(int i=1;i<=6;i++)
{long double u=1/6.0;
long double v=0;
   for(int j=1;j<1000;j++) {pr[0][i]+=(u*j);v+=u;u=1-v;u/=6.0;}
}
//cout<<pr[0][1];
for(int i=0;i<10;i++)
{
    for(int j=0;j<10;j++)cin>>r[i][j];
}
for(int i=7;i<10;i++)
{
    for(int j=1;j<=6;j++)
    pr[0][i]+=1/6.0*(1+pr[0][i-j]);

}
for(int i=1;i<10;i++)
{ if(i%2==0)
    for(int j=0;j<10;j++)
    {
        int x=i,y=j;
        bool bl=false;
        for(int u=0;u<6;u++)
        {if(bl)y++;
        else
            y--;
            if(y<0){x--;y=0;bl=true;}
            if(r[x][y]==0) pr[i][j]+=(1/6.0)*(1+pr[x][y]);
            else pr[i][j]+=1/6.0*(1+min(pr[x][y],pr[x-r[x][y]][y]));
        }
    }
else
    for(int j=9;j>=0;j--)
    {
        bool pp=false;
        int x=i,y=j;
        for(int u=0;u<6;u++)
        {if(pp)y--;
        else
            y++;
            if(y>9){x--;y=9;pp=true;}
            if(r[x][y]==0) pr[i][j]+=(1/6.0)*(1+pr[x][y]);
            else pr[i][j]+=1/6.0*(1+min(pr[x][y],pr[x-r[x][y]][y]));
        }
    }
}
cout<<fixed<<setprecision(10)<<pr[9][0];
  //cout<<pr[9][0];
    return 0;
}