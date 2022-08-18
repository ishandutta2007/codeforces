/*
Gather some people and build a country
You cannot force me to be happy and free
Gotta run away from where I was born to live
See the world while the world is watching me
National pride now I will follow you straight into death
Wait for me with a knife - Let the world see

Why am I born to be brother of Cain
Brother love ends in frustration
God loves me more than any other man
In a brother of Cain nation

Brother of Cain - Mother of pain
Brother of Cain - My way of dying

If being not free means peace
Then send me to prison
War comes with freedom
And life lacks of reason
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
#define bs 1000000007
#define bsize 512
#define right adsgasgadsg
#define free adsgasdg

using namespace std;

long answ,pref,lson[1<<22],rson[1<<22];
long ans[1<<22],lans[1<<22],rans[1<<22];
long ttl,n,a[1<<20];
vector<pair<long, long> > v;
long l,r,L,R,tests,T[1<<20];
long w;

void combine(long v,long l,long r)
{
 long m=l+r;
 m/=2;
 ans[v]=max(ans[lson[v]],ans[rson[v]]);
 ans[v]=max(ans[v],rans[lson[v]]+lans[rson[v]]);
 lans[v]=lans[lson[v]];
 if (lans[v]==m-l+1) lans[v]+=lans[rson[v]];
 rans[v]=rans[rson[v]];
 if (rans[v]==r-m) rans[v]+=rans[lson[v]];
}

long update(long root, long l,long r,long ps)
{
// cout<<"^^"<<ps<<" "<<l<<" "<<r<<" "<<root<<endl;
 long nroot=ttl+1;
 ++ttl;
 if (l==r)
 {
  lans[nroot]=rans[nroot]=ans[nroot]=1;
  return nroot;
 }
 long m=l+r;
 m/=2;
 if (ps<=m)
 {
  lson[nroot]=update(lson[root],l,m,ps);
  rson[nroot]=rson[root];
 }
 else
 {
  lson[nroot]=lson[root];
  rson[nroot]=update(rson[root],m+1,r,ps);
 }
 combine(nroot,l,r);
 return nroot;
}

void query(long rt,long l,long r,long L,long R)
{
 //cout<<rt<<" "<<l<<" "<<r<<" "<<L<<" "<<R<<" "<<ans[rt]<<" "<<lans[rt]<<" "<<rans[rt]<<" "<<pref<<" "<<answ<<" "<<l<<" "<<r<<endl;
 if (L<=l&&R>=r)
 {
  answ=max(answ,ans[rt]);
  answ=max(answ,pref+lans[rt]);
  if (lans[rt]==r-l+1)pref+=lans[rt];
  else pref=rans[rt];
  return;
 }
 long m=l+r;
 m/=2;
 if (R<=m){query(lson[rt],l,m,L,R);return;}
 if (L>m){query(rson[rt],m+1,r,L,R);return ;}
 query(lson[rt],l,m,L,m);
 query(rson[rt],m+1,r,m+1,R);
}

int main(){
//freopen("logins.in","r",stdin);
//freopen("logins.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>a[i];
    v.push_back(make_pair(a[i],i));
}

sort(v.begin(),v.end());
reverse(v.begin(),v.end());

for (int i=1;i<=n;i++) //PST
{
 T[i]=update(T[i-1],1,n,v[i-1].second);
// cout<<v[i-1].second<<"^"<<endl;
}
cin>>tests;
for (;tests;--tests)
{
    cin>>L>>R>>w;
    long l,r;
    l=1;
    r=n;
    while (l<r)
    {
     long mid=l+r;
     mid/=2;
     answ=pref=0;
     query(T[mid],1,n,L,R);
     //cout<<mid<<"  "<<answ<<endl;
     if (answ>=w)
      r=mid;
     else l=mid+1;
    }
    //cout<<"%"<<l<<endl;
    cout<<v[l-1].first<<endl;
}
cin.get();cin.get();
return 0;}