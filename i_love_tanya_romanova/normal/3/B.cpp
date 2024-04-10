/*
Convictions, lost direction

Once a fielded dream
Controlled by the heat within
Cold could not withstand
Pressure to keep the sky in my hand

Now a failing breeze
Grabs a hold and pulls me down
Hands have turned to clay
Gripping the hope that lives inside

I move on praying for a way
To save my own will
Time falls whisked away
With each breath I take

Falling into time a waste, an endless torture
Sealing a fate of nothing
Dark times how do I conquer
A life now chains

Go onward is the only method
Forget the pain and face our progression on
Survival is vital in pain we succeed
How did I lose convictions?

Lost direction

Try to find a hold
Certain steps are led astray
Seems no other space
Forcing me out there's not enough time

Now it's time to bring
All I know to help me win
Efforts have gone to hell
Crushing my will to act as the lead

Failed, fault, lost, now climb

Push away
Fading terms that burn the skin
Saved till now
Haunts me in each step I take

Times have changed
Overload is bearing down
Face each day
Circled by what I should have done

Dive, crime, loss, give into time and fall

Procrastination, fail to follow through
With all I must do
Days they fall in shame, I slip in deeper
Confined by the weight that overbears
Stood tall but killed in it's nature
Forced steps I do not care what's there

They can see it in my eyes
I can feel it in my eyes
They can see it in my eyes
I can feel it in my eyes

Time lies, I am falling further down
I've tried, but landing is hard, fallen chance
Another lesson, I'll give it all I can
Another lesson, I gave it all I could
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

long n,v,tp,c;
vector<long> vec[5];
long s1[200000],s2[200000],bst,bp;
long rem,tc;
vector<long> ans;
vector<pair<long, long> > vec1[10];

int main(){
//freopen("rush.in","r",stdin);
//freopen("rush.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>v;
for (int i=1;i<=n;i++)
{
 cin>>tp>>c;
 vec[tp-1].push_back(c);
 vec1[tp-1].push_back(make_pair(c,i));
}
sort(vec[0].begin(),vec[0].end());
sort(vec[1].begin(),vec[1].end());
reverse(vec[0].begin(),vec[0].end());
reverse(vec[1].begin(),vec[1].end());

sort(vec1[0].begin(),vec1[0].end());
sort(vec1[1].begin(),vec1[1].end());
reverse(vec1[0].begin(),vec1[0].end());
reverse(vec1[1].begin(),vec1[1].end());

for (int i=1;i<=vec[0].size();i++)
 s1[i]=s1[i-1]+vec[0][i-1];
for (int i=1;i<=vec[1].size();i++)
 s2[i]=s2[i-1]+vec[1][i-1];

bst=-1e9;
bp=0;
for (int i=0;i<=vec[1].size();i++)
{
 if (i*2>v)break;
 rem=v-i*2;
 tc=s2[i];
 if (rem>vec[0].size())rem=vec[0].size();
 tc+=s1[rem];
 if (tc>bst)
 {
  bst=tc;
  bp=i;
 }
}

cout<<bst<<endl;

rem=v-bp*2;
for (int i=0;i<bp;i++)
 ans.push_back(vec1[1][i].second);

if (rem>vec[0].size())rem=vec[0].size();
for (int i=0;i<rem;i++)
 ans.push_back(vec1[0][i].second);

for (int i=0;i<ans.size();i++)
{
 if (i)cout<<" ";
 cout<<ans[i];
}
cout<<endl;

cin.get();cin.get();
return 0;}