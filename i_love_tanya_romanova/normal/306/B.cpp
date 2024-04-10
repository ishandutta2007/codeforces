/*
Dancing violet dreams.
Joining nights of satin fame.
Acting jewel games.
All forgiven, you streak my heart.
More than pleasure in ice cold flames.
Crying soft, as love flies tame.
Swelling tears in diaries of lies.
Fading lights, as songs die quiet.
Bleeding sweet for dying blind.
Masking fears of silent decline.

Cherry Orchards. Ginger looks upon pain.
Cherry Orchards. August fades like tears in vain.

Winter's final shine. Dressing gold, one last time.
Seep from lace. Roses for an unborn face.

Cherry Orchards. Ginger looks upon pain.
Cherry Orchards. August fades like tears in vain.
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
#define bsize 256

using namespace std;

long n,m,a,b;
vector<pair<pair<long, long>, long>  > v;
vector<long> ans;
long temp,r;
long tr,id,arp[2000000];//,usd[200000];

int main(){
//freopen("evacuate.in","r",stdin);
//freopen("evacuate.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
for (int i=1;i<=m;i++)
{
    cin>>a>>b;
    v.push_back(make_pair(make_pair(a,-a-b+1),i));
}

sort(v.begin(),v.end());

r=0;

long ii=0;
while (ii<m)
{
 tr=r;id=-1;
 while (ii<m&&v[ii].first.first<=r+1)
 {
  if (tr<-v[ii].first.second){tr=-v[ii].first.second;id=v[ii].second;}
   ++ii;
 }
 if (id+1){r=tr;arp[id]=1;}
 else ++r;
}

for (int i=1;i<=m;i++){
if (arp[i]==0){ans.push_back(i);//cout<<i<<endl;
}
}

//sort(ans.begin(),ans.end());

cout<<ans.size()<<endl;
for (int i=0;i<ans.size();i++)
{
    if (i)cout<<" ";
    cout<<ans[i];
}
cout<<endl;

cin.get();cin.get();
return 0;}