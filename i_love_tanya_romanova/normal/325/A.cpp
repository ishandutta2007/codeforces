/*
' ,  
 ' ,    .
 ,  .
    .
  ...
  ...

    ,
,     .
    .
     .
  ...
  ...

    ',
     .
    .
 .   .
  ...

   ,
      .
  !   ?
     !
  ...
*/

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
#define lr asgasgash

#define  INF 100000000
#define eps 1e-9
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000000
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 3
#define clone agsdahfaassdg

using namespace std;

long long n,x1,y1,x2,y2,maxx,minx,maxy,miny,s;

int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
minx=1000000;
miny=1000000;

for (int i=1;i<=n;i++)
{cin>>x1>>y1>>x2>>y2;
s+=abs((y2-y1)*(x2-x1));
minx=min(minx,x1);minx=min(minx,x2);
maxx=max(maxx,x1);maxx=max(maxx,x2);
miny=min(miny,y1);miny=min(miny,y2);
maxy=max(maxy,y1);maxy=max(maxy,y2);
}

if((maxy-miny)*(maxx-minx)==s&&maxy-miny==maxx-minx)
cout<<"YES"<<endl;
else cout<<"NO"<<endl;

cin.get();cin.get();
return 0;}