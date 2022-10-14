// system.cout(translate *from glut);
#include <bits/stdc++.h>

using namespace std;
#define f first

#define ll long long
const int s=1e9+7;
vector<int> p;
map<int,int> factors;
int n,i,b,c,d,x,y,del,cnt1,cnt2,max1,max2,sum;
ll my_pow(int x,int y)
{    ll num=1;
    for(ll i=x;y>0;i=(i*i)%s,y>>=1)
        if(y&1)num=((num%s)*i)%s;
    return num%s;
}
void pfact(int x)
{   if(x%2==0){p.push_back(2);while(x%2==0)x/=2;}
    for(int i=3;i*i<=x;i+=2)
        if(x%i==0){p.push_back(i);while(x%i==0)x/=i;}
    if(x>1)p.push_back(x);
}
string ss,sway;int way[100];
int down,up,right1,left1;
bool check()
{
    if(down==up||down==right1||down==left1)return false;
    if(up==right1||up==left1)return false;
    if(right1==left1)return false;
    return true;
}
void go(int x){if(x==down)c--;if(x==up)c++;
if(x==left1)d--;if(x==right1)d++;}

int main()
{
   ios_base::sync_with_stdio(false);
   cin>>x>>y;
   int s1,s2;
   char road[x+2][y+2];
   for(int i=1;i<x+1;i++){for(int j=1;j<y+1;j++){cin>>road[i][j];if(road[i][j]=='S')s1=i,s2=j;}}
   cin>>sway;n=sway.size();
   for(int i=0;i<n;i++)
    {int x=sway[i];way[i]=x-48;}
   for(int i=1;i<256;i++)
   {int mp=i;
   down=(mp&3);mp/=4;up=(mp&3);mp/=4;
   right1=(mp&3);mp/=4;left1=(mp&3);mp/=4;
       if(!check())continue;
       c=s1,d=s2;
       for(int j=0;j<n;j++)
       {
         go(way[j]);
         if(c==0||c==x+1||d==0||d==y+1||road[c][d]=='#')break;
         if(road[c][d]=='E'){cnt1++;break;}
       }
   }
    cout<<cnt1;
    return 0;
}