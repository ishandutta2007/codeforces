/*
My anxiety's clawing
Out from deep within me
It burns within as my throat begins to cauterize

This negativity's leeching
Any shred of composure
Rationale has decayed and left me bound in madness

I reach for calm
I starve for a balance unknown
This burden tortures me deep in my soul

I've found that strife won't make the bleeding stop
Nor will it take away the pain
I feel like this search is all in vain
And I struggle to find my way

How I yearn for the silence
For an end to the voices
The calamity grows and the deafness leads to disarray

Guilt buries me alive
In a coffin - criticized
I shouldered the blame and dug this hole for me to lay in

I reach for calm
I starve for a balance unknown
This burden tortures me deep in my bones

I've found that strife won't make the bleeding stop
Nor will it take away the pain
I feel like this search is all in vain
And I struggle to find my way

I've found that strife won't make the bleeding stop
Nor will it take away the pain
I feel like this search has been all in vain
And I struggle to find my way

I've found that strife won't make the bleeding stop
Nor will it take away the pain
I feel like this search is all in vain
And I struggle to find my way

I've found that strife won't make the bleeding stop
Nor will it take away the pain
I feel like this search has been all in vain
And I struggle to find my way
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

#define  INF 100000000
#define eps 1e-13
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
#define MAXN 10000
//#define SIZE 60
#define bsize 256

using namespace std;

long n,q,ar[2100][2100];
long flag;

int main(){
//freopen("cyclic.in","r",stdin);
//freopen("cyclic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
 for (int j=1;j<=n;j++)
 {
  cin>>q;
  if (q)ar[i][j/30]|=(1<<(j%30));
 }
 
 
for (int k=1;k<=n;k++)
 for (int i=1;i<=n;i++)
  if (ar[i][k/30]&(1<<(k%30)))
   for (int j=0;j<=n/30+1;j++)
    ar[i][j]|=ar[k][j];
 
 flag=0;
 for (int i=1;i<=n;i++)
  for (int j=1;j<=n;j++)
   if ((ar[i][j/30]&(1<<(j%30)))==0)flag=1;
 
 if (flag)cout<<"NO"<<endl;
 else cout<<"YES"<<endl;
 
cin.get();cin.get();
return 0;}