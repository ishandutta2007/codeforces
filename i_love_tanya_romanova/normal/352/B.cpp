/*
       ,  ,         ...
  ,     ,     ,   , , ,  ...
            ...
     ,       ,  ,  ,  ...
         ,   ,          ...
       ,        ...
   ,      ,  ,  ,   ...
   ,     ...     ...    ,    ...

  ,    !
   ,    !
       !
     ...

    ,        ...
    ,  ,  , ,  ...
     ,         ...
, ,         ,     ...
,      ,       ...
...     ?        ,      ...
,                ...
            ...    ...

   ,    !
   ,    !
       !
     ...

           ...
    ,       ...
   ,      !   !
      ,         !..
   ,   ,        ...
 ,    ,          ...
   ,           ...
  ... ...  ...   !..

   ,    !
   ,    !
       !
     ...
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
#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-8
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

long n,q,fl;
vector<long> v[200000];
vector<pair<long, long> > ans;

int main(){
//freopen("firesafe.in","r",stdin);
//freopen("firesafe.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>q;
    v[q].push_back(i);
}

for(int i=1;i<=100000;i++)
{
 if (v[i].size()==0)continue;
 fl=0;
 for (int j=1;j<v[i].size();j++)
 if (v[i][j]-v[i][j-1]!=v[i][1]-v[i][0])fl=1;
 if (fl==0)
 {
  v[i].push_back(v[i][0]);
  ans.push_back(make_pair(i,v[i][1]-v[i][0]));
 }
}
cout<<ans.size()<<endl;
for (int i=0;i<ans.size();i++)
cout<<ans[i].first<<" "<<ans[i].second<<endl;

cin.get();cin.get();
return 0;}