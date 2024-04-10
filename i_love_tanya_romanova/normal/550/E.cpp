/*
This era, this music, this scene
Our great monument to nothing
This glory, this sweat, this play
Makes no difference what we say
For every man stands a ghost
For every ghost stands a star
For every star stands a thought
And these accumulate somewhere
If God is the personification
Of the total of man's thought
Then I must be the reflection
Of all you have fought
This era, this music, this scene
Our great monument to nothing
This glory, this sweat, this play
makes no difference what we say
Look into a place that you dare not look
You'll find me staring back at you
A perfect reflection
Your mirror
Your representative
I am you
Here we stand all as one
Nothing said as we are done
But no matter what we do
We're together, me and you
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
#define bsize 256

using namespace std;

int n,ar[1<<20];

int main(){
//freopen("newlines.in","r",stdin);
//freopen("newlines.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
 cin>>ar[i];

int cnt=0;
for (int i=n;i;--i)
{
    if (ar[i]==0)
        cnt++;
    else break;
}

if (cnt%2==1)
{
    cout<<"YES"<<endl;
    if (cnt<n)
    {
        cout<<"(";
    }
    for (int i=1;i<=(n-cnt);i++)
    {
        if (i>1)
        cout<<"->";
        cout<<ar[i];
    }
    if (cnt<n)
    cout<<")";
    
    for (int i=n-cnt+1;i<=n;i++)
    {
        if (i>1)cout<<"->";
        cout<<ar[i];
    }
    cout<<endl;
}
else if (cnt==2)
{
    int found=0;
    for (int i=1;i<(n-cnt);i++)
        if (ar[i]==0)
            found=i;
    if (found==0)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    
    cout<<"YES"<<endl;
    int q=found;
    while (ar[q-1]==0&&q>1)
        --q;
    
    for (int i=1;i<q;i++)
    {
        if (i>1)cout<<"->";
        cout<<ar[i];
    }
    if (q>1)
    
    cout<<"->";
    cout<<ar[q];
    cout<<"->";
    cout<<"(";
    cout<<"(";
    for (int i=q+1;i<=n-cnt;i++)
    {
        if (i>q+1)cout<<"->";
        cout<<ar[i];
    }
    cout<<")";
    cout<<"->";
    cout<<0;
    cout<<")";
    for (int i=n-cnt+2;i<=n;i++)
    {
        cout<<"->";
        cout<<ar[i];
    }
    cout<<endl;
}
else if (cnt>=4)
{
    cout<<"YES"<<endl;
    for (int i=1;i<=n-4;i++)
    {
        if (i>1)cout<<"->";
        cout<<ar[i];
    }
    if (n>4)cout<<"->";
    cout<<"(0->(0->0))->0"<<endl;
}
else
{
    cout<<"NO"<<endl;
}
//cin.get();cin.get();
return 0;}