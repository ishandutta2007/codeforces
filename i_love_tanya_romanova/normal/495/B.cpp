/*
Where'd those days go when I thought I knew you?
What happened to the person, I once loved?
Desolate thoughts are all I think of now
It's killing my mind and now I want to kill you

I see you now and stare into those whore stained eyes
And wonder how I could let you lead me to
Believe that you were someone good for me, you weren't
You're just another blood sucking leech

Violence breaks out, in my head
Passive thoughts are now, now thrown away

Go

Despise and disgust are all I see in you now
I wish things could have been right between us
I wish you were the person you had appeared to be
But now my thoughts are gone and thrown away

But now my hate is buried in me
Left for new seeds to grow from this

How long will it be
Until you notice there is nothing left for us?

Spoken infidelities will never see our daylight again
So where does this all lead us to now?
I'll never be able to look at you again
But maybe that is for the best now we'll see
Death is now near my dear, we must part our ways

One thousand cries now die
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
 
#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
 
using namespace std;

long a,b,t;
set<long> ans;

int main(){
//freopen("lesson.in","r",stdin);
//freopen("lesson.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>a>>b;
if (a<b)cout<<0<<endl;
else if (a==b)
 cout<<"infinity"<<endl;
 else
 {
  for (int i=1;i*i<=a-b;i++)
  {
   if ((a-b)%i)continue;
   t=i;
   if (t>b)ans.insert(t);
   t=(a-b)/i;
   if (t>b)ans.insert(t);
  }
  cout<<ans.size()<<endl;
 }
 
cin.get();cin.get();
return 0;}