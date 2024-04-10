/*
Soldier of sunlight
Welcome to the Kingdom of ignorance
Where all the tears of ages tell their tales

No one dares to break the spell
No one dares to fly
Time is running out, you can't deny

How many times
Have you found yourself under the influence?
How many times has a mirror made you cry?

Now it's time to stand upright
Turn down your inner door
The birth of yourself can't wait no more

In your mind there's a battle raging on
Try to find what you're fighting for

Wake up the King
From his sleep in your fantasy
Wake up the King
Let him be all your ecstasy

Tears flow to rivers
And rivers to oceans of broken dreams
Have you ever heard of tears of joy?

Show yourself a sense of life
Open up your eyes
Let your heartbeat be your best advice

In your eyes I can see the fire burn
Realize, now it is your turn

Wake up the King
From his sleep in your fantasy
Wake up the King
Let him be all your ecstasy

Look at the mountain, look at the sun
Feel all the pure energy
Birds fly and whisper, call out your name
They belong to you and you're the

King of a Kingdom, light in your hand
Look at what you have never seen
Walk on a rainbow, look to the stars
Cry it out and make your dream come true

Wake up the King
From his sleep in your fantasy
Wake up the King
Let him be all your ecstasy

Wake up the King
From his sleep in your fantasy
Wake up the King
Let him be all your ecstasy

Can't you see the crown?
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
#define right adsgasgadsg
#define free adsgasdg

using namespace std;

long n,k,up,dwn;
vector<long> ans;

int main(){
//freopen("logins.in","r",stdin);
//freopen("logins.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>k;

if (k%2==0)// dwn
{
 up=dwn=n-k/2;
 ++up;
 --dwn;
 ans.push_back(up-1);
 for (int i=1;i<=k;i++)
 {
  if (i%2){ans.push_back(up);++up;}
  else {ans.push_back(dwn);--dwn;}
 }
 for (int i=k+2;i<=n;i++)
  ans.push_back(n-i+1);
}
else
{
 up=dwn=k/2+1;
 ++up;
 --dwn;
 ans.push_back(up-1);
 for (int i=1;i<=k;i++)
 {
  if (i%2){ans.push_back(up);++up;}
  else {ans.push_back(dwn);--dwn;}
 }
 for (int i=k+2;i<=n;i++)
  ans.push_back(i);
}
 for (int i=0;i<ans.size();i++)
 {
  if (i)cout<<" ";
  cout<<ans[i];
 }
 cout<<endl;
cin.get();cin.get();
return 0;}