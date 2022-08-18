/*
In the bowels of rocky mountain
A fiery bird I forged
Forged from iron, from molten steel
A flaming eagle, majestic beast

On the wings of my eagle
To black river I flew
To the dale of the dead
To the stream that grinds all flesh

The eagle soared sky high
Touched the vault of heaven
The sky sparkled, cracked and creaked

The eagle soared sky high
Soared my flaming griffin
The thunder crashed and rolled
Rolled the monster's head

I found a monster, a black giant pike
From its jaws my eagle saved me
Dragged the fish under the sun
Split its belly, ripped the head off

I rolled the pike's head to the house of the north
I threw the bony skull at the haughty queen
Here's a throne for you to rest your frozen bones
I have done my share, now keep your promise

I had made the heavens, forged out a miracle
The snake infested field of death turned over
Slayed the wolf of shadow lands

Shackled the bear of death
I captured the impossible
The pike from the black river
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
#define M_PI 3.141592653589793
#define bs 1000000000
#define bsize 512
#define MAG 40

using namespace std;

int n,ar[1<<20];
int er;

int main(){
//freopen("center.in","r",stdin);
//freopen("center.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>ar[i];
    while (ar[i]%2==0)
        ar[i]/=2;
    while (ar[i]%3==0)
        ar[i]/=3;
}

for (int i=2;i<=n;i++)
    if (ar[i]!=ar[1])
        er=1;

if (er)
    cout<<"No"<<endl;
else
    cout<<"Yes"<<endl;
    
//cin.get();cin.get();
return 0;}