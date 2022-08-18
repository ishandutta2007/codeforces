/*
Legions mass upon this place
For another night of violent abuse
Maniacs in leather and black
Ready and willing for the attack
Metal mayhem running free
Now all around is breaking loose
Fists are flying, pulses race
The circle will destroy this place

Feel adrenaline rush
Jump into the pit
Kicking as you push
Braced for the hit
Bow down to the thrasher

Blood on the stage, a thousand rage
A thrasher's soul on fire
Chaos spreads across the floor
Bang your head, make it sore
Metal madness engulfs the stage
In the pit you come of age
Let battle commence, no space for the weak
The thrasher's dreams are now complete

Feel adrenaline rush
Jump into the pit
Kicking as you push
Braced for the hit
Bow down to the thrasher
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
#define eps 1e-7
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

long n,ans,ar[200000],q;

int main(){
//freopen("gift.in","r",stdin);
//freopen("gift.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
cin>>ar[i];
ans=1;
if (n>1)ans=2;
q=2;
for (int i=3;i<=n;i++)
{
    if (ar[i]==ar[i-1]+ar[i-2]){
                                q++;
                                }
    else q=2;
    ans=max(ans,q);
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}