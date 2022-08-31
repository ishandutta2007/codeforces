/*  
Gone...
We keep writing, talking and planning, but everything's changing.
We all know what to do but know one does it.
Now this time has passed and full of regret.
Two in my heart have left me a while, I stand alone.
When they get back, it won't be the same.
My life, you've always been there.
Now you're gone and my heads spinning.
Left the childhood, left the memories, left the good times in the past.
Moving on your time has run out.
Wishing the clock would stand still, the world can wait.
Wasting away once again, once lived as friends.

As time passes by, regrets for the rest of my life.
The ones who I confide were gone in the black of the night.

Never will I forget you, and all the memories past.
So rarely I get to see your face.
Growing I looked to you in guidance.
We knew that time would kill us, but you're still so close to me.

To me you were my life.
To me you were my soul companion.
Now you are so far away.
Nothing can take away the time and the memories we had.
Come back - to the days when we were young
Come back - to the days when nothing mattered.
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
#define eps 1e-9
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 3
#define clone agsdahfaassdg
using namespace std;

long n,x[5000],y[5000];
vector<pair<long,pair<long, long> > > v;

long ar[5000][110];
long span,t1,t2,ans;

void add_edge(long a,long b)
{
     ar[a][b/30]|=(1<<(b%30));
}

bool ok(long a,long b)
{
 for (int i=0;i<=100;i++)
 if (ar[a][i]&ar[b][i])return true;
 return false;
}

int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
cin>>x[i]>>y[i];

for (int i=1;i<=n;i++)
for (int j=i+1;j<=n;j++)
{
    v.push_back(make_pair((y[i]-y[j])*(y[i]-y[j])+(x[i]-x[j])*(x[i]-x[j]),make_pair(i,j)));
}

sort(v.begin(),v.end());
reverse(v.begin(),v.end());

for (int i=0;i<v.size();i++)
{
 span=v[i].first;
 t1=v[i].second.first;
 t2=v[i].second.second;
 if (ok(t1,t2)){ans=span;break;}   
 add_edge(t1,t2);
 add_edge(t2,t1);
}
cout.precision(10);
//cout<<ans<<endl;
cout<<fixed<<sqrt(1.0*ans)/2<<endl;

cin.get();cin.get();
return 0;}