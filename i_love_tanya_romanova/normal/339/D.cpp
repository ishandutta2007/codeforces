/*
I've seen it coming, it's got to be.
No illusions at the turning of the century.
All our wishes - forever free -
all destroyed because somehow we lost the masterkey.

Leaving my dreams far behind,
got no ambitions in time if only I'm so

Black in mind, When there's no point in making it.
Black in mind. When there's no hope for love, I'm so
Black in mind. When these madmen are wasting it.
Black in mind. I don't want to be sacrificed for

a territorial war. Leave me alone, I'm so black in mind.

You made me want it, too blind to see
that all it gave me were illusions of reality.
My eyes got used to the things they've seen,
now where's the difference between my life and the TV screen.
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
#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-9
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007
#define bs 2000000014

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 4
#define clone agsdahfaassdg

using namespace std;

long n,q,iter,m;
vector<long> v[100];
long ar[500000];

int main(){
//freopen("path.in","r",stdin);
//freopen("path.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
/*
cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>q;v.push_back(q);
}

while (v.size()>1)
{
      ++iter;
      vector<long> v1;
      long r;
      for (int i=0;i+1<v.size();i+=2)
      {
          if (iter%2)r=(v[i]|v[i+1]);
          else r=(v[i]^v[i+1]);
          v1.push_back(r);
      }
      v=v1;
      for (int i=0;i<v.size();i++)
      cout<<v[i]<<" ";
      cout<<endl;
}
*/

cin>>n>>m;
for (int i=0;i<(1<<n);i++)
{
    cin>>ar[i];
    v[0].push_back(ar[i]);
}

for (int iter=0;iter<n;iter++)
 {
     for (int j=0;j<v[iter].size();j+=2)
     if (iter&1)v[iter+1].push_back(v[iter][j]^v[iter][j+1]);else v[iter+1].push_back(v[iter][j]|v[iter][j+1]);
 }   
/*
for (int i=0;i<=n;i++)
{
    for (int j=0;j<v[i].size();j++)
    cout<<v[i][j]<<" ";
    cout<<endl;
}*/

long a,b,temp;

for (int it=1;it<=m;it++)
{
    cin>>a>>b;--a;
    v[0][a]=b;
//    --a;
    for (int iter=0;iter<n;iter++)
    {
        temp=v[iter][a^1];
        if (iter&1)v[iter+1][a>>1]=(temp^b);
        else v[iter+1][a>>1]=(temp|b);
        a>>=1;
        b=v[iter+1][a];
    }
    cout<<v[n][0]<<endl;
    
//------------    
/*for (int i=0;i<=n;i++)
{
    for (int j=0;j<v[i].size();j++)
    cout<<v[i][j]<<" ";
    cout<<endl;
}*/

}

cin.get();cin.get();
return 0;}