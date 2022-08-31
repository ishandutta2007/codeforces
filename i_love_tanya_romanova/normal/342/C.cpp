/*
I got a big fat Cadillac built for you
I got a honk that'll blow the avenue
Got a hot dog kickin' all bend my thing
Got a a sugar looking woman with a bald headed man
Give me five o here boy, that's what I'll do
Got a big fat momma who can hold a tune
Gotta slip that bone in hard and mean
A honky tonk woman get the best of me

Can't hold me back
Can't hold me back
Can't hold me back
Get a heart attack
Can't hold me back

Got a honky tonk big ball hit to thrill
I got a sugar boot money baby that'll kill
A honky tonk 15 golden mile
Gotta bald headed woman loaded in the town
You can get me to the ball man, drivin' in
And don't balk the kill, call in the 'ville
You gotta map the wrong town, hit the road
You got the whole boppa movin' on down the road

Can't hold me back
You can't hold me back
You can't hold me back
You get a heart attack
Can't hold me back

You can't hold me back
You can't hold me back
You can't hold me back
You get a heart attack
Can't hold me back

You can't hold me back, you can't hold me back
You can't hold me back, you can't hold me back
Can't hold me back, you can't hold me back
You can't hold me back, you get a heart attack
Can't hold me back (hold me back)
You can't hold me back (hold me back)
You can't hold me back (hold me back)
Can't hold me back (hold me back)
You can't hold me back (hold me back)
Can't hold me back (hold me back)
You can't hold me back (hold me back)
You can't hold me back
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
#define eps 1e-8
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
//#define bsize 250
#define clone agsdahfaassdg

using namespace std;

long long h,r,ans,pc;

int main(){
//freopen("raydist.in","r",stdin);
//freopen("raydist.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>r>>h;
r*=2;h*=2;
pc=r/2;
while (pc<=h){ans+=2;pc+=r;}
if (ans==0)ans=1;
else
{
    pc-=r;
//    cout<<"#"<<pc<<endl;
    if ((r*r)/4+(h+r/2-pc)*(h+r/2-pc)>=r*r)
     ++ans;
}
cout<<ans<<endl;
cin.get();cin.get();
return 0;}