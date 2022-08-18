/*
Lets take a moment and break the ice
So my intentions are known
See I pity in watching you suffer
I know the feeling of feeling of being damned alone
I have a storybook of my own

Don't you see I am your pride
Agent of will
Bearer of needs
And you know what's right
I am your war
I'm in strong
Aiming the weak
Know me by name
Shepherd of fire

Well I can promise you paradise
No need to serve on your knees
And when you're lost in the darkest of hours
Take a moment and tell me who you see
Wont tell ya who not to be

Now you know I am your pride
Agent of will
Bearer of needs
And you know what's right
I am your war
I'm in strong
Aimin the weak
Know me by name
Shepherd of fire

Deciple of the cross and champion of the suffering
Emerse yourself in the kingdom of redemption
Pardon your mind through the chains of the divine
Make way for the shepherd of fire

Through the ages of time
I've been known for my hate
But I'm a dealer of sinful choices
For me it's never too late

I am your pride
Agent of will
Bearer of needs
And you know what's right
I am your war
I'm in strong
Aimin the weak

I am your wrath
I am your guilt
I am your lust
And you know it's right
I am your love
I am your stall
I am your trust

Know me by name
Shepherd of fire
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

long n,a,b,h[2000],dp[20][20][20][20],par1[20][20][20][20];
pair<pair<long, long> ,pair<long, long> > par[20][20][20][20];
long c1,c2,c3,c4;
vector<long> ans;
long tp,tq,tw;

int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>a>>b;
for (int i=1;i<=n;i++)
{cin>>h[i];++h[i];}

for (int i=1;i<=n;i++)
for(int p=0;p<=17;p++)
 for (int q=0;q<=17;q++)
  for (int w=0;w<=17;w++)
{
 dp[i][p][q][w]=1e9; 
}

dp[2][h[1]][h[2]][h[3]]=0;

for (int i=1;i<=n;i++)
 for (int p=17;p+1;--p)
  for (int q=17;q+1;--q)
   for (int w=17;w+1;--w)
   {
    if (p==0)
     if (dp[i+1][q][w][h[i+2]]>dp[i][p][q][w])
     dp[i+1][q][w][h[i+2]]=min(dp[i+1][q][w][h[i+2]],dp[i][p][q][w]),par[i+1][q][w][h[i+2]]=
     make_pair(make_pair(i,p),make_pair(q,w)); // kd
    tp=p-b;
    if(tp<0)tp=0;
    tq=q-a;
    if (tq<0)tq=0;
    tw=w-b;
    if (tw<0)tw=0;
    if (dp[i][tp][tq][tw]>dp[i][p][q][w]+1)
    dp[i][tp][tq][tw]=min(dp[i][tp][tq][tw],dp[i][p][q][w]+1),par[i][tp][tq][tw]=
    make_pair(make_pair(i,p),make_pair(q,w));
   }
   
cout<<dp[n-1][0][0][0]<<endl;

c1=n-1;
c2=0;
c3=0;
c4=0;
while (c1>0)
{
 pair<pair<long, long> ,pair<long, long> > tp;
 tp=par[c1][c2][c3][c4];
// cout<<c1<<" "<<c2<<" "<<c3<<" "<<c4<<endl;
 if (tp.first.first==c1)ans.push_back(c1);
 c1=tp.first.first;
 c2=tp.first.second;
 c3=tp.second.first;
 c4=tp.second.second;
}

for (int i=0;i<ans.size();i++)
{
 if (i)cout<<" ";
 cout<<ans[i];
}
cout<<endl;

cin.get();cin.get();
return 0;}