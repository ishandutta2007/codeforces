/*
Blind-folded and gagged, stood waiting
With the whole world: my firing squad
At the edge of the world I'm faced out
Staring the sun right in the eye

Vultures circle above, hyenas mocking the kill
Excrement drooling down their chins
Atop the cliffs I look down, into the starving Hell-mouth
The rabid foam crashes hard on its teeth

Their mouth's salivate
Fantasizing my gruesome ending
This world looks down upon
A man who can stand on his own two feet

As they're feeding their guns: "Ready, aim"
They say I'll live, if I die for their cause
Living under the rule of fellow Cro-Magnon fool
They fear who leads and will kill to stay still

Their mouth's salivate
Fantasizing my gruesome ending
This world looks down upon
A man who can stand on his own two feet
Without eating from their claws

Life feels quite like Hell should
But this Hells so cold
Pull another knife out
Stick it with rest of them
When my back is full
Turn me around to face it

Life feels quite like Hell should
But this Hells so cold
Pull another knife out
Stick it with rest of them
When my back is full
Turn me around to face it

Such melancholy, burning the stars from skies
As we melt, drowning inside their bloodied eyes
Hope is ravaged, running from lacerations
Sob so heavily, we choke, then we die

Die

Life feels quite like Hell should
But this Hells so cold
Pull another knife out
Stick it with rest of them
When my back is full
Turn me around to face it [4x]

Go

Sob so heavily, we choke, then we die
*/

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define INF 1000000000
#define eps 1e-9
//#define M_PI 3.141592653589793
#define mx 1000000000000ll
#define bs 1000000007
using namespace std;
long long aabs(long long a)
{if (a<0)return -a; else return a;
 }
long long a,b,x1,x2,y1,y2,s1,s2,ans;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>a>>b;

cin>>x1>>y1>>x2>>y2;

s1=(x1+y1+2000000000ll*2*a)/(2*a);
s2=(y2+x2+2000000000ll*2*a)/(2*a);
ans=aabs(s1-s2);
//cout<<s1<<" "<<s2<<endl;
s1=(x1-y1+2000000000ll*2*b)/(2*b);
s2=(x2-y2+2000000000ll*2*b)/(2*b);
ans=max(ans,aabs(s1-s2));

//cout<<s1<<" "<<s2<<endl;
cout<<ans<<endl;
cin.get();cin.get();
return 0;}