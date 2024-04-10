/*
l see you watching me
Very carefully
Is it your belief
Sibling rivalry
Getting in too deep
Quicksand at you feet
Can you stand the heat
Or cave in to defeat

l've seen it all before
A cycle evermore
The walls come crashing in
But l don't care
l don't care

Take it for what it is
Pain is one man''s bliss
A life of opposites
A matter of perception
Life is suffering
Think of the joy it brings
The sound is deafening
It's making my ears ring

Tell me to turn it down
I'll make it twice as loud
You say I have to stop
But l don't care
l don't care

You listen for the sound
Your ears to the ground
Your time will come 'round
Don't let it get you down
All things under the sun
Will return to one
And when our days are done
No where to turn and run

You say my ways ain't right
That l don't see the light
l see them every night
But l don't care
l don't care
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

int a,b,c,pdif;
double dp[105][105][105],ans1,ans2,ans3;

int main(){
//freopen("k.in","r",stdin);
//freopen("k.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>a>>b>>c;
dp[a][b][c]=1;
for (int i=a;i+1;--i)
 for (int j=b;j+1;--j)
  for (int q=c;q+1;--q)
  {
    if (dp[i][j][q]<1e-50)continue;
    pdif=i*j+j*q+i*q;
    if (i>0&&j>0)
     dp[i][j-1][q]+=1.0*i*j*dp[i][j][q]/pdif;
    if (j>0&&q>0)
     dp[i][j][q-1]+=1.0*j*q*dp[i][j][q]/pdif;
    if (i>0&&q>0)
     dp[i-1][j][q]+=1.0*i*q*dp[i][j][q]/pdif;
  }


for (int i=1;i<=100;i++)
{
    ans1+=dp[i][0][0];
    ans2+=dp[0][i][0];
    ans3+=dp[0][0][i];
}
cout.precision(12);
cout<<fixed<<ans1<<" "<<ans2<<" "<<ans3<<endl;


cin.get();cin.get();
return 0;}