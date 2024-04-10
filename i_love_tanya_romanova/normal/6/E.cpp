/*
Murder, drugs, cash, and greed
It touches everyone and everything
Within the walls there's no escaping the disease
Sidwalks turn to pharmacies
All the pimps and pushers territories
Dollars pouring in from the victims trapped within
Schoolyard's a place of sorrow
Pray your children live to see tomorrow
A place where mothers cry, and kiss their dying sons goodbye
Living in a state of fear
Afraid of everything they see or hear
Someone they love may get shot
For drugs they never even bought!

Violence is a way of life
Revenge delivered with a gun or knife
Paybacks are a bitch
They'll leave you dying in a ditch
Caught in the hypnotic spell
Their life's story they'll never life to tell
In a hazy curtain, they can't see the end is certain
Imprisoned by narcotic chains
Life for some will never be the same
Trapped in walls of glass
Hoping that this all will pass
But some will find their way outside
Face the evil, eyes open wide
Break the bonds that pull you in
Escape the hell that thrives...

Within the walls
Of chaos and despair
Most are unemployed
Living on welfare
Prowling the halls
The vultures come to feed
On the flesh of those
Who are enslaved to the need
The final curtain falls
And no one sheds a fear
Their pleas for help always seem to fall
Upon deaf ears
Within the walls of chaos they forgot
That dignity and sanity
Are things that can't be bought

With every passing day
Another life is cast astray
Wear the wrong colors
And you might get blown away

Turn of a page
Another name's crossed off the list
Shot between the eyes
With a rig clenched in his fist

Driven to the grave
Ruled by need for kicks
Extract their own gold teeth
To satisfy their fix

There's cracks in the foundation
The time will soon arrive
When the walls will crumble down
And bury everyone alive!

Within the walls...
Within the walls of chaos...
Within the walls...
Within the walls of chaos...
Within the walls...
Within the walls of chaos!
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

long n,m,ar[200000];
multiset<long> s;
vector<pair<long, long> > ans;
long l,r;
multiset<long>::iterator it;
long answ;
long asp;

void ad(){s.insert(ar[r+1]);++r;}
void ml(){it=s.find(ar[l]);s.erase(it);++l;}
bool cadd(long x)
{
 if (s.size()==0)return true;
 long a,b;
 it=s.begin();
 a=(*it);
 it=s.end();
 --it;
 b=(*it);
 a=min(a,x);
 b=max(b,x);
 return (b-a<=m);
}

int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
 cin>>ar[i];

l=r=1;
s.insert(ar[1]);

while (l<=n)
{
 while (r<n&&cadd(ar[r+1]))ad();
// ans.push_back(make_pair(l,r));
 if (r-l+1>asp){ans.clear();ans.push_back(make_pair(l,r));answ=1;asp=r-l+1;}
 else if (r-l+1==asp){++answ;ans.push_back(make_pair(l,r));}
 if (r==n)break;
 while (!cadd(ar[r+1]))ml();
      
}

cout<<asp<<" "<<answ<<endl;
for (int i=0;i<ans.size();i++)
cout<<ans[i].first<<" "<<ans[i].second<<endl;

cin.get();cin.get();
return 0;}