/*
Come by, you have come far
All I had I lost in the flood
Come sit with me at the bar
Tell me of progress, strengthen my blood

No one here knows my name, no
I have traded my memories for things
But I remember you clearly
Do you remember that I used to sing?

Why have you waited so long?
Why have you waited so long?

Come by, you have come far
Long since I saw you, so how have you been?
Come sit with me at the bar
How long since they told you that they had found him

No one here knows my name, no
I gave up my worries for one good thing
But I remember you clearly
Do you remember that I used to sing?

Why have you waited so long?
Why have you waited so long?
Why have you waited so long?
Why have you waited so long?

Was it because I never told you
I was going away that you waited so long?
Was it because your fucking dreams
Meant nothing to me that you waited so long?

It runs from the top of my fingers
Into my hands
What is it I have been drinking
I do not understand

I thought I'd lost you, my brother
I'm so glad you came
My regards to the ones that I love, I miss them
Tell them I love them, I miss them
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
#define MAG 10000

using namespace std;

long n,l[1000],r[1000],tl,tr,id,ps;
string ans;
pair<long, long> tp;
stack<pair<long, long> > s;
long cur;

int main(){
//freopen("hiking.in","r",stdin);
//freopen("hiking.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
 cin>>l[i]>>r[i];

cur=1;

for (int i=1;i<=n*2;i++)
{
 if (s.size()==0)
  tl=tr=-1;
 else
 {
  tp=s.top();
  id=tp.first;
  ps=tp.second;
  tl=ps+l[id];
  tr=ps+r[id];
 }
 if (tl<=i&&tr>=i)
 {
  s.pop();
  ans+=")";
  continue;
 }
 s.push(make_pair(cur,i));
 ++cur;
 ans+="(";
}

long cnt=0;
for (int i=0;i<n*2;i++)
 if (ans[i]=='(')++cnt;
if (cnt==n)
cout<<ans<<endl;
else
cout<<"IMPOSSIBLE"<<endl;

cin.get();cin.get();
return 0;}