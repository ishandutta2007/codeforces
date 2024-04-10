/*
Why don't you listen to me when I try to talk to you
Stop thinking of yourself, for just a second fool
Shut up, shut up, I don't wanna hear your mouth
Your mother made a monster, now get the hell out of my house

Can't stand it for another day
I ain't gonna live my life this way
Cold sweat, my fists are clenching
Stomp, stomp, stomp the idiot convention

Which one of these words don't you understand
I'm Caught in a Mosh!
Talking to you is like clapping with one hand

What is it? Caught in a Mosh!
What is it? Caught in a Mosh!
What is it? Caught in a Mosh!
What is it? Caught in a Mosh!

Don't tell me how to do my job
There's the door, your name's on the knob
You're always in the way, like a beast on my back
Were you dropped as a baby, cause brains you lack

Can't stand it for another day
I ain't gonna live my life this way
Cold sweat, my fists are clenching
Stomp, stomp, stomp, the idiot convention
Which one of these words don't you understand?
I'm Caught in a Mosh 
Talking to you, is like clapping with one hand

What is it? Caught in a Mosh!
What is it? Caught in a Mosh!
What is it? Caught in a Mosh!
What is it? Caught in a Mosh!

Think - before you speak
Or suffer for your words
Learn, to give respect That others, give to you
AAAAAAAAAAAh, The best you can do

Hey Man!
I'm trying to reason but you don't understand 
Talking in circles, we'll never get it straight
Just you and me in our theatre of hate
Can't stand it for another day
I ain't gonna live my life this way
Cold sweat, my fists are clenching
Stomp, stomp, stomp, the idiot convention
Which one of these words don't you understand?
I'm Caught in a Mosh!
Talking to you is like talking with one hand

What is it? Caught in a Mosh!
What is it? Caught in a Mosh!
What is it? Caught in a Mosh!
What is it? Caught in a Mosh!
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
#define eps 1e-10
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
#define MAXN 10000
//#define SIZE 60
#define bsize 256

using namespace std;

long n;
long ways[2000];
vector<long> lev[100];
long calc;
long ar[1100][1100];

void add_edge(long a,long b)
{ways[b]+=ways[a];
ar[a][b]=ar[b][a]=1;
}

int main(){
//freopen("circuit.in","r",stdin);
//freopen("circuit.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
ways[1]=1;
lev[0].push_back(1);
lev[1].push_back(3);
lev[1].push_back(4);
add_edge(1,3);
add_edge(1,4);
calc=4;
for (int lvl=2;lvl<=32;lvl++)
{
 for (int j=1;j<=30;j++)
 {
  calc++;
  lev[lvl].push_back(calc);
 }
}

for (int lvl=2;lvl<=30;lvl++)
{
 for (int i=0;i<30;i++)
 {
  //add_edge(lev[lvl-1][0],lev[lvl][i]);
  if (i+lvl<=30)
  {add_edge(lev[lvl-1][1],lev[lvl][i]);add_edge(lev[lvl-1][0],lev[lvl][i]);}
  else
  {
   if (lvl==2)add_edge(lev[lvl-1][0],lev[lvl][i]);
   else add_edge(lev[lvl-1][i],lev[lvl][i]);
  }
 }
}

for (int i=0;i<30;i++)
if (n&(1<<i))
add_edge(lev[30][30-i-1],2);

cout<<calc<<endl;
for (int i=1;i<=calc;i++)
{
 for (int j=1;j<=calc;j++)
 {
  if (ar[i][j])cout<<"Y";else cout<<"N";
 }
 cout<<endl;
}


//cout<<ways[2]<<endl;

/*for (int i=1;i<=30;i++)
{for (int j=0;j<lev[i].size();j++)cout<<ways[lev[i][j]]<<" ";
cout<<endl;}
*/

cin.get();cin.get();
return 0;}