/*
A place afar in distant dreams
Mystic winds blow
Men mount birds of prey to war
And raid each others shore
Wizards and Warlocks battle by night
One survives by cunning and might
Take what you can by sword and sabre
Just reward for perilous labour

Stands among them a natural King
A man of barbaric breed
In a blade of steel he lays his trust
Killing and taking his needs
Upon him the scars of battles gone by
From many who have gazed in his murderous eye
Astride his mount he cursed and then
Assembled his men in thousands and ten
Onward lads we'll kill them all
Victory is ours
We'll have their heads and female slaves
Soon to loot their towers
Riding hard they rushed the gates
And scaled the granite walls
Through boiling oil and falling stone
His men endured it all

In bloody streets the battle raged
Brave men died and women were caged
Amidst the hoard, a barbaric roar
He gut the guard and kicked down the door
Sword in one hand, torch in the other
Alert every step of the way
If legends be true this place is cursed
Demons stand guard night and day

Living hell cloaked in black
Three ungodly hosts
Upon the dais a ball of light
Which binds them to their post
Faster than a striking cobra
Hit the altar and knocked it over
Shattered in a silver shower
The priests of hell have lost their power

Up the stairs a golden door
The queen awaits within
Her naked body close to his
The prize is won again
And has she yields to his force
His mind drifts off to Future Wars
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
 
#define eps 1e-9
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
 
//#define free asdfasdfsdadsg
#define bsize 512
 
using namespace std;

long x,k,used[10000],tp;
vector<long> vec;
long ans1,ans2;
long calc,q;

int main(){
//freopen("rmq.in","r",stdin);
//freopen("rmq.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>x>>k;
used[x]=1;
for (int i=1;i<=k;i++)
{
 cin>>tp;
 for (int j=1;j<=3-tp;j++)
 {
  cin>>q;used[q]=1;
 }
}
for (int i=1;i<=x;i++)
{
 if (used[i]==0){++calc;}
 else
 {
  if (calc)vec.push_back(calc);calc=0;
 }
}

for (int i=0;i<vec.size();i++)
{
 ans2+=vec[i];
 ans1+=(vec[i]+1)/2;
}
cout<<ans1<<" "<<ans2<<endl;

cin.get();cin.get();
return 0;}