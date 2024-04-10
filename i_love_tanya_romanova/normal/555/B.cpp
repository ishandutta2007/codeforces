/*
Before you accuse me, take a look at yourself.
Before you accuse me, take a look at yourself.
You say I've been buyin' another woman clothes,
But you've been talkin' to someone else.
I called your mama 'bout three or four nights ago.
I called your mama 'bout three or four nights ago.
Your mama said, "Son,
Don't call my daughter no more."

Before you accuse me, take a look at yourself.
Before you accuse me, take a look at yourself.
You say I've been buyin' another woman clothes,
But you've been takin' money from someone else.

Come on back home, baby; try my love one more time.
Come on back home, baby; try my love one more time.
You've been gone away so long,
I'm just about to lose my mind.

Before you accuse me, take a look at yourself.
Before you accuse me, take a look at yourself.
You say I've been buyin' another woman clothes,
But you've been talkin' to someone else.
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

long long n,m,l[1<<20],r[1<<20];
vector<pair<long long, pair<long long, long long> > >events;
set<pair<long long, long long> > gaps;
set<pair<long long, long long> >::iterator it;
long long taken;
long long ans[1<<20];
long long L[1<<20];
vector<pair<long long, long long> > B;
int ptr;

int main(){
//freopen("gadgets.in","r",stdin);
//freopen("gadgets.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
//ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
{
//  cin>>l[i]>>r[i];
    scanf("%lld",&l[i]);
    scanf("%lld",&r[i]);
}

for (int i=1;i<=m;i++)
{
//  cin>>L[i];
scanf("%lld",&L[i]);
}

for (int i=2;i<=n;i++)
{
    long long a,b;
    a=l[i]-r[i-1];
    b=r[i]-l[i-1];
    events.push_back(make_pair(a,make_pair(b,i-1)));
}

for (int i=1;i<=m;i++)
{
    B.push_back(make_pair(L[i],i));
}

sort(B.begin(),B.end());
sort(events.begin(),events.end());
ptr=0;

for (int i=0;i<B.size();i++)
{
    while (ptr<events.size()&&events[ptr].first<=B[i].first) // add new
    {
        gaps.insert(make_pair(events[ptr].second.first,events[ptr].second.second));
        ++ptr;
    }
    
    while (true) // del inv
    {
        if (gaps.size()==0)break;
        it=gaps.begin();
        if ((*it).first<B[i].first)gaps.erase(it);
        else break;
    }
    
//  cout<<B[i].first<<"   "<<gaps.size()<<"%"<<"  "<<taken<<" "<<endl;
    if (gaps.size()==0)continue;
    it=gaps.begin();
    ans[(*it).second]=B[i].second;
    gaps.erase(it);
    ++taken;
}

//cout<<"#"<<taken<<" "<<n<<endl;

if (taken<n-1)
{
    cout<<"No"<<endl;
}
else
{
    cout<<"Yes"<<endl;
    for (int i=1;i<n;i++)
    {
        if (i>1)printf(" ");
        printf("%lld",ans[i]);
//      cout<<ans[i];
    }
    cout<<endl;
}

//cin.get();cin.get();
return 0;}