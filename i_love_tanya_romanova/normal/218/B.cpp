/*
Auschwitz, the meaning of pain
The way that I want you to die
Slow death, immense decay
Showers that cleanse you of your life
Forced in
Like cattle
You run
Stripped of
Your life's worth
Human mice, for the Angel of Death
Four hundred thousand more to die
Angel of Death
Monarch to the kingdom of the dead
Sadistic, surgeon of demise
Sadist of the noblest blood

Destroying, without mercy
To benefit the Aryan race

Surgery, with no anesthesia
Feel the knife pierce you intensely
Inferior, no use to mankind
Strapped down screaming out to die
Angel of Death
Monarch to the kingdom of the dead
Infamous butcher,
Angel of Death

Pumped with fluid, inside your brain
Pressure in your skull begins pushing through your eyes
Burning flesh, drips away
Test of heat burns your skin, your mind starts to boil
Frigid cold, cracks your limbs
How long can you last
In this frozen water burial?
Sewn together, joining heads
Just a matter of time
'Til you rip yourselves apart
Millions laid out in their
Crowded tombs
Sickening ways to achieve
The holocaust
Seas of blood, bury life
Smell your death as it burns
Deep inside of you
Abacinate, eyes that bleed
Praying for the end of
Your wide awake nightmare
Wings of pain, reach out for you
His face of death staring down,
Your blood running cold
Injecting cells, dying eyes
Feeding on the screams of
The mutants he's creating
Pathetic harmless victims
Left to die
Rancid Angel of Death
Flying free

Angel of Death
Monarch to the kingdom of the dead
Infamous butcher,
Angel of Death

Angel of Death
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
 
#define  INF 100000000
#define eps 1e-11
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60

using namespace std;

vector<long> v,v1;
long q,a,b,ans1,n,m,ans2;

int main(){
//freopen("distance5.in","r",stdin);
//freopen("distance5.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
for (int i=1;i<=m;i++)
{
    cin>>q;v.push_back(q);
}
v1=v;

ans1=ans2=0;
for (int i=0;i<n;i++)
{
    sort(v.begin(),v.end());
    ans1+=v[0];
    v[0]--;
    if (v[0]==0)v.erase(v.begin());
    
    
}
v=v1;
for (int i=0;i<n;i++)
{
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    ans2+=v[0];
    v[0]--;
    if (v[0]==0)v.erase(v.begin());
    
    
}
cout<<ans2<<" "<<ans1<<endl;

cin.get();cin.get();
return 0;}