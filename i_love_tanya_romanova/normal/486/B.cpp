/*
One day you'll wake up
And life will have no meaning
Except that feeling in your veins

Another blast another line
You'd hardly do it
Your lungs are craving
That cocaine

Well, all your friends
Will sit and watch you do it
And when it's time they'll do the same

You taste the smoke
It's the evil that's inside you
You know the winner of the game

Oh no, can't you feel the pain?
Can you feel the misery?

Well, time goes on
And you feel your body slipping
There's no control, you're a slave

You breathe in deep
And be sure your hearts still pumping
You ain't ready for the grave

One more time
And you promise the you will quit
But today's just not the day

Everyday you give that
Same old sermon
Still you crack your life away

Today they found you
In your room, your eyes were empty
A stem of a glass clutched in your hand

Your heart had stopped
And your life had left you
Dead young American
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
#define right adsgasgadsg
#define free adsgasdg

using namespace std;

long n,m,a[200][200],b[200][200],q,er;
long temp;

int main(){
//freopen("digits.in","r",stdin);
//freopen("digits.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;

for (int i=1;i<=n;i++) 
 for (int j=1;j<=m;j++)
  a[i][j]=1;

for (int i=1;i<=n;i++)
 for (int j=1;j<=m;j++)
 {
  cin>>q;
  b[i][j]=q;
  if (q==1)continue;
  for (int q=1;q<=m;q++)
   a[i][q]=0;
  for (int q=1;q<=n;q++)
   a[q][j]=0;
 }

for (int i=1;i<=n;i++)
 for (int j=1;j<=m;j++)
 {
  temp=0;
  for (int q=1;q<=m;q++)
   temp|=a[i][q];
  for (int q=1;q<=n;q++)
   temp|=a[q][j];
   if (temp!=b[i][j])er=1;
 }
if (er)cout<<"NO"<<endl;
else
{
    cout<<"YES"<<endl;
    for (int i=1;i<=n;i++)
    {
     for (int j=1;j<=m;j++)
     {
         if (j>1)cout<<" ";
         cout<<a[i][j];
     }
     cout<<endl;
    }
    
}
cin.get();cin.get();
return 0;}