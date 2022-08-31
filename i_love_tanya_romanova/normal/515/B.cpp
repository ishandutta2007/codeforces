/*
What's coming through is alive.
What's holding up is a mirror.
But what's singing songs is a snake
Looking to turn my piss to wine.

They're both totally void of hate,
But killing me just the same.

The snake behind me hisses
What my damage could have been.
My blood before me begs me
Open up my heart again.

And I feel this coming over like a storm again.
Considerately.

Venomous voice, tempts me,
Drains me, bleeds me,
Leaves me cracked and empty.
Drags me down like some sweet gravity.

The snake behind me hisses
What my damage could have been.
My blood before me begs me
Open up my heart again.

And I feel this coming over like a storm again now.
And I feel this coming over like a storm again now.

I am too connected to you
To slip away, fade away.
Days away I still feel you
Touching me, changing me,

Considerately killing me.
Considerately killing me.
Considerately killing me.
Considerately killing me.
Without the skin here,
Beneath the storm.
Under these tears now,
The walls came down.

And as the snake is drowned
And as I look in his eyes,
My fear begins to fade
Recalling all of those times.

I could have cried then.
I should have cried then.

And as the walls come down
And as I look in your eyes
My fear begins to fade
Recalling all of the times
I have died
and will die.
It's all right.
(I don't mind)
I don't mind.
I don't mind.
I don't mind.

I am too connected to you
To slip away, fade away.
Days away I still feel you
Touching me, changing me,

Considerately killing me.
Considerately killing me and
Considerately killing me.
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

long n,m,q,temp,x,have[1<<20];

long gcd(long a,long b)
{
 while (a&&b)a>b?a%=b:b%=a;
 return a+b;
}

int main(){
//freopen("hiking.in","r",stdin);
//freopen("hiking.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
q=gcd(n,m);
cin>>temp;
for (;temp;--temp)
{
 cin>>x;
 have[x%q]=1;   
}
cin>>temp;
for (;temp;--temp)
{
 cin>>x;
 have[x%q]=1;
}
long cnt=0;
for (int i=0;i<q;i++)
{
 cnt+=have[i];
}
if (cnt==q)
 cout<<"Yes"<<endl;
else
 cout<<"No"<<endl;
 
cin.get();cin.get();
return 0;}