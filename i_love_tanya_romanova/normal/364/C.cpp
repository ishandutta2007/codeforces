/*

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
//#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-7
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

long n;
long pr[10000];
vector<long> v;
set<long> has;
long ul;
long limm;
set<long>::iterator it;
long calc[100];vector<long> v1;
long need[200];

void generate(long x)
{
     has.insert(x);
//     cout<<ul<<endl;
     for (int j=0;j<ul;j++)
     {
         if (x*v[j]<=limm&&has.find(x*v[j])==has.end())
         {
          has.insert(x*v[j]);
          generate(x*v[j]);
         }
     }
}

bool check()
{
 
for (int j=0;j<ul;j++)
need[j]=(n+1)/2;

for (int j=v1.size()-1;j>=v1.size()-n;--j)
{
    long mx,mp;
    mx=-1;mp=0;
    for (int q=0;q<ul;q++)
    if (need[q]>mx){mx=need[q];mp=q;}
    if (v1[j]%v[mx])continue;
    for (int q=0;q<ul;q++)
    if (v1[j]%v[q]==0)--need[q];
 //   if (j+1!=v1.size())cout<<" ";
 //   cout<<v1[j];
}
for (int i=0;i<ul;i++)
if (need[i]>0)return false;
return true;
}

int main(){
//freopen("gift.in","r",stdin);
//freopen("gift.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);


pr[1]=1;
for (int i=2;i<=1000;i++)
if (pr[i]==0)
for (int j=i*2;j<=1000;j+=i)
pr[j]=1;

for (int i=1;i<=1000;i++)
if (pr[i]==0)
v.push_back(i);

cin>>n;
limm=n*n*2;
for (int upp=2;upp<=10;upp++)
{
    has.clear();
    ul=upp;
    generate(1);
    for (int j=0;j<upp;j++)
    calc[j]=0;
   /* for (it=has.begin();it!=has.end();++it)
    {
        long q=(*it);
        for (int j=0;j<upp;j++)
        if (q%v[j]==0)++calc[j];
    }
    */
    if (has.size()>=n*1.04)break;;
   // if (check()==false)continue;
    it=has.end();
    --it;
/*    cout<<has.size()<<endl;
    for (int j=0;j<upp;j++)
    cout<<calc[j]<<" ";
    cout<<endl;
*/

}

for (it=has.begin();it!=has.end();++it)
{
    v1.push_back(*it);
}
//reverse(v1.begin(),v1.end());

 
for (int j=0;j<ul;j++)
need[j]=(n+1)/2;

long done=0;
for (int j=v1.size()-1;j>=0;--j)
{
    long mx,mp;
    mx=-1;mp=-1;
    for (int q=0;q<ul;q++)
    if (need[q]>mx){mx=need[q];mp=q;}
    if (mp>-1)if (v1[j]%v[mp])continue;
    if (done<n){
    cout<<v1[j]<<" ";++done;
    
    for (int q=0;q<ul;q++)
    if (v1[j]%v[q]==0)--need[q];
    }
 //   if (j+1!=v1.size())cout<<" ";
 //   cout<<v1[j];
}
cout<<endl;
/*
cout<<done<<endl;
for (int i=0;i<ul;i++)
cout<<need[i]<<" ";
cout<<endl;
*/
cin.get();cin.get();
return 0;}