/*
Came to the sunset scene
To find out who's inside of me
Some lies I've never seen
But this one lies on the silver screen
In between real and dream
Like a scream

Hollywood black
I'm caught in the middle
Hollywood black

Same story, different eyes
Here's where the hero never, never dies
Can't you tell
That all the wishes you've made
Have filled up the well

Hollywood black
Caught in the middle
Hollywood black
Yeah
Oh, Hollywood black
Right in the middle
Too late to little

Back to the street again
Or was that yesterday
Another yesterday's gone, gone

Back in the jungle
Running with the animals
Howling at the sign of the spotlight
Ooh

Those dreams are made of glass
You throw just one stone
And then there goes your last window
Can't you tell
That every wish that you made
Filled up the well

Hollywood black
Caught in the middle
Hollywood black

Hollywood black
Right in the middle
Ah, Hollywood black
Hollywood black
Caught in the middle
Too late to little
And only the fools come back
'Cause Hollywood is black
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

int n,tests;
string st,S;
int P[1<<20],start[1<<20];
int sz[1<<20];
int pw[1<<20];
int H[1<<20];
int old;
vector<int> v;
vector<int> T[1<<21];
int hh[20][1<<20];

void build(int V,int l,int r)
{
    if (l==r)
    {
        T[V].push_back(P[v[l]]);
        return;
    }
    int tm=l+r;
    tm/=2;
    build(V*2,l,tm);
    build(V*2+1,tm+1,r);
    int p1,p2;
    p1=p2=0;
    while (p1<T[V*2].size()||p2<T[V*2+1].size())
    {
        if (p2==T[V*2+1].size())
        {
            T[V].push_back(T[V*2][p1]);
            ++p1;
        }
        else if (p1==T[V*2].size())
        {
            T[V].push_back(T[V*2+1][p2]);
            ++p2;
        }
        else if (T[V*2][p1]<T[V*2+1][p2])
        {
            T[V].push_back(T[V*2][p1]);
            ++p1;
        }
        else
        {
            T[V].push_back(T[V*2+1][p2]);
            ++p2;
        }
    }
}

int gh(int a,int span)
{
    int val=H[a+span];
    val-=H[a];
    if (val<0)val+=bs;
    val=1ll*val*pw[(1<<19)-a]%bs;
    return val;
}

int get(int v,int tl, int tr, int l,int r,int bound)
{
    if (l>r) return 0;
    if (tl==l&&tr==r)
    {
        int L,R;
        if (T[v][0]>bound)return 0;
        L=0;
        R=T[v].size()-1;
        if (T[v][R]<=bound)return R+1;
        while (L<R)
        {
            int m=L+R+1;
            m/=2;
            if (T[v][m]<=bound)L=m;
            else R=m-1;
        }
        return L+1;
    }
    int tm=tl+tr;
    tm/=2;
    return get(v*2,tl,tm,l,min(r,tm),bound)+get(v*2+1,tm+1,tr,max(tm+1,l),r,bound);
}

int ulog[1<<20];

int CMP(int ps1, int ps2, int span)
{   
    if (ps1==ps2)
        return 0;
    if (S[ps1]!=S[ps2])
    {   
    for (int i=0;i<=0;i++)
    {
        if (S[ps1+i]>S[ps2+i])return 1;
        if (S[ps1+i]<S[ps2+i])return -1;
    }
    }
    
    for (int i=ulog[span];i+1;--i)
    {
        if (span==0)return 0;
        if (S[ps1]>S[ps2])return 1;
        if (S[ps1]<S[ps2])return -1;
        if ((1<<i)>span)continue;
        if (hh[i][ps1]==hh[i][ps2])
        {
            span-=(1<<i);
            ps1+=(1<<i);
            ps2+=(1<<i);
        }
    }
    if (span==0)return 0;
    
    for (int i=0;i<=0;i++)
    {
        if (S[ps1+i]>S[ps2+i])return 1;
        if (S[ps1+i]<S[ps2+i])return -1;
    }
    return 0;
}


bool cmp(int a,int b)
{
    int rem=n+1-max(a,b);
    return (CMP(a,b,rem)==-1);
}

int s[1<<20];
int cnt[1<<20],p[1<<20];
int c[1<<20],c1[1<<20],classes;
int pn[1<<20];
int mid1,mid2;
int cn[1<<20];
int ent[1<<20];
int did[1<<20];
int memps1[1<<20],memps2[1<<20];

bool X(int a,int b)
{
    return c[a]<c[b];
}

int main(){
//freopen("newlines.in","r",stdin);
//freopen("newlines.out","w",stdout);
//freopen("F:/input.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
//ios_base::sync_with_stdio(0);
//cin.tie(0);

for (int i=1;i<(1<<19);i++)
 ulog[i]=ulog[i/2]+1;
 
cin>>n>>tests;
for (int i=1;i<=n;i++)
{
    cin>>st;
    S+=st;
    S+="#";
    for (int j=old;j+1<S.size();j++)
        P[j]=i;
    start[i]=old;
    sz[i]=st.size();
    old=S.size();
}

pw[0]=1;
for (int i=1;i<(1<<20);i++)
 pw[i]=1ll*pw[i-1]*173%bs;

for (int i=1;i<=S.size();i++)
    H[i]=(H[i-1]+1ll*S[i-1]*pw[i])%bs;

for (int i=0;i<S.size();i++)
{
    v.push_back(i);
}

n=v.size();
/*
if (n>100&&tests==500000)
{
    cout<<clock()*1.0/CLOCKS_PER_SEC<<endl; 
}*/


for (int i=0;i<=n;i++)
 hh[0][i]=S[i];

for (int lev=1;lev<=19;lev++)
 for (int i=0;i<=n;i++)
  hh[lev][i]=(1ll*hh[lev-1][i]*pw[(1<<lev)/2]+hh[lev-1][i+(1<<lev)/2])%bs;
  /*
if (n>100&&tests==500000)
{
    cout<<clock()*1.0/CLOCKS_PER_SEC<<endl; 
}*/

 
 // SUF
 
for (int i=0;i<n;i++)
 s[i]=S[i]-30;
 
for (int i=0;i<n;i++)
 ++cnt[s[i]];

for (int i=1;i<100;i++)
 cnt[i]+=cnt[i-1];

for (int i=0;i<n;i++)
{
 p[--cnt[s[i]]]=i;
}

c[p[0]]=0;
classes=1;

for (int i=1;i<n;i++)
{
 if (s[p[i]]!=s[p[i-1]])++classes;
 c[p[i]]=classes-1;
}
/*
for (int i=0;i<n;i++)
 cout<<c[i]<<" ";
 cout<<endl;
 */
for (int h=0;(1<<h)<n;++h)
{
 for (int i=0;i<n;i++)
 {
  pn[i]=p[i]-(1<<h);
  if (pn[i]<0)pn[i]+=n;
 }   
 for (int i=0;i<=classes;i++)
  cnt[i]=0;
 for (int i=0;i<n;i++)
  cnt[c[pn[i]]]++;
 for (int i=1;i<=classes;i++)
  cnt[i]+=cnt[i-1];
 for (int i=n-1;i>=0;--i)
  p[--cnt[c[pn[i]]]]=pn[i];
 cn[p[0]]=0;
 classes=1;
 for (int i=1;i<n;i++){
 mid1=p[i]+(1<<h);
 mid2=p[i-1]+(1<<h);
 mid1%=n;mid2%=n;
 if (c[p[i]]!=c[p[i-1]]||c[mid1]!=c[mid2])
  ++classes;
  cn[p[i]]=classes-1;}
  
 for (int i=0;i<=n;i++)
 c[i]=cn[i];
}
/*
for (int i=0;i<n;i++)
 cout<<c[i]<<" ";
*/
// suf array
sort(v.begin(),v.end(),X);
for (int i=0;i<v.size();i++)
 ent[v[i]]=i;
 
/*
if (n>100&&tests==500000)
{
    cout<<clock()*1.0/CLOCKS_PER_SEC<<endl; 
}*/
// seg tree
build(1,0,n-1);
/*
if (n>100&&tests==500000)
{
    cout<<clock()*1.0/CLOCKS_PER_SEC<<endl; 
}*/
/*
for (int i=0;i<v.size();i++)
{
    cout<<v[i]<<"  ";
    for (int j=v[i];j<S.size();j++)
     cout<<S[j];
    cout<<endl;
}
*/
// queries

for (;tests;--tests)
{
    int a,b,id;
/// cin>>a>>b>>id;
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&id);
    int ps1,ps2;
    if (did[id]){ps1=memps1[id];ps2=memps2[id];}
    else
    {
    int l,r;
    l=0;
    r=ent[start[id]];
    while (l<r)
    {
        int mid=l+r;
        mid/=2;
        if (CMP(v[mid],start[id],sz[id])>=0)
            r=mid;
        else
            l=mid+1;
    }
    ps1=l;
    l=ent[start[id]];
    r=n-1;
    while (l<r)
    {
        int mid=l+r+1;
        mid/=2;
        if (CMP(v[mid],start[id],sz[id])<=0)
        l=mid;
        else r=mid-1;
    }
    ps2=r;}
    did[id]=1;
    memps1[id]=ps1;
    memps2[id]=ps2;
//  cout<<ps1<<"  "<<ps2<<endl;
    int res=get(1,0,n-1,ps1,ps2,b)-get(1,0,n-1,ps1,ps2,a-1);
    printf("%d\n",res);
}

//cin.get();cin.get();
return 0;}