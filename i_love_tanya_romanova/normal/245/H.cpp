/*
My fast heart is beating my soul cut and bleeding
My hells are too meeting with the man inside my brain
I tell him the all as I stand and I fall
And just to top it all I pay him for the task
My guts I am spilling I tell of the killings
With me at top billing I take off the mask
His jaw starts a dropping I say there's no stopping
The blood I'll be mopping right there on his couch
Another time he'll ask me what it is I'm thinking
And I will have to show him I long to see him dead
The walls dripping red from the axe in his head
And I'm sure now he's dead by the look in his eyes
Put me to sleep and hypnotize see the dead stare in my eyes
Let your guard down when you try to get inside my head
Dive in deep into my mind wonder all the things you'll find
A war is up your death is signed session over-dead
I think I'm starting to go crazy over wanting to kill
I think I'll never stop the craving to see blood start to spill
I see the outcome when your heart stops beating and I start to sweat
I love the moment when you're dead but haven't taken your last breath
The cops busting in in the middle of my sin
I stop and start to grin as I see the bodies fly
In my mind I kill them all heads will roll and bodies fall
Blood and guts and that is all that you can recognize
I come back from a daydream open eyes and start to scream
What does all this gore mean is it really real or not
Splash my face and rub my eyes maybe noone really dies
Open up to realize its all inside my head
I think I'm starting to go crazy over wanting to kill
I think I'll never stop the craving to see blood start to spill
I see the outcome when your heart stops beating and I start to sweat
I love the moment when you're dead but haven't taken your last breath
I think I'm starting to go crazy over wanting to kill
I think I'll never stop the craving to see blood start to spill
I think I'm starting to go crazy over wanting to kill
I think I'll never stop the craving to see blood start to spill
I see the outcome when your heart stops beating and I start to sweat
I love the moment when you're dead but haven't taken your last breath yet
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
//#define bsize 250
#define clone agsdahfaassdg

using namespace std;

string st;
long l,r,q,ans[5001][5001],answ[5001][5001],a,b;

int main(){
//freopen("raydist.in","r",stdin);
//freopen("raydist.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>st;
for (int i=0;i<st.size();i++)
{
 l=r=i;
 ans[l][r]++;
 
 while (l>0&&r+1<st.size()&&st[l-1]==st[r+1])
 {
  --l;++r;
  ans[l][r]++;     
 }   
}

for (int i=1;i<st.size();i++)
{
    l=i-1;r=i;
    if (st[l]!=st[r])continue;
    
 ans[l][r]++;
 
 while (l>0&&r+1<st.size()&&st[l-1]==st[r+1])
 {
  --l;++r;
  ans[l][r]++;     
 }  
}

for (int i=0;i<st.size();i++)
{
    for (int j=i;j<st.size();j++)
    ans[i][j]=ans[i][j-1]+ans[i][j];
}

for (int span=0;span<st.size();span++)
{
    for (int i=0;i<st.size();i++)
    {
        if (i+span>=st.size())continue;
        answ[i][i+span]=ans[i][i+span]+answ[i+1][i+span];
    }
}
cin>>q;
for (int i=1;i<=q;i++)
{
    cin>>a>>b;
    --a;--b;
    cout<<answ[a][b]<<endl;
}

cin.get();cin.get();
return 0;}