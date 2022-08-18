/*
No sign of life did flicker
In floods of tears she cried
"All hope's lost it can't be undone
They're wasted and gone"

"Save me your speeches
I know (They blinded us all)
What you want
You will take it away from me
Take it and I know for sure
The light she once brought in
Is gone forevermore"

Like sorrowful seaguls they sang
"(We're) lost in the deep shades
The misty cloud brought
(A wailing when beauty was gone
Come take a look at the sky)
Monstrous it covered the shore
Fearful into the unknown"
Quietly it crept in new horror
Insanity reigned
And spilled the first blood
When the old king was slain

[chorus:]
Nightfall
Quietly crept in and changed us all
Nightfall
Quietly crept in and changed us all
Nightfall
Immortal land lies down in agony

"How long shall we
Mourn in the dark
the bliss and the beauty
Will not return
Say farewell to sadness and grief
Though long and hard the road may be"
But even in silence I heard the words
"An oath we shall swear
By the name of the one
Until the world's end
It can't be broken"

Just wondering how
I can still hear these voices inside

The doom of the Noldor drew near

The words of a banished king
"I swear revenge"
Filled with anger aflamed our hearts
Full of hate full of pride
We screamed for revenge

[chorus]

"Vala he is that's what you said
Then your oath's been sworn in vain
(But) freely you came and
You freely shall depart
(So) never trust the northern winds
Never turn your back on friends"

"Oh I'm heir of the high lord!"
"You better don't trust him"
The enemy of mine
Isn't he of your kind and
Finally you may follow me
Farewell
He said

[chorus]

Back to where it all began
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

long n,m;
string tp;
long val;
vector<long> v1,v2,v3;
long dp[105][105][105][3];
long q,answ;

int main(){
//freopen("dagger.in","r",stdin);
//freopen("dagger.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
{
 cin>>tp>>val;
 if(tp=="ATK")v1.push_back(val);
  else v2.push_back(val);
}

for (int i=1;i<=m;i++)
{
 cin>>q;
 v3.push_back(q);
}

sort(v1.begin(),v1.end());
sort(v2.begin(),v2.end());
sort(v3.begin(),v3.end());

for (int i=0;i<=v1.size();i++)
 for (int j=0;j<=v2.size();j++)
  for (int q=0;q<=v3.size();q++)
   dp[i][j][q][0]=dp[i][j][q][1]=-1e9;
 
dp[0][0][0][0]=dp[0][0][0][1]=0;

for (int i=0;i<=v1.size();i++)
 for (int j=0;j<=v2.size();j++)
  for (int q=0;q<v3.size();q++)
  {
//   cout<<i<<"   "<<j<<"  "<<q<<"  "<<dp[i][j][q][0]<<"   "<<dp[i][j][q][1]<<endl;
   if (i<v1.size()&&v3[q]>=v1[i]) // at att
    dp[i+1][j][q+1][0]=max(dp[i+1][j][q+1][0],dp[i][j][q][0]+v3[q]-v1[i]),
    dp[i+1][j][q+1][1]=max(dp[i+1][j][q+1][1],dp[i][j][q][1]+v3[q]-v1[i]);
   if (j<v2.size()&&v3[q]>v2[j]) // att def
    dp[i][j+1][q+1][0]=max(dp[i][j+1][q+1][0],dp[i][j][q][0]),
    dp[i][j+1][q+1][1]=max(dp[i][j+1][q+1][1],dp[i][j][q][1]);
    
   dp[i][j][q+1][1]=max(dp[i][j][q+1][1],dp[i][j][q][1]+v3[q]);// s push
   
   //skp
   dp[i][j][q+1][0]=max(dp[i][j][q+1][0],dp[i][j][q][0]);
   dp[i][j][q+1][1]=max(dp[i][j][q+1][1],dp[i][j][q][1]);
   
  }

answ=0;
answ=max(answ,dp[v1.size()][v2.size()][v3.size()][1]);
//cout<<dp[v1.size()][v2.size()][v3.size()][1]<<endl;

for (int i=0;i<=v1.size();i++)
 for (int j=0;j<=v2.size();j++)
  for (int q=0;q<=v3.size();q++) 
  answ=max(answ,dp[i][j][q][0]);
 
 cout<<answ<<endl;
 
cin.get();cin.get();
return 0;}