/*
Coming onto you
The hell you got me through
What would I have to do to kiss that frown
I know whats wrong with you
That fucked up part of you
Is gonna bury me under ground

Now I'm awake
Been stuck in a place I really hate
And it's not fate
Everything's just fine

So why must it be
Chaos Lives in Everything
Trapped inside a dream
It all comes back to me

Get away from you
Is what I gotta do
I want my soul back, I'll stand my ground
So walk away from me
You know this has to be
Another way for me to kiss that frown

And it's not fate
Everything's just fine

So why must it be
Chaos Lives in Everything
Trapped inside a dream
It all comes back to me
Now I'm guilty, not ashamed
Got this thing attached to me, throw it all away
It just comes back to me

Gonna take you
Gonna break you
Gonna rape you, fuck you bitch, frown
Sometimes I worry
Sometimes I'm sorry
Sometimes I just want to beat you down
Gonna take you
Gonna break you
Gonna rape you, fuck you bitch, frown
Sometimes I worry
Sometimes I'm sorry
Sometimes I just want to kiss that frown

I'm insane but now you gotta give it up to me
Life is wearing thin
My only pleasure is watching you give in
I tried
To pretend
All it got me was nothing in the end
I tried
To win
All it got me was nothing in the end

So why must it be
Chaos Lives in Everything
Trapped inside a dream
It all comes back to me
Now I'm guilty, not ashamed
Got this thing attached to me, throw it all away
It just comes back to me
It just comes back to me
It just comes back to me
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
#define eps 1e-11
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
#define bsize 256
 
using namespace std;

long long n,t,dp[40][40][40][4];
long long answ;

int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>t;
for (int i=1;i<=4;i++)
 for (int j=i+1;j<=4;j++)
  dp[2][0][j][1]+=1;
  
for (int i=2;i<=n;i++)
 for (int done=0;done<=t;done++)
  for (int last=1;last<=4;last++)
   for (int nw=1;nw<=4;nw++)
   {
    if (last==nw)continue;
    if (nw<last){dp[i+1][done+1][nw][0]+=dp[i][done][last][1];
    dp[i+1][done][nw][0]+=dp[i][done][last][0];}
    else
    {
     dp[i+1][done][nw][1]+=dp[i][done][last][0]+dp[i][done][last][1];
    }
   }
answ=0;
for (int i=1;i<=4;i++)
 answ=answ+dp[n][t][i][0];//+dp[n][t][i][1];
cout<<answ<<endl;
   
cin.get();cin.get();
return 0;}