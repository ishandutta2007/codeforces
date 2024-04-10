/*
Have you ever felt the need
To see more than you can see
Look into uncertainty
Reflections of treachery

Would you leave the world behind
Endless life is here to find
I can interest you in lies
Sell your soul for all it buys

Play with your insanity
Shatter your reality
Pulsing in your blood

I can satisfy your greed
For now all your debts are free
I have all eternity
To quench all the death I breed

Recreate the rules of play
From now things are done my way
None have ever won my game
Crucified them all in flames

Play with your insanity
Shatter your reality
Pulsing in your blood

Have you ever danced with the devil?
Has temptation ever summoned you?
Ever penned your name in blood
Let possession slowly swallow you?

When you stand under full moonlight
The attraction mesmerizes you
Have you ever wondered why?
It seems that evil you're attracted to

Reach out to my hand
Step back in time's sand
Genetic wasteland
Far beyond death
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

#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

string st;
long l,r;
set<long>::iterator it;
long calc[300000];

long gett(char c)
{
 if (c>='A'&&c<='Z')c=c-'A'+'a';
 if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u')return -1;
 return 2;
}

long check(long p)
{
 long res=0;
 set<long> sett;
 
 for (int i=1;i<p;i++)
 {
  calc[i]=gett(st[i-1])+calc[i-1];
 }
 
 for (int i=p;i<=st.size();i++)
 {
  calc[i]=calc[i-1]+gett(st[i-1]);
  sett.insert(calc[i-p]);
  it=sett.begin();
  if ((*it)<=calc[i])++res;
 }
 
 return res;
}

int main(){
//freopen("rush.in","r",stdin);
//freopen("rush.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>st;
l=1;
r=st.size();
if (check(1)==false)
 {cout<<"No solution"<<endl;
 return 0;}

while (l<r)
{
 long mid=l+r+1;
 mid/=2;
 if (check(mid)>0)l=mid;
 else r=mid-1;
}

cout<<l<<" "<<check(l)<<endl;

cin.get();cin.get();
return 0;}