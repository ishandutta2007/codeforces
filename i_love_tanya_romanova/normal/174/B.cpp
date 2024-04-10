/*
Hold me when I'm standing
When i've fallen, we're disbanding
You are so goddamn beautiful, but
Unstable, your joke got old

Sick one trick pony
You fed my fire,
Now I'm rising ever higher
And the red ripples multiply as
Reflections rise from the sea

From the sea

Take away the pain inflected on me
The hunger you're letting me feed

I bleed my rust on the roses
That once have chained us, me to you
Your dying love is a rose
I will bury somewhere close to you

When we are dancing
I hear worlds, you're still fading
I feel safe, yet unsatisfied
Soaked in trance and disgrace

You are so jaded, keep me sedated
With your nonsense, deeds and phrases
And if suns still set in your eyes
You get to see my face glow

Take away the pain inflected on you
The hunger you're letting me feed

Bleed my rust on the roses
That once have chained us, me to you
Your dying love is a rose
I will bury, somewhere close to you

You, bleed your rust on the roses
That once have chained us, me to you
Your dying love is a rose
I will bury somewhere close to you

I bleed my rust on the roses
That once have chained us, me to you
Your dying love is a rose
I will bury somewhere close to you
*/

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
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
 
#define  INF 100000000
#define eps 1e-6
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000002013
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60

using namespace std;

string st;
vector<long> v;
set<long> cuts;
long fl;

int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>st;
for (int i=0;i<st.size();i++)
if (st[i]=='.')v.push_back(i);

if (v.size()==0){cout<<"NO"<<endl;return 0;}
if (v[0]>=9)fl=1;
if (v[0]==0)fl=1;
if (v[v.size()-1]<st.size()-4)fl=1;
if (v[v.size()-1]>st.size()-2)fl=1;

for (int i=1;i<v.size();i++)
if (v[i]-v[i-1]>12)fl=1;
for (int i=1;i<v.size();i++)
if (v[i]-v[i-1]<3)fl=1;

if (fl)cout<<"NO"<<endl;
else
{
 for (int i=1;i<v.size();i++)
 {cuts.insert(min(v[i-1]+3,v[i]-2));
 }   
 cout<<"YES"<<endl;
 for (int i=0;i<st.size();i++)
 {
     cout<<st[i];
     if (cuts.find(i)!=cuts.end())
     cout<<endl;
 }
 cout<<endl;
}

cin.get();cin.get();
return 0;}