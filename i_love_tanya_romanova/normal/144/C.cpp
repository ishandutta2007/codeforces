/*
Shhh... quiet, you might piss somebody off
Like me motherfucker, you've been at it for too long
While you feed off others' insecurities
You stand in front of me and bite the hand that feeds

(Self-righteousness is wearing thin)
Lies inside your head your best friend
(Heart bleeds but not for fellow man)
Broken glass, your fake reflection

I've had enough
It's time for something real
I don't respect the words you're speaking
Gone too far, a clone

So how does it feel to know that someone's kid in the heart of America
Has blood on their hands, fighting to defend your rights?
So you can maintain the lifestyle that insults his family's existence
Well, where I'm from we have a special salute we aim high in the air
Towards all those pompous assholes who spend their days pointing fingers

Fuck you

Shh... quiet, you might piss somebody off
Like the heartbeat of this country when antagonized too long
I'll be damned if you count me in
As part of your generous hypocrisy collecting enemies

Tabloid gossip queen worthless man
(There's no need for us to bury you)
Selfish agenda, once again
(Right this way, you've dug your own grave)

I've had enough it's time for something real
Don't respect the words you're speaking
gone too far, a clone

All the way from the east to the west
We've got this high society looking down on their very foundation
Constantly reminding us that our actions are the cause of all their problems
Pointing the fingers in every direction and
Blaming their own nation for who wins the elections
They've never contributed a fucking thing to the country they love to criticize

Excuse the obscene, ignore the untrue
Depictions we see, try and get through
Admitting mistakes can't hurt
I'm not the last but I sure ain't the first

Shhh... quiet, you might piss somebody off

Self-righteousness is wearing thin
(Lies inside your head your best friend)
Heart beats but not for fellow man
(Broken glass, your fake reflection)

I've had enough it's time for something real
I don't respect the words you're speaking
gone too far, a clone
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
#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-8
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

string st1,st2;
long calc1[200000][30],calc[30],ans,fl;
long temp;

int main(){
//freopen("firesafe.in","r",stdin);
//freopen("firesafe.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);


cin>>st1;
cin>>st2;

for (int i=0;i<st1.size();i++)
{
 for (int j=0;j<26;j++)
 calc1[i+1][j]=calc1[i][j];
 if (st1[i]!='?')calc1[i+1][st1[i]-'a']++;   
}

for (int i=0;i<st2.size();i++)
calc[st2[i]-'a']++;

for (int i=st2.size();i<=st1.size();i++)
{
    fl=0;
    for (int j=0;j<26;j++)
    {temp=calc1[i][j]-calc1[i-st2.size()][j];if (temp>calc[j])fl=1;}
    if (fl==0)++ans;
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}