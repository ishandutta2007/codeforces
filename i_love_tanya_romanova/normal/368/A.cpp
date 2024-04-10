/*
So glad to see you well
Overcome and completely silent now
With heavens help you cast your demons out

And not to pull your halo down
Around your neck and tug you off your cloud
But I'm more then just a little curious
How you're planning to go about making your amends
To the dead
To the dead

Recall the deeds as if they're all
Someone else's atrocious stories
Now you stand reborn before us all
So glad to see you well

And not to pull your halo down
Around your neck and tug you to the ground
But I'm more then just a little curious
How you're planning to go about making your amends
To the dead
To the dead

With your halo slipping down
Your halo slipping
Your halo slipping down
Your halo slipping down

But I'm more then just a little curious
How you're planning to go about making your 
More then just a little curious
How you're planning to go about making your
More then just a little curious
How you're planning to go about making your amends

Your halo slipping down
Your halo slipping down
To choke you now
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
//#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-7
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

long n,d,ar[20000],m,ans;

int main(){
//freopen("virus.in","r",stdin);
//freopen("virus.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>d;
for (int i=1;i<=n;i++)
{cin>>ar[i];
}
sort(ar+1,ar+n+1);

cin>>m;
for (int i=1;i<=m;i++)
if (i<=n)ans+=ar[i];
else ans-=d;
cout<<ans<<endl;

cin.get();cin.get();
return 0;}