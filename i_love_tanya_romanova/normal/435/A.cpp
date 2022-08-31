/*
And I feel myself so close
To this lost boy that we blame
He is so weak
Yeah we have all felt the same
He'd life us to forgive
Every mistake he made
But we can't accept
Him acting like a child
Is there someone left to help him
To listen to his complaints?
Everybody's run away
From this fearful young man
Who cannot stay alone.
But what else could we say?
"It is time to become a Man"
And now that it's over
Have you forgotten what happened?
We've been through some many things
So many memories you can't bury
How do you realise
The things you've done?
But what else could we've said?
At that time, you went too far my friend.
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

long n,m,ar[200],ans,ins;

int main(){
//freopen("dagger.in","r",stdin);
//freopen("dagger.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
cin>>ar[i];
ans=1;
ins=ar[1];
for (int i=2;i<=n;i++)
{
    if (ins+ar[i]>m){++ans;ins=ar[i];}
    else ins+=ar[i];
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}