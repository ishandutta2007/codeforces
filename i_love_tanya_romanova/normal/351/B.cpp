/*
Stop be quite now
Out with the light and
Then up and down it goes

Fly
Out with the light
There at the door
The inspiration I've looked for
The spirit of the youth appears

No one ever dares to speak
It's nothing else but fantasy
It's make believe
Make believe

No one ever dares to speak
It's nothing else but fantasy
But one day
It all will come to life

Step out of line
And I'll teach you how to fly
Then away we'll go
Leave your mark land of mine
Leave your mark
In the land of mine

The second one to right
And then straight on
Until morning light

Stop be quite now
No irritation
No, not the slightest doubt

We got once
Quick - we better hurry
There from the road I sense
The end of fun gets near
Wonderful thoughts
And imaginations
These things will lift you up

What is it like?
You ask me, my dear
Will there be fairies
Or things to fear?
For fairies sake I'd say
You better come with me
So soon you'll see
Now up and down it goes
And round
Round and round and round

Praise
To my cleverness
They all follow me
All praise to innocence
That's everything it needs
Fly in
Fly out
They'll leave it all behind

No one ever dares to speak...

Life is a map
And it is quite confusing
The lights are up
Now let the play begin
She flies, she flies
Into the light she flies
No words like "Just" in mind
She's finding Neverland
There on the day she dies
Don't stop it now
She still enjoys the scene
Don't stop it now
Don't stop it now
Don't stop it now
Don't stop it now, now, now

No one ever dares to speak...
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

long n,answ;
long ar[5000];
double prob[1000][1000];

int main(){
//freopen("firesafe.in","r",stdin);
//freopen("firesafe.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

//cin>>n;
/*
prob[0][n]=1;

for (int i=0;i<=100;i++)
 for (int j=1;j<=100;j++)
 {
  if (i%2==0){prob[i+1][j-1]+=prob[i][j];}
  else {prob[i+1][j-1]+=prob[i][j]*0.5;prob[i+1][j+1]+=prob[i][j]*.5;   }
 }
 double 
 answ=0;
 for (int i=0;i<=100;i++)
 answ+=i*prob[i][0];
 cout<<answ<<endl;
 */
 
 cin>>n;
 for (int i=1;i<=n;i++)
 cin>>ar[i];
 for (int i=1;i<=n;i++)
  for (int j=i+1;j<=n;j++)
  if (ar[j]<ar[i])
  ++answ;
  cout.precision(9);
  if (answ==0)cout<<fixed<<0<<endl;
  else if (answ%2==0)cout<<fixed<<answ*2.0<<endl;
  else cout<<fixed<<2.0*(answ-1)+1<<endl;
cin.get();cin.get();
return 0;}