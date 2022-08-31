/*
My eyes are open wide
By the way I made it through the day
I watch the world outside
By the way I'm leaving out today

I just saw Haley's Comet, shooting
Said, "Why you always running in place?"
Even the man in the moon disappeared
Somewhere in the stratosphere

Tell my mother, tell my father I've done the best I can
To make them realize this is my life, I hope they understand
I'm not angry, I'm just saying
Sometimes goodbye is a second chance

Please don't cry one tear for me
I'm not afraid of what I have to say
This is my one and only voice
So listen close, it's only for today

I just saw Haley's Comet, shooting
Said, "Why you always running in place?"
Even the man in the moon disappeared
Somewhere in the stratosphere"

Tell my mother, tell my father I've done the best I can
To make them realize this is my life, I hope they understand
I'm not angry, I'm just saying
Sometimes goodbye is a second chance

Here is my chance
This is my chance

Tell my mother, tell my father I've done the best I can
To make them realize this is my life, I hope they understand
I'm not angry, I'm just saying
Sometimes goodbye is a second chance
Sometimes goodbye is a second chance
Sometimes goodbye is a second chance
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

using namespace std;

double vp,vd,t,f,c;
long ans;
double crd;
double cc,at;

long solve()
{
 if (vp>=vd)return 0;
 crd=vp*t;
 cc=crd/(vd-vp);
 crd+=cc*vp;
 if (crd<=c-eps)ans=1;
 else return 0;
 while (true)
 {
  at=crd/vd+f;
  crd+=at*vp;
  at=crd/(vd-vp);
  crd+=at*vp;
  if (crd<=c-eps)++ans;
  else return ans;
 }
}

int main(){
//freopen("magic.in","r",stdin);
//freopen("magic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>vp>>vd>>t>>f>>c;

cout<<solve()<<endl;

cin.get();cin.get();
return 0;}