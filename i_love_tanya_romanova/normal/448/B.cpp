/*
Ascending from the enemy abyss
Ending decadent diabolic bliss
Into a pit of horror it arrives
Fear becomes the flame upon the ice
Ghosts under the violent sun of death
Lives are cured of greed and emptiness
Berserkers start a blood-chain of attacks
Against religion and all nations' flags
A phantom scouring across the land
Leaving trails of blood and sand
End this torture and misery
For souls awake enough to see
Far beyond the lies
Phantom Antichrist
Phantom Antichrist
Artisans of someone else's faith
The free became the hopelessly enslaved
The inheritance of a darkened world
For a kingdom lost under the sword
The brave may fall but they never yield
Wake the conquerors from the righteous sleep
From the ashes of this plundered paradise
A king is born, a phantom Antichrist
A phantom scouring across the land
Leaving trails of blood and sand
End this torture and misery
For souls are awake enough to see
Far beyond the lies
Phantom Antichrist
Phantom Antichrist
Terror will prevail
Terror from the left
Terror from the right
Depression is the root to our dreams suicide
Behold the god of gods overthrow it all
Extinction of this inhumane mind contagion
Fulfilling all the vows from human history
Democide, genocide war atrocities
The shadows of his wings absorbing every glint
Every earthly color turning into black
A saviour scouring across the land
A new beginning that has no end
An open mind a forceful will
Numbs the lurking fear that killed
The soul of love and life
Phantom Antichrist
Phantom Antichrist
Phantom Antichrist
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
//#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-14
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
//#define N 120000

using namespace std;

string st1,st2;
long calc[2000],er,ps;

int main(){
//freopen("pattern.in","r",stdin);
//freopen("pattern.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>st1;
cin>>st2;
for (int i=0;i<st1.size();i++)
 calc[st1[i]]++;
for (int i=0;i<st2.size();i++)
 calc[st2[i]]--;

er=0;
for (int i='a';i<='z';i++)
if (calc[i])er=1;
if (er==0){cout<<"array"<<endl;return 0;}

long ps=0;
for (int i=0;i<st1.size();i++)
{
    if (ps<st2.size()&&st1[i]==st2[ps])++ps;
}
if (ps==st2.size()){cout<<"automaton"<<endl;return 0;}

er=0;
for (int i='a';i<='z';i++)
 if (calc[i]<0)er=1;
if(er==0){cout<<"both"<<endl;return 0;}
cout<<"need tree"<<endl;
cin.get();cin.get();
return 0;}