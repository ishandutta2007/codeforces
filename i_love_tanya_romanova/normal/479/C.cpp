/*
So welcome to the no man's land
Where you can finally face yourself
Fear of feeling something real
Is your friend now
There's no need to run

So welcome to the no man's land
Where nothing is as it seems
Mysteries hidden from six feet under
And six feet above

And to feel your heart this way
Before it gets too late

The moon began to split in half
And the darkness could be touched
Blindfolded
You're trying to find a way
To the bottom of your soul

Well I can see all your scars
That you wish you could hide
And I won't let you remember
What it was like
When you were here before

And to hear your voice again
And to feel your touch this way
Before it gets too late
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
#define right adsgasgadsg
#define free adsgasdg

using namespace std;

long n,a,b,ans;
vector<pair<long, long> > v;

int main(){
//freopen("logins.in","r",stdin);
//freopen("logins.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>a>>b;
 v.push_back(make_pair(a,b));
}
ans=-1e9;
sort(v.begin(),v.end());
for (int i=0;i<v.size();i++)
{
 if (v[i].second<ans)ans=v[i].first;
 else ans=v[i].second;
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}