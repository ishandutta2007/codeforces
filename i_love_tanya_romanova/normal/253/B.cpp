/*
You were born but you don't know why you're existing
You are unable why is it you and not me

Your parents they're shocked butstill they love you
You are their flesh and blood whatelse could they do

Not even modern medicine can help your tortured body
Hospitals are your world, doctors your friends
To keep your dreadful life

Other people never treat you like a normal human being
They often think you shouldn't be a part of their sick society

They smile at you but deep inside they think you shouldn't be here
Because they never ever realize, you got a heart and feelings too

People turn their heads
Whenever you walk by
Because they believe
You live a life without sense
Life without sense
Life without sense

If I'd be you, i might to commit suicide
But you're strong enough to live on
Because it's you and not me

If I'd be you, i might to commit suicide
But you're strong enough to live on
Because it's you and not me

People turn their heads
Whenever you walk by
Because they believe
You live a life without sense
Life without sense
Life without sense
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
#define eps 1e-8
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 250
#define clone agsdahfaassdg

using namespace std;

long n,q,r,ans;
vector<long> v;

int main(){
//freopen("bridges.in","r",stdin);
//freopen("bridges.out","w",stdout);
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>q;
    v.push_back(q);
}
sort(v.begin(),v.end());
r=0;
for (int i=0;i<v.size();i++)
{
    while (r+1<v.size()&&v[r+1]<=2*v[i])++r;
    ans=max(ans,r-i+1);
}

cout<<n-ans<<endl;

cin.get();cin.get();
return 0;}