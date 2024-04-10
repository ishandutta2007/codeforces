/*
Only for the wind I lay myself down
Feeling this scarlet scent of death
Under ebony shades I dream of a child
Dancing in heaven, dancing in heaven

I must have seen this face before
A monument of shallow sorrows
Under ebony shades a child now dies
But grievance won't regain

Something grasp for my soul
I think it's God
But my sorrow is dragging me down
Through my sins

Where is God in his heaven?
Why am I a twisted mind?
Now I see the light above
But in darkness I must fall

For my soul you pray at last
Will I find my place?
The stench of sorrow that pierces my flesh
Can never be pure

When the blackness overwhelms me
Where shall I turn?
To run away to never look back
To run away from evil

Only for the wind I lay myself down
Feeling this scarlet scent of death
Under ebony shades I dream of a child
Dancing in heaven, dancing in heaven

I must have seen this face before
A monument of shallow sorrows
Under ebony shades a child now dies
But grievance won't regain

Dancing in heaven
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
//#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-13
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 2000

using namespace std;

long calc1[20000],calc2[2000];
long t,n,k,iter,m,bp;
vector<pair<long, long> > v1,v2,av;
long ans;
long tc;

int main(){
//freopen("ascii.in","r",stdin);
//freopen("ascii.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>k;
for (int i=1;i<=n;i++)
{
    cin>>t;
    calc1[t]++;
    calc2[t]++;
}

for (iter=1;iter<=n;iter++)
{
 v1.clear();v2.clear();

for (int i=1;i<=k;i++)
{
// cout<<calc1[i]<<" ";
 v1.push_back(make_pair(calc1[i],i));
 v2.push_back(make_pair(calc2[i],-i));
}
//cout<<endl;

 sort(v1.begin(),v1.end());
 sort(v2.begin(),v2.end());
 
// reverse(v1.begin(),v1.end());
 
 tc=v1[v1.size()-1].second;
 bp=-1;
 for (int j=0;j<v2.size();j++)
 if ((-v2[j].second)!=tc&&(v2[j].first)>0)bp=j;
// cout<<bp<<endl;
 if (bp==-1)
 {
  av.push_back(make_pair(v1[v1.size()-1].second,v1[v1.size()-1].second));
  calc1[v1[v1.size()-1].second]--;
  calc2[v1[v1.size()-1].second]--;
 }   
 
 else
 {
  av.push_back(make_pair(v1[v1.size()-1].second,-v2[bp].second));
  ++ans;
  calc1[v1[v1.size()-1].second]--;
  calc2[-v2[bp].second]--;
 }
}

cout<<ans<<endl;
for (int i=0;i<av.size();i++)
cout<<av[i].first<<" "<<av[i].second<<endl;

cin.get();cin.get();
return 0;}