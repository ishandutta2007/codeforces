/*
There's a secret place I like to go
Everyone is there but their face don't show
If you get inside, you can't get out
There's no coming back, I hear them shout

Welcome to my hide away, my secret place
How I arrived I can't explain
You're welcome to, if you want to stay
But everyone just runs away

Oh there's a secret place I like to go
Everyone is there but their face don't show
If you get inside you can't get out
There's no coming back, I hear them shout

Let me in, get me out
Can't do more then twist and shout
Lost my soul without a trace
Found it again in my secret place

Let me in, get me out
Can't do more then twist and shout
Lost my soul without a trace in disgrace

I hide from those that try to find me
Scary things that's right behind me
I lost myself, I must confess
I can't explain how I got this mess

Welcome to my hide away, my secret place
How I arrived I can't explain
You're welcome to, if you wanna stay
But everyone just runs away

My secret place, there's a secret place
My secret place, there's a secret place
I like to go, my secret place
There's a secret place, just runs away
My secret place
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
#define eps 1e-9
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

long n,m,k,temp,ans;

int main(){
//freopen("virus.in","r",stdin);
//freopen("virus.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m>>k;
for (int i=1;i<=n;i++)
{cin>>temp;
 if (temp==1)
 {
  if (m==0)++ans;
  else --m;
 }
 if (temp==2)
 {
  if (k)--k;
  else if (m)--m;
  else ++ans;
 }
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}