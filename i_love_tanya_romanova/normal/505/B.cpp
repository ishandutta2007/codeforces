/*
What goes around comes around
What goes around comes around

What goes around comes around
You better realize
You kill life, you kill life, why? Why?
I see your eyes, I see your lies
I see your eyes, inside

What goes around comes around
Now it's your time
How long can you lie? How long can you hide?
How long can you live with your soulbleed?
How long can you live with your

Bleed
(Bleed)
Bleed
(Bleed)
Bleed
(Bleed)

Bleed
(Bleed)
Bleed
(Bleed)
Bleed
(Bleed)

Bleed
(Bleed)
Bleed
(Bleed)
Bleed
(Bleed)

Bleed
(Bleed)
Bleed
(Bleed)
Bleed
(Bleed)

What goes around comes around
No more lies
You kill life, you kill life, why? Why?
I see a mother cry
I see a brother cry

What goes around comes around
Now it's your time
How long can you lie? How long can you hide?
How long can you live with your soulbleed?
How long can you live with your

Bleed
(Bleed)
Bleed
(Bleed)
Bleed
(Bleed)

Bleed
(Bleed)
Bleed
(Bleed)
Bleed
(Bleed)

Bleed
(Bleed)
Bleed
(Bleed)
Bleed
(Bleed)

Bleed
(Bleed)
Bleed
(Bleed)
Bleed
(Bleed)

Bring it on
Bring it
Bring

I'll make you bleed and you're bleeding now
I'll make you bleed and you're bleeding now
I'll make you bleed and you're bleeding now
Muthafucka

I got my pride and that's all I need
I'll make you bleed with another blow without the radio
Don't take advantage of this process
You might have to digest a blade made for your ass to fade

Living on instinct
Never think when I'm rushin' bones crushin'
[Incomprehensible] sealed and delivered from a savage
And now you sweat because you're goin' down
You envious clown fuckin' bleed

Fuck your ass
Muthafucka, muthafucka, muthafucka
Muthafucka, muthafucka, muthafucka
Muthafucka, muthafucka, muthafucka
Muthafucka, muthafucka

Bleed
(Bleed)
Bleed
(Bleed)
Bleed
(Bleed)

Bleed
(Bleed)
Bleed
(Bleed)
Bleed
(Bleed)

Bleed
(Bleed)
Bleed
(Bleed)
Bleed
(Bleed)

Bleed
(Bleed)
Bleed
(Bleed)
Bleed
(Bleed)
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
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
#define MAG 10000

using namespace std;

long n,m,a,b,ans,w[200][200];
long c,tests;

long get(long a,long b)
{
 if (w[b][a]==a)
  return a;
 return get(w[b][a],b);
}

void merge(long a,long b,long c)
{
 w[c][a]=b;
}

int main(){
//freopen("evacuation.in","r",stdin);
//freopen("evacuation.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
for (int i=1;i<=100;i++)
 for (int j=1;j<=n;j++)
  w[i][j]=j;
  
for (int i=1;i<=m;i++)
{
 cin>>a>>b>>c;
 a=get(a,c);
 b=get(b,c);
 if (a==b)continue;
// cout<<a<<" "<<b<<endl;
 merge(a,b,c);
}

cin>>tests;
for (;tests;--tests)
{
 cin>>a>>b;
 ans=0;
 for (int i=1;i<=100;i++)
  if (get(a,i)==get(b,i))++ans;
 cout<<ans<<endl;
}

cin.get();cin.get();
return 0;}