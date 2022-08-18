/*
City of screaming statues
Your soul will grow to understand and respect this place
It will be with you in your heart, on your journey

The gates of the city lies before you
The temples of truth whispering their waves
Chase your visions, slay your fears
What moves the truth is the sound of your thoughts

Scream

The struggle of the soul
Depends on the strenght of your will
Among the twisted shapes of your madness
You will find your light and your genius
In this city where the statues they scream
For their truth is to be real

The dreams and the visions
The reality and the light
Within the soul of the city
may be whatever you wish it to be
In the city where the statues they scream
For their truth is to be real

Stand up and turn your back on reality
Lie down and let your dreams attack
The silence of the soul that is true
Is the silence that you lack
Fell the strengeth pulsating through you
As the gates, they close behind you

The answers lie within the city of light
Within the light
In the sunrise of your soul, time is the key
The music of the truth, now behold

Rise and crush them

The gates of the city lies before you
The temples of truth whispering their waves
Chase your visions, slay your fears
What moves the truth is the sound of your thoughts

The statues they scream
For their truth is to be real
Within the walls of the city
Where death ain't the end

The music of the truth, the light of the end
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
#define bsize 512

using namespace std;

long long ar1[300000],ar2[300000],ar3[300000],flag[300000];
long long n,m,tl,tr,tv,res;
string st;
vector<long> v;
vector<long> parse(string st)
{
 st+=" ";
 vector<long> tt;
 long temp=0;
 long fll=0;
 for (int i=0;i<st.size();i++)
 {
     if (st[i]==' '){if (fll)temp=-temp;fll=0;tt.push_back(temp);temp=0;}
     else if (st[i]=='-')fll=1;else temp=temp*10+st[i]-48;   
 }
 return tt;
}

void upd(long l,long r,long long val)
{
 //push l
 if (flag[l/bsize])
 for (int i=l/bsize*bsize;i<l/bsize*bsize+bsize;i++)
 ar1[i]+=ar3[i/bsize];
 ar3[l/bsize]=0;flag[l/bsize]=0;
 
 long lblock=l/bsize;
 
 while (l%bsize>0&&l<=r)
 {
  ar1[l]+=val;++l;
 }
 ar2[lblock]=1e18;
 
 for (int i=lblock*bsize;i<lblock*bsize+bsize;i++)
  ar2[lblock]=min(ar2[lblock],ar1[i]);
 
 while (l+bsize<=r)
 {
  ar2[l/bsize]+=val;
  ar3[l/bsize]+=val;
  flag[l/bsize]=1;
  l+=bsize;
 }
  
  //push l
 if (flag[l/bsize])
 for (int i=l/bsize*bsize;i<l/bsize*bsize+bsize;i++)
 ar1[i]+=ar3[i/bsize];
 ar3[l/bsize]=0;flag[l/bsize]=0;
 
 lblock=l/bsize;
 
 while (l<=r)
 {
  ar1[l]+=val;l++;
 }
 ar2[lblock]=1e18;
 
 for (int i=lblock*bsize;i<lblock*bsize+bsize;i++)
  ar2[lblock]=min(ar2[lblock],ar1[i]);
 
}

long long gett(long long l,long long r)
{
 long long res=1e18;
 
 if (flag[l/bsize])
 for (int i=l/bsize*bsize;i<l/bsize*bsize+bsize;i++)
 ar1[i]+=ar3[i/bsize];
 ar3[l/bsize]=0;flag[l/bsize]=0;
 
 while (l%bsize&&l<=r)
 {
  res=min(res,ar1[l]);++l;
 }
 while (l+bsize<=r)
 {
  res=min(res,ar2[l/bsize]);
  l+=bsize;
 }
 
 if (flag[l/bsize])
 for (int i=l/bsize*bsize;i<l/bsize*bsize+bsize;i++)
 ar1[i]+=ar3[i/bsize];
 ar3[l/bsize]=0;flag[l/bsize]=0;
 
 while (l<=r)
 {res=min(res,ar1[l]);l++;}
 return res;
}
int main(){
//freopen("teams.in","r",stdin);
//freopen("teams.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=0;i<=n+1000;i++)
ar1[i]=ar2[i]=1e18;
for (int i=0;i<n;i++)
cin>>ar1[i];
cin>>m;
for (int i=0;i<n;i++)
ar2[i/bsize]=min(ar2[i/bsize],ar1[i]);

for (int i=0;i<n;i++)
flag[i]=0;

getline(cin,st);

for (int i=0;i<m;i++)
{
 /*   for (int j=11;j<=44;j++)
    cout<<gett(j,j)<<" ";
    cout<<endl;
   */
    getline(cin,st);
    v=parse(st);
    if (v.size()==3)
    {
     tl=v[0];tr=v[1];
     tv=v[2];
     if (tl>tr){upd(tl,n-1,tv);upd(0,tr,tv);}
     else upd(tl,tr,tv);
    }
    else
    {
        tl=v[0];tr=v[1];
        if (tl>tr){res=min(gett(tl,n-1),gett(0,tr));}
        else res=gett(tl,tr);
        cout<<res<<endl;
    }
}

cin.get();cin.get();
return 0;}