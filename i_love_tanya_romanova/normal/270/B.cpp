/*
Religion changed the face of man, thou shalt not kill, we all are gone
The seed of ignorance is born thou shalt not think, thou shalt conform

The pigs order us to follow orders and obey
The flies drink the decaying nectar of their tortured effigy

Cling to wasted beliefs and visions and bathe in apathy again
No solution, the retribution of spiritual sickness begins

The legacy of suffering is through, the guilt we bear shall not tear us in two

Born we are the same, within the silence, indifference be Thy name
Torn we walk alone, we sleep in silent shades
The grandeur fades, the meaning never known

If nothing in the world can change our children will inherit nothing

Born we are the same, within the silence, indifference be Thy name
Torn we walk alone, we sleep in silent shades
The grandeur fades, the meaning never known

The pigs call for pure submission and fall into the fray
The lonely hunter beats his shallow drum, the soundtrack of world disarray

Cling to wasted beliefs and visions and bathe in apathy again
No solution, the retribution of spiritual sickness begins

Born we are the same, within the silence, indifference be Thy name
Torn we walk alone, we sleep in silent shades
The grandeur fades, the meaning never known

If nothing in the world can change our children will inherit nothing
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
//#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-8
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000009

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

long n,mn,ar[200000],ans;
long temp;

int main(){
//freopen("test.in","r",stdin);
//freopen("test.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
cin>>ar[i];
temp=1;
for (int i=1;i<n;i++)
{
    if (ar[i]>ar[i+1]){ans+=temp;temp=1;}
    else ++temp;
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}