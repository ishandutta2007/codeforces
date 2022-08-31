/*
It started off with a one night stand and lingered to a fling
I'm sorry to all the soldiers who didn't see me as a fake
All you feel and all you want you still need your blood
Talons raised different now you're up to no good
(Take my hand show me the way, heal all the children
They are great. Take my hand show me the way, heal all
The children that make me sing)

One more nail in the coffin, one more for the grave
One more time I'm on my knees trying to walk away
How has it come to this

I've said it once, I've said it twice,
I've said it a thousand fucking times
That I'm ok that I'm fine, that it's all just in my mind
But this has got the best of me and I can't seem to sleep
It's not just your alone with me its just you'll never leave
(I've said it once I've said it twice I've said it a
Thousand fucking times)

You said it's a suicide and I say this is a war,
When I rode into battle.
Battle, this is oh.
This is what you call love.
This is our war, our cause.

One more nail in the coffin, one more for the grave
One more time I'm on my knees trying to walk away.
Everything I loved, is nearly everything I've lost

I've said it once, I've said it twice,
I've said it a thousand fucking times
That I'm ok that I'm fine, that it's all just in my mind
But this has got the best of me and I can't seem to sleep
It's not your just alone with me its just you'll never leave
It's not your just alone with me its just you'll never leave!

Every second, every minute, every hour, every day
It never ends, it never ends
Every second, every minute, every hour, every day
It never ends, it never ends
Every second, every minute, every hour, every day
It never ends, it never ends
Every second, every minute, every hour, every day
It never ends, it never ends
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