/*
Lonely times
Long lost are the days I am longing
Slowly gone, now things have changed
I can feel it

This can't be
Enough is enough
You've gone too far
You've crossed the line
Lost so much time
And now I see
This must end here

Now times passed
No more are those days in my mind now
Now you're gone
I'm free at last
Free from you now!

This can't be...

This can't be
Enough is enough
You've gone too far
You've crossed the line
Lost so much time
And now I see
This has to end
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
#include <ctime> 
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

int n;
string st;
map<string, int> cnt;
int ans;

int main(){
//freopen("gadgets.in","r",stdin);
//freopen("gadgets.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>st;
    cnt[st]++;
    ans=max(ans,cnt[st]);
}
cout<<ans<<endl;

//cin.get();cin.get();
return 0;}