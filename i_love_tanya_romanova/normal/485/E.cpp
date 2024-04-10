/*
Speculations, rumours or lies?
The circle of blood and force
Under the seal of secrecy
Ritual acts - no remorse

Call them: skull and bones
Scroll and key
Call them: wolf's head
Book and snake

They rob - spread fear - they swat
They lie - oppress - they garrot
The chosen ones - the slaughter mob
They rob - spread fear - they swat
They lie - oppress - they garrot
The chosen ones - the slaughter mob

Bonemen of secret soceties
The hall of fame and the rich
Domination without varieties
Legal aggression - to go off without a hitch

Call them: skull and bones
Scroll and key
Call them: wolf's head
Book and snake

Conquering fear - the attainment of power by killing
The end is near - and if you're not willing?

The slaughter seems to be teachable
The dignity of men is unimpeachable

Speculations, rumours or lies?
Conspiracy theories - desperate cries?
Missuse of power doesn't pay?
The network of lies rules us all - runaway!
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

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg

using namespace std;

string st;
long tests,n,k,d,ttl;
long p1[1<<20];
long temp;
char res[1<<20],tres[1<<20];

vector<long> one(long sz)
{
 vector<long> res;
 for (int i=0;i<sz;i++)
  res.push_back(i);
 return res;
}

vector<long> mult(vector<long> &a,vector<long> b)
{
 vector<long> res;
 res.resize(a.size());
 for (int i=0;i<a.size();i++)
  res[i]=b[a[i]];
 return res;
}

void show(vector<long> v)
{
 for (int i=0;i<v.size();i++)
  cout<<v[i]<<" ";
 cout<<endl;
}

vector<long> pw(vector<long> &a,long b)
{
// show(a);
// cout<<"%"<<b<<endl;
 vector<long> vv,temp;
 vv=one(a.size());
 temp=one(a.size());
 while (b){
 if (b%2)for (int i=0;i<vv.size();i++)
  vv[i]=a[vv[i]];
 b/=2;
 for (int i=0;i<vv.size();i++)
  temp[i]=a[a[i]];
 for (int i=0;i<vv.size();i++)
  a[i]=temp[i];
 }
 return vv;
}

vector<long> perm;
int main(){
//freopen("logins.in","r",stdin);
//freopen("logins.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>st;
cin>>tests;
n=st.size();

perm.resize(n);

for (;tests;--tests)
{
    cin>>k>>d;
    for (int i=0;i<n;i++)
     p1[i]=i;
     
    ttl=0;
    for (int i=0;i<d;i++)
    {
     for (int j=i;j<k;j+=d)
     {
      p1[ttl]=j;
      ++ttl;
     }
    }
    temp=p1[0];
    for (int j=0;j+1<n;j++)
    {
     p1[j]=p1[j+1];
    }
    p1[n-1]=temp;
  
    /*for (int j=0;j<ttl;j++)
     cout<<p1[j]<<" ";
    cout<<endl;*/
    
    ttl=n-k+1;
    for (int i=0;i<n;i++)
     perm[i]=p1[i];
    perm=pw(perm,ttl);
    for (int i=0;i<n;i++)
     tres[i]=st[perm[i]];
/*    for (int i=0;i<n;i++)
     cout<<tres[i];
    cout<<endl;
 */   ttl=0;
    for (int i=k-1;i+1<n;i++)
     {res[ttl]=tres[i];
     ttl++;}
     res[ttl]=tres[n-1];
     ++ttl;
    for (int i=0;i<k-1;i++)
     {res[ttl]=tres[i];
     ttl++;}
     
     for (int i=0;i<n;i++)
      cout<<res[i];
     for (int i=0;i<n;i++)
      st[i]=res[i];
     cout<<"\n";
}

cin.get();cin.get();
return 0;}