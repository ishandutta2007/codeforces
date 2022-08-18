/*
Anesthetized sleep
Just conscious of life
Collapsing around
Us in grainy pieces

A rare alchemy of sea and stars explode
It mesmerises me
What we have known of pleasure was nothing
The frenzied passion, it strangles, suffocates
But the space intrudes, malign and ruthless

A hundred years explodes in that half moment
Stepping outside the temporal load time unstuck
For this is the peak the moment time slows down
Where gravity disappears from the vacuum

Blood rushing through ushering the rays of chaos
Everything becomes non linear, an endless space
As shivers creep down my spine all else in waves
In the conscious hour the hour of none

I feel it tighten round my throat
As i strangle out whats left
poisonous veins bulge the residue of pleasure
My skin it crawls with the primeval rush

Its strangle how the mind can twist
Wave upon demented wave just like a pulse
Poisonous veins bulge with the residue of pleasure
My skin it crawls with the primeval rush...

Wave upon demented wave just like a pulse
To one vast chord of wound
That already clots and stales
In the darkest hour the hour of none
The conscious hour the hour of none
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

using namespace std;

long ans;
string st1,st2;
long dist;
long n;

int main(){
//freopen("k.in","r",stdin);
//freopen("k.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
cin>>st1;
cin>>st2;
for (int i=0;i<n;i++)
{
    dist=st1[i]-st2[i];
    dist=abs(dist);
    dist=min(dist,10-dist);
    ans+=dist;
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}