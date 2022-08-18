/*
I reach for my shadow in horror
Envy eats but its own cold heart
Some friends, the few I have left
Set sail out of the frame Im in

He begins to die, That loses his desires
All are not merry that dance here lightly
Fear follows those who live by the sword and fire
My heart was my weapon, and the death of me

I saw the evening anew, all lean and red of hue
Its a lonely ocean out there, watched from my shore of despair
So unto the sea my grief set sail, in disbelief
Fevers and time burn away, Nothing is allowed to stay

There is nothing new underneath the sun
The moon with its long arms, reaches into the sea
My eyes were towers high, in my heaven

And from my body drew a cold breath and final clue
The sun made clear its thoughts, It was never coming through

I saw the evening anew, all lean and red of hue
Its a lonely ocean out there, watched from my shore of despair
So unto the sea my grief set sail, in disbelief
Fevers and time burn away, Nothing is allowed to stay
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

long long n,ways[4][55555],ar[55555],ans;

int main(){
//freopen("circuit.in","r",stdin);
//freopen("circuit.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
ways[0][10000]=1;

for(int i=1;i<=n;i++)
{
 cin>>ar[i];
 for (int j=1;j<=20000;j++)
 ways[i%2][j]=0,ways[1-i%2][j]%=bs;
 for (int j=1;j<=20000;j++)
 {
  if (ways[1-i%2][j]==0)continue;
  ways[i%2][j+ar[i]]+=ways[1-i%2][j];
  ways[i%2][j-ar[i]]+=ways[1-i%2][j];
 }
 ans+=ways[i%2][10000];
 ways[i%2][10000]++;
}
cout<<ans%bs<<endl;

cin.get();cin.get();
return 0;}