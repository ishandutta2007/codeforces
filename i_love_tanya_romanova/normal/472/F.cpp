/*
Call it liberation or frustration
As it hits like a bomb
Tearing you apart as you're first in line
Entering the zone

Watch how it runs
A nerve wrecking resistance
Watch how it burns
A venomous script's getting formed

You've traveled a long way to get here
And now its waking you up
Waking you up

Walk straight for a final solution
Walk straight, don't you be so cold
Walk straight with a clear resolution
I'll state my case and never turn

Watch how it runs, watch how it burns
And it's all a deception
Break it and learn, there's no return
For a presence like mine

You've traveled a long way to get here
It's getting all so clear now all the things at least
An elapse of conscious progress will last forevermore

My courageous insanity follows an infinite time
I'll be attaching the world on my shoulders
Without a look inside
Inside

Walk straight for a final solution
Walk straight, don't you be so cold
Walk straight with a clear resolution
I'll state my case and never turn

Walk straight for a final solution
Walk straight, don't you be so cold
Walk straight with a clear resolution
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

using namespace std;

vector<pair<long, long> > ops;
vector<pair<long, long> > restore;
long n,q;
vector<long> v1,v2;

void swap(long a,long b,vector<long>& v)
{
 if (a==b)return;
 ops.push_back(make_pair(a,b));
 ops.push_back(make_pair(b,a));
 ops.push_back(make_pair(a,b));
 swap(v[a],v[b]);
}

void xorr(long a,long b,vector<long>& v)
{
 ops.push_back(make_pair(a,b));
 v[a]^=v[b];
}

void run_gauss(vector<long>&v)
{
 long rows=0;
 for (int bit=30;bit>=0;--bit)
 {
     for (int j=rows;j<v.size();j++)
      if (v[j]&(1<<bit))
      {
       swap(j,rows,v);
       for (int k=0;k<v.size();k++)
        if (k!=rows)
         if (v[k]&(1<<bit))
          xorr(k,rows,v);
       ++rows;
       break;
      }
 }
}

int main(){
//freopen("army.in","r",stdin);
//freopen("army.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=0;i<n;i++)
{
 cin>>q;
 v1.push_back(q);
}
for (int i=0;i<n;i++)
{
 cin>>q;
 v2.push_back(q);
}

run_gauss(v2);
restore=ops;
ops.clear();
run_gauss(v1);

long er=0;
/*
for (int i=0;i<v1.size();i++)
cout<<v1[i]<<endl;
for (int i=0;i<v2.size();i++)
cout<<v2[i]<<endl;
*/

for (int i=0;i<40&&i<v1.size();i++)
{
 long old=30;
 if (v1[i]==0)continue;
 while ((v1[i]&(1<<old))==0)--old;
 
 for (int j=0;j<40&&j<v1.size()&&j<v2.size();j++)
  if ((v1[j]^v2[j])&(1<<old))
   xorr(j,i,v1);
 
}
/*
for (int i=0;i<v1.size();i++)
cout<<v1[i]<<endl;
for (int i=0;i<v2.size();i++)
cout<<v2[i]<<endl;
*/
for (int i=0;i<v1.size();i++)
 if (v1[i]!=v2[i])er=1;
 
reverse(restore.begin(),restore.end());
for (int i=0;i<restore.size();i++)
 ops.push_back(restore[i]);

if (er)cout<<-1<<endl;
else{
cout<<ops.size()<<endl;
for (int i=0;i<ops.size();i++)
cout<<ops[i].first+1<<" "<<ops[i].second+1<<"\n";
}

cin.get();cin.get();
return 0;}