//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
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
#include <memory.h>
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
 
#define  INF 100000000
#define eps 1e-11
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60
using namespace std;  

long n,k,cx,cy,bx,bd,by,sz,td,fl;
long usd[1000][1000];
long ax,ay;

int main(){
//freopen("length.in","r",stdin);
//freopen("length.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>k>>n;

cx=n+1;
cx/=2;
cy=cx;

for (int i=1;i<=k;i++)
{
    cin>>sz;
    bx=0;by=0;
    bd=10000000;
    
    for (int x=1;x<=n;x++)
    {
     for (int j=1;j+sz<=n+1;++j)
     {
      td=0;fl=0;
      
      for (int q=0;q<sz;q++)
      {
          ax=x;
          ay=j+q;
          td+=abs(ax-cx);
          td+=abs(ay-cy);
          
          if (usd[ax][ay]){fl=1;break;}
          
      }
      if (fl)continue;
      if (td<bd)
      {
                bd=td;
                bx=x;by=j;
      }
     }   
    }
if (bd<1000000){    for (int j=0;j<sz;j++)
    usd[bx][by+j]=1;
    cout<<bx<<" "<<by<<" "<<by+sz-1<<endl;
}else cout<<-1<<endl;}

cin.get();cin.get();
return 0;}