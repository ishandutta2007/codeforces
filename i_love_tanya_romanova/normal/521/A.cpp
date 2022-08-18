/*
Blackened is the end
Winter it will send
Throwing all you see
Into obscurity

Death of mother earth
Never a rebirth
Evolution's end
Never will it mend, never

Fire to begin whipping dance of the dead
Blackened is the end
To begin whipping dance of the dead
Color our world blackened

Blistering of earth
Terminate, it's worth
Deadly nicotine
Kills what might have been

Callous frigid chill
Nothing left to kill
Never seen before
Breathing nevermore, never

Fire to begin whipping dance of the dead
Blackened is the end
To begin whipping dance of the dead
Color our world blackened, blackened

Opposition
(Opposition)
Contradiction
(Contradiction)
Premonition
(Premonition)

Compromise agitation
(Agitation)
Violation
(Violation)
Mutilation
(Mutilation)

Planet dies
Darkest color
Blistered earth
True death of life

Termination
(Termination)
Expiration
(Expiration)
Cancellation
(Cancellation)

Human race expectation
(Expectation)
Liberation
(Liberation)
Population
(Population)

Lay to waste
See our mother
Put to death
See our mother die

Smoldering decay
Take your breath away
Millions of our years
In minutes disappears

Darkening in vain
Decadence remains
All is said and done
Never is the sun, never

Fire to begin whipping dance of the dead
Blackened is the end
To begin whipping dance of the dead

Fire is the outcome of hypocrisy
Darkest potency
In the exit of humanity
Color our world blackened, blackened
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

string st;
long long cnt[1<<20],n,an,mx,ways;
long long ans;

int main(){
//freopen("evacuation.in","r",stdin);
//freopen("evacuation.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
cin>>st;
for (int i=0;i<st.size();i++)
 cnt[st[i]-'A']++;

ans=1;
for (int i=0;i<26;i++)
 if (cnt[i]>mx)
  mx=cnt[i];

ways=0;
for (int i=0;i<26;i++)
 if (cnt[i]==mx)
  ++ways;

for (int i=1;i<=st.size();i++)
 ans=(ans*ways)%bs;
cout<<ans<<endl;

cin.get();cin.get();
return 0;}