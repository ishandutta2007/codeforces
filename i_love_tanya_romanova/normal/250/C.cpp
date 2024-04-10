/*
One night when the stars were right
For the gypsy queen
And she found she could drog you down
To a place that's in - between it all she's a
Madman with a delicate hand and evil eyes
And I've heard she'll only say a word
And that's enough to satisfy

Don't ask why
Don't even think about it
Brave men die
But what a way to go

She's not above
Death by love

One spell from the wishing well
And you're nevermore
Bad start for the sacred heart
Cause the end has come before the beginning

Knee deep in the darkest sleep
But the eyes see all
So high you could break the sky
And never feel the fall to come

Strong men die
But what a way to go

She's not above
Death by love

Don't ask why
Don't even think about it
Brave men die
But what a way to go

You've got symptoms of
Death by love
She's not above
Death by love

Don't ask why
Don't even guess about it
All men die
But this is death by love
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
#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-6
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
//#define bsize 250
#define clone agsdahfaassdg

using namespace std;

long n,k,ar[200000];
vector<long> v;
long ans[200000];
long bp,bans;

int main(){
//freopen("experimental.in","r",stdin);
//freopen("experimental.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>k;
for (int i=1;i<=n;i++)
{
 cin>>ar[i];
 if (i==1||ar[i]!=ar[i-1])
 v.push_back(ar[i]);   
}

for (int i=0;i<v.size();i++)
{
 if (i>0&&i+1<v.size()&&v[i-1]==v[i+1])
 ans[v[i]]+=2;
 else ans[v[i]]+=1;
}

/*for (int i=1;i<=5;i++)
cout<<ans[i]<<endl;
*/
bans=-1;

for (int i=1;i<=k;i++)
{
    if (ans[i]>bans){bans=ans[i];bp=i;}
}

cout<<bp<<endl;

cin.get();cin.get();
return 0;}