/*
Help me write these words down
I'll write a great song to die to
'Cause my days are numbered
And it's certain that I'm gonna drag you

I don't plan on going alone
I need a friend like a typhoid, Mary
We'll walk with a goose step
With vigor and might that's scary

There I go
(Down)
And I'm lovin' it

Dig way deep in
Bid farewell to a world I can't live in
I scratched the surface
And found pride was paper thin

I tried evil
I wish it had more of and impact
'Cause faith ain't helping
To rid the apes on my back

After me come the flood
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
#define right adsgasgadsg
#define free adsgasdg
 
using namespace std;

string st1,st2;
long n,m,v1,v2,pen[100][200];
string tst1,tst2;
vector<pair<long, pair<string, long> > > ans;
string tst;
long num;

int main(){
//freopen("knockout.in","r",stdin);
//freopen("knockout.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>st1>>st2;
cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>m>>tst>>num>>tst1;
 if (tst=="h") 
  v1=0;
  else v1=1;
  if (pen[v1][num]>1)continue;
  if (tst1=="r")
   pen[v1][num]+=2;
   else pen[v1][num]+=1;
  if (pen[v1][num]>1)
  {
   if (v1==0)
    tst=st1;
    else tst=st2;
    ans.push_back(make_pair(m,make_pair(tst,num)));
  }
}

sort(ans.begin(),ans.end());
for (int i=0;i<ans.size();i++)
{
 cout<<ans[i].second.first<<" "<<ans[i].second.second<<" "<<ans[i].first<<endl;
}

cin.get();cin.get();
return 0;}