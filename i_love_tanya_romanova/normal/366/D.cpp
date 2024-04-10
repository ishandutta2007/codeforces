/*
Come break my bones, come spread my ashes.
Come wear me down, come wear me down.

In life a king, in death a failure.
Come help me cry, come help me cry.

"I wanted to be changed by the road.
I so wanted to change the road.
But somehow we both resisted change.
Somehow we were both too strong.
And yet we both winded away, unsure of where we head.
And it's like we're both confused as to who is who.
As if, late in the night, you can't tell the runner from the road - the walker from the walked.
Maybe I am just the road, dreaming that I walk"

Dust in my throat, dust in my nostrils.
Dust in my mouth, dust in my eyes.
From dust I come, through dust I wander.
Dust I'll remain - dust all I am.
Dust I'll remain - dust all I am.
Dust I'll remain - dust all I am.
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
#define eps 1e-7
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

long n,m,a[200000],b[200000],l[20000],r[20000],lp,rp;
long w[200000],d[200000];
vector<long> ls,rs;
long ta,tb;
long ans;

bool ok()
{
 long q,e;
 q=1;
 e=n;
 while (q!=w[q])q=w[q];
 while (e!=w[e])e=w[e];
 return (q==e);
}

void generate(long aa,long bb)
{
 for (int i=1;i<=n;i++)
 w[i]=i;
 for (int i=1;i<=n;i++)
 d[i]=0;
 for (int i=1;i<=m;i++)
 if (l[i]<=aa&&r[i]>=bb)
 {
  ta=a[i];
  tb=b[i];
  while (ta!=w[ta])ta=w[ta];
  while (tb!=w[tb])tb=w[tb];
  if (ta==tb)continue;
  if (d[ta]>d[tb])
  {
   w[tb]=ta;
  }
  else
  {
   w[ta]=tb;
   if (d[ta]==d[tb])++d[tb];
  }
 }
 
}

int main(){
//freopen("gift.in","r",stdin);
//freopen("gift.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
for (int i=1;i<=m;i++)
{
    cin>>a[i]>>b[i]>>l[i]>>r[i];
    ls.push_back(l[i]);
    rs.push_back(r[i]);
}
sort(ls.begin(),ls.end());
sort(rs.begin(),rs.end());

ans=-1;
lp=0;
rp=0;
for (;lp<ls.size();++lp)
{
//    cout<<lp<<" "<<rp<<" "<<ls[lp]<<" "<<rs[rp]<<endl;
 while (true){
 generate(ls[lp],rs[rp]);
 //cout<<lp<<" "<<rp<<" "<<ls[lp]<<" "<<rs[rp]<<" "<<ok()<<endl;
 if (ok())
 {ans=max(ans,rs[rp]-ls[lp]);}
 if (ok()&&rp+1<rs.size())++rp;
 else break;
 } 
}

//cout<<ans<<endl;
if (ans<0)cout<<"Nice work, Dima!"<<endl;
else cout<<ans+1<<endl;
cin.get();cin.get();
return 0;}