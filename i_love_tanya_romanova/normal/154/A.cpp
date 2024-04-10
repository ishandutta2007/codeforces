/*
You're not the right one dumb damn rapper
Not the right goddamn
Who are you to rap shit take off
And who says you're right

On top you think you're bomb artista
But you're bent out of, oh, right
Suck my dick
But don't you think that you're, oh, right

Sometimes things might make me
Oh, it makes me mad
And when it happens fuck it
Rugged in mind a hint of bite
Why does it not exist in you?

Right, shit, why hit in yet another day
Woo hoo right
It's not woo hoo right
But you're wrong

Twist, twist, twist, twist

Put me in right, now make mad
Prove that you're right
Somehow you're not right, huh
But that don't make me mad

Right now you're beggin' for a little brew
All night
Yeah, it's so simple
I had some red dog, you hand over it

Twist, twist, twist, twist
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

using namespace std;

string st;
long bad;
long ar[200][200];
long dp[105000][30];
long ans;
string st1;
long temp,answ;

int main(){
//freopen("rush.in","r",stdin);
//freopen("rush.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>st;
cin>>bad;
for (;bad;--bad)
{
 cin>>st1;
 ar[st1[0]-'a'][st1[1]-'a']=1;
 ar[st1[1]-'a'][st1[0]-'a']=1;
}

for (int i=0;i<=st.size();i++)
 for (int last=0;last<=26;last++)
  dp[i][last]=1e9;

for (int i=0;i<=26;i++)
 dp[0][i]=0;

for (int i=0;i<st.size();i++)
 for (int last=0;last<26;last++)
 {
  temp=st[i]-'a';
  dp[i+1][last]=min(dp[i+1][last],dp[i][last]+1);// del
  if (ar[last][temp]==0)
   dp[i+1][temp]=min(dp[i+1][temp],dp[i][last]);
 }

answ=1e9;
for (int i=0;i<=26;i++)
 answ=min(answ,dp[st.size()][i]);
cout<<answ<<endl;

cin.get();cin.get();
return 0;}