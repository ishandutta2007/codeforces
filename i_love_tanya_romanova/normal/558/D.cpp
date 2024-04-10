/*
No more shall we pray for peace
Never ever ask them why
No more shall we stop their visions
Of selfdestructing genocide
Dogs on leads march to war
Go ahead end it all...

Blow up the world
The final silence
Blow up the world
I don't give a damn!

Screams of terror, panic spreads
Bombs are raining from the sky
Bodies burning, all is dead
There's no place left to hide
Dogs on leads march to war
Go ahead end it all...

Blow up the world
The final silence
Blow up the world
I don't give a damn!

(A voice was heard from the battle field)

"Couldn't care less for a last goodbye
For as I die, so do all my enemies
There's no tomorrow, and no more today
So let us all fade away..."

Upon this ball of dirt we lived
Darkened clouds now to dwell
Wasted years of man's creation
The final silence now can tell
Dogs on leads march to war
Go ahead end it all...

Blow up the world
The final silence
Blow up the world
I don't give a damn!
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
#define bsize 1024

using namespace std;

long long h,q,ml,mr,lev,l,r,tp;
vector<pair<long long, long long> > segs;
long long ans,aspan;
long long one=1;

int main(){
//freopen("blind.in","r",stdin);
//freopen("blind.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>h>>q;
ml=(one<<h)/2;
mr=(one<<h)-1;

for (int i=1;i<=q;i++)
{
    cin>>lev>>l>>r>>tp;
    l=l*(one<<(h-lev));
    r=(r+1)*(one<<(h-lev))-1;
    if (tp==1) // YES
    {
        ml=max(ml,l);
        mr=min(mr,r);
    }
    else
    {
        segs.push_back(make_pair(l,r));
    }
}
/*
for (int i=0;i<segs.size();i++)
{
    cout<<segs[i].first<<" "<<segs[i].second<<endl;
}
*/
segs.push_back(make_pair(1,ml-1));
segs.push_back(make_pair(mr+1,(one<<h)));
sort(segs.begin(),segs.end());

mr=(one<<h)/2-1;

for (int i=0;i<segs.size();i++)
{
    if (segs[i].first>mr+1)
    {
        ans=segs[i].first-1;
        aspan+=segs[i].first-mr-1;
    }
    mr=max(mr,segs[i].second);
}

if (aspan==0)
    cout<<"Game cheated!"<<endl;
else if (aspan>1)
    cout<<"Data not sufficient!"<<endl;
else
    cout<<ans<<endl;
    
//cin.get();cin.get();
return 0;}