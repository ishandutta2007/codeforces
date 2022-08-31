/*
Remember I painted pictures of you
And I never found my way out
I spent a lifetime of dreams in the fields of your eyes
Lay me down when the rain covers you
And I'm afraid of the emptiness holding my thoughts
I see blue I see grey all the while

And when the night comes again I'll hold my hands to the skies
I've got a dream of home I've got a dream of home
And when the winter comes calling turn my face to the wind
I've got a dream of home I've got a dream
Of Alaska

Your name is whispered with the breath of my soul
In a hope that I'll never let fade
Between the mist on the waves and the blue of the sky
I threw a rose to the sea in your name
Now listen
Somewhere tonight there are tears on the wind
Are they yours are they mine I don't know

I'm crying out to the sky
I hope you're with me tonight
I've got a dream of home I've got a dream of home
And now the earth is left wanting
Turn my face to the wind
I've got a dream of home I've got a dream
Of Alaska

All through my life I stood tall as the sky
Hold to the things that I knew were so real
All I could feel
Strange how it goes how it comes to an end
Lord take your hand
Take you home once again
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

using namespace std;

long long hr,hb,wr,wb,th,rem,ans;
long long c,mx;

int main(){
//freopen("k.in","r",stdin);
//freopen("k.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>c;
cin>>hr>>hb>>wr>>wb;

if (wr<wb)
 swap(wr,wb),
 swap(hr,hb);

if (wr>=50000)
{
 for (int i=0;i<=c/wr;i++)
 {
  th=hr*i;
  rem=c-i*wr;
  th+=rem/wb*hb;
  ans=max(ans,th);   
 }
}
else
{
 if (hr<hb)
  swap(hr,hb),
  swap(wr,wb);
 mx=c/wr;
 for (int i=mx;i>=0&&i>=mx-10000000;i--)
 {
  th=hr*i;
  rem=c-i*wr;
  th+=rem/wb*hb;
  ans=max(ans,th);
 }
 for (int i=0;i<=mx&&i<=10000000;i++)
 {
  th=hr*i;
  rem=c-i*wr;
  th+=rem/wb*hb;
  ans=max(ans,th);
 }
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}