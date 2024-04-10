/*
A tearless stare
encased by fear
like a thread my heart is torn
and ripped right from my soul
with no control

Suits in disguise then fades to red
brings a blackened sky to fall
and make you very cold
while you grow old

Gone whithout a trace (gone)
it's left me chained and bound
my heart you thrust a dagger
my life and dreams are shattered
and left in tyranny

Rapture or pain
you spill my blood and take my life away
rapture or pain
all adversions still remain

You've realized
you're not alone
they've took your breath of life
and left your mind to unfold
lifeless and cold

Your thoughts erased
it's death you taste
your searing face
it hides the scars of love

Gone whithout a trace (gone)
it's left me chained and bound
my heart you thrust a dagger
my life and dreams are shattered
and left in tyranny

Rapture or pain
you spill my blood and take my life away
rapture or pain
all adversions still remain

Rapture or pain
you spill my blood and take my life away
rapture or pain
all adversions still remain
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

int n;
int ar[1<<20];
vector<pair<int, int> > v;
vector<int> ans;
int t[1<<20];

void inc(int i,int delta)
{
    for (;i<=n;i=(i|(i+1)))
        t[i]+=delta;
}

int sum(int r)
{
    int res=0;
    for (;r>=0;r=(r&(r+1))-1)
        res+=t[r];
    return res;
}

int main(){
//freopen("newlines.in","r",stdin);
//freopen("newlines.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>ar[i];
    v.push_back(make_pair(ar[i]+i,i));
}
/*for (int i=0;i<v.size();i++)
 cout<<v[i].first<<" ";
 cout<<endl;
*/sort(v.begin(),v.end());
/*for (int i=0;i<v.size();i++) 
 cout<<v[i].first<<" "<<v[i].second<<endl;
*/
for (int i=1;i<=n;i++)
 inc(i,1);
 
for (int i=0;i<v.size();i++)
{
    int id=v[i].second;
    int val=ar[id];
    val-=(n-id)-(sum(n)-sum(id));// moved fwd
    val+=sum(id-1);// pd
//  cout<<id<<"^"<<val<<endl;
    ans.push_back(val);
    inc(id,-1);
}

int er=0;
for (int i=0;i<ans.size();i++)
{
    if (ans[i]<0)er=1;
}
for (int i=1;i<ans.size();i++)
 if (ans[i]<ans[i-1])er=1;

if (er)cout<<":("<<endl;else{
for (int i=0;i<ans.size();i++)
{
    cout<<ans[i]<<" ";
}
cout<<endl;}

//cin.get();cin.get();
return 0;}