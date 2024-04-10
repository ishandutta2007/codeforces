/*
There stood the fence that penned me in when I was younger
This was the house where we all stayed
There was a tree we used to hang out under
This was the place where I played
But now that's gone so I have to wonder
Is it worth the price we pay?
A long range test has put us under
And made us go away, go away...

This was the town where all my friends and I had grown up
The only place I've ever known
A long gray street with some houses built on it
Less than perfect but it was home
Now it's gone and I curse it in my darkness
This is the cross I have to bear
We pay the price of our own injustice
We made us go nowhere
Go nowhere, nowhere

This was our earth our garden of eden
Took what we could and left her there bleeding
And what became of the hopes and the dreams
Did they die with us 'cause that's how it seems
Here comes the rain can't you taste the acid?
Or has it left you numb?
This is the moral to the story I offer
Can you hear me son...
Or have you gone away
Away
Away
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

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1234567891
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg

using namespace std;

long long n,ar[1<<20];
pair<long long, long long> t[1<<20],tp,old[1<<20],nw[1<<20];
vector<pair<long long, long long> > v;
long long ps;
pair<long long, long long> ans;
long long sz,ttl;

pair<long long, long long> comb(pair<long long, long long> p1,
pair<long long, long long> p2)
{
 if (p1.first>p2.first)p2.second=0;
 if (p2.first>p1.first)p1.second=0;
 p1.first=max(p1.first,p2.first);
 p1.second+=p2.second;
 p1.second%=bs;
 if (p1.first==0)p1.second=1;
 return p1;
}

pair<long long ,long long >get(long v,long tl,long tr,long l,long r)
{
 if (l>r)return make_pair(0,1);
 if (tl==l&&tr==r)
 return t[v];
 long tm=tl+tr;
 tm/=2;
 pair<long long, long long> p1,p2;
 p1=get(v*2,tl,tm,l,min(r,tm));
 p2=get(v*2+1,tm+1,tr,max(l,tm+1),r);
 return comb(p1,p2);
}

void update(long v,long tl,long tr,long ps,pair<long long, long long> tp)
{
 if (tl==tr)
 {
  t[v]=tp;return;
 }
 long tm=tl+tr;
 tm/=2;
 if (ps<=tm)update(v*2,tl,tm,ps,tp);
 else update(v*2+1,tm+1,tr,ps,tp);
 t[v]=comb(t[v*2],t[v*2+1]);
}

int main(){
//freopen("digits.in","r",stdin);
//freopen("digits.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>ar[i];
}

for (int i=1;i<(1<<20);i++)
 t[i]=make_pair(0,1);

// pref
v.clear();
for (int i=1;i<=n;i++)
{
 v.push_back(make_pair(ar[i],-i));
}
sort(v.begin(),v.end());

for (int i=0;i<v.size();i++)
{
 ps=-v[i].second;
 tp=get(1,1,n,1,ps-1);
 tp.first++;
 update(1,1,n,ps,tp);
 old[ps]=tp;
}

//suf
reverse(v.begin(),v.end());
for (int i=1;i<(1<<20);i++)
 t[i]=make_pair(0,1);

for (int i=0;i<v.size();i++)
{
 ps=-v[i].second;
 tp=get(1,1,n,ps+1,n);
 tp.first++;
 update(1,1,n,ps,tp);
 nw[ps]=tp;
}

for (int i=1;i<=n;i++)
    ans=comb(ans,old[i]);

/*for (int i=1;i<=n;i++)
{
 cout<<i<<": "<<old[i].first<<" "<<old[i].second<<" "<<nw[i].first<<" "<<nw[i].second<<endl;
}
*/

//cout<<ans.first<<" "<<ans.second<<endl;

for (int i=1;i<=n;i++)
{
 sz=old[i].first+nw[i].first-1;
 ttl=(old[i].second*nw[i].second)%bs;
 if (sz<ans.first)
  cout<<1;
 else if (ttl!=ans.second)
  cout<<2;
  else cout<<3;
}
cout<<endl;
cin.get();cin.get();
return 0;}