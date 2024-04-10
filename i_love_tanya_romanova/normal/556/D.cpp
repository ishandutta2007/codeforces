/*
The battle plan closed in my hands
I have already made to conquer all these lands
Will be released within tonight
Constraining Exentar to fight
What I've prepared is just unfair
But I don't care about it 'cause my goal's prevail
The Astar's fall and death for all, my role
Defeating him I get control.

My rising force sets off my wars
And his behaviour is so false
To make me nervous and to ruin his goals
No pity, no escape but a battle upon him!

I've got a plan to trick Lord Exenthar
He's daring to obscure my fame
He'll try the rage, he'll try the hate I need
To impede his fate
I will propose a false alliance
Deceiving my enemy and then
Will be a surprise, my crowd will rise
He nevermore will see the light
He nevermore will see the light!

I don't know why he said to be
A friend of mine, an old allied
I don't remember who is he
I only know he's just an enemy!
I'll simulate to be whom says
And finally he will be in a maze
I wanna see the blood upon his face
Just wanna cause the extinction of his race!

I'll call him in a golden town
To make new peace, I have been around!
Instead I'll wait for him in the Derdian gorge
No pity, no escape but a battle upon him!
I've got a plan to trick Lord Exenthar
He's daring to obscure my fame
He'll try the rage, he'll try the hate I need
To impede his fate
I will propose a false alliance
Deceiving my enemy and then
Will be a surprise, my crowd will rise
He nevermore will see the light
He nevermore will see the light!
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