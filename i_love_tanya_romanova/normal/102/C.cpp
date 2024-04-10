/*
Funeral held for the depression of man
Holds the key to his own death
Entering a tomb of a corpse yet conceived
Tighten the tourniquet around your neck

Sifting away the debris of hated life
Cold touch of death begins to chill your spine
Seeking life beyond your perishment
Repeating words echoing through your mind

Chanting lines of blind witchery
To save yourself from extinction
Wanting to die is your reason to live
New life born from the oppressed

Taste your blood as it trickles through the air
Another casualty beyond the shadows you fall
Losing ground, the fate you feel it draws near
Fatality, reality, you await the final call

My sinful glare at nothing holds thoughts of death behind it
Skeletons in my mind commence tearing at my sanity
Vessels in my brain carry death until my birth
Come and die with me forever
Share insanity

Do you want to die!

The waves of blood are rushing near, pounding at the walls of lies
Turning off my sanity, reaching back into my mind
Non-rising body from the grave showing new reality
What I am, what I want, I'm only after death
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