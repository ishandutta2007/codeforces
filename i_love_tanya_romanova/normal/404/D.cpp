/*
Murder, drugs, cash, and greed
It touches everyone and everything
Within the walls there's no escaping the disease
Sidwalks turn to pharmacies
All the pimps and pushers territories
Dollars pouring in from the victims trapped within
Schoolyard's a place of sorrow
Pray your children live to see tomorrow
A place where mothers cry, and kiss their dying sons goodbye
Living in a state of fear
Afraid of everything they see or hear
Someone they love may get shot
For drugs they never even bought!

Violence is a way of life
Revenge delivered with a gun or knife
Paybacks are a bitch
They'll leave you dying in a ditch
Caught in the hypnotic spell
Their life's story they'll never life to tell
In a hazy curtain, they can't see the end is certain
Imprisoned by narcotic chains
Life for some will never be the same
Trapped in walls of glass
Hoping that this all will pass
But some will find their way outside
Face the evil, eyes open wide
Break the bonds that pull you in
Escape the hell that thrives...

Within the walls
Of chaos and despair
Most are unemployed
Living on welfare
Prowling the halls
The vultures come to feed
On the flesh of those
Who are enslaved to the need
The final curtain falls
And no one sheds a fear
Their pleas for help always seem to fall
Upon deaf ears
Within the walls of chaos they forgot
That dignity and sanity
Are things that can't be bought

With every passing day
Another life is cast astray
Wear the wrong colors
And you might get blown away

Turn of a page
Another name's crossed off the list
Shot between the eyes
With a rig clenched in his fist

Driven to the grave
Ruled by need for kicks
Extract their own gold teeth
To satisfy their fix

There's cracks in the foundation
The time will soon arrive
When the walls will crumble down
And bury everyone alive!

Within the walls...
Within the walls of chaos...
Within the walls...
Within the walls of chaos...
Within the walls...
Within the walls of chaos!
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
#define eps 1e-13
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
#define MAXN 10000
//#define SIZE 60
#define bsize 256

using namespace std;

string st;
long long dp[1200000][10];

int main(){
//freopen("cyclic.in","r",stdin);
//freopen("cyclic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>st;
// 0 - d1 - f1 - d2 - f2 - b

if (st[0]=='0'||st[0]=='?')
dp[0][0]=1;
if (st[0]=='1'||st[0]=='?')
dp[0][2]=1;
if (st[0]=='2'||st[0]=='?')
dp[0][3]=1;
if (st[0]=='*'||st[0]=='?')
dp[0][5]=1;

for (int i=1;i<st.size();i++)
{
 if (st[i]=='0'||st[i]=='?')
 {
  dp[i][0]=dp[i-1][0]+dp[i-1][1];
  dp[i][0]%=bs;
 }
 if (st[i]=='1'||st[i]=='?')
 {
  dp[i][1]=dp[i-1][5];
  dp[i][2]=dp[i-1][0]+dp[i-1][1];
  dp[i][2]%=bs;
 }
 if (st[i]=='2'||st[i]=='?')
 {
  dp[i][3]=0;// nvr
  dp[i][4]=dp[i-1][5];
 }
 if (st[i]=='*'||st[i]=='?')
 {
  dp[i][5]=dp[i-1][2]+dp[i-1][4]+dp[i-1][5];
  dp[i][5]%=bs;
 }
}
/*
for (int i=0;i<=st.size();i++){
for (int j=0;j<6;j++)
cout<<dp[i][j]<<" ";cout<<endl;}
*/
long long res=0;
res=res+dp[st.size()-1][5]+dp[st.size()-1][0]+dp[st.size()-1][1];
cout<<res%bs<<endl;

cin.get();cin.get();
return 0;}