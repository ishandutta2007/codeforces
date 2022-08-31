/*
Before the story begins, is it such a sin
For me to take what's mine until the end of time?
We were more than friends before the story ends
And I will take what's mine, create what God would never design

Our love had been so strong for far too long
I was weak with fear that something would go wrong
Before the possibilities came true I took all possibility from you
Almost laughed myself to tears, conjuring her deepest fears

Must have stabbed her fifty fucking times
I can't believe it
Ripped her heart out right before her eyes
Eyes over easy, eat it, eat it, eat it

She was never this good in bed even when she was sleeping
Now she's just so perfect, I've never been quite so fucking deep in
It goes on and on, and on, I can keep you looking young
And preserved forever with a fountain to spray on your youth whenever

Cause I really always knew that my little crime
Would be cold that's why I got a heater for your thighs
And I know, I know it's not your time but bye, bye
And a word to the wise when the fire dies
You think it's over but it's just begun, baby don't cry

You had my heart, at least for the most part
Cause everybody's gotta die sometime
We fell apart, let's make a new start
Cause everybody's gotta die sometime, but baby, don't cry

The possibilities I'd never considered
Are occurring the likes of which I'd never heard
Now an angry soul comes back from beyond the grave
To repossess a body with which I'd misbehaved

Smiling right from ear to ear
Almost laughed herself to tears

Must have stabbed him fifty fucking times
I can't believe it
Ripped his heart out right before his eyes
Eyes over easy, eat it, eat it, eat it

Now that it's done, I realize the error of my ways
I must venture back to apologize
From somewhere far beyond the grave

I gotta make up for what I've done
Cause I was all up in a piece of heaven
While you burned in hell, no peace forever

Cause I really always knew that my little crime
Would be cold that's why I got a heater for your thighs
And I know, I know it's not your time but bye, bye
And a word to the wise when the fire dies
You think it's over but it's just begun but baby, don't cry

You had my heart at least for the most part
Cause everybody's gotta die sometime
We fell apart, lets make a new start
Cause everybody's gotta die sometime, but baby, don't cry

I will suffer for so long
(What will you do, not long enough?)
To make it up to you
(I pray to God that you do)
I'll do whatever you want me to do
(Well then Ill grant you a chance)

And if it's not enough
(If its not enough, if its not enough)
If it's not enough
(Not enough)
Try again
(Try again)
And again
(And again)
Over and over again

Were coming back, coming back
Well live forever, live forever
Lets have a wedding, have a wedding
Lets start the killing, start the killing

Cause I really always knew that my little crime
Would be cold that's why I got a heater for your thighs
And I know, I know it's not your time but bye, bye
And a word to the wise when the fire dies
You think it's over but it's just begun but baby, don't cry

You had my heart at least for the most part
Cause everybody's gotta die sometime
We fell apart, lets make a new start
Cause everybody's gotta die sometime, but baby, don't cry
*/
 
#pragma comment(linker, "/STACK:16777216")
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
 
long n,x,t,h,m,itr,qh,calc,usd[3][3000],bst,bp,ans;
vector<pair<long, long> > v[3];

int main(){
//freopen("trade.in","r",stdin);
//freopen("trade.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);
 
cin>>n>>x;
for (int i=1;i<=n;i++)
{
 cin>>t>>h>>m;
 v[t].push_back(make_pair(h,m));
} 

ans=0;

// strt 0
itr=0;
qh=x;
calc=0;
while (true)
{
    //  cout<<itr<<endl;
 bst=-1e9;
 bp=-1;
 for (int i=0;i<v[itr].size();i++)
 {
  if (usd[itr][i]==0&&v[itr][i].first<=qh)
   if (v[itr][i].second>bst){bst=v[itr][i].second;bp=i;}
 }
 if (bst<0)break;
 calc++;
// cout<<itr<<endl;
 usd[itr][bp]=1;
 qh+=bst;
// cout<<bst<<" "<<bp<<" "<<itr<<endl;
 itr=1-itr;
// cout<<qh<<endl;
}
ans=max(ans,calc);

for (int i=0;i<2;i++)
 for (int j=0;j<v[i].size();j++) 
  usd[i][j]=0;
  
// strt 1
itr=1;
qh=x;
calc=0;
while (true)
{
 bst=-1e9;
 bp=-1;
 for (int i=0;i<v[itr].size();i++)
 {
  if (usd[itr][i]==0&&v[itr][i].first<=qh)
   if (v[itr][i].second>bst){bst=v[itr][i].second;bp=i;}
 }
 if (bst<0)break;
 calc++;
 usd[itr][bp]=1;
 qh+=bst;
 itr=1-itr;
}
ans=max(ans,calc);

cout<<ans<<endl;

cin.get();cin.get();
return 0;}