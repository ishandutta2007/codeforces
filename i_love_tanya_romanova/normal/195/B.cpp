/*
Saint Anger 'round my neck
Saint Anger 'round my neck
He never gets respect
Saint Anger 'round my neck

[x2]
You flush it out, You flush it out
Saint Anger 'round my neck
You flush it out, You flush it out
He never gets respect

Fuck it all and no regrets
I hit the lights on these dark sets
I need a voice to let myself
To let myself go free
Fuck it all and fuckin' no regrets
I hit the lights on these dark sets
Medallion noose, I hang myself
Saint Anger 'round my neck

I feel my world shake
Like an earth quake
Hard to see clear
Is it me? Is it fear?

I'm madly in anger with you [x4]

Saint Anger 'round my neck
Saint Anger 'round my neck
He never gets respect
Saint Anger 'round my neck

[x2]
You flush it out, You flush it out
Saint Anger 'round my neck
You flush it out, You flush it out
He never gets respect

Fuck it all and no regrets
I hit the lights on these dark sets
I need a voice to let myself
To let myself go free
Fuck it all and fuckin' no regrets
I hit the lights on these dark sets
Medallion noose, I hang myself
Saint Anger 'round my neck

I feel my world shake
Like an earth quake
Hard to see clear
Is it me? Is it fear?

I'm madly in anger with you [x4]

And I want my anger to be healthy
And I want my anger just for me
And I need my anger not to control me
And I want my anger to be me

And I need to set my anger free [x4]

Set it free!

Fuck it all and no regrets
I hit the lights on these dark sets
I need a voice to let myself
To let myself go free
Fuck it all and fuckin' no regrets
I hit the lights on these dark sets
Medallion noose, I hang myself
Saint Anger 'round my neck

I feel my world shake
Like an earth quake
Hard to see clear
Is it me? Is it fear?

I'm madly in anger with you [x4]
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
//#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60

using namespace std;

long n,m,q;
vector<long> v;

bool cmp(long a,long b)
{
     if (abs(m+1-2*a)<abs(m+1-2*b))return true;
     if (abs(m+1-2*a)>abs(m+1-2*b))return false;
     if (a<b)return true;
     return false;
}

int main(){
//freopen("distance5.in","r",stdin);
//freopen("distance5.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;

for (int i=1;i<=m;i++)
{
    v.push_back(i);
}

sort(v.begin(),v.end(),cmp);
for (int i=0;i<n;i++)
cout<<v[i%m]<<endl;
cin.get();cin.get();
return 0;}