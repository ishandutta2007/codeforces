/*
,  ,  
 ,     ?
    ,
   .
,  ,  
 ,    ?
   ,
  .

 :

  ,
   .
  
,   .
   
  ,
,  ,
   .
   ...

    ,
   .
    
  ,
  ...

[ 3]
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
#include <memory.h>
#include <ctime> 
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
 
#define eps 1e-9
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

map<string,long> ans;
long tests,answ;
string st1,st2;

string norm(string st)
{
 for (int i=0;i<st.size();i++)
 {
  if( st[i]>='A'&&st[i]<='Z')
   st[i]=st[i]-'A'+'a';
 }
 return st;
}

int main(){
//freopen("k.in","r",stdin);
//freopen("k.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>tests;
ans["polycarp"]=1;
answ=1;

for (;tests;--tests)
{
 cin>>st1>>st2>>st2;
 st2=norm(st2);
 st1=norm(st1);
 ans[st1]=ans[st2]+1;
 answ=max(answ,ans[st1]);
}
cout<<answ<<endl;

cin.get();cin.get();
return 0;}