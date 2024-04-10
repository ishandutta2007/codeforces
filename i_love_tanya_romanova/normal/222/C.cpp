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
#define eps 1e-10
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
using namespace std;

long pr[11000000],maxx[11000000],
up[11000000],down[11000000];
long scor,
arr1[200000],arr2[200000],ar1[200000],ar2[200000];
pair<long, long> p;
vector<pair<long, long> > v;
vector<pair<long, long> > vv[200000][2];
vector<long> v1;
long n,m,a,b;
//vector<long> lp;

void fact(long a,long b,long c)
{
     v.clear();
     v1.clear();
     while (a>1)
     {
           if (maxx[a]==0){
                           v1.push_back(a);break;
                           }
                           
           v1.push_back(maxx[a]);
           a/=maxx[a];
     }     
     
     long calc=1;
     
     for (int i=1;i<v1.size();i++)
     {
         if (v1[i]==v1[i-1])++calc;
         else
         {
             p=make_pair(v1[i-1],calc);
             vv[b][c].push_back(p);
             calc=1;
         }
     }
     
  if (v1.size())
  {   p=make_pair(v1[v1.size()-1],calc);
     vv[b][c].push_back(p);
}}

int main(){
//freopen("max.in","r",stdin);
//freopen("max.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

pr[1]=1;
//fact(1);


//pr[4]=1;

for (long i=2;i<=10000000;i++)
if (pr[i]==0)
{
 if (i<10000)
 for (int q=i*i;q<=10000000;q+=i)
  {
          pr[q]=1;if (maxx[q]==0)
          maxx[q]=i; else
          maxx[q]=min(maxx[q],i);
  }            
}

for (int i=1;i<=10000000;i++)
up[i]=down[i]=0;


cin>>n>>m;

for (int i=1;i<=n;i++)
{
    cin>>ar1[i];
    fact(ar1[i],i,0);
  //  vv[i][0]=v;
    
    for (int j=0;j<vv[i][0].size();j++)
    {
        a=vv[i][0][j].first;
        b=vv[i][0][j].second;
        up[a]+=b;
    }
    
}

for (int i=1;i<=m;i++)
{
    cin>>ar2[i];
    fact(ar2[i],i,1);
    for (int j=0;j<vv[i][1].size();j++)
    {
        a=vv[i][1][j].first;
        b=vv[i][1][j].second;
        down[a]+=b;
    }
    //vv[i][1]=v;
}

for (int i=1;i<=10000000;i++)
{
 scor=min(up[i],down[i]);
 
 up[i]-=scor;
 down[i]-=scor;
}
/*
for (int i=1;i<=10;i++)
cout<<i<<"  "<<up[i]<<" "<<down[i]<<endl;
*/

for (int i=1;i<=n;i++)
{
// fact(ar1[i]);   
//v=vv[i][0];
 arr1[i]=1;
 for (int j=0;j<vv[i][0].size();j++)
 {
    a=vv[i][0][j].first;
    b=vv[i][0][j].second;
    for (int q=1;q<=b;q++)
    {
        if (up[a]>0){--up[a];
        arr1[i]*=a;}
    } 
 }
}

for (int i=1;i<=m;i++)
{
// fact(ar2[i]);
// v=vv[i][1];
  arr2[i]=1;
 for (int j=0;j<vv[i][1].size();j++)
 {
    a=vv[i][1][j].first;
    b=vv[i][1][j].second;
    for (int q=1;q<=b;q++)
    {
        if (down[a]>0){
        arr2[i]*=a;--down[a];}
    } 
 }
}

cout<<n<<" "<<m<<endl;

for (int i=1;i<=n;i++)
{if (i>1)cout<<" ";
cout<<arr1[i];}
cout<<endl;

for (int i=1;i<=m;i++)
{if (i>1)cout<<" ";
cout<<arr2[i];}
cout<<endl;

cin.get();cin.get();
return 0;}