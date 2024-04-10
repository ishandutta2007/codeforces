/*
How much must I curse your name
And put your beliefs to shame
Before you prove yourself
And end this life?

End this life

And I'll say a fucking prayer
Because I know it
won't be answered

Where is your god?
Where is your god?
Where is your fucking god?

And even though I
don't believe in you
I pray for the day
I pray for the day
That you end this life

So please
Take Me
Away

I want the hand of god
To come and strike me down
I want the hand of god
To come and strike me down

Where is your god?
Where is your god?
Where is your fucking god?

For all the prayers that go
unanswered
For all the prayers that go
unanswered
Why do you think that is?

For the families that
waste their time
Open your eyes

For all the prayers that go
unanswered
Why do you think that is?

For the families that
waste their time
Open your fucking eyes.
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

long m,n,x[1<<20],y[1<<20],l[1<<20][5],r[1<<20][5];
long calc;
long ans[200];

int main(){
//freopen("magic.in","r",stdin);
//freopen("magic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>m>>n;
for (int i=1;i<=n;i++)
{
 cin>>x[i]>>y[i];
}

for (int i=1;i<=m*4;i++)
 for (int j=0;j<4;j++)
  l[i][j]=1e9,r[i][j]=-1e9;

for (int i=1;i<=n;i++)
{
 l[x[i]][0]=min(l[x[i]][0],y[i]);
 r[x[i]][0]=max(r[x[i]][0],y[i]);
 l[y[i]][1]=min(l[y[i]][1],x[i]);
 r[y[i]][1]=max(r[y[i]][1],x[i]);
 
 l[x[i]+y[i]][2]=min(l[x[i]+y[i]][2],x[i]);
 r[x[i]+y[i]][2]=max(r[x[i]+y[i]][2],x[i]);
 
 l[x[i]-y[i]+m][3]=min(l[x[i]-y[i]+m][3],x[i]);
 r[x[i]-y[i]+m][3]=max(r[x[i]-y[i]+m][3],x[i]);
}

for (int i=1;i<=n;i++)
{
 calc=0;
 if (l[x[i]][0]<y[i])++calc;
 if (r[x[i]][0]>y[i])++calc;
 if (l[y[i]][1]<x[i])++calc;
 if (r[y[i]][1]>x[i])++calc;
 if (l[x[i]+y[i]][2]<x[i])++calc;
 if (r[x[i]+y[i]][2]>x[i])++calc;
 if (l[x[i]-y[i]+m][3]<x[i])++calc;
 if (r[x[i]-y[i]+m][3]>x[i])++calc;
 ans[calc]++;
}

for (int i=0;i<9;i++)
{
 if(i)cout<<" ";
 cout<<ans[i];   
}
cout<<endl;

cin.get();cin.get();
return 0;}