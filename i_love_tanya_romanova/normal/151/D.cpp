/*
I had wrists donning slits
Flowing constantly
My broken body in a wreck
Wrapped around a tree
A crosswalk hit and run
The finish line for me
People clutter in the gutter
Take a look and see

[chorus:]
No escaping pain
You belong to me
Clinging on to life
By the skin o'my teeth

My blood flows through the streets
Deluge from the wounds
Empty jars of sleeping pills
On the dresser in my room
My wet brain neighbor cranes
His neck in time to see
The white lights a train
Bearing down on me

[Chorus]

I won't feel the hurt
I'm not trash any longer
That that doesn't kill me
Only makes me stronger
I need a ride to the morgue
That's what 911 is for
So, tag my toe and don't forget
Ooh to close the drawer

[Chorus]
*/

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define INF 1000000000
#define eps 1e-15
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define szz 400
//#define pb push_back
using namespace std;
long long n,m,k,ans;
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n>>m>>k;
if (k==1||k>n)
{ans=1;for (int i=1;i<=n;i++)
{ans=ans*m%bs;
 }
 cout<<ans<<endl;
}
else
if (k==n)
{ans=1;for (int i=1;i*2<=n+1;i++)
{ans=ans*m%bs;}
cout<<ans<<endl;
}
else
if (k%2==1)
{if (n==1)ans=m; else ans=m*m;
cout<<ans<<endl;
           }
else cout<<m<<endl;
cin.get();cin.get();
return 0;}