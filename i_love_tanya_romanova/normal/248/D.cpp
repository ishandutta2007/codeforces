/*
Rise of nations pride

Russians on a route to ruin
Kremlin is more than certain to win
Sent away an army to the west

Blizzard reigned the ground were chosen
Snow was deep and hell were frozen
Stalin were too eager to invade

He thought of the might he possessed
And not of his foe
Rage of winter

Rise, nations pride
Hold whats yours
Strike'em where it hurts

Fight, hold your ground
Winter war
Reinforce the line

Split them into small divisions
Rip 'em of the conquest visions
Motti tactics used with great result

Snipers move unseen in snowfall
Force them to retreat and recall
Fight the Russian rule and their demand

With Molotov cocktail in hand
No fear of their tanks
Death or glory

Rise, nations pride
Hold whats yours
Strike'em where it hurts

Fight, hold your ground
Winter war
Reinforce the line

A slice of a knife to a throat
And their blood turns to ice
Talvisota!

Rise, nations pride
Hold whats yours
Strike'em where it hurts

Fight, hold your ground
Winter war
Reinforce the line

Rise, nations pride
Hold whats yours
Strike'em where it hurts

Fight, hold your ground
Winter war
Reinforce the line
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

#define  INF 100000000
#define eps 1e-11
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
#define bsize 256

using namespace std;

long n,tim;
string st;
long lpos,calc1,calc2;
long need,ans,calc;
long l,r,has,bad;

int main(){
//freopen("melman.in","r",stdin);
//freopen("melman.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>n>>tim;
cin>>st;
lpos=-1;
for (int i=0;i<st.size();i++)
{
 if (st[i]=='H')++calc1;
 if (st[i]=='H')lpos=i;
 if (st[i]=='S')++calc2;
}

if (tim<=lpos){cout<<-1<<endl;return 0;}
l=0;
r=1e6;
if (calc1>calc2)l=calc1-calc2;

while (l<r)
{
 long mid=l+r;
 mid/=2;
 calc=0;
 has=mid;
 bad=1e9;
 need=0;
 
 long oscore=1e9;
 long tt=mid;
 long epos=0;
 
 for (int i=0;i<st.size();i++)
 {
  if (tt<calc1)epos=i;
  if (st[i]=='S')++tt;
 }
 if (epos<lpos)epos=lpos;
// cout<<mid<<"  "<<epos<<endl;
 
 for (long i=0;i<st.size();i++)
 {
  ++calc;
  if (bad<1e7)
  oscore=min(oscore,epos-i+calc+(epos-bad)*(bad<1e7));
//  cout<<i<<" "<<has<<" "<<lpos<<" "<<need<<" "<<bad<<endl;
  
  if (st[i]=='H'){if (has==0){bad=min(bad,i);need++;}else{--has;}}
  if(st[i]=='S'){++has;if (has>=need&&i>=lpos){if (need)calc+=i-bad;break;}if (has>=need&&need>0){//cout<<i<<"   "<<bad<<endl;
  calc+=2*(i-bad);bad=1e9;has-=need;need=0;}}
  //cout<<i<<" "<<lpos<<" "<<calc<<" "<<has<<" "<<need<<endl;
  if (i>=lpos&&has>=need){if (need)calc+=i-bad;break;}// f back

 }
// cout<<calc<<" "<<mid<<endl;
 calc=min(calc,oscore);
 if (calc>tim)l=mid+1;
 else r=mid;
}
cout<<l<<endl;

cin.get();cin.get();
return 0;}