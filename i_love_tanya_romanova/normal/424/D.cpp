/*
You come clean, waves collide now.
Defenceless numb points
And no voice of reason
So, how come you invited me too, you knew I wanted you.
You glide above.
So, this night belongs to you. I know this isn't through.
Are you dead too long?
I see the bright lights, it's the month of July.
It's violent here, why have you left me?
If only you could stay, and keep me in.
It's violent here, why did you run from me?
So, how come you invited me to, you knew I wanted you.
You glide above.
So, this night belongs to you. I know this isn't through/true.
I am dead too long.
Heat, night devour me.
Heat, night devour me.
I see the bright lights, it's the month of July.
It's violent here, why have you left me?
If only you could stay, and keep me in.
It's violent here, why did you run from me?
*/

//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
//#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
//#define N 120000

using namespace std;

long n,m,t,tp,tu,td,l[400][400],r[400][400],d[400][400],u[400][400];
long ar[400][400],bst,temp,ax1,ay1,ax2,ay2;
long lwr,upr;

int main(){
//freopen("trading.in","r",stdin);
//freopen("trading.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m>>t;
cin>>tp>>tu>>td;

for (int i=1;i<=n;i++)
 for (int j=1;j<=m;j++)
  cin>>ar[i][j];

// right
for (int i=1;i<=n;i++)
 for (int j=2;j<=m;j++)
  {
   r[i][j]=r[i][j-1];
   if (ar[i][j]==ar[i][j-1])r[i][j]+=tp;
   if (ar[i][j]<ar[i][j-1])r[i][j]+=td;
   if (ar[i][j]>ar[i][j-1])r[i][j]+=tu;
  }

// left
for (int i=1;i<=n;i++)
 for (int j=m-1;j;j--)
  {
   l[i][j]=l[i][j+1];
   if (ar[i][j]==ar[i][j+1])l[i][j]+=tp;
   if (ar[i][j]<ar[i][j+1])l[i][j]+=td;
   if (ar[i][j]>ar[i][j+1])l[i][j]+=tu;
  }

// down
for (int j=1;j<=m;j++)
 for (int i=2;i<=n;i++)
 {
  d[i][j]=d[i-1][j];
  if (ar[i][j]==ar[i-1][j])d[i][j]+=tp;
  if (ar[i][j]<ar[i-1][j])d[i][j]+=td;
  if (ar[i][j]>ar[i-1][j])d[i][j]+=tu;
 }

// up
for (int j=1;j<=m;j++)
 for (int i=n-1;i;i--)
 {
  u[i][j]=u[i+1][j];
  if (ar[i][j]==ar[i+1][j])u[i][j]+=tp;
  if (ar[i][j]<ar[i+1][j])u[i][j]+=td;
  if (ar[i][j]>ar[i+1][j])u[i][j]+=tu;
 }
bst=-1e9;

lwr=-1e8;
upr=1e9;

for (int ly=m-2;ly>=1;ly--)
 for (int lx=n;lx>=1;lx--)
  for (int rx=lx+2;rx<=n;rx++)
   for (int ry=ly+2;ry<=m;ry++)
   {
    temp=r[lx][ry]-r[lx][ly]+d[rx][ry]-d[lx][ry]+l[rx][ly]-l[rx][ry]+
    u[lx][ly]-u[rx][ly];
//    if (lx==4&&ly==3&&rx==6&&ry==7)
//    cout<<"^"<<temp<<endl;
    if (temp>=lwr&&temp<=upr)
    {
     bst=temp;
     lwr=t-abs(bst-t);
     upr=t+abs(bst-t);
     ax1=lx;
     ay1=ly;
     ax2=rx;
     ay2=ry;
    }
   }

cout<<//bst<<" "<<
ax1<<" "<<ay1<<" "<<ax2<<" "<<ay2<<endl;

cin.get();cin.get();
return 0;}