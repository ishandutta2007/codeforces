/*
Tear down the walls
Wake up the world
Ignorance is not bliss
So fed up with second best
Our time is here and now

I am the enemy
I am the antidote
Watch me closely
I will stand up now

We will Rise
Rise
Rise above

Stereotype Fools
Playing the game
Nothing unique
They all look the same
In this sea of mediocrity
I can be anything
Anything I want to be

I am the enemy
I am the antidote
Watch me closely
I will stand up now
We will rise
Rise
Rise above
*/

//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
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
#define eps 1e-6
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60

using namespace std;
string st;
string er(string st,long ps)
{
       string r="";
       for (int i=0;i<ps;i++)
       r+=st[i];
       for (int i=ps+3;i<st.size();i++)
       r+=st[i];
       return r;
}

int main(){
//freopen("wedding.in","r",stdin);
//freopen("wedding.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>st;
while (st.size()>3&&st[0]=='W'&&st[1]=='U'&&st[2]=='B')
{
      st=er(st,0);
}
while (st.size()>3&&st[st.size()-3]=='W'&&st[st.size()-2]=='U'&&st[st.size()-1]=='B')
 st=er(st,st.size()-3);

string rres="";

for (int i=0;i<st.size();i++)
{
 if (i>st.size()-3||st[i]!='W'||st[i+1]!='U'||st[i+2]!='B')
 rres+=st[i];else {rres+=' ';if (i<=st.size()-3)i+=2; }  
}//cout<<endl;

for (int i=0;i<rres.size();i++)
if (rres[i]!=' '||i==0||rres[i-1]!=' ')cout<<rres[i];
cout<<endl;

cin.get();cin.get();
return 0;}