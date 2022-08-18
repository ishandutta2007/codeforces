/*
If eyes are the mirror of the soul
You will find in mine the scorn and apathy
You will read my hatred as in a curs'd book
You will see yourself as I see you
It is a mirror sombre and opaque
Which protects me, which stifles me
A great ditch around the heart
Which rejects, which estranges me
There is a world in my head
A dead world where nothing lives
And it is there I am, too far,
Far to far to be rejoined
A crown of thorns is still a crown
I am a king in a kingodm of suffering
I have taken my time to reach this stage
I have taken pains to tourture myself
To descend, to descend
Into Pain, I exist
An if my brain is numbed
The thorn in my flesh
Can overcome apathy
There is glory in humiliation
A throne to be taken, a crown to win
I have no more tears,
And my smile has lost its brilliance
I have forgotten who I was
I have killed my emotions
Crushed, empty, weary
Always standing, I am a tree
Awaiting the lightning
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