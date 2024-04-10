/*
You, you got a nasty reputation
We're in a sticky situation
It's down to me and you

So tell me, is it true?
They say there ain't nobody better
Well, now that we're together
Show me what you can do

You're under the gun
Out on the run
Gonna set the night on fire

Out on the run
Under the gun
Playin' to win

Raise your hands
When you want to let it go
Raise your hands
When you want to let a feeling show

Raise your hands
From New York to Chicago
Raise your hands
From New Jersey to Tokyo

Whoa, whoa
Raise your hands

I, I've been out on the front line
Where you'll go down if you waste time
They'll walk all over you

But I, I ain't here lookin' for surrender
I'll raise the flag, if you'll defend her
It's up to you

You're under the gun
Out on a run
Gonna set the night on fire

Out on the run
Under the gun
Playin' to win

You got to raise your hands
When you want to let it go
Raise your hands
When you want to let a feeling show

Raise your hands
From New York to Chicago
Raise your hands
From New Jersey to Tokyo

Whoa, whoa
Raise your hands
Whoa, whoa
Raise your hands

Alright, lets go!

Raise your hands
Raise your hands

Raise your hands
When you want to let it go
Raise your hands
And you want to let a feeling show

Raise your hands
In New York to Chicago
Raise your hands
From New Jersey to Tokyo

Whoa, whoa
Raise your hands
Raise your hands
Raise your hands
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
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

long n,ar[1<<20];
vector<pair<long, long> > v;
set<long> S;
long ans[1<<20];
long ps1,ps2;
set<long>::iterator it;

int main(){
//freopen("newlines.in","r",stdin);
//freopen("newlines.out","w",stdout);
//freopen("F:/input.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>ar[i];
    v.push_back(make_pair(ar[i],i));
}

sort(v.begin(),v.end());

S.insert(0);
S.insert(n+1);

for (int i=0;i<v.size();i++)
{
    it=S.lower_bound(v[i].second);
    ps2=(*it);
    --it;
    ps1=(*it);
//  cout<<ps1<<" "<<ps2<<endl;
    ans[ps2-ps1-1]=max(ans[ps2-ps1-1],v[i].first);
    S.insert(v[i].second);
}

for (int i=n;i;--i)
 ans[i]=max(ans[i],ans[i+1]);

for (int i=1;i<=n;i++)
{
    if (i>1)cout<<" ";
    cout<<ans[i];
}
cout<<endl;

//cin.get();cin.get();
return 0;}