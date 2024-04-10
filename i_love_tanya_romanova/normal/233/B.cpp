/*
When passion's lost and all the trust is gone
Way too far for way too long
Children crying, cast out and neglected
Only in a world so cold, only in a world this cold

Hold the hand of your best friend, look into their eyes
Then watch them drift away
Some might say, We've done the wrong things
For way too long, for way too long

Fever inside the storm, so I'm turning away
Away from the game, away from the storm
It's like through mending the worlds of us
Keep your thorn 'cuz I'm running away
Away from the games, away from the space
The circumstances of a world so cold

Burning whispers remind me of the days
I was left alone in a world this cold
Guilty of the same things reveled by the cause
I've left alone in a world so cold

Fever inside the storm, so I'm turning away
Away from the game, away from the storm
It's like through mending the worlds of us
Keep your thorn 'cuz I'm running away
Away from the games, away from the space
The circumstances of a world so cold

I'm flying, I'm flying away
Away from the games, away from the flames
The circumstances of a world so cold

Why does everyone feel like my enemy?
Don't want any part of depressional darkness
I've had enough, sick and tired
Bring the sun or I'm gone, or I'm gone

I'm packing out, I'm no more no motherfuckin' shit
Never lied, never loved, never lived, never lost
Never hurt, never worried about being afraid of anyone else
Not a care, no concern, don't give a shit about anything

I'm packing out, I'm no more no motherfuckin' shit
Never lied, never loved, never lived, never lost
Never hurt, never worried about being afraid of anyone else
Not a care, no concern, don't give a shit about anything

I need to find a darkened corner, a blackless corner
Where it's safer and calmer, I'm drowning away
Away from the game away from flame
'Cause I feel mending the worlds of us, I'm running away
Away from the game away from this space
Of circumstances of a world so cold, I'm flying, I'm flying away
Away from the game, away from the game
Of circumstances of a world so cold
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

long long n,d,v1,temp;
set<long long> ans;
set<long long>:: iterator it;

long long gett(long long x)
{
 long long r=0;
 while (x){r+=x%10;x/=10;}
 return r;
}

int main(){
//freopen("magic.in","r",stdin);
//freopen("magic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int sum=0;sum<=200;sum++)
{
 d=sum*sum+4*n;
 if (d<0)continue;
 temp=sqrt(d+0.5);
 if (temp*temp!=d)continue;
 v1=-sum+temp;
 if (v1%2)continue;
 v1/=2;
 if (gett(v1)==sum)ans.insert(v1);
}

if (ans.size()==0)cout<<-1<<endl;
else
{
    it=ans.begin();
    cout<<(*it)<<endl;
}
cin.get();cin.get();
return 0;}