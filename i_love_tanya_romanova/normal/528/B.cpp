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
In a coffin criticized
I shouldered the blame and dug this hole for me to lay in

I reach for calm
I starve for a balance unknown
This burden tortures me deep in my soul

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
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
#define MAGIC 47
#define count adsgasdgasdg

using namespace std;

long n,a,b,ans,r;
vector<pair<long, long> > v;

int main(){
//freopen("k.in","r",stdin);
//freopen("k.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>a>>b;
 v.push_back(make_pair(a+b,a-b));
}
sort(v.begin(),v.end());

r=-2e9;
for (int i=0;i<v.size();i++)
{
 if(v[i].second>=r)
 {
  r=v[i].first;
  ++ans;
 }
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}