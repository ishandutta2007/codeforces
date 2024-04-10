/*
Awken from below I call thee
Thy master pure in darkness
The one of hate before thy paths
Were chose to be forsaken
From depths of time in portals
Through empty eyes of light
I searched the texts for knowledge
Now I bleed the sacrifice
I am of purest power
Strengths of a thousand souls
I hear the voices of
The oldest ones burning within
Reveal the truth unto me
For I'll command the worthy
March through the ruins of
Diminished tribes

Beyond redemption!

In vein of sacred scriptures
Prodive the sight and visions
The lusting of hypocrisy
Forever scars the soul
Cursed is the life once given
Your prayers obsolite
The termination of the myths
You've led yourself to believe
I summon winds of fire
I summon winds of disease
I summon torture upon
All my rivalries who shall bleed
Confronting all before me
To tempt what I have in store
Don't tempt my fury for
The flames shall burn eternally

Beyond redemption
Aftermath of ashes and dust
Beyond redemption
The weak shall lie beneath the earth
Beyond redemption
You shall weep upon the feast I feed

I summon winds of fire
I summon winds of disease
I summon torture upon
All my rivalries who shall bleed
Confronting all before me
To tempt what I have in store
Don't tempt my fury for
The flames shall burn eternally
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
//#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-14
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
//#define N 120000

using namespace std;

string st;
long k,c,cc[2000],bst,ans;

int main(){
//freopen("magic.in","r",stdin);
//freopen("magic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>st;
cin>>k;
for (int i='a';i<='z';i++)
{
 cin>>c;
 cc[i]=c;
 if (c>bst)bst=c;
}

for (int i=1;i<=st.size()+k;i++)
 if (i<=st.size())
  ans+=cc[st[i-1]]*i;
  else ans+=bst*i;

cout<<ans<<endl;

cin.get();cin.get();
return 0;}