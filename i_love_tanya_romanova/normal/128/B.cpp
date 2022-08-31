/*
Like the last of the Mohicans
You acted like bloody pagans
Let the bells ring
Rejoice and sing

Jim Jones, where did you come from
Jim Jones, Was it for fun
Jim Jones, That's your name
Jim Jones, a silent death

Religious sects and promised lands
Are you ready for the gods?
Martyrs, killers holding hands
Do not fight the odds
The dying angel said drink up
Be merry and be dead

Jim Jones where did you come from
Jim Jones was it for fun?
Jim Jones that's your name
Jim Jones you died for fame

Murder
Murder
Murder
The Zero Hero

Walk on them like insects
Gamble with death for a joke
Mercenary disciples
With bibles and rifles
In temple of people
A doomsday book of evil
No Poster hanging high

I die, you die don't ask why
I die, you die don't ask why
I die, you die don't ask why
I die, you die don't ask why
I die, you die don't ask why
I die, you die don't ask why
I die, you die don't ask why
I die, you die don't ask why

why ah ha, ha, ha, ha
oh lord you Die
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

using namespace std;

string st;
long n,k;
string s;
set<pair<string, long> > sett;
set<pair<string, long> > ::iterator it;
pair<string, long> tt;

int main(){
//freopen("rush.in","r",stdin);
//freopen("rush.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>st;
n=st.size();
cin>>k;

if (1ll*n*(n+1)/2<k)
{
 cout<<"No such line."<<endl;
 return 0;
}

for (int i=0;i<n;i++)
{
 s="";
 s+=st[i];
 sett.insert(make_pair(s,i));
}

--k;
for (;k;--k)
{
 it=sett.begin();
 tt=(*it);
 sett.erase(it);
 if (tt.second!=n-1)
 {tt.second++;tt.first+=st[tt.second];sett.insert(tt);}
}

it=sett.begin();
cout<<(*it).first<<endl;

cin.get();cin.get();
return 0;}