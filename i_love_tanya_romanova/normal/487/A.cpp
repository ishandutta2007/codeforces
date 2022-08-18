/*
I watched the sunset
From the east side of the river
When I was alive and I could feel its water
Out of the late evening sky
I pull to this place
Where I could remember
The river's deep brown bleeding eyes

It pulled me in by the ankles
My senses all have left
Then I heard you calling my name
As it asked me to come

Come down to the water baby
Bring all of your lies
Come down and bring everything
That you've got to disguise

I missed the sunrise
In the stillness of the morning
Submerged by the one who
Kept me to these shores
I call to the brightest of angles
To save me from this scene
But he can't reach me in time to save me
The water pulls beneath

Come down to the water baby
Bring all of your lies
Come down and bring everything
That you got to disguise
Come down to the water baby
Bring what you believe
Just be sure you know that this
Is where you cease to be
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