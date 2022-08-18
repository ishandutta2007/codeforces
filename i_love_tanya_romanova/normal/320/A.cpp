/*
Oh say can you fucking see
The missiles fall like rain
Bloody mountains majesty
Dead bodies on the plain
By the bombing's eerie light
See the crimsons waves of red
What so proudly they all fell
The twilight of the dead

[Chorus:]
America - the violent
The indifferent
God shit is grace on me
America - the arrogant
The belligerent
Will live in infamy
We the people, for no people
Secure the blessings of tragedy
Do or dain we have enstablished
The scar spangled banner

We pledge allegiance to no god
Only to the blood
Liberty is just a dream
When dying in the mud
This, the land of the deceived, home of the depraved
Bombs, they drop like falling leaves
And the deadly flag still waves

[Repeat Chorus]

Red - the beautiful color of blood
Flowing like a stream
White - the color of bleaching bone
Lovely and obscene
Blue - the bruising color of flesh
Battered, ripped and torn
The colors of the flag of hate
Of violence and porn
What you see is what you get
You haven't see the bloody trail yet
I'm no patriot, just a hate-triot

Blood sport, my sure bet
See the flag, get a body bag
Salvation form a .44 mag.
Nothing left, no one saved
Cause our goddamn motherfucking bloody ass
Banner still waves
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
#define eps 1e-9
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

using namespace std;

string st;
set<string> s;
void dfs(string t)
{
     s.insert(t);
     if (t.size()>10)return;
     dfs(t+"14");
     dfs(t+"144");
     dfs(t+"1");
}
int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>st;
dfs("");
if (s.find(st)!=s.end())cout<<"YES"<<endl;
else cout<<"NO"<<endl;

cin.get();cin.get();
return 0;}