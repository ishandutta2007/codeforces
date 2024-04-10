/*
Consider your position position your defense
Why don't you let me ask you is it mere coincidence
Feeding speculators on a downhill gravy train
Like vultures ripping out the eyes to reach the dying brain

Listen to the wind - a silent scream
Tearing at your broken heart
Like a forgotten dream

And there's a time for peace a time for war
Wondering what we've been put here for
A time for giving a time to take
A time for love and a time for hate
A time for beg and a time to steal
So you gamble on that spinning wheel
Of all these things I've had my fill
Lord I need some time to kill

Ten percent of nothing is exactly what you got
You thing you've got the given right to take another shot
I'll take away your money all you've got is coloured beads
Find a piece of land where you can sow your seeds

Listen to the wind - a silent scream
Tearing at your broken heart
Like a forgotten dream

There's a time for passion a time for pain
A time to learn that we're all the same
A time to remember a time to forget
Wondering how we're going to pay our debts
A time for thunder a time for rain
Waiting for the seasons to change
Of all these things I've had my fill
Lord I need some time to kill
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
#define bsize 512

using namespace std;

int n,ar[1<<20];
vector<pair<int, int> >v;
int ans1[1<<20],ans2[1<<20];

int main(){
//freopen("blind.in","r",stdin);
//freopen("blind.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=0;i<n;i++)
{
    cin>>ar[i];
    v.push_back(make_pair(ar[i],i));
}
sort(v.begin(),v.end());
for (int i=0;i<v.size();i++)
{
    int id=v[i].second;
    ans1[id]=2e9;
    if (i)
        ans1[id]=min(ans1[id],abs(v[i].first-v[i-1].first));
    if (i+1<v.size())
        ans1[id]=min(ans1[id],abs(v[i+1].first-v[i].first));
    ans2[id]=max(v[i].first-v[0].first,abs(v[i].first-v.back().first));
}
for (int i=0;i<n;i++)
    cout<<ans1[i]<<" "<<ans2[i]<<endl;
    
//cin.get();cin.get();
return 0;}