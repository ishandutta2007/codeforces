/*
Weaving another web of lies around me
Leaving an endless trail of pain behind me

I don't deserve the love you give to me
How to mend the damage done to you?
I would trade a kingdom for a real life mulligan
To vindicate what I have done

Home is where the heart is
So maybe that's where I left mine
I know I have failed you
But please don't change the lock on your heart

Home is where the heart is
So maybe that's where I left mine
I know I have failed you
But please don't change the lock on your heart

Encaged in a mirage of my own design
Engaged something I hardly can define

Even though I'm always on my run
Echoes of your voice still hunts me down
Waging war on myself
To vindicate what I have done
(To vindicate what I have done)

Home is where the heart is
So maybe that's where I left mine
I know I have failed you
But please don't change the lock on your heart

Home is where the heart is
So maybe that's where I left mine
I know I have failed you
But please don't change the lock on your heart

The older that I get the more memories I have to leave behind
Can't undo anything at all but for you I'll step in line and remain confined

My halo will never glow again
But the horns keep penetrating my skull

Home is where the heart is
So maybe that's where I left mine
I know I have failed you
But please don't change the lock on your heart

Home is where the heart is
So maybe that's where I left mine
I know I have failed you
But please don't change the lock on your heart

My halo will never glow again
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
#include <ctime> 
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
 
#define eps 1e-9
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512
#define right adsgasgadsg
#define free adsgasdg
 
using namespace std;

string st1,st2;
long long c,res,q,qq,s;

int main(){
//freopen("alter.in","r",stdin);
//freopen("alter.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>st1>>st2>>c;

long tt=st2.size()-1;
while (st2[tt]=='0'){st2[tt]='9';--tt;}
st2[tt]--;

s=0;
for (int i=0;i<st1.size();i++)
 s=s*10+st1[i]-48,
 s%=c;

res=1;
q=s;

for (int i=st2.size()-1;i+1;--i)
{
 for (int j=0;j<st2[i]-48;j++)
  res=res*q%c;
  long long t=1;
 for (int j=0;j<10;j++) 
  t=t*q%c;
 q=t;
}

res*=(s+c-1);
res%=c;

if (res==0)res=c;

cout<<res<<endl;

cin.get();cin.get();
return 0;}