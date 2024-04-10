/*
- ,     
    ,     
       
   ,    
-    
    
  ,    
     

    --
   ,    
     
     
  ,    
   ,   
  ,    
     

:
-, ,  ...

       
       
  ,     
      
  ,    
     ,   
    ,    
   ,    



- ,     
    ,     
       
   ,    
-    
    
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
#define MAG 10000

using namespace std;

string name[1000];
long n,q,a,b,ar[200][200];
long indeg[200];
vector<long> ans;
long temp;
long er;
vector<long> todo;

int main(){
//freopen("hiking.in","r",stdin);
//freopen("hiking.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
 cin>>name[i];

for (int i=1;i<n;i++)
{
 q=0;
 while (q<name[i].size()&&q<name[i+1].size()&&name[i][q]==name[i+1][q])
  ++q;
 if (q==name[i+1].size()&&q<name[i].size())er=1;
 if (q==name[i].size())continue;
 a=name[i][q]-'a';
 b=name[i+1][q]-'a';
// cout<<a<<" "<<b<<endl;
 ar[a][b]=1;
}

for (int k=0;k<26;k++)
for (int i=0;i<26;i++)
 for (int j=0;j<26;j++)
  if (ar[i][k]&&ar[k][j])
   ar[i][j]=1;

for (int i=0;i<26;i++)
 for (int j=0;j<26;j++)
  indeg[j]+=ar[i][j];
  
for (int i=0;i<26;i++)
 if (ar[i][i])er=1;
 
 
for (int i=0;i<26;i++)
 if (indeg[i]==0)
  todo.push_back(i);
 
while (todo.size())
{
 temp=todo.back();
 todo.pop_back();
 ans.push_back(temp);
 for (int i=0;i<26;i++)
  if (ar[temp][i])
  {
   indeg[i]--;
   if (indeg[i]==0)
    todo.push_back(i);
  }
}

if (ans.size()<26||er==1)
 cout<<"Impossible"<<endl;
 else
 {
  for (int i=0;i<ans.size();i++)
   cout<<char(ans[i]+'a');
  cout<<endl;
 }
 
cin.get();cin.get();
return 0;}