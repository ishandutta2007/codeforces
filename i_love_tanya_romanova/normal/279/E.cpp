/*  
Talk is cheep,
I can't afford the, price of wasted time...
Who will reap the profit of the lie?

Fantasy,
Illusion fusion impressions of a high...
Sacred is the being of the lie.

Drawn is a picture of myself,
It's all that I see, leaving!
Gone are the cries I heard for help,
The mirror spits,
Reflections of a lie.

Are you waiting for a chance?
Won't happen standing in the rain.

Damage done,
The truth is drowning in a sea of hate...
Wet, they wear the fiction like a badge over their hearts.

Drawn is a picture of myself,
It's all that I feel bleeding!
Gone are the cries I made for help,
The mirror spits,
Reflections of a lie.

Feed my head! I'm hungry for a lie.

Be sure and teach your children well,
To use it pure and slow.
Be sure they teach their children,
Be sure the children's children.

Slight of hand, slight of word.
Slight to beleive, the absurd.
Feed my head I'm hungry.
I'm hungry for a lie.

Drawn is a picture of myself,
It's all that I see greiving!
Gone are the cries I made for help,
The mirror spits,
Reflections of a lie.

Feed my head of a lie!
Feed my head reflections of a lie.
Feed my head. Feed my
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
#define clone agsdahfaassdg
using namespace std;

string st;

long dp[2000000];

int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>st;
dp[1]=1;
//all0-all1

for (int i=0;i<st.size();i++)
{
    if (st[i]=='0'){dp[1]=min(dp[0]+1,dp[1]+1);}
    if (st[i]=='1'){dp[0]=min(dp[1]+1,dp[0]+1);}
}
cout<<dp[0]<<endl;

cin.get();cin.get();
return 0;}