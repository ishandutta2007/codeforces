/*
All that is evil come forward its time
A call to which we`ll answer
All who was born in the depths of this hell
Arise from your grave
The tale has been told a few times in the past
A power of which we feed of
A slumbering force in the core of this world will soon see the day

Rise! Reign!
My internal demons
Rise!

The power of darkness sweeps over the world
This war will last forever
There is no return, there is no escape
Come join my side
In the blink of an eye I can teach you to fight
Serving my point of interest
A gun in your hand but one thought in your head.
Fight until your dead

One shot, one kill
You all are under our will
Forget yourself
Youre nothing but a shell

[Chorus:]
No fear can conquer us and no tear runs down our chin, hell yeah
We`ll fight until the end of time with a fire in our eyes

Our blood is thicker than yours and we do not feel regret
Come clean and say what you want, we will still be at the top

As the blitzkrieg continues a weapon is born
The one and only demon
People will fall like the ants that they are
By the anger of his fist

The plan is complete yeah the goal has been reached.
We`ve earned the celebration
A flawless idea that was made into truth
And awakened all our dreams.

One shot, one kill
You all are under our will
Forget yourself
Youre nothing but a shell

[Chorus]

Rise! Reign!
My internal demons
Rise!
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
 
using namespace std;

string st;
long n,k,mid,qp,er,used[1<<19];

int main(){
//freopen("lesson.in","r",stdin);
//freopen("lesson.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>k;
cin>>st;
n=st.size();

for (int i=0;i<st.size();i++)
{
    if (st[i]!='?')used[st[i]-'a']++;
}

mid=(n+1)/2-1;
qp=k-1;

/*for (int i=0;i<k;i++)
 cout<<used[i];
cout<<endl;
*/

for (int i=mid;i>=0;--i)
{
 if (st[i]!='?'&&st[st.size()-i-1]!='?')
 {
  er|=(st[i]!=st[st.size()-i-1]);
  continue;
 }
 if (st[i]=='?'&&st[st.size()-i-1]!='?')
 {
  st[i]=st[n-i-1];
  used[st[i]]=1;
  continue;
 }
 if (st[i]!='?'&&st[n-i-1]=='?')
 {
  st[n-i-1]=st[i];
  used[st[i]]=1;
  continue;
 }
 while (qp>0&&used[qp]>0)
 --qp;
 used[qp]=1;
 st[i]=st[n-i-1]=qp+'a';
}

//cout<<"%"<<er<<endl;
//cout<<st<<endl;
//cout<<qp<<endl;

for (int i=0;i<k;i++)
 if (used[i]==0)
  er=1;

for (int i=k;i<26;i++)
 if (used[i])er=1;

if (er)cout<<"IMPOSSIBLE"<<endl;
else cout<<st<<endl;

cin.get();cin.get();
return 0;}