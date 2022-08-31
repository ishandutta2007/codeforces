/*
Anybody searching for action
Anything to feel the emptiness inside
Any place that the streets are empty
Any takers wanna pour out their lives

With fire and lighting shooting from my hand
And desolation written across my eyes
My itchy finger on hair pain trigger
My tempers hot and my patience's taken flight

Inside the abattoir
The cover charge is somebody's gotta die
Now, I hear you screaming out for mercy
Last man that's standing wins the fight
Too late, I see your end zero in on you

Even mortal enemies they can't deny
Let me help you up again
The wings of God surround me
I live to play because I know Ill never die

If I win again, I'm still the champion
And if you win, ha, that's just impossible
I don't play for keeps, I don't play for your soul
I don't play to win, I don't play for it all, I play for blood

I don't play for keeps, I play for blood
I don't play for your soul, I play for blood
I don't play to win, I play for blood
I don't play for it all, I play for blood
Play for blood
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

#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

string st;
long bad;
long ar[200][200];
long dp[105000][30];
long ans;
string st1;
long temp,answ;

int main(){
//freopen("rush.in","r",stdin);
//freopen("rush.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>st;
cin>>bad;
for (;bad;--bad)
{
 cin>>st1;
 ar[st1[0]-'a'][st1[1]-'a']=1;
 ar[st1[1]-'a'][st1[0]-'a']=1;
}

for (int i=0;i<=st.size();i++)
 for (int last=0;last<=26;last++)
  dp[i][last]=1e9;

for (int i=0;i<=26;i++)
 dp[0][i]=0;

for (int i=0;i<st.size();i++)
 for (int last=0;last<26;last++)
 {
  temp=st[i]-'a';
  dp[i+1][last]=min(dp[i+1][last],dp[i][last]+1);// del
  if (ar[last][temp]==0)
   dp[i+1][temp]=min(dp[i+1][temp],dp[i][last]);
 }

answ=1e9;
for (int i=0;i<=26;i++)
 answ=min(answ,dp[st.size()][i]);
cout<<answ<<endl;

cin.get();cin.get();
return 0;}