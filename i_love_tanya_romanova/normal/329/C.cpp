/*
I'm waiting in my cold cell when the bell begins to chime
Reflecting on my past life and it doesn't have much time
'Cause at 5 o'clock they take me to the Gallows Pole
The sands of time for me are running low

When the priest comes to read me the last rites
I take a look through the bars at the last sights
Of a world that has gone very wrong for me

Can it be that there's some sort of an error
Hard to stop the surmounting terror
Is it really the end not some crazy dream?

Somebody please tell me that I'm dreaming
It's not easy to stop from screaming
But words escape me when I try to speak
Tears they flow but why am I crying?
After all I am not afraid of dying
Don't I believe that there never is an end?

As the guards march me out to the courtyard
Someone calls from a cell "God be with you"
If there's a God, why has he let me go?

As I walk all my life drifts before me
And though the end is near I'm not sorry
Catch my soul 'cause it's willing to fly away

Mark my words believe my soul lives on
Don't worry now that I have gone
I've gone beyond to seek the truth

When you know that your time is close at hand
Maybe then you'll begin to understand
Life down there is just a strange illusion

Yeah, yeah, yeah,
Hallowed be Thy name
Yeah, yeah, yeah,
Hallowed be Thy name
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
#define eps 0.001
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 3
#define clone agsdahfaassdg
using namespace std;

long n,m,a,b,iters,fl,ans;
vector<long> v;
set<pair<long, long> > bad;

int main(){
//freopen("lifts.in","r",stdin);
//freopen("lifts.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
for (int i=1;i<=m;i++)
{
cin>>a>>b;
if (a>b)swap(a,b);
bad.insert(make_pair(a,b));
}

for (int i=0;i<n;i++)
v.push_back(i+1);

iters=4000000/n;

for (;iters;--iters)
{
 random_shuffle(v.begin(),v.end());
 fl=0;
 for (int i=0;i<m&&i<v.size()-1;i++)
 {a=v[i];b=v[i+1];if (a>b)swap(a,b);
 if (bad.find(make_pair(a,b))!=bad.end())fl=1;}
 if (m==n)
 {
  a=v[0];
  b=v[v.size()-1];
  if (a>b)swap(a,b);
  if (bad.find(make_pair(a,b))!=bad.end())fl=1;
 }
 if (fl==0){ans=1;
 break;}
}
v.push_back(v[0]);

if (ans==0)
{
 cout<<-1<<endl;
}
else for (int i=0;i<m;i++)
cout<<v[i]<<" "<<v[i+1]<<endl;
cin.get();cin.get();
return 0;}