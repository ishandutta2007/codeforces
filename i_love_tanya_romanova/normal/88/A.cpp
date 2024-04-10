/*
Guilty as charged but damn it, it ain't right
There's someone else controlling me
Death in the air, strapped in the electric chair
This can't be happening to me

Who made you God to say
I'll take your life from you?

Flash before my eyes
Now, it's time to die
Burning in my brain
I can feel the flame

Wait for the sign to flick the switch of death
It's the beginning of the end
Sweat, chilling cold as I watch death unfold
Consciousness, my only friend

My fingers grip with fear
What am I doing here?

Flash before my eyes
Now, it's time to die
Burning in my brain
I can feel the flame

Someone help me
Oh please, God help me
They are trying to take it all away
I don't want to die

Someone help me
Oh please, God help me
They are trying to take it all away
I don't want to die

Time moving slow, the minutes seem like hours
The final curtain call I see
How true is this? Just get it over with
If this is true, just let it be

Wakened by horrid scream
Freed from this frightening dream

Flash before my eyes
Now, it's time to die
Burning in my brain
I can feel the flame
*/

//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <memory.h>
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
 
#define  INF 100000000
#define eps 1e-6
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60

using namespace std;

string st1,st2,st3;
string zr[100];
long usd[100];

int main(){
//freopen("wedding.in","r",stdin);
//freopen("wedding.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

zr[0]="C";
zr[1]="C#";
zr[2]="D";
zr[3]="D#";
zr[4]="E";
zr[5]="F";
zr[6]="F#";
zr[7]="G";zr[8]="G#";
zr[9]="A";zr[10]="B";
zr[11]="H";
cin>>st1>>st2>>st3;
for (int i=0;i<12;i++)
if (zr[i]==st1||zr[i]==st2||zr[i]==st3)usd[i]=usd[i+12]=1;

for (int i=0;i<20;i++)
if (usd[i]==1&&usd[i+4]==1&&usd[i+7]==1){cout<<"major"<<endl;return 0;}

for (int i=0;i<20;i++)
if (usd[i]==1&&usd[i+3]==1&&usd[i+7]==1){cout<<"minor"<<endl;return 0;}

cout<<"strange"<<endl;
cin.get();cin.get();
return 0;}