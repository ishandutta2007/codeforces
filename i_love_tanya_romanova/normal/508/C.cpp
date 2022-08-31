/*
Hurts to see
Mind capacity
Shame, idlemind
No, you have changed me
My mouth is shut
Stupidity has shut my mouth
Shame, idlemind
No, you have changed me
So, when you come
Until I'm prepared to come along
I hold your hand so hard my knuckles turn white
When you clear the streets and kill the lights
See the light
Pull it to freedom
The words and the light
My name, you have changed it
You totally changed it, cruel
This is how you tell me
Once again
How am I nothing on you
How everything is supposed to end
Father, I will make it
It's the journey of our life
Fix my eyes on the sun
What have I done?
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

long m,t,r,tt,cnt,light[1<<20];
long ans;

int main(){
//freopen("hiking.in","r",stdin);
//freopen("hiking.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>m>>t>>r;
for (int i=1;i<=m;i++)
{
 cin>>tt;
 tt+=t;
 cnt=0;
 for (int j=tt-1;j>=tt-t;j--)
 {
  if (light[j])++cnt;
 }
 for (int j=tt-1;j>=tt-t;j--)
 {
  if (cnt<r&&light[j]==0)
  ++cnt,
  light[j]=1;
 }
 if (cnt<r)
 {
  cout<<-1<<endl;
  return 0;
 }
}
for (int j=0;j<=2000;j++)
 if (light[j])++ans;

cout<<ans<<endl;

cin.get();cin.get();
return 0;}