/*
It's snowing outside the rumbling sound
of engines roar in the night,
The mission is near the confident men
are waiting to drop from the sky.

The Blizzard goes on but still they must fly
No one should go where eagles dare.

Bavarian alps that lay all around
they seem to stare from below,
The enemy lines a long time passed
are lying deep in the snow.

Into the night they fall through the sky
No one should fly where eagles dare.

They're closing in the fortress is near
it's standing high in the sky,
The cable car's the only way in
it's really impossible to climb.

They make their way but maybe too late
They've got to try to save the day.

The panicking cries the roaring of guns
are echoing all round the valley,
The mission complete they make to escape
away from the Eagles Nest.

They dared to go where no one would try
they chose to fly where eagles dare.
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
 
#define  INF 100000000
#define eps 1e-11
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60

using namespace std;

long n,k,q;
vector<pair<long, long> > v;

int main(){
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>k;
for (int i=1;i<=n;i++)
{
    cin>>q;v.push_back(make_pair(q,i));
}
sort(v.begin(),v.end());
reverse(v.begin(),v.end());
cout<<v[k-1].first<<endl;
for (int i=0;i<k;i++)
{
    if (i)cout<<" ";
    cout<<v[i].second;
}
cout<<endl;

cin.get();cin.get();
return 0;}