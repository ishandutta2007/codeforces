/*
There's someone in the attic
Building a strange machine
Never really seen him
But I think he works all day
Blinded by the world outside,
I stay inside
Hardly know my name
But it's getting better by time

I saw something in the mirror
Someone's watching me
If I hide in the attic
He will never get to me
I found some rope on the floor
I have to build a trap
So I start on my machine
I am never to be seen
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
#define bsize 300
#define clone agsdahfaassdg

using namespace std;

long n,a,b,q;
vector<long> g[200000];
long arp[200000];

void dfs(long v)
{
     for (int i=0;i<g[v].size();i++)
     {
         long q=g[v][i];
         if (arp[q]==0){arp[q]=v;dfs(q);}
     }
}

int main(){
//freopen("path.in","r",stdin);
//freopen("path.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>a>>b;

for (int i=1;i<=n;i++)
{
 if (i!=a)
 {
  cin>>q;g[i].push_back(q);g[q].push_back(i);
 }   
}

dfs(b);

for (int i=1;i<=n;i++)
{
    if (i!=b)cout<<arp[i]<<" ";
}
cout<<endl;

cin.get();cin.get();
return 0;}