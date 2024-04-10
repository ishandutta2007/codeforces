/*
Kill for gain or shoot to maim
But we don't need a reason
To Golden Goose is on the loose
And never out of season
Blackened pride still burns inside
This shell of bloody treason
Here's my gun for a barrel of fun
For the love of living death

The killer's breed or the Demon's seed,
The glamour, the fortune, the pain,
Go to war again, blood is freedom's stain
Don't you pray for my soul anymore?

2 minutes to midnight,
The hands that threaten doom.
2 minutes to midnight,
To kill the unborn in the womb.

The blind men shout "Let the creatures out
We'll show the unbelievers."
The napalm screams of human flames
Of a prime time Belsen feast ... yeah!
As the reasons for the carnage cut their meat and lick the gravy
We oil the jaws of the war machine and feed it with our babies.

The killer's breed or the Demon's seed,
The glamour, the fortune, the pain,
Go to war again, blood is freedom's stain
Don't you pray for my soul anymore.

2 minutes to midnight,
The hands that threaten doom.
2 minutes to midnight,
To kill the unborn in the womb.

The body bags and little rags of children torn in two
And the jellied brains of those who remain to put the finger right on you
As the madmen play on words and make us all dance to their song
To the tune of starving millions to make a better kind of gun.

The killer's breed or the Demon's seed,
The glamour, the fortune, the pain,
Go to war again, blood is freedom's stain
Don't you pray for my soul anymore.

2 minutes to midnight,
The hands that threaten doom.
2 minutes to midnight,
To kill the unborn in the womb.

Midnight
Midnight
Midnight
It's all night

Midnight
Midnight
Midnight
It's all night
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
 
#define  INF 100000000
#define eps 1e-11
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60

using namespace std;

string st1,st2;
long a,b;

bool checknul(string st)
{
     for (int i=0;i<st.size();i++)
     if (st[i]=='1')return false;
     return true;
}


int main(){
//freopen("bees.in","r",stdin);
//freopen("bees.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>st1>>st2;
if (st1.size()!=st2.size())
cout<<"NO"<<endl;
else
{
    a=checknul(st1);
    b=checknul(st2);
    if (a!=b)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}

cin.get();cin.get();
return 0;}