/*
Hear the sound of a machinegun
Hear it echo in the night
Mortars firing rains the scene
Scars the fields
that once were green

It's a stalemate at the frontline
where the soldiers rest in mud
roads and houses
all is gone
there is no glory to be won

know that many men will suffer
know that many men will die
half a million lives at stake
Ask the fields of Passchendaele

And as the night falls the general calls
and the battle carries on and on
What is the purpose of it all
What's the price of a mile?

Thousands of feet march to the beat
It's an army on the march
Long way from home
Paying the price in young men's lives
Thousands of feet march to the beat
It's an army in despair
Knee-deep in mud
Stuck in the trench with no way out

Thousands of machineguns
Kept on firing through the night
Mortars blazed and wrecked the scene
Guns in the fields that once were green

Still a deadlock at the frontline
Where the soldiers die in mud
roads and houses since long gone
still no glory has been won
know that many men has suffered
know that many men has died

Six miles of ground has been won
Half a million men are gone
And as the men crawled the general called
And the killing carried on and on
What's the purpose of it all?
What's the price of a mile?

Thousands of feet march to the beat
It's an army on the march
Long way from home
Paying the price in young men's lives
Thousands of feet march to the beat
It's an army in despair
Knee-deep in mud
Stuck in the trench with no way out

Young men are dying
They pay the price
Oh how they suffer
So tell me what's the price of a mile

That's the price of a mile.

Thousands of feet march to the beat
It's an army on the march
Long way from home
Paying the price in young men's lives
Thousands of feet march to the beat
It's an army in despair
Knee-deep in mud
Stuck in the trench with no way out
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

#define  INF 100000000
#define eps 1e-11
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
#define bsize 256

using namespace std;

long n,t,q;


int main(){
//freopen("melman.in","r",stdin);
//freopen("melman.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>n;
if (n<3){cout<<-1<<endl;return 0;}
if (n==3){cout<<210<<endl;return 0;}

t=1;
for (int i=2;i<=n;i++)
{
 t=t*10;
 t%=210;
}

if (t==0)q=0;else q=210-t;
cout<<1;
for (int i=2;i<n-2;i++)
cout<<0;
cout<<q/100;
q%=100;
cout<<q/10;
cout<<q%10;
cout<<endl;

cin.get();cin.get();
return 0;}