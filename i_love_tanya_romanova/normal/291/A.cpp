/*
    ,   
   ,      .
         
 ,      ,  .

:
 ,  ,   .
        .
  -,  ,
    ,    .

       ,
      ,  .
   ,  ,  
     ,  .

 (2)
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
 
#define  INF 100000000
#define eps 1e-5
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

long n,fl,ar[200000],ans;
map<long, long> calc;

int main(){
//freopen("dkl.in","r",stdin);
//freopen("dkl.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=0;i<n;i++)
{cin>>ar[i];if (ar[i]==0)continue;
calc[ar[i]]++;if (calc[ar[i]]==2)++ans;
if (calc[ar[i]]>2)fl=1;}
if (fl)cout<<-1<<endl;
else cout<<ans<<endl;

cin.get();cin.get();
return 0;}