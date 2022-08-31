/*
Move with the storm, with the wind, with the flood
get down, rise up, hold on to the vibe
Move to the left, to the right, attraction, rejection
the floor we dance on is the firmament of our eyes
Creation transcends creator
Yes is the word to everything
to pain, to torture, to war and destruction
Yes is the word to everything
to liberty, to sweetness, to peace and construction
Choose, make up your mind before after is no more
time stops while another time is coming
the same leads back to the same
"Present is the time including all times
each second is eternity as eternity is now
and now is forever..."
Yes is the word to everything
to liberty, to sweetness, to peace and construction
Move with the stars, with the wave and with us
dance to the thunder beats, feel it all around
Jupiterian vibe
Move with the storm, with the wind, with the flood
Move with the stars, with the wave and with us
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

long n,a[200000],ps[200000],b[200000];
multiset<long> sett;
multiset<long>::iterator it;
long ans;

int main(){
//freopen("rush.in","r",stdin);
//freopen("rush.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=0;i<n;i++)
{
 cin>>a[i];
 ps[a[i]]=i;
}
for (int i=0;i<n;i++)
{
 cin>>b[i];
 sett.insert(i-ps[b[i]]);
}

for (int i=0;i<n;i++)
{
 ans=n;
 it=sett.lower_bound(i);
 if (it!=sett.end())ans=min(ans,(*it)-i);
 if (it!=sett.begin()){
                    it--;
                    ans=min(ans,i-(*it));
                    }
 cout<<ans<<endl;
 it=sett.find(i-ps[b[i]]);
 sett.erase(it);
 sett.insert(i-ps[b[i]]+n);
}

cin.get();cin.get();
return 0;}