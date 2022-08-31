/*
The lowest form of life that's crawling in our streets
From seedy dope pushers to the politicians we meet
The sorry religious vomit that infests in our TVs
The weapons that we sell to the trash in the middle east
Murderous drug smugglers pay their way to pass
They look the other way when they take the kickback
We've got to put a stop to this senseless bullshit
Take all these people and throw them in the pit

Let us know - where our tax dollars are spent
Tell us how - how much it costs to repent
Time has come - for us to take a stand
Let us know - when you meet our demands

You can take this all to hell
Shove it up your ass where the sun ain't shining
We know now what it takes to defend
If disaster strikes then they'll be hiding
You can take this all to hell
Shove it up your ass where the sun ain't shining
We know now what it takes to defend
If disaster strikes, then they'll be hiding
Corruption

From laundering money to hookers on the make
There's always a scandal, someone's on the take
They payoff for secrets, sell plans to a spy
They cover their asses and say it's a lie
Society cries when the vermin go free
When they're done, what's left for me?
This social disorder that's causing us pain
Indecent disease, it's they who are to blame
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
//#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-7
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

string st;
long long a;
long long s[200000];
long long calc[1000000];
long long temp,ans;

long long gett(long long x)
{
 if (x>66666)return 0;
 return calc[x];
}

long long parts;

int main(){
//freopen("gift.in","r",stdin);
//freopen("gift.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>a;
cin>>st;
//st="";
//for (int i=1;i<=4000;i++)
//st+="1";

for (int i=0;i<st.size();i++)
{
 s[i+1]=s[i]+st[i]-48;   
}

for (int i=0;i<st.size();i++)
for (int j=i+1;j<=st.size();j++)
{
 //if (a==0)ans++;
 parts++;
 calc[s[j]-s[i]]++;   
}


for (int i=1;i*i<=a;i++)
{
 if (a%i==0)
 {
  temp=gett(i)*gett(a/i);
  if (a/i==i)ans+=temp;
  else ans+=2*temp;
 }   
}

//if (a==0)ans*=calc[0]*2;

if (a==0)ans=parts*calc[0]+calc[0]*parts-calc[0]*calc[0];

cout<<ans<<endl;

cin.get();cin.get();
return 0;}