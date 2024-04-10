/*
This is the verity for a lot of you
And how you always stand
From the outside looking in
Now did you ever feel you are so open minded
That you don't really belong anywhere
Well I've been there too

Why are these vultures circling over me
I'm not dead yet
Used silence as a language for too long
This is where we make our stand
The wounds at my back begin to heal
Our enemy outnumber us three to one
But still we fight on

Someone has to build
Even if it's severe
A bridge between the worlds
We shoulder it for you
All borders will be removed
To create a better existence

I spend two years
To figure out myself
I say it's your time now
Your time to rise
This isn't your only choice
But your best choice
Refuse to stay put and watch this cancer grow
Until it explodes, we must interfere
Before the shit hits the fan

Someone has to build
Even if it's severe
A bridge between the worlds
We shoulder it for you
All borders will be removed
To create a better existence

This goes out to all you people
Who have been mistreated and abused
For what you believe in
This song is for you

The only freedom you'll ever get
Is your own mind and thoughts
Even if tyrants try to hold you down
They can never take that away from you

Why are these vultures circling over me
I'm not dead yet
Used silence as a language for too long
This is where we make our stand
The wounds at my back begin to heal
Our enemy outnumber us three to one
But still we fight on

Someone has to build
Even if it's severe
A bridge between the worlds
We shoulder it for you
All borders will be removed
To create a better existence

Someone has to build
Even if it's severe
A bridge between the worlds
We shoulder it for you
All borders will be removed
To create a better existence

To create a better existence
To create a better existence
To create a better existence
To create a better existence
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
#define bsize 512
#define right adsgasgadsg
#define free adsgasdg

using namespace std;

vector<pair<long, long> > v;
long long pw[1<<20];
long long s[1<<20];
long id1,id2;
long n,ar[1<<20],span;
vector<pair<long,pair<long, long> > > vec;
long cp;

long long get(long l,long r)
{
 long long res=s[r]-s[l-1];
 res*=pw[277777-l];
 return res;
}
int main(){
//freopen("alter.in","r",stdin);
//freopen("alter.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

pw[0]=1;
for (int i=1;i<=300000;i++)
 pw[i]=pw[i-1]*1000000007;
 
cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>ar[i];
 v.push_back(make_pair(ar[i],i));
 s[i]=s[i-1]+ar[i]*pw[i];
}

sort(v.begin(),v.end());
for (int i=0;i<v.size();i++)
{
 for (int j=i+1;j<v.size()&&v[j].first==v[i].first;j++)
 {
  int id1=v[i].second;
  int id2=v[j].second;
  span=(id2-id1);
  if (id2+span-1>n)continue;
  if (get(id1,id2-1)==get(id2,id2+span-1))
   vec.push_back(make_pair(id2-id1,make_pair(id1,id2)));
 }
}

sort(vec.begin(),vec.end());

for (int i=0;i<vec.size();i++)
{
 if (vec[i].second.first>cp)
 {
  cp=vec[i].second.second-1;
 }
}
//cout<<cp<<endl;
cout<<n-cp<<endl;
for (int i=cp+1;i<=n;i++)
{
    if (i>cp+1)cout<<" ";
    cout<<ar[i];
}
cout<<endl;

cin.get();cin.get();
return 0;}