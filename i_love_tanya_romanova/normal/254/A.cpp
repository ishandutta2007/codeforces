/*
I'm crawling through the shadows of the underworld
I'm creeping like a creature through the dark
There's something moving slowly, down below
The beast is on the verge to take away my soul
I'm lost, I fall

Lust and strange desires
Screaming kills all my pain
Dust of raging fires
There comes the night again

Blasting pounds of thunder
Are shaking up the ground
Lost, I'm going under
And then the night is closing in

Come my guardian angel, come my guardian angel
Right to my side
I can hear the demons laughter, far through the night
The one who breaks the spell

The darkness, the darkness comes
The darkness, the darkness comes again

Flashing tongues of fire
Are slicing through the air
Clash, Fuck, I retire
Heat is rising everywhere

Crashing rays of lightning
Clouds of heavy rain
Lost, I'm going under
And then the night is closing in

All I need's a wonder, all I need's a wonder
Right by my side
You will see me going under, lost in the night
When all my power fails

The darkness, the darkness comes
The darkness, the darkness comes again

The darkness comes, it comes
The devil on the throne
All I need's a wonder
Now, it comes

The darkness, the darkness comes
The darkness, the darkness comes again
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
//#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-10
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
#define MAXN 10000
//#define SIZE 60
#define bsize 256

using namespace std;

long n,q;
vector<pair<long,long> > v;
long fl;

int main(){
//freopen("transform.in ","r",stdin);
//freopen("transform.out","w",stdout);
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
n*=2;
for (int i=0;i<n;i++)
{
 cin>>q;
 v.push_back(make_pair(q,i+1));
}
sort(v.begin(),v.end());
for (int i=0;i<v.size();i++)
{
 if (i%2==1&&v[i].first!=v[i-1].first)fl=1;
}
if (fl)cout<<-1<<endl;
else
{
    for (int i=0;i<v.size();i+=2)
    cout<<v[i].second<<" "<<v[i+1].second<<endl;
}
cin.get();cin.get();
return 0;}