/*
Dead as dead can be
The doctor tells me
But I just can't believe him
Ever the optimistic one
I'm sure of your ability
To become my perfect enemy

Wake up and face me
Don't play dead 'cause maybe
Someday, I'll walk away and say
You disappoint me
Maybe you're better off this way

Leanin' over you here
Cold and catatonic
I catch a brief reflection
Of what you could and might have been
It's your right and your ability
To become my perfect enemy

Wake up and face me
(Why can't you?)
(Come on now)
Don't play dead 'cause maybe
(Don't play dead)
('Cause maybe)
Someday I'll walk away and say
(Someday I'll)
You disappoint me
Maybe you're better off this way

Maybe you're better off this way
Maybe you're better off this way
Maybe you're better off this way
You're better off this
You're better off this
Maybe you're better off

Wake up and face me
(Why can't you?)
(Come on now)
Don't play dead 'cause maybe
(Don't play dead)
('Cause maybe)
Someday I'll walk away and say
(Someday I'll)
You fuckin' disappoint me
Maybe you're better off this way

Go ahead and play dead
(Go)
I know that you can hear this
(Go)
Go ahead and play dead
(Go)
Why can't you turn and face me?
(Why?)
Why can't you turn and face me?
(Why?)
Why can't you turn and face me?
(Why?)
Why can't you turn and face me?
(Go)
You fuckin' disappoint me

Passive, aggressive bullshit
Passive, aggressive bullshit
Passive, aggressive bullshit
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

using namespace std;

long n,m;
char c;
long hi[600000][3],hj[600000][3],ans;
long temp;
long l,u;

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
 for (int j=1;j<=m;j++)
 {
     cin>>c;
     if (c=='.')continue;
     temp=c-48;
     if (temp<3)l=1;else l=0;
     if (l%2==j%2)
     hi[i][1]=1;
     else hi[i][0]=1;
     if (temp==1||temp==4)u=1;else u=0;
     if (u%2==i%2)
     hj[j][1]=1;else hj[j][0]=1;
 }

ans=1;
for (int i=1;i<=n;i++)
{
 temp=2;
 temp-=hi[i][0]+hi[i][1];
 ans=ans*temp%1000003;
}

for (int i=1;i<=m;i++)
{
 temp=2;
 temp-=hj[i][0]+hj[i][1];
 ans=ans*temp%1000003;
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}