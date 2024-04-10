/*
You were born but you don't know why you're existing
You are unable why is it you and not me

Your parents they're shocked butstill they love you
You are their flesh and blood whatelse could they do

Not even modern medicine can help your tortured body
Hospitals are your world, doctors your friends
To keep your dreadful life

Other people never treat you like a normal human being
They often think you shouldn't be a part of their sick society

They smile at you but deep inside they think you shouldn't be here
Because they never ever realize, you got a heart and feelings too

People turn their heads
Whenever you walk by
Because they believe
You live a life without sense
Life without sense
Life without sense

If I'd be you, i might to commit suicide
But you're strong enough to live on
Because it's you and not me

If I'd be you, i might to commit suicide
But you're strong enough to live on
Because it's you and not me

People turn their heads
Whenever you walk by
Because they believe
You live a life without sense
Life without sense
Life without sense
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

string ans,st,temp;
long n;
bool pal(string st)
{
 string st1=st;
 reverse(st1.begin(),st1.end());
 return (st==st1);
}

int main(){
//freopen("rush.in","r",stdin);
//freopen("rush.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>st;
n=st.size();

ans=st[0];

for (int mask=0;mask<(1<<n);mask++)
{
 string temp="";
 for (int i=0;i<n;i++)
 if (mask&(1<<i))temp+=st[i];
 if (pal(temp))
  if (temp>ans)
   ans=temp;
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}