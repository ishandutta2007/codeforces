/*
Somebody's shouting
Up at a mountain
Only my own words return
Nobody's up there
It's a deception
When will I ever learn?

[CHORUS:]
I'm alone here
With emptiness eagles and snow
Unfriendliness chilling my body
And whispering pictures of home

Wondering blindly
How can they find me
Maybe they don't even know
My body is shaking
Anticipating
The call of the black footed crow...

[Chorus]

Here in this prison
Of my own making
Year after day I have grown
Into a hero
But there's no worship
Where have they hidden my thrown...

[Chorus]
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
#include <memory.h>

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
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 4
#define clone agsdahfaassdg

using namespace std;
string st;
long calc[1000];
long d;

int main(){
//freopen("bridges.in","r",stdin);
//freopen("bridges.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>st;

for (int i=0;i<st.size();i++)
{
 calc[st[i]]++;    
}

for (int i='a';i<='z';i++)
if (calc[i]&1)++d;

if (d<2)cout<<"First"<<endl;
else if (d%2)cout<<"First"<<endl;
else cout<<"Second"<<endl;
cin.get();cin.get();
return 0;}