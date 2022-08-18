/*
Devious to those unknown
He walks below the land
Alluring victims to their death
Perish to the sand

Master of the blackened arts
Living his decree
Thrives amongst the Seven Gates
Searching for the keys

[Chorus:]
I have seen the darkened depths of Hell
Sorcery beyond the witches' spell
Robbed the crypts of Death's eternity
Killed the priest and cursed him endlessly

Chants of evil incantation
Fill the murky night
Free the Devil's knights of Hell
Unleash their growing spite

Directing power forcibly
The fire of Hell is cast
Resurrect from crypts of Death
A demon from the past

[Chorus]

Cringe with fear
Violate the unbroken seal of Hell
Death will come searching for
Your mere soul
Still you are eager to seek your fate
All that lie here are remains of Death

Grinding bones, screaming skulls
Broken by the lapse of time
Decay to powder, ashes to dust
Diminishing, disintegrating
Man's soul and mind

Empty space tracks throughout
I make my claim

Darkness covers the world
My Kingdom, my Domain
*/

//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
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
#define eps 1e-6
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60

using namespace std;

vector<pair<long, long> > v;
long ps,usd[1000],n;
string st;
long calc[1000];
string ans;

int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>st;
cin>>n;
for (int i=0;i<st.size();i++)
calc[st[i]]++;
for (int i='a';i<='z';i++)
{v.push_back(make_pair(calc[i],i));}

sort(v.begin(),v.end());
ps=0;

while (ps<27&&n>=v[ps].first)
{ 
//      cout<<v[ps].first<<" "<<char(v[ps].second)<<endl;
 n-=v[ps].first;
 ps++;
}

for (int i=0;i<ps;i++)
usd[v[i].second]=1;

for (int i=0;i<st.size();i++)
{
    if (usd[st[i]]==0)ans+=st[i];
}
for (int i='a';i<='z';i++)
usd[i]=0;
for (int i=0;i<ans.size();i++)
usd[ans[i]]++;
long c=0;
for (int i='a';i<='z';i++)
if (usd[i])++c;
cout<<c<<endl;
cout<<ans<<endl;

cin.get();cin.get();
return 0;}