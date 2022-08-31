/*
And if I say to you tomorrow. Take my hand, child, come with me. 
It's to a castle I will take you, where what's to be, they say will be. 

[Chorus:]
Catch the wind, see us spin, sail away, leave today, way up high in the sky. 
But the wind won't blow, you really shouldn't go, it only goes to show 
That you will be mine, by takin' our time. 

And if you say to me tomorrow, oh what fun it all would be. 
Then what's to stop us, pretty baby. But What Is And What Should Never Be. 

[Chorus]

So if you wake up with the sunrise, and all your dreams are still as new, 
And happiness is what you need so bad, girl, the answer lies with you. 

[Chorus]

Oh the wind wont blow and we really shouldn't go and it only goes to show. 
Catch the wind, we're gonna see it spin, we're gonna...sail, leave today 
do do do, bop bop a do-oh, my my my my my my yeah. 
Everybody I know seems to know me well
but they're never gonna know that I move like hell.
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
//#define bsize 250
#define clone agsdahfaassdg

using namespace std;

long n,m,cl[200000];
set<long> deg[200000];
long ans,answ,a,b;
long has[200000];

int main(){
//freopen("raydist.in","r",stdin);
//freopen("raydist.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
{
    cin>>cl[i];
    has[cl[i]]=1;
}
for (int i=1;i<=m;i++)
{
    cin>>a>>b;
    if (cl[a]==cl[b])continue;
    deg[cl[a]].insert(cl[b]);
    deg[cl[b]].insert(cl[a]);
//    cout<<a<<" "<<b<<" "<<cl[a]<<" "<<cl[b]<<endl;
}

ans=-1;

for (int i=1;i<=100000;i++)
{
    if (has[i]==0)continue;
//    cout<<i<<" "<<deg[i].size()<<endl;
    if (deg[i].size()+0ll<=ans+0ll)continue;
 //   cout<<"$"<<ans<<" "<<answ<<endl;
    ans=deg[i].size();
    answ=i;
}
//cout<<ans<<endl;
cout<<answ<<endl;

cin.get();cin.get();
return 0;}