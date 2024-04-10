/*
Evil minds bend on destruction
Ignoring the pleas of their race
Final chapter in humanic abduction
All signs of society erased

People asking fewer questions
Letting politicians do their thinking
Not questioning nuclear judgment
As warheads enter our space

Our atmosphere clouded with poison
Killing ourselves to live
Filling the world with hate and dissention
We'll have only our lives to give

What we do now is the key to the future
Have only ourselves to blame
For arming the world with the tools of destruction
Our ignorance means death

Warring on opposite nations
Starvation amongst impoverished nations
Outlook bleak for the world residue
Ignorance of mankind

Clouding the world with residue
Of man's toxic industry
Slowly killing nameless victims
Whose ignorance leaves them dead

Our atmosphere clouded with poison
We're killing ourselves to live
Filling the world with hate and dissention
We'll have only our lives to give

What we do now is the key to the future
We'll only have ourselves to blame
For arming the world with the tools of destruction
Our ignorance means death

We're crowded with anger inventions of danger
From man's diabolical mind
Humanities dying no use in trying
It's only a matter of time

How long will it be before there's no air to breathe
And our water is polluted water
Ignorance runs rampant noone is caring
Suicide of the human race

Ignorance
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

using namespace std;

int n,a[1<<20],b[1<<20];
vector<int> v;
map<int, int> mapp,rmap;
int cnt;
int ar[1<<20];
int t[1<<20];
long long ans;
int ps[1<<20];
int temp;
int ttl;

int sum (int r)
{
    int result = 0;
    for (; r >= 0; r = (r & (r+1)) - 1)
        result += t[r];
    return result;
}

void inc (int i, int delta)
{
    for (; i <= cnt; i = (i | (i+1)))
        t[i] += delta;
}

int sum (int l, int r)
{
    return sum (r) - sum (l-1);
}

int main(){
//freopen("k.in","r",stdin);
//freopen("k.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>a[i]>>b[i];
    v.push_back(a[i]);
    v.push_back(b[i]);
}

sort(v.begin(),v.end());
for (int i=0;i<v.size();i++)
{
    if (i>0&&v[i]==v[i-1])continue;
    mapp[v[i]]=cnt;
    rmap[cnt]=v[i];
    ++cnt;  
}

//cout<<"^"<<cnt<<endl;

for (int i=0;i<cnt;i++)
{
    ar[i]=i;
}

for (int i=1;i<=n;i++)
{
    a[i]=mapp[a[i]];
    b[i]=mapp[b[i]];
    swap(ar[a[i]],ar[b[i]]);
}

for (int i=0;i<cnt;i++)
{
    ps[ar[i]]=i;
}

for (int i=0;i<cnt;i++)
{
    temp=ps[i];
    ans+=sum(cnt)-sum(temp);
    inc(temp,1);
    if (ar[temp]==temp)continue;
    if (ar[temp]<temp) // lg left
    {
    ttl=rmap[temp]-rmap[ar[temp]];
    ttl-=(temp-ar[temp]);
    ans+=ttl;
    }
    else
    {
    ttl=rmap[ar[temp]]-rmap[temp];
    ttl-=(ar[temp]-temp);
    ans+=ttl;
    
    }
//  cout<<i<<" "<<temp<<" "<<ar[temp]<<endl;
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}