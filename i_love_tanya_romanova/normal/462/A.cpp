/*
I remember the times we had, take a look at the past
I can see you clearly now, very well
But I don't know when you lost yourself
There was no way to find you
You were deep, so deep inside your world

Don't know where to go
Ohh, and I miss you so
I lost you and I'll never be the same
Now you're gone and I learned to be strong
(Learn to be strong)

And there's no need to cry and there's no need to die
'Cause all we need is love
There is no need to cry and there's no need to die
Ohh, 'cause the world keeps turning on

So much I've said but I guess I was right after all
You have never, never really been alone
And on our way there's been trouble and pain
And everything that comes along with it
We had seen it all before

No need to cry and there's no need to die
'Cause all we need is love
There is no need to cry and there's no need to die
Ohh, 'cause the world keeps turning on

What have you done with all your life?
What have you done with all of your love?
Who cares about it when you're gone?
Oh, I don't know and you'll never see

What's the sense of it?
What's the sense of all? What's the sense of our life?
There's one hundred million ways to go
And we will never know what's our truth or reality?
Ooh, yeah

What have you done with all your love?
And what have you done with all of your life?
There's nothing left to stay right now
And I don't know and you'll never know

No need to cry and there's no need to die
'Cause all we can give is hope, truth and love
There is no need to cry and there's no need to die
Ohh, the world keeps turning on

There is a light in the dark
A light in the dark
For everyone, for everyone
For everyone
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
#define rmost agasdgasdg

using namespace std;

long n;
string st;
long calc;
long er;
char ar[2000][2000];

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>st;
 for (int j=1;j<=n;j++)
  ar[i][j]=st[j-1];
}

for (int i=1;i<=n;i++)
 for (int j=1;j<=n;j++)
 {
     calc=0;
     if (ar[i-1][j]=='o')++calc;
     if (ar[i+1][j]=='o')++calc;
     if (ar[i][j-1]=='o')++calc;
     if (ar[i][j+1]=='o')++calc;
     if (calc%2)++er;
 }
if (er)cout<<"NO"<<endl;
else cout<<"YES"<<endl;

cin.get();cin.get();
return 0;}