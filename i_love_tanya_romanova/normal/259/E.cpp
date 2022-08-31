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

vector<long long>v[200000];
long long n,ans,ar[200000];
long long res;
long long sz,cm[1000],r1,r,calc[200000],tcalc[200000];
long long mx;

long long pw(long long a,long long b)
{
     if (b==0)return 1;
     if (b==1)return a%bs;
     if (b%2==0)
     {return pw(a*a%bs,b/2);}
     return pw(a,b-1)*a%bs;
     
}

long long solve(long long sz)
{
     long long r=1;
     for (int i=0;i<=sz;i++){
  //  if (sz==4)
    //cout<<r<<"    "<<cm[i]<<" "<<endl;
     r=r*pw(i,cm[i])%bs;} return r;
}

int main(){
//freopen("peacefulsets.in","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

for (int i=1;i<=100000;i++)
for (int j=1;j*j<=i;j++)
if (i%j==0)
{
 v[i].push_back(j);if (i/j!=j)v[i].push_back(i/j);          
}

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>ar[i];
// ar[i]=100000;
calc[ar[i]]++;   
}

for (int i=1;i<=100000;i++)tcalc[i]=tcalc[i-1]+calc[i];

mx=0;
for (int i=1;i<=100000;i++)
mx=max(mx+0ll,v[i].size()+0ll);
//cout<<mx<<endl;

for (int i=1;i<=100000;i++)
{
 sort(v[i].begin(),v[i].end());
 sz=v[i].size();

 
 for (int j=0;j<=sz;j++)
 cm[j]=0;
 
 cm[0]=tcalc[v[i][0]-1];
 
 long long tss=0;
 
 for (int j=1;j<sz;j++)
 {//if (i==6)
 //cout<<v[i][j]-1<<" b"<<tcalc[v[i][j]-1]<<" "<<endl;
 cm[j]=tcalc[v[i][j]-1]-tss;tss+=cm[j];}
 
 cm[sz]=n;
 
 /*if (i==6)
 for (int j=0;j<sz;j++)
 cout<<"q "<<cm[j];
 cout<<endl;
 */
 for (int j=0;j<sz;j++)
 cm[sz]-=cm[j];
 
 //cout<<ans<<" "<<i<<" "<<sz<<endl;
 r1=solve(sz);
 
  
 /*if(i<10)
 {
         for (int j=0;j<sz;j++)
         cout<<v[i][j]<<" ";
         cout<<endl;
  for (int j=0;j<=sz;j++)
 cout<<cm[j]<<" ";
 cout<<endl;
 cout<<endl;
 }
 */
 
 cm[sz-1]+=cm[sz];cm[sz]=0;
 r1-=solve(sz-1);
 while (r1<0)r1+=bs;
 
 ans=ans+r1;
 while (ans<0)ans+=bs;
 ans%=bs;
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}