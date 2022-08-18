/*
All the white lights falling

The blue lights are falling
Night is warm
Came down with a promise
I have my best shirt on
I lower myself now
It is a way to forgot
Of last year's failure

Will the streetlights reflect me well enough
Am I transparent when I am clean
Will the darkness around me be so strong
That there is no way I can be seen

Boys will we become
Heroes of this night
Or am I just happy
Whenever not sober
I cleaned myself well
Clean today

Will the streetlights reflect me well enough
Am I transparent when I am clean
Will the darkness around me be so strong
That there is no way I can be seen

And when I pause for a breath
I see millions like me

Will the streetlights reflect me well enough
Am I transparent when I am clean
Will the darkness around me be so strong
That there is no way I can be seen
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

#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
//#define N 120000

using namespace std;

long pref[1600000];
long full,temp,n;
long res;

int main(){
//freopen("trading.in","r",stdin);
//freopen("trading.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

pref[0]=0;
for (int i=1;i<=1300000;i++)
 pref[i]=pref[i-1],pref[i]^=i;

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>temp;
 full=n/i;
 if (full%2)temp^=pref[i-1];else temp^=0;
 temp^=pref[n%i];
 res^=temp;
}
cout<<res<<endl;

cin.get();cin.get();
return 0;}