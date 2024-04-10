/*
Take a minute just to breathe
Take a minute 'till I'm wide awake
I'm searching' once again
And the sun has left the sky

And you're on my mind
And you're on my mind

Take a second to believe
Just a second you won't have to wait
Don't you turn your back on me
I couldn't look into your eyes

And I don't know why and I don't know why
But I'll try again on another day

You make my mind
Just wanna leave this world behind
You make my mind, you make my mind

Let the silence creep in
(Let the silence creep in)
In the silence I'm awake all night
Just searching once again
(Searching once again)
Well could I reach you in the morning light

If I closed my eyes, if I closed my eyes
Well you're here right away

You make my mind
Just wanna leave this world behind
You make my mind, you make my mind

You're on my mind
I'll try again on another day

And I don't know why and I don't know why
If I close my eyes, if I close my eyes
Well you're here right away

You make my mind
Just wanna leave this world behind
You make my mind
Just wanna leave this world behind
You make my mind, you make my mind

You make my mind, make my mind
You make my mind, make my mind
You make my mind, make my mind
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