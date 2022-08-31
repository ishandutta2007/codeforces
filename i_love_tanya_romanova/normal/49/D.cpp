/*  
Slowly crossing as the river runs below
Never stopping for whats waiting soon will slow
And this last time looking back I'll see
My home for he awaits me reaching for my
soul. He calls my name,and waves me on
The fallen one he stands in flame

Well the life that he has given full of riches
And success has a price that I made good in
Blood to pay. And the light he now is showing
To guide my every footstep is insurance if
I falter on my way. And what God has now
Forsaken and man has never seen are the
Riches of the underworld below all my
Years of earthly pleasures gave support
Unto the briges I now cross it giving
Him my soul

Dark Lord, I summon thee demanging the
Sucred right to burn in hell, ride up to hells
hot wind. Face one more evilthan thou,take
My lustful soul,
Drink my blood as I drink yours, impale me on
the horns of death
Cut off my head release all my evel Lucifer is king
Praise Satan

I know the one who waits satan is
His name,is across the bridge of
Death there he stands in flame
I know the one who waits satan is
His name,is across the bridge of
Death there he stands in flame.

He is my provider as I walk into the
Void for eternity I give to him my soul
I shall do his bidding obey him
Without question even walk among the living if
I'm told

Satan don't forsake me I wait for
You take me grant me wings and as
You messenger I'll fly.
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
#define eps 1e-15
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000000
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
long dp[2000][3];

int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

long n;
cin>>n;
cin>>st;

for (int i=0;i<=st.size();i++)
dp[i][0]=dp[i][1]=1000000;
dp[0][0]=dp[0][1]=0;

for (int i=0;i<st.size();i++)
{
 if (i+1<st.size()&&st[i]==st[i+1]){dp[i+2][0]=min(dp[i+2][0],dp[i][0]+1);}
 if (i+1<st.size()&&st[i]==st[i+1]){dp[i+2][1]=min(dp[i+2][1],dp[i][1]+1);}
 
 if (st[i]=='0'){dp[i+1][0]=min(dp[i][1],dp[i+1][0]);dp[i+1][1]=min(dp[i+1][1],dp[i][0]+1);}
 if (st[i]=='1'){dp[i+1][1]=min(dp[i][0],dp[i+1][1]);dp[i+1][0]=min(dp[i+1][0],dp[i][1]+1);}
 
 /*if (i+1<st.size()&&st[i]=='0'&&st[i+1]=='1')
 {
  dp[i+2][1]=min(dp[i+2][1],dp[i][1]);dp[i+2][0]=min(dp[i][0]+1,dp[i+2][0]);
 }
 
 if (i+1<st.size()&&st[i]=='1'&&st[i+1]=='0')
 { 
  dp[i+2][0]=min(dp[i+2][0],dp[i][0]);dp[i+2][1]=min(dp[i][1]+1,dp[i+2][1]);
 }
 */
}
/*
for (int i=0;i<=st.size();i++)
cout<<i<<" "<<dp[i][0]<<" "<<dp[i][1]<<endl;
*/
cout<<min(dp[st.size()][0],dp[st.size()][1])<<endl;

cin.get();cin.get();
return 0;}