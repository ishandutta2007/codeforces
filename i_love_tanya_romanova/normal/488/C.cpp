/*
There's a dream that comes to me
And it whispers all night long
Telling lies of things to be
And makes it all seem wrong
Even sleep is choking me
Am I feeling weak or strong
In the dreams I could not be
But it's killing me inside
It's killing me inside
Killing me inside
There's a dream I cannot see
And it laughs for all too long
Open eyes stare down at me
And it sings the same old song
Now its raining down on me
And I can't believe they're gone
All the dreams I used to see
Is now killing me inside
Killing me inside
I see you can breathe inside
My brain is obsessed with sorrow
Killing me inside
My brain is obsessed with sorrow
I see you can breathe inside
My brain is obsessed with sorrow
Killing me inside
My brain is obsessed with sorrow
I see you can breathe inside
My brain is obsessed with sorrow
Catch me
It's killing me inside
My brain is obsessed with sorrow
My brain is obsessed with sorrow
Killing me inside
My brain is obsessed with sorrow
My brain is obsessed with sorrow
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
 
#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
 
using namespace std;

long long hp1,atk1,def1,hp2,atk2,def2,ch,ca,cd,ans,ttl,ps,rec,need;

int main(){
//freopen("average.in","r",stdin);
//freopen("average.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>hp1>>atk1>>def1;
cin>>hp2>>atk2>>def2;
cin>>ch>>ca>>cd;

ans=1e9;

for (int bat=0;bat<=1000;bat++)
 for (int bdef=0;bdef<=1000;bdef++)
 {
     ttl=bat*ca+bdef*cd;
     if (atk1+bat<=def2)continue;
     ps=hp2/(atk1+bat-def2);
     if (hp2%(atk1+bat-def2))++ps;
     rec=atk2-def1-bdef;
     if (rec<0)rec=0;
     need=1+ps*rec;
     if (need>hp1)
      ttl+=(need-hp1)*ch;
     ans=min(ans,ttl);
 }

cout<<ans<<endl;

cin.get();cin.get();
return 0;}