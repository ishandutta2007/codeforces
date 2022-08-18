/*  
With this ink in our skin we've sealed our fate,
and the axe comes early
(only naturally) So what does that matter?
There's a bed of skeletons waiting for me,
on the other side
They're waiting for my next move (next fatal breath)
Human lives to me seem so unreal, can't see through the fog
(nothing past a grey wall) see past the stereotype
Belief, structure built up in you.
I'll tear you down and the one who created you

If they didn't have One how would they act?
If we didn't have hope how would we behave?
Would they still feel remorse
if they slaughtered innocent beings?
Or is hope the only thing that keeps you sane?

A good friend once told me you are our memory
without them we equal nothing
And all I can see is the place I wanna be
Suddenly my life was so free
Leaves at my feet, blown to the ground
their echoes are reaching my ears
Nights coming fast, suns going down
But keep away from me... keep away from me

(it's hard, to keep me in this place, keep away from me)

We may have created the beginning, mentally
We may have created the beginning, physically
To the end of our human existence...

I see through you
The fear that's in your eyes

A good friend once told me we are our memory
Without it we equal nothing
And all I can see is the place I wanna be
Timeless my life was so free
Leaves at my feet, blown to the ground
their echoes are reaching my ears
Nights coming fast, suns going down - confused
I don't know the answers but neither do you
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

long ar[30],ans[1<<24],n,answ;
long d[100][100];

long calc(long mask)
{long r=0;
for (int i=0;i<24;i++)
if (mask&(1<<i))++r;
return r;
}

void dfs(long mask)
{
//     cout<<mask<<endl;
 if (ans[mask])return;
 ans[mask]=1;
 long cp=26;
 while (!(mask&(1<<cp)))--cp;
 if (cp==n-1)
 {
  answ=min(answ,calc(mask));return;
 }    
 ++cp;
 long fl=0;
 long q=0;
 for (int delbit=0;delbit<cp;delbit++)
 {
   q=d[cp][delbit];
  if (q==0)continue;
  if (!(mask&(1<<delbit)))continue;
  --q;
  if (!(mask&(1<<q)))continue;
  fl=1;
  if (fl)break;
 }
 if (fl==0)return;
  for (int npos=0;npos<=cp;npos++)
  {
      if (mask&(1<<npos))dfs(mask-(1<<npos)+(1<<cp));
  }
  dfs(mask|(1<<cp));
}

int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=0;i<n;i++)
{
 cin>>ar[i];   
}
answ=n+100;

for (int i=0;i<n;i++)
for (int j=0;j<n;j++)
for (int q=0;q<n;q++)
{
 if (ar[i]-ar[j]==ar[q])
 d[i][j]=q+1;   
}

for (int mask=0;mask<(1<<n);++mask)
ans[mask]=0;
dfs(1);
if (answ>n)answ=-1;
cout<<answ<<endl;


cin.get();cin.get();
return 0;}