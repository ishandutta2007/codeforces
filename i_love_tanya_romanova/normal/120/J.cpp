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
#define eps 1e-11 
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define szz 400
//#define pb push_back
using namespace std;
long n;
long anstpa,anstpb;


struct pt{double x,y; long id;long tp;};

inline bool cmp_x(const pt&a, const pt&b)
{
       return a.x<b.x||a.x==b.x&&a.y<b.y;
}

inline bool cmp_y(const pt&a, const pt&b)
{
       return a.y<b.y;
}

pt a[500000];
double mindist;
int ansa,ansb;

inline void upd_ans(const pt&a, const pt&b)
{
       double dist=sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));

       if (dist<mindist)
       {mindist=dist; ansa=a.id;ansb=b.id;anstpa=a.tp;anstpb=b.tp;}       
}

void rec(long l,long r)
{
     if (r-l<=3)
     {for (int i=l;i<=r;i++)
          for (int j=i+1;j<=r;j++)
          upd_ans(a[i],a[j]);
          sort(a+l,a+r+1,&cmp_y);return;
     }
     long m=l+r;
     m/=2;
     long midx=a[m].x;
     rec(l,m);
     rec(m+1,r);
     static pt t[1000000];
     merge(a+l,a+m+1,a+m+1,a+r+1,t,&cmp_y);
     copy(t,t+r-l+1,a+l);
     int tsz=0;
     for (int i=l;i<=r;i++)
     if (fabs(a[i].x-midx)<mindist)
     {
                                  for (int j=tsz-1;j>=0&&a[i].y-t[j].y<mindist;--j)
                                  {upd_ans(a[i],t[j]);
                                  }
                                  t[tsz++]=a[i];
     }
}


int main(){
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin>>n;
for(int i=0;i<n;i++)
{cin>>a[i].x>>a[i].y; a[i].id=i;
if (a[i].x<0&&a[i].y<0){a[i].tp=4;}
else
if (a[i].x>=0&&a[i].y<0){a[i].tp=3;}
else if
(a[i].x<0&&a[i].y>=0){a[i].tp=2;}
else
{a[i].tp=1;}
}

for (int i=0;i<n;i++)
{a[i].x=fabs(a[i].x);a[i].y=fabs(a[i].y);}


/*for (int i=0;i<n;i++)
cout<<a[i].x<<" "<<a[i].y<<" "<<" "<<a[i].tp<<endl;
*/

sort(a,a+n,&cmp_x);
/*
for (int i=0;i<n;i++)
cout<<a[i].x<<" "<<a[i].y<<" "<<" "<<a[i].tp<<endl;
*/

mindist=1e13;

rec(0,n-1);
//cout.precision(6);
if (ansa>ansb){swap(ansa,ansb);swap(anstpa,anstpb);}
if (anstpb==1)anstpb=4; else if (anstpb==2)anstpb=3;
else if (anstpb==3)anstpb=2; else anstpb=1;
if (anstpa==4&&anstpb==4)anstpa=anstpb=1;
cout<<ansa+1<<" "<<anstpa<<" "<<ansb+1<<" ";
cout<<anstpb<<endl;
//cout<<fixed<<mindist<<endl;
cin.get();cin.get();
return 0;}