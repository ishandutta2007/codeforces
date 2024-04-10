/*
      ,
     .
  , , ,
    ,  ?

       ,
-   ,
 ,  ,
    ?

:
  ,   ,
   .   !
  ,   ,
   .   !

       ,
     .
      
  .


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
#define eps 1e-9
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007
#define bs 2000000014

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 300
#define clone agsdahfaassdg

using namespace std;

vector<pair<pair<long, long>, long> > v;
vector<long> ans1;
long long n,calc,calc1;
long tests,a,b;


int main(){
//freopen("path.in","r",stdin);
//freopen("path.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>tests;
for (;tests;--tests)
{
 cin>>n;
 n=n*2-1;
 v.clear();
 for (int i=0;i<n;i++)
 {
     cin>>a>>b;
     v.push_back(make_pair(make_pair(a,b),i+1));
 }   
 sort(v.begin(),v.end());
 calc=0;
 for (int i=0;i<n;i++)
 calc+=v[i].first.second;
 calc1=0;
 for (int i=0;i<n;i+=2)
 calc1+=v[i].first.second;
 ans1.clear();
 cout<<"YES"<<endl;
 if (calc1*2>=calc)
 {
  for (int i=0;i<n;i+=2)
  ans1.push_back(v[i].second);                 
 }
 else {for (int i=1;i<n;i+=2)ans1.push_back(v[i].second);ans1.push_back(v[n-1].second);}
 for (int i=0;i<ans1.size();i++)
 {
     if (i)cout<<" ";
     cout<<ans1[i];
 }
 cout<<endl;
}

cin.get();cin.get();
return 0;}