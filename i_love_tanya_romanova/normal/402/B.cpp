/*
Master of creation
This manipulation
Means manifestation now...
Fatal termination
Divine intervention
End the sufferation now...
Build up tension
Deterioration
Killing operation now...
Karma to burn
Becoming undone
Injustice is done now...

Kill... Survive... Survive to kill
Breath and breath - The air smells diseased
Trenches and trenches - The middle passage ending
Bleed in... Bleed out... No one will get out

Five to one - One to five - No one gets out alive
Master of creation - No more chains - Oppression
Slave state - Slave hate - Feel this day of hate
Five to one - One to five - No one gets out alive

Break the chains and break away
Break the hate and run away
Break the chains and face the day
Make a way, a new dawn fades
Stolen away, a new dawn fades
Stolen away, empty decay
They fade away in the slave trade
Lord of hate, lord of fate
I resist - Desecrate

Military dominance
Communication ends
Ordinary intolerance
Chaos and insolence
Ominous apparition
Evil manifestation
Malicious operation
Corruption and tension

Slavery is misery
Inflicting heresy
Wounds are open endlessly
Hatred, animosity
Torture masks and bleeding backs
Whipping cracks and faceless deaths
We'll rise and we'll defy it
And send their masters to the fire...

Destroy the chains - These are the chains of hate
Destroy the chains - We cannot tolerate
Destroy the chains - Where we were created
Destroy the chains - The evil of man-made
Destroy the chains...

The chains...
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
#define eps 1e-13
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
#define MAXN 10000
//#define SIZE 60
#define bsize 256

using namespace std;

long n,k,bst,bp,need,ar[20000];

int main(){
//freopen("cyclic.in","r",stdin);
//freopen("cyclic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>k;
bst=1e9;
bp=0;

for (int i=1;i<=n;i++)
cin>>ar[i];

for (int start=1;start<=1000;start++)
{
 need=0;
 
 for (int i=1;i<=n;i++)
 if (ar[i]!=(i-1)*k+start)++need;
 
 if (need<bst)
 {
  bst=need;
  bp=start;
 }
}

cout<<bst<<endl;
for (int i=1;i<=n;i++)
{
 if (ar[i]==bp+(i-1)*k)continue;
 if (ar[i]<bp+(i-1)*k)
 cout<<"+ "<<i<<" "<<bp+(i-1)*k-ar[i]<<endl;
 else cout<<"- "<<i<<" "<<ar[i]-bp-(i-1)*k<<endl;
}

cin.get();cin.get();
return 0;}