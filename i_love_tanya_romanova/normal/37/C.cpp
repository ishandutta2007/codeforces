/*
    
    
     
        
    -  
      
     
   

  
   
    ,   
      



   
     
 ,    
     
   -  
     
     
   

  
   
    ,   
      

  
   
    ,   
      

   
   
    ,   
      

   
   
    ,   
      
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
#define right adsgasgadsg
#define free adsgasdg
 
using namespace std;

vector<string> s[1<<10];
set<string>::iterator it;
long q,ttl[1<<10];
vector<long> req[1<<10];
string ans[1<<10];
long n;
long er;
string st,st1,st2;
long temp;

int main(){
//freopen("capital.in","r",stdin);
//freopen("capital.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>q;
 ttl[q]++;
 req[q].push_back(i);
}

s[0].push_back("");
for (int i=0;i<1010;i++)
{
 while (ttl[i]>0&&s[i].size()>0)
 {
  temp=req[i].back();
  req[i].pop_back();
  ans[temp]=s[i].back();
  s[i].pop_back();
  --ttl[i];
 }
 if (ttl[i]>0){er=1;break;}
 for (int j=0;j<s[i].size();j++)
 {
     st=s[i][j];
     st1=st+"0";
     st2=st+"1";
     s[i+1].push_back(st1);
     s[i+1].push_back(st2);
     if (s[i+1].size()>1000)break;
 }
 s[i].clear();
}

if (er)cout<<"NO"<<endl;
else
{
 cout<<"YES"<<endl;
 for (int i=1;i<=n;i++)
  cout<<ans[i]<<endl;
}
cin.get();cin.get();
return 0;}