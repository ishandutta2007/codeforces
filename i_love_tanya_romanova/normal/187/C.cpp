//#pragma comment(linker, "/STACK:16777216")
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define  INF 1000000000
#define eps 1e-6
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007
//#define szz 400
//#define pb push_back
using namespace std;

long n,k,t,f,s,p,gd[300000],a,b,l,r,m,arp[300000],d[300000],ff;
queue <long> qu;
vector<long> v[300000];

int main(){
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

scanf("%d",&n);
scanf("%d",&m);
scanf("%d",&k);

for (int i=0;i<k;i++)
{scanf("%d",&t);--t;gd[t]=1;}

for (int i=0;i<m;i++)
{
   scanf("%d",&a);--a;
   scanf("%d",&b);--b;
    v[a].push_back(b);
    v[b].push_back(a);
}

scanf("%d",&s);
scanf("%d",&ff);
--s;--ff;

l=0;
r=2000000;
while (l<r)
{
      m=l+r;
      m/=2;
      for (int i=0;i<n;i++)
      {
          arp[i]=0;d[i]=10000000;
      }
      
      
      qu.push(s);
      d[s]=0;
      while(!qu.empty()&&arp[ff]==0)
      {
                      
      f=qu.front();
      qu.pop();
      
      arp[f]=1;
      for (int i=0;i<v[f].size();i++)
          {
               p=d[f];
              // if (gd[v[f][i]])p=0; else p++;
               if (p<m&&d[v[f][i]]>p)
               {
                                d[v[f][i]]=p+1;
                                if (gd[v[f][i]])d[v[f][i]]=0;
                                qu.push(v[f][i]);
               }
               
          }
      
      }
      while(!qu.empty())qu.pop();
      
      if (d[ff]<1000000)r=m; else l=m+1;
    //  cout<<d[ff]<<" "<<d[3]<<" "<<d[4]<<" "<<d[5]<<endl;
}

if (l<1000000)cout<<l<<endl;else cout<<-1<<endl;

cin.get();cin.get();
return 0;}