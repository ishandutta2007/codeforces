/*
Legend tells a secret, buried deep in time
A may to free our people, to free them from these crimes
Lost beneath fountain, across the distant sea
We'll journey there together in search of liberty

We board the ship together and sail into the night
No land to see before us, we follow stars so bright
Then the land is sighted, our journey almost done
We leave the ship unguarded, the legend drivers us on

Through wind and rain we travel, onwards 'cross the land
Guided by the starlight, towards the eastern sands

Far away in a bygone age
When the stories all were true
Legends told by the men of old
Have brought us here today

The fountain stands before us, our mission is complete
We search beneath the water, a sword lies our feet
The sword will bring us glory, our freedom is assured
We will return to save our land from suffering endured

Through wind and rain we travel, onwards 'cross the land
Guided by the starlight, towards the eastern sands

Far away in a bygone age
When the stories all were true
Legends told by the men of old
Have brought us here today

Through wind and rain we travel, onwards 'cross the land
Guided by the starlight, towards the eastern sands

Far away in a bygone age
When the stories all were true
Legends told by the men of old
Have brought us here today
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
#define bsize 512
#define right adsgasgadsg
#define free adsgasdg
 
using namespace std;

long m;
string s;
unsigned long cur[1<<12];
vector<long> ans;
unsigned long sett[1<<12];
unsigned long one;
long in_base[1<<20];
unsigned long aset[2050][77],
base_vec[2050][77];

bool G()
{
 for (int i=0;i<=2000;i++)
  if ((cur[i/32]&(one<<(i%32)))>0&&in_base[i]==1)
  {
   for (int j=0;j<=64;j++)
    cur[j]^=base_vec[i][j],
    sett[j]^=aset[i][j];
  }
/*  cout<<cur[0]<<endl;

  for (int i=0;i<=20;i++)
   if(in_base[i])
    cout<<i<<"  "<<base_vec[i][0]<<endl;
  */  
  long er=0;
 for (int i=0;i<=64;i++)
  if (cur[i]){er=1;break;}
  
  if (er==0)return true;
 
 for (int i=2000;i+1;i--)
 {
  if (in_base[i]==1)continue;
  if ((cur[i/32]&(one<<(i%32)))==0)
   continue;
  
  for (int j=0;j<=2000;j++)
  {
   if (in_base[j]==0)continue;
   if ((base_vec[j][i/32]&(one<<(i%32)))==0)continue;
   for (int q=0;q<=74;q++)
   {
    base_vec[j][q]^=cur[q],
    aset[j][q]^=sett[q];
   }
  }
   in_base[i]=1;
   for (int j=0;j<=64;j++)
    base_vec[i][j]=cur[j],
    aset[i][j]=sett[j];
 //  cout<<i<<" "<<base_vec[i][0]<<" "<<aset[i][0]<<endl;
    break;
 }
 return false;
}

vector<long> st;

string norm(string st)
{
 reverse(st.begin(),st.end());
 while( st.size()%6)st+="0";
 reverse(st.begin(),st.end());
 return st;
}

long get(string &st,long ps)
{
 long res=0;
 for (int i=ps;i<ps+6;i++)
  res=res*10+st[i]-48;
 return res;
}

int main(){
//freopen("alter.in","r",stdin);
//freopen("alter.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
//ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>m;

one =1;

getline(cin,s);

for (int iter=0;iter<m;iter++)
{
 getline(cin,s);
 s=norm(s);
 st.clear();
 
 for (int i=0;i<s.size();i+=6)
  st.push_back(get(s,i));
  
 for (int i=0;i<=64;i++)
 {
  cur[i]=0;
 }
 reverse(st.begin(),st.end());
 
 long cnt=0;
 while (true)
 {
  long rem=0;
  for (int i=st.size()-1;i+1;--i)
  {
   st[i]=st[i]+rem*1000000;
   rem=st[i]%2;
   st[i]/=2;
  }
   
  if (rem)
   cur[cnt/32]|=(one<<(cnt%32));
  while (st.size()>1&&st[st.size()-1]==0)
   st.pop_back();
  if (st.size()==1&&st[0]==0)break;
  ++cnt;
 }   
 
 /*for(int i=0;i<1;i++)
  cout<<cur[i]<<endl;*/
  
 for (int i=0;i<=64;i++)
  sett[i]=0;
 sett[iter/32]|=(one<<(iter%32));
 
 ans.clear();
 if (G())
 {
  for (int j=0;j<iter;j++)
  {
   if (sett[j/32]&(one<<(j%32)))
    ans.push_back(j);
  }
 }
 
 if (ans.size()==0)
  printf("%ld\n",0);
  
 else
 {
     printf("%ld",ans.size());
     
  for (int i=0;i<ans.size();i++)
   printf(" %ld",ans[i]);//cout<<" "<<ans[i];
  printf("\n");//cout<<endl;
 }
}

cin.get();cin.get();
return 0;}