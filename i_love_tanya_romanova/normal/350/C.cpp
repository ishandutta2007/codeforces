/*
Inner perception trapped in a soul cage
Human wreckage i leave my liquid face
Who am i sense blurred who's my mind
In this life obscured
Visual progressions leave me no peace
Subliminal merger clutch the
Fence of needs
What's there in desperation what's real
Flawless confusion

Void of emptyness reign my truth
Before my eyes flashes of youth
Memory-nuances pass where's my life
Frayed pictures mass
Insidious deception feelings fade
Reenous mirrors i praise the
Blackened day
What am i to reality what's in line
Subsequently

Forever turning through a lifetime
Endless burning of soul and mind
Step by step i'm taken through the past
To burn in fear of lies i'm lost mouldering
Oblivions grasp makes my soul burn
Burn

This astray mind has sieged my soul
Forever chained to this tearing cold
I'll never tell the truth from lies
Disbelief covers my eyes i'm lost mouldering
Perpetual pain in this soul burn

Pieces to me strange wrapped up disguise
Reflections of myself in another life

I see it vague before my eyes
Pictures drawn of naked bare lies
It makes no sense to live this mess
Constant until i find my rest
Enemy within a soul in flames
Gaining it's pulse breeding inside
Pressure increase drowns my belief
As i unveil myself in me
Burn
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
#define bsize 256

using namespace std;

long n,a,b;
vector<pair<long, pair<long, long> > > v;
vector<pair<long, pair<long, string> > > moves;

void add_move(long a,string b)
{moves.push_back(make_pair(1,make_pair(a,b)));}
void add2()
{
 moves.push_back(make_pair(2,make_pair(0,"")));
}
void add3()
{
 moves.push_back(make_pair(3,make_pair(0,"")));
}

void solve(pair<long, long> p)
{
 if (p.first!=0){if (p.first<0)add_move(-p.first,"L");else add_move(p.first,"R");}
 if (p.second!=0){if (p.second<0)add_move(-p.second,"D"); else add_move(p.second,"U");}
 add2();
 if (p.first!=0){if (p.first<0)add_move(-p.first,"R");else add_move(p.first,"L");}
 if (p.second!=0){if (p.second<0)add_move(-p.second,"U"); else add_move(p.second,"D");}
 add3();
}
int main(){
//freopen("firesafe.in","r",stdin);
//freopen("firesafe.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>a>>b;
 v.push_back(make_pair(abs(a)+abs(b),make_pair(a,b)));   
}

sort(v.begin(),v.end());

for (int i=0;i<v.size();i++)
solve(v[i].second);

cout<<moves.size()<<endl;
for (int i=0;i<moves.size();i++)
{
    cout<<moves[i].first;
    if (moves[i].first==1)cout<<" "<<moves[i].second.first<<" "<<moves[i].second.second;//<<endl;
    cout<<endl;
}

cin.get();cin.get();
return 0;}