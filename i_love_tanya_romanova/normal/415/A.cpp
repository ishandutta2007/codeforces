/*
Straight into a vicious wind, this is where it all begins
You bare your soul one last time, laying everything on the line
The struggle of so many years, all the pain, all the tears
Still you're always pushing on, waiting for your day in the sun
We see with blood in our eyes, taking no prisoners
And leaving the weak ones behind
Years of rage made you insane, you've traveled through both fire and rain
Good or bad this is your life, standing on the edge of the knife
What makes you weak can make you strong, but in the end time marches on
So make your mark and make it now, you'll go down in history somehow
Now is the time, the time to rise
Staring at a vicious man, this is where it all began
Break the mirror one last time, laying everything on the line
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

long n,m,q,ans[200];

int main(){
//freopen("melman.in","r",stdin);
//freopen("melman.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>n>>m;
for (int i=1;i<=m;i++)
{
 cin>>q;
 for (int j=q;j<=n;j++)
  if (ans[j]==0)ans[j]=q;
}

for (int i=1;i<=n;i++)
{
    if (i-1)cout<<" ";
    cout<<ans[i];
}
cout<<endl;

cin.get();cin.get();
return 0;}