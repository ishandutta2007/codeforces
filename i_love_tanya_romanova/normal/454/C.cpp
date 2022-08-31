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

long n,m;

double ans,dp[200000];
double prob;

double pw(double a,long b)
{
 if (b==0)return 1;
 if (b%2)return a*pw(a,b-1);
 return pw(a*a,b/2);
}

int main(){
//freopen("rush.in","r",stdin);
//freopen("rush.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>m>>n;

for (int mx=1;mx<=m;mx++)
{
 prob=1;
 prob=pw(mx*1.0/m,n);
 dp[mx]=prob;
}

for (int i=1;i<=m;i++)
 ans+=i*(dp[i]-dp[i-1]);
cout.precision(12);
cout<<fixed<<ans<<endl;

cin.get();cin.get();
return 0;}