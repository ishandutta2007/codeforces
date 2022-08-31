/*
I'm fed up with these fuckin' assholes
Wish 'em all disease, hope they die
From cancer in their mind
Like to kill 'em with chainsaw
Sitting there with all the strings in hand
Think they can decide upon a band
What they know is nothing relevant
Money makes them all fucked up
Trying to save nothing else but just their ass
Lying to you day in and day out and just pretend
Telling you 'bout the money you make but never get
Being so dumb, you trust in their words and sign the shit
It's been your fault
Rippin' you off blind
Rippin' you off blind
Put you on a trip to America
Give a little tip, leave for Bavaria
Not a single call, no sign of care behind
We never needed you in the first place
Send a cheque - uncovered once again
Promise you: I won't do it no more
Please excuse, there's been some problems there
Fuck off! No one believes you
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