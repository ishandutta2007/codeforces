/* 
Decapitated head licking your cunt
Sucking all the blood from your stump
Intestinal guts taking their hold
Leaving you dead, stiff and cold

Controlling the minds of the bloodthristy dead
Unholy seizure slicing through your head
Who will survive only time will tell
Dripping from your mouth comes a rancid smell
Lobotomised corpse shredding your flesh
Leaving your body a bloody mess

Scream bloody gore
Scream bloody gore

Inject the reborn terror, the blood comes spurting out
Another to control, add it to your count
Orders to destroy, rip and tear apart
Wishing for the end, your dead is just the start

Controlling the minds of the bloodthristy dead
Unholy seizure slicing through your head
Who will survive only time will tell
Dripping from your mouth comes a rancid smell
Lobotomised corpse shredding your flesh
Leaving your body a bloody mess

Scream bloody gore
Scream bloody gore

Armies of the dead
Hail their leader's head
Hungry for the flesh
While it's warm and fresh

Through the smoke who will see
Who will come out alive?
Now it's your turn to feel the pain
Now it's your turn to die
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
#define eps 0.001
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 3
#define clone agsdahfaassdg
using namespace std;

long long n,q,ans;
vector<long long> v;

int main(){
//freopen("lifts.in","r",stdin);
//freopen("lifts.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
{cin>>q;
v.push_back(q);}
sort(v.begin(),v.end());
for (int i=0;i<n;i++)
ans+=abs(v[i]-(i+1));

cout<<ans<<endl;

cin.get();cin.get();
return 0;}