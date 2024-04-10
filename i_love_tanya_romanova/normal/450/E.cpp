/*
One wish alone have I
In some calm land beside the sea to die

Upon its strand
That I forever sleep
The forest near, a heaven near
Stretched over the peaceful deep

No candles shine
A tomb I need, instead
Let them form me a bed
Of twigs entwine

That no one weeps my end
Nor for me grieves
But let the autumn lend
Tongues to the leaves

When brooklet ripples fall
With murmuring sound
And moon is found
Among the pine trees tall

In solitude

As I will then no more a wanderer be
Let them with fondness store my memory

And Lucifer the while
Above the pine, good comrade mine

Will on me gently smile?
In mournful mood
The sea sing sad refrain...
And I be earth again

In solitude

That no one weeps my end
Nor for me grieves
But let the autumn lend
Tongues to the leaves

When brooklet ripples fall
With murmuring sound
The seven moon is found
Among the pine trees tall

In solitude

While softly rings
The wind is trembling chime
And over me the lime
In blossom flings

(In mournful mood
The sea sing sad refrain
And I be earth again
In solitude)

That no one weeps my end
Nor for me grieves
But let the autumn lend
Tongues to the leaves

When brooklet ripples fall
With murmuring sound
The seven moon is found
Among the pine trees tall

I'm in solitude
Oh, I be earth again (in solitude)
In solitude
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
//#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
//#define N 120000

using namespace std;

long n;
long pr[300000];
vector<pair<long, long> > ans;
vector<long> vec;
long used[300000];
long calc[2000];

int main(){
//freopen("path.in","r",stdin);
//freopen("path.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
pr[1]=1;
for (int i=2;i<=100000;i++)
 if (pr[i]==0)
  for (int j=i*2;j<=100000;j+=i)
   pr[j]=1;

for (int i=3;i*2<=n;i++)
 if (pr[i]==0)
 {
  vec.clear();
  for (int j=i;j<=n;j+=i)
  {
   if (used[j]==0)
    vec.push_back(j);
  }
  if (vec.size()%2)
  {
   vec.erase(vec.begin()+1,vec.begin()+2);
  }
  /*for (int j=0;j<vec.size();j++)
   cout<<vec[j]<<"% ";
   cout<<endl;
  */for (int j=0;j<vec.size();j+=2)
  {
   ans.push_back(make_pair(vec[j],vec[j+1]));
   used[vec[j]]=used[vec[j+1]]=1;
  }
 }

vec.clear();

for (int i=2;i<=n;i++)
{
 if (used[i]==0&&i%2==0)
  vec.push_back(i);
}
 
  for (int j=0;j+1<vec.size();j+=2)
  {
   ans.push_back(make_pair(vec[j],vec[j+1]));
   used[vec[j]]=used[vec[j+1]]=1;
  }

/*for (int i=0;i<ans.size();i++)
 calc[ans[i].first]++,calc[ans[i].second]++;

for (int i=1;i<=100;i++)
 if (calc[i]>1)cout<<"%"<<i<<endl;
 */
cout<<ans.size()<<endl;
for (int i=0;i<ans.size();i++)
 cout<<ans[i].first<<" "<<ans[i].second<<endl;
 
cin.get();cin.get();
return 0;}