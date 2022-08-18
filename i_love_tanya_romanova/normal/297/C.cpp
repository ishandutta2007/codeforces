/*
Did you ever believe in your dreams before
Were you always afraid of the dark
Is the edge of the world always in your head
Does the gun point straight at your heart

It used to come just when you sleep
But now, it's only a shout away

You always seem to find the sun
But this time, the sun is a fire
Bring down the rain
This house is burning again
Put out the flame
Bring down the rain

You were told that the storm would just roll on by
That the thunder was made in your mind
And the heat in the night was to keep you warm
And the truth could be told by a lier now

You always seem to find the light
But this time, the light is a fire
Bring down the rain
This house is burning again
Put down the flame
Bring down the rain

Shake up, break up, everybody make up
Everything's always the same
Trapped down, trapped down, everybody back down
Bring down the rain

You always seem to find the light
But this time, the light is a fire
Bring down the rain
This house is burning again
Don't play the game
Bring down the rain
Put out the flame
Bring down the rain

It's the shake up, break up, everybody make up
Well, it's always the same
Trapped down, cracked down, everybody back down
Won't you bring down all the rain
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
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

vector<pair<int, int> >v;
int n;
int a[1<<20];
int b[1<<20];
int q;

int main(){
//freopen("newlines.in","r",stdin);
//freopen("newlines.out","w",stdout);
//freopen("F:/input.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>q;
    v.push_back(make_pair(q,i));
}
sort(v.begin(),v.end());
for (int i=0;i<n/3;i++)
{
    int id=v[i].second;
    a[id]=i;
    b[id]=v[i].first-a[id];
}

for (int i=n/3;i<2*n/3;i++)
{
    int id=v[i].second;
    b[id]=i;
    a[id]=v[i].first-b[id];
}

for (int i=2*n/3;i<n;i++)
{
    int id=v[i].second;
    b[id]=n-i-1;
    a[id]=v[i].first-b[id];
}

cout<<"YES"<<endl;
for (int i=1;i<=n;i++)
{
    if (i>1)cout<<" ";
    cout<<a[i];
}
cout<<endl;
for (int i=1;i<=n;i++)
{
    if (i>1)cout<<" ";
    cout<<b[i];
}

//cin.get();cin.get();
return 0;}